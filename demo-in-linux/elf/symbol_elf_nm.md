```text
> nm symbol.elf
000000000000038c r __abi_tag
0000000000004018 B __bss_start
0000000000004018 b completed.0
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004000 D __data_start
0000000000004000 W data_start
0000000000001090 t deregister_tm_clones
0000000000001100 t __do_global_dtors_aux
0000000000003dc0 d __do_global_dtors_aux_fini_array_entry
0000000000004008 D __dso_handle
0000000000003dc8 d _DYNAMIC
0000000000004018 D _edata
0000000000004028 B _end
0000000000001238 T _fini
0000000000001140 t frame_dummy
0000000000003db8 d __frame_dummy_init_array_entry
00000000000021b8 r __FRAME_END__
0000000000001149 T functionA
000000000000117f T functionB
00000000000011b5 T functionC
000000000000401c B globalIntA
0000000000004010 D globalIntB
0000000000003fb8 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
0000000000002064 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
00000000000011eb T main
                 U printf@GLIBC_2.2.5
00000000000010c0 t register_tm_clones
0000000000001060 T _start
0000000000004020 b staticIntA.0
0000000000004014 d staticIntB.1
0000000000004018 D __TMC_END__
```