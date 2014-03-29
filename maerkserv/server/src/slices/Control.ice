module Maerklin {
	
	interface Control{
		void Locom(int idLocom, int vel, int dir, out int ret);
	    void Func(int idLocom, int fun, int stat, out int ret);
		void Sole(int idSole, int stat, out int ret);
	};
};
