void __usercall stlp_std::priv::_Stl_tenscale(int exp@<eax>, unsigned __int64 *p, int *bexp)
{
  int *v3; // edi
  signed int v4; // ebx
  int v5; // eax
  int *v6; // eax
  int v7; // edi
  unsigned __int64 v8; // [esp-18h] [ebp-48h]
  unsigned __int64 v9; // [esp-10h] [ebp-40h]
  unsigned __int64 v10; // [esp-Ch] [ebp-3Ch]
  int v11; // [esp+Ch] [ebp-24h]
  signed int v12; // [esp+10h] [ebp-20h] BYREF
  int v13; // [esp+14h] [ebp-1Ch] BYREF
  int v14; // [esp+18h] [ebp-18h] BYREF
  int v15; // [esp+1Ch] [ebp-14h]
  unsigned __int64 v16; // [esp+20h] [ebp-10h] BYREF
  unsigned __int64 v17; // [esp+28h] [ebp-8h] BYREF

  v3 = bexp;
  *bexp = 0;
  if ( exp )
  {
    v4 = 0;
    v12 = 0;
    v11 = exp;
    if ( exp <= 0 )
    {
      v4 = (-1 - exp) / 0x1Cu + 1;
      v12 = v4;
      v11 = exp + 28 * v4;
      v5 = 37;
      v13 = 13;
    }
    else
    {
      if ( exp > 27 )
      {
        v11 = exp + 1;
        if ( exp + 1 > 27 )
        {
          v4 = (exp - 27) / 0x1Cu + 1;
          v12 = v4;
          v11 = exp + 1 - 28 * v4;
        }
      }
      v5 = 26;
      v13 = 11;
    }
    if ( v4 )
    {
      v15 = v5 - 1;
      do
      {
        v6 = &v13;
        if ( v13 >= v4 )
          v6 = &v12;
        v4 -= *v6;
        v7 = v15 + *v6;
        HIDWORD(v9) = HIDWORD(Stl_tenpow[v7]);
        LODWORD(v9) = Stl_tenpow[v7];
        v8 = *p;
        v12 = v4;
        stlp_std::priv::_Stl_mult64(&v16, v8, v9, &v17);
        stlp_std::priv::_Stl_norm_and_round(p, &v14, v17, v16);
        *bexp += Stl_twoexp[v7] - v14;
      }
      while ( v4 );
      v3 = bexp;
    }
    if ( v11 )
    {
      HIDWORD(v10) = dword_6B4774[2 * v11];
      LODWORD(v10) = dword_6B4770[2 * v11];
      stlp_std::priv::_Stl_mult64(&v16, *p, v10, &v17);
      stlp_std::priv::_Stl_norm_and_round(p, &v14, v17, v16);
      *v3 += *((__int16 *)&Stl_tenpow[79] + v11 + 3) - v14;
    }
  }
}
