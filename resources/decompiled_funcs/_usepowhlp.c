double __usercall usepowhlp@<st0>(int a1@<ebp>, long double y@<st1>, long double x@<st0>)
{
  int v4; // eax
  double result; // st7
  long double *v6; // [esp+10h] [ebp-7Ch]
  long double v7[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v7;
  v6 = v7;
  __asm { fsave   byte ptr [esi+8] }
  v4 = _powhlp(x, y, v7);
  __asm { frstor  byte ptr [esi+8] }
  result = v7[0];
  if ( v4 )
    _rttosnpopde(a1);
  return result;
}
