cmd_/home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.o := powerpc-4xx-softfloat-gcc -m32 -Wp,-MD,/home/napster/PFC/maerkapp/maerkserv/module/.maerk_mod.o.d  -nostdinc -isystem /opt/eldk-5.2.1/powerpc-4xx-softfloat/sysroots/i686-eldk-linux/usr/lib/ppc405-linux/gcc/powerpc-linux/4.6.4/include -I/home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include -Iarch/powerpc/include/generated -Iinclude  -include /home/napster/uclinux/linux-2.6-xlnx/include/linux/kconfig.h -D__KERNEL__ -Iarch/powerpc -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -msoft-float -pipe -Iarch/powerpc -ffixed-r2 -mmultiple -mno-altivec -mno-vsx -mno-spe -mspe=no -funit-at-a-time -fno-dwarf2-cfi-asm -mno-string -Wa,-m405 -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(maerk_mod)"  -D"KBUILD_MODNAME=KBUILD_STR(maerk_mod)" -c -o /home/napster/PFC/maerkapp/maerkserv/module/.tmp_maerk_mod.o /home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.c

source_/home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.o := /home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.c

deps_/home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.o := \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  include/linux/sysinfo.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/posix_types.h \
  include/asm-generic/posix_types.h \
  /opt/eldk-5.2.1/powerpc-4xx-softfloat/sysroots/i686-eldk-linux/usr/lib/ppc405-linux/gcc/powerpc-linux/4.6.4/include/stdarg.h \
  include/linux/linkage.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/linkage.h \
  include/linux/bitops.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/bitops.h \
    $(wildcard include/config/ppc64.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/asm-compat.h \
    $(wildcard include/config/ibm405/err77.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/ppc-opcode.h \
  include/linux/stringify.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/synch.h \
    $(wildcard include/config/ppc/e500mc.h) \
    $(wildcard include/config/e500.h) \
    $(wildcard include/config/smp.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/feature-fixups.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/asm-generic/bitops/sched.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/dynamic_debug.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/string.h \
  include/linux/errno.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/byteorder.h \
  include/linux/byteorder/big_endian.h \
  include/linux/swab.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/module.h \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/const.h \
  include/linux/stat.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/stat.h \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/cache.h \
    $(wildcard include/config/8xx.h) \
    $(wildcard include/config/403gcx.h) \
    $(wildcard include/config/ppc32.h) \
    $(wildcard include/config/ppc/47x.h) \
    $(wildcard include/config/6xx.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  include/linux/bug.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/thread_info.h \
    $(wildcard include/config/ppc/256k/pages.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/processor.h \
    $(wildcard include/config/vsx.h) \
    $(wildcard include/config/ppc/prep.h) \
    $(wildcard include/config/task/size.h) \
    $(wildcard include/config/kernel/start.h) \
    $(wildcard include/config/booke.h) \
    $(wildcard include/config/ppc/adv/debug/regs.h) \
    $(wildcard include/config/ppc/adv/debug/iacs.h) \
    $(wildcard include/config/ppc/adv/debug/dvcs.h) \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/altivec.h) \
    $(wildcard include/config/spe.h) \
    $(wildcard include/config/kvm/book3s/32/handler.h) \
    $(wildcard include/config/kvm.h) \
    $(wildcard include/config/pseries/idle.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/reg.h \
    $(wildcard include/config/40x.h) \
    $(wildcard include/config/fsl/emb/perfmon.h) \
    $(wildcard include/config/ppc/book3s/64.h) \
    $(wildcard include/config/ppc/book3s/32.h) \
    $(wildcard include/config/ppc/book3e/64.h) \
    $(wildcard include/config/e200.h) \
    $(wildcard include/config/ppc/cell.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/cputable.h \
    $(wildcard include/config/mpc10x/bridge.h) \
    $(wildcard include/config/ppc/83xx.h) \
    $(wildcard include/config/8260.h) \
    $(wildcard include/config/ppc/mpc52xx.h) \
    $(wildcard include/config/bdi/switch.h) \
    $(wildcard include/config/4xx.h) \
    $(wildcard include/config/power3.h) \
    $(wildcard include/config/power4.h) \
    $(wildcard include/config/ppc/book3e.h) \
    $(wildcard include/config/44x.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/reg_booke.h \
    $(wildcard include/config/ppc/icswx.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/ptrace.h \
  include/asm-generic/ptrace.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/page.h \
    $(wildcard include/config/ppc/64k/pages.h) \
    $(wildcard include/config/ppc/16k/pages.h) \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/nonstatic/kernel.h) \
    $(wildcard include/config/relocatable/ppc32.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/ppc/std/mmu/64.h) \
    $(wildcard include/config/ppc/smlpar.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/kdump.h \
    $(wildcard include/config/crash/dump.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/page_32.h \
    $(wildcard include/config/physical/align.h) \
    $(wildcard include/config/not/coherent/cache.h) \
    $(wildcard include/config/pte/64bit.h) \
  include/asm-generic/getorder.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/irqflags.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/hw_irq.h \
  include/linux/bottom_half.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/barrier.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  include/linux/spinlock_up.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_up.h \
  include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
    $(wildcard include/config/generic/atomic64.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/atomic.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/cmpxchg.h \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/atomic-long.h \
  include/asm-generic/atomic64.h \
  include/linux/math64.h \
  include/linux/uidgid.h \
    $(wildcard include/config/uidgid/strict/type/checks.h) \
    $(wildcard include/config/user/ns.h) \
  include/linux/highuid.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/cma.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/memblock/node.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/wait.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/current.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/nodemask.h \
  include/linux/bitmap.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  include/linux/notifier.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/have/arch/mutex/cpu/relax.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  arch/powerpc/include/generated/asm/rwsem.h \
  include/asm-generic/rwsem.h \
  include/linux/srcu.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/preempt/rt.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/completion.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/rcutiny.h \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/linux/param.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/param.h \
  include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/timex.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/pfn.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/topology.h \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/ppc/splpar.h) \
  include/asm-generic/topology.h \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  include/linux/rbtree.h \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/elf.h \
    $(wildcard include/config/spu/base.h) \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/uprobes.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/cfs/bandwidth.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/mm/owner.h) \
  include/linux/capability.h \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/transparent/hugepage.h) \
  include/linux/auxvec.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/auxvec.h \
  include/linux/prio_tree.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/guard.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  include/linux/uprobes.h \
    $(wildcard include/config/arch/supports/uprobes.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/mmu.h \
    $(wildcard include/config/ppc/fsl/book3e.h) \
    $(wildcard include/config/ppc/std/mmu/32.h) \
    $(wildcard include/config/ppc/book3e/mmu.h) \
    $(wildcard include/config/ppc/8xx.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/mmu-44x.h \
    $(wildcard include/config/ppc/early/debug/44x.h) \
    $(wildcard include/config/ppc/early/debug/44x/physlow.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/ipcbuf.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/sembuf.h \
  include/linux/signal.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/signal.h \
  include/asm-generic/signal-defs.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/pid.h \
  include/linux/proportions.h \
  include/linux/percpu_counter.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/seccomp/filter.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/seccomp.h \
  include/linux/unistd.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/unistd.h \
  include/linux/rculist.h \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/resource.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/timerfd.h) \
  include/linux/timerqueue.h \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/latencytop.h \
  include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/security.h) \
  include/linux/key.h \
  include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  include/linux/aio.h \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
  include/linux/tracepoint.h \
  include/linux/static_key.h \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  include/linux/export.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/module.h \
    $(wildcard include/config/dynamic/ftrace.h) \
  include/linux/ioport.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/uaccess.h \
  include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  include/linux/limits.h \
  include/linux/ioctl.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/linux/blk_types.h \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
  include/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/rculist_bl.h \
  include/linux/list_bl.h \
  include/linux/bit_spinlock.h \
  include/linux/path.h \
  include/linux/radix-tree.h \
  include/linux/semaphore.h \
  include/linux/fiemap.h \
  include/linux/shrinker.h \
  include/linux/migrate_mode.h \
  include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  include/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/nfs_fs_i.h \
  include/linux/fcntl.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/fcntl.h \
  include/asm-generic/fcntl.h \
  include/linux/err.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/io.h \
    $(wildcard include/config/ra.h) \
    $(wildcard include/config/rd.h) \
    $(wildcard include/config/ppc/indirect/io.h) \
    $(wildcard include/config/eeh.h) \
    $(wildcard include/config/ppc/indirect/pio.h) \
    $(wildcard include/config/ppc/indirect/mmio.h) \
  include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  include/linux/klist.h \
  include/linux/pm.h \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  include/linux/ratelimit.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/device.h \
    $(wildcard include/config/swiotlb.h) \
  include/linux/pm_wakeup.h \
  include/linux/io.h \
    $(wildcard include/config/has/ioport.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/delay.h \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/time.h \
    $(wildcard include/config/power.h) \
    $(wildcard include/config/8xx/cpu6.h) \
  include/asm-generic/iomap.h \
    $(wildcard include/config/generic/iomap.h) \
  include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/io-defs.h \
  include/linux/cdev.h \
  include/linux/interrupt.h \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
  include/linux/irqreturn.h \
  include/linux/irqnr.h \
  include/linux/hardirq.h \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/hardirq.h \
  include/linux/irq.h \
    $(wildcard include/config/s390.h) \
    $(wildcard include/config/generic/pending/irq.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/irq.h \
    $(wildcard include/config/nr/irqs.h) \
  include/linux/irqdomain.h \
    $(wildcard include/config/irq/domain.h) \
    $(wildcard include/config/of/irq.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/irq_regs.h \
  include/asm-generic/irq_regs.h \
  include/linux/irqdesc.h \
    $(wildcard include/config/irq/preflow/fasteoi.h) \
    $(wildcard include/config/sparse/irq.h) \
  include/linux/platform_device.h \
    $(wildcard include/config/suspend.h) \
    $(wildcard include/config/hibernate/callbacks.h) \
  include/linux/mod_devicetable.h \
  include/linux/of_address.h \
    $(wildcard include/config/of/address.h) \
  include/linux/of.h \
    $(wildcard include/config/sparc.h) \
    $(wildcard include/config/of/dynamic.h) \
    $(wildcard include/config/of.h) \
  /home/napster/uclinux/linux-2.6-xlnx/arch/powerpc/include/asm/prom.h \
  include/linux/of_fdt.h \
    $(wildcard include/config/of/flattree.h) \
    $(wildcard include/config/blk/dev/initrd.h) \
  include/linux/of_irq.h \
    $(wildcard include/config/ppc/pmac.h) \
  include/linux/of_device.h \
    $(wildcard include/config/of/device.h) \
  include/linux/of_platform.h \

/home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.o: $(deps_/home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.o)

$(deps_/home/napster/PFC/maerkapp/maerkserv/module/maerk_mod.o):
