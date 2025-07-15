void __usercall _startOneArgErrorHandling(
        int a1@<eax>,
        int a2@<edx>,
        char *a3@<ecx>,
        __int16 savCW,
        unsigned int ret_addr,
        unsigned __int64 param1)
{
  _exception exc; // [esp+0h] [ebp-20h] BYREF

  exc.type = a1;
  __asm { fstp    [ebp+exc.retval] }
  exc.name = a3;
  *(_QWORD *)&exc.arg1 = param1;
  _87except(a2, &exc, (unsigned __int16 *)&savCW);
  __asm { fld     [ebp+exc.retval] }
  if ( savCW != 639 )
    __asm { fldcw   word ptr [ebp+savCW] }
}
