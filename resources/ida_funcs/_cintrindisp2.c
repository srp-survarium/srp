int __usercall _cintrindisp2@<eax>(int a1@<edx>, __int16 a2@<fpstat>, double a3@<st1>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp2(a1, (int)&savedregs, a2, a3, a4);
  return cintrinexit();
}
