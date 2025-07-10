void __usercall _ctrandisp1(double a1@<st0>, unsigned __int64 parm1)
{
  int v2; // edx
  __int16 v3; // cx
  __int16 v4; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm1);
  _trandisp1(v2, v3, (int)&savedregs, v4, a1);
  ctranexit((int)&savedregs);
}
