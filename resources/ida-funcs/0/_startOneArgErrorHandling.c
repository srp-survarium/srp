void __usercall _startOneArgErrorHandling(
        int a1@<eax>,
        int a2@<edx>,
        char *a3@<ecx>,
        unsigned __int16 savCW,
        unsigned int ret_addr,
        long double param1)
{
  _exception exc; // [esp+0h] [ebp-20h] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  exc.type = a1;
  __asm { fstp    [ebp+exc.retval] }
  exc.name = a3;
  exc.arg1 = param1;
  _87except((int)&savedregs, a2, &exc, &savCW);
  __asm { fld     [ebp+exc.retval] }
  if ( savCW != 639 )
    __asm { fldcw   [ebp+pcw16] }
}
