void __usercall _ctrandisp2(double a1@<st1>, double a2@<st0>, unsigned __int64 parm1, unsigned __int64 parm2)
{
  int v4; // edx
  __int16 v5; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm1);
  _fload(parm2);
  _trandisp2(v4, (int)&savedregs, v5, a1, a2);
  ctranexit();
}
