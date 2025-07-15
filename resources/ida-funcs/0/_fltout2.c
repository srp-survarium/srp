_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  __int16 v8; // [esp-Eh] [ebp-4Ah] BYREF
  int v9; // [esp-Ch] [ebp-48h]
  int v10; // [esp-8h] [ebp-44h]
  int v11; // [esp-4h] [ebp-40h]
  char *_Dst; // [esp+Ch] [ebp-30h]
  _FloatOutStruct fos; // [esp+10h] [ebp-2Ch] BYREF
  _LDOUBLE pld; // [esp+2Ch] [ebp-10h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(&pld, &x.x);
  v5 = _I10_OUTPUT(pld, 17, 0, &fos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = fos.sign;
  v4->decpt = fos.exp;
  if ( strcpy_s((int)&v8, v6, resultsize, fos.man) )
  {
    v11 = 0;
    v10 = 0;
    v9 = 0;
    v8 = 0;
    _invoke_watson((int)v4, (int)&v8, (int)v6);
  }
  v4->mantissa = v6;
  return v4;
}
