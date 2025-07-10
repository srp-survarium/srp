_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  char *v5; // esi
  __int16 v7; // [esp-Eh] [ebp-4Ah] BYREF
  int v8; // [esp-Ch] [ebp-48h]
  int v9; // [esp-8h] [ebp-44h]
  int v10; // [esp-4h] [ebp-40h]
  char *_Dst; // [esp+Ch] [ebp-30h]
  _FloatOutStruct autofos; // [esp+10h] [ebp-2Ch] BYREF
  _LDOUBLE ld; // [esp+2Ch] [ebp-10h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(&ld, &x.x);
  v5 = _Dst;
  v4->flag = _I10_OUTPUT(ld, 17, 0, &autofos);
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(v5, resultsize, autofos.man) )
  {
    v10 = 0;
    v9 = 0;
    v8 = 0;
    v7 = 0;
    _invoke_watson((unsigned int)v4, (unsigned int)&v7, (unsigned int)v5);
  }
  v4->mantissa = v5;
  return v4;
}
