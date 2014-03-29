/* Graphic User Interface
 * J.Manuel Muñoz, Ingeniería informática */

#include <stdio.h>
#include <gtkmm.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <glibmm/thread.h>
#include <iostream>
#include "Args.h"
#include "Client.h"

#ifdef ENABLE_NLS
#  include <libintl.h>
#endif

#define UI_FILE "../ui/gui.ui"
#define PARAMLEN 3
#define LHOUR 9

Gtk::Window* main_win = 0;
Gtk::ComboBoxText* comboConLoc = 0;
Gtk::ComboBoxText* comboVel = 0;
Gtk::ComboBoxText* comboFunLoc = 0;
Gtk::ComboBoxText* comboFun = 0;
Gtk::ComboBoxText* comboSole = 0;
Gtk::RadioButton* radHor = 0;
Gtk::RadioButton* radAnti = 0;
Gtk::RadioButton::Group group;
Gtk::Switch* swFun = 0;
Gtk::Switch* swSole = 0;
Gtk::Button* butCon = 0;
Gtk::Button* butFun = 0;
Gtk::Button* butSole = 0;
Gtk::TextView* textCons = 0;
Gtk::ScrolledWindow* scrolled = 0;
Glib::RefPtr<Gtk::TextBuffer> ref_buf;

Client *cli;
arguments ar;
attr maerkAttr;
Glib::Mutex mutex_msg;
Glib::Mutex mutex_sig;

void fillComboLoc();
void fillComboVel();
void fillComboFun();
void fillComboSole();
static void conLocChanged();
static void velChanged();
static void funLocChanged();
static void funChanged();
static void soleChanged();
static void radioChanged();
static void btConClicked();
static void btFunClicked();
static void btSoleClicked();
int checkCon();
int checkFun();
int checkSole();
void checkStatus(int status);
void sysHour(char *hour);
void printConsole(const char *msg);
void showMessage(const char *msg);
void event(int n);
void initAttr(attr maerkAttr);

void fillComboLoc() {
	int i;
	char buf[PARAMLEN];

	for(i = MIN_LOCOM; i <= MAX_LOCOM; i++) {
		snprintf(buf, PARAMLEN, "%d", i);
		comboConLoc -> append(buf);
		comboFunLoc -> append(buf);
	}
}

void fillComboVel() {
	int i;
	char buf[PARAMLEN];

	for(i = MIN_VEL; i <= MAX_VEL; i++) {
		snprintf(buf, PARAMLEN, "%d", i);
		comboVel -> append(buf);
	}
}

void fillComboFun() {
	int i;
	char buf[PARAMLEN];

	for(i = MIN_FUN; i <= MAX_FUN; i++) {
		snprintf(buf, PARAMLEN, "%d", i);
		comboFun -> append(buf);
	}
}

void fillComboSole() {
	int i;
	char buf[PARAMLEN];

	for(i = MIN_SOLE; i <= MAX_SOLE; i++) {
		snprintf(buf, PARAMLEN, "%d", i);
		comboSole -> append(buf);
	}
}

static void conLocChanged() {

	const char *buf;
	
	buf = (comboConLoc -> get_active_text()).c_str();
	maerkAttr.idConLocom = atoi(buf);
	printf("Locomotora seleccionada: %d \n", maerkAttr.idConLocom);
}

static void velChanged() {

	const char *buf;
	
	buf = (comboVel -> get_active_text()).c_str();
	maerkAttr.vel = atoi(buf);
	printf("Velocidad seleccionada: %d \n", maerkAttr.vel);
}

static void funLocChanged() {

	const char *buf;
	
	buf = (comboFunLoc -> get_active_text()).c_str();
	maerkAttr.idFunLocom = atoi(buf);
	printf("Locomotora seleccionada: %d \n", maerkAttr.idFunLocom);
}

static void funChanged() {

	const char *buf;
	
	buf = (comboFun -> get_active_text()).c_str();
	maerkAttr.fun = atoi(buf);
	printf("Función seleccionada: %d \n", maerkAttr.fun);
}

static void soleChanged() {

	const char *buf;
	
	buf = (comboSole -> get_active_text()).c_str();
	maerkAttr.idSole = atoi(buf);
	printf("Solenoide seleccionado: %d \n", maerkAttr.idSole);
}

static void radioChanged() {

	if(radHor -> get_active ()) {
		maerkAttr.dir = DIR_C;
	}
	else if(radAnti -> get_active()) {
		maerkAttr.dir = DIR_O;
	}
	else {
		fprintf(stderr, "Error: radio button coherence error");
	}
	
	printf("Sentido seleccionado: %d \n", maerkAttr.dir);
}

static void btConClicked() {
	int ret, status;

	ret = checkCon();
	if(ret == 0) {
		status = cli -> ctrlInvocation(ar, OPCON, maerkAttr);
		checkStatus(status);
	}
}

static void btFunClicked() {
	int ret, status;

	if(swFun -> get_active()) {
		maerkAttr.fstat = ON;
	} else {
		maerkAttr.fstat = OFF;
	}	
	
	ret = checkFun();
	if(ret == 0) {
		status = cli -> ctrlInvocation(ar, OPFUN, maerkAttr);
		checkStatus(status);
	}
}

static void btSoleClicked() {
	int ret, status;

	if(swSole -> get_active()) {
		maerkAttr.sstat = OPEN;
	} else {
		maerkAttr.sstat = CLOSE;
	}
	
	ret = checkSole();
	if(ret == 0) {
		status = cli -> ctrlInvocation(ar, OPSOLE, maerkAttr);
		checkStatus(status);
	}
}

int checkCon() {

	if(maerkAttr.idConLocom == -1 || maerkAttr.vel == -1 || maerkAttr.dir == -1) {
		printConsole("Info: Faltan parámetros para ejecutar la órden de control");
		return -1;
	}
	else {
		return 0;
	}
}

int checkFun() {

	if(	maerkAttr.idFunLocom == -1 || maerkAttr.fun == -1 || maerkAttr.fstat == -1) {
		printConsole("Info: Faltan parámetros para ejecutar la órden de función");
		return -1;
	}
	else {
		return 0;
	}
}

int checkSole() {
	
	if(maerkAttr.idSole == -1 || maerkAttr.sstat == -1) {
		printConsole("Info: Faltan parámetros para ejecutar la órden de solenoide");
		return -1;
	}
	else {
		return 0;
	}
}

void checkStatus(int status) {
	
	if(status == EXIT_SUCCESS) {
		printConsole("Info: Comando válido y enviado al servidor");
	}
	else if(status == EXIT_FAILURE) {
		printConsole("Error: No se puede conectar con el servidor");
	}
	else {
		printConsole("Error: Comando inválido, no se envía al servidor");
	}
}

void sysHour(char *hour) {

	char buf[LHOUR];
	time_t curtime;
	struct tm *loctime;

	curtime = time(NULL);
	loctime = localtime(&curtime);
	strftime (buf, LHOUR, "%H:%M:%S", loctime);

	strncpy(hour, buf, LHOUR);
	hour[LHOUR - 1] = '\0';
}

void printConsole(const char *msg) {

	char param[LENMSG];

	strncpy(param, msg, LENMSG);
	param[LENMSG - 1] = '\0';
	
	Glib::Thread *const thr = Glib::Thread::create(
	sigc::bind(sigc::ptr_fun(&showMessage), param), true);
       
	thr->join();
}

void showMessage(const char *msg) {

	mutex_msg.lock();
	
	int lines;
	char hour[LHOUR];
	char buf[512];
	Gtk::TextBuffer::iterator iter;

	sysHour(hour);
	snprintf(buf, sizeof(buf), "(%s) %s \n", hour, msg);
	
	ref_buf -> insert_at_cursor(buf);
	textCons -> set_buffer(ref_buf);

	lines = ref_buf -> get_line_count();
	iter = ref_buf -> get_iter_at_line(lines);
	textCons -> scroll_to(iter);

	mutex_msg.unlock();
}

void event(int n) {

	mutex_sig.lock();

	char msg[LENMSG];
	cli -> readEvent(msg);
	printConsole(msg);

	mutex_sig.unlock();
}

void initAttr() {
	
	maerkAttr.idConLocom = -1;
	maerkAttr.vel = -1;
	maerkAttr.dir = DIR_C;
	maerkAttr.idFunLocom = -1;
	maerkAttr.fun = -1;
	maerkAttr.fstat = ON;
	maerkAttr.idSole = -1;
	maerkAttr.sstat = CLOSE;
}

int main(int argc, char **argv) {

	initAttr();
	ar.argc = argc;
	ar.argv = argv;
	ar.pid = getpid();
	
	Glib::thread_init();

	signal(SIGALRM, event);

	Gtk::Main kit(argc, argv);

	Glib::RefPtr<Gtk::Builder> builder;

	try {
		builder = Gtk::Builder::create_from_file(UI_FILE);
	}
	catch (const Glib::FileError & ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	
	builder -> get_widget("main_window", main_win);

	if(main_win) {

		builder -> get_widget("comboConLoc", comboConLoc);
		builder -> get_widget("comboVel", comboVel);
		builder -> get_widget("comboFunLoc", comboFunLoc);
		builder -> get_widget("comboFun", comboFun);
		builder -> get_widget("comboSole", comboSole);

		if(comboConLoc && comboVel && comboFunLoc && comboFun && comboSole) {
			fillComboLoc();
			fillComboVel();
			fillComboFun();
			fillComboSole();
			comboConLoc -> signal_changed().connect(sigc::ptr_fun(conLocChanged));
			comboVel -> signal_changed().connect(sigc::ptr_fun(velChanged));
			comboFunLoc -> signal_changed().connect(sigc::ptr_fun(funLocChanged));
			comboFun -> signal_changed().connect(sigc::ptr_fun(funChanged));
			comboSole -> signal_changed().connect(sigc::ptr_fun(soleChanged));

			builder -> get_widget("radioHor", radHor);
			builder -> get_widget("radioAnti", radAnti);

			if(radHor && radAnti) {
				group = radHor -> get_group();
				radAnti -> set_group(group);
				radHor  -> signal_released().connect(sigc::ptr_fun(radioChanged));
				radAnti -> signal_released().connect(sigc::ptr_fun(radioChanged));

				builder -> get_widget("switchOnOff", swFun);
				builder -> get_widget("switchOpClo", swSole);

				if(swFun && swSole) {
					builder -> get_widget("btCon", butCon);
					builder -> get_widget("btFun", butFun);
					builder -> get_widget("btSole", butSole);

					if(butCon && butFun && butSole) {

						butCon -> signal_clicked().connect(sigc::ptr_fun(btConClicked));
						butFun -> signal_clicked().connect(sigc::ptr_fun(btFunClicked));
						butSole -> signal_clicked().connect(sigc::ptr_fun(btSoleClicked));

						builder -> get_widget("scrolledWin", scrolled);
						builder -> get_widget("textConsole", textCons);

						if(scrolled && textCons) {
							ref_buf = textCons -> get_buffer();

							cli = Client::Instance();
							if(!cli -> init(ar)) {
								kit.run(*main_win);
							}
							cli -> end();
						}
					}
				}
			}
		}
	}
	return 0;
}
