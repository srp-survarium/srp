void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // eax
  __int16 v7; // cx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = (unsigned int)&loc_FFFFF & v4;
  msb = 0x80000000;
  if ( !(_WORD)v3 )
  {
    if ( !v6 && !v5 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_13;
    }
    v7 = 15361;
    msb = 0;
    goto LABEL_9;
  }
  if ( (unsigned __int16)v3 != 2047 )
  {
    v7 = v3 + 15360;
LABEL_9:
    v8 = v7;
    goto LABEL_10;
  }
  v8 = 0x7FFF;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  *(_DWORD *)&pld->ld[4] = v11;
  *(_DWORD *)pld->ld = v5 << 11;
  if ( (v11 & 0x80000000) == 0 )
  {
    do
    {
      v12 = *(__int64 *)pld->ld >> 31;
      v13 = 2 * *(_DWORD *)pld->ld;
      --v8;
      *(_DWORD *)&pld->ld[4] = v12;
      *(_DWORD *)pld->ld = v13;
    }
    while ( (v12 & 0x80000000) == 0 );
  }
  v10 = v8 | sign;
LABEL_13:
  *(_WORD *)&v9->ld[8] = v10;
}
