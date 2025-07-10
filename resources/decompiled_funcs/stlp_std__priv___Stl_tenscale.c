void __usercall stlp_std::priv::_Stl_tenscale(int exp@<eax>, unsigned __int64 *p, int *bexp)
{
  int *v3; // edi
  int v4; // ebx
  int v5; // eax
  int *p_num_hi; // eax
  int v7; // edi
  unsigned __int64 v8; // [esp-18h] [ebp-48h]
  unsigned __int64 v9; // [esp-10h] [ebp-40h]
  unsigned __int64 v10; // [esp-Ch] [ebp-3Ch]
  int exp_lo; // [esp+Ch] [ebp-24h]
  int exp_hi; // [esp+10h] [ebp-20h] BYREF
  int num_hi; // [esp+14h] [ebp-1Ch] BYREF
  int norm; // [esp+18h] [ebp-18h] BYREF
  int v15; // [esp+1Ch] [ebp-14h]
  unsigned __int64 prodlo; // [esp+20h] [ebp-10h] BYREF
  unsigned __int64 prodhi; // [esp+28h] [ebp-8h] BYREF

  v3 = bexp;
  *bexp = 0;
  if ( exp )
  {
    v4 = 0;
    exp_hi = 0;
    exp_lo = exp;
    if ( exp <= 0 )
    {
      v4 = (-1 - exp) / 0x1Cu + 1;
      exp_hi = v4;
      exp_lo = exp + 28 * v4;
      v5 = 37;
      num_hi = 13;
    }
    else
    {
      if ( exp > 27 )
      {
        exp_lo = exp + 1;
        if ( exp + 1 > 27 )
        {
          v4 = (exp - 27) / 0x1Cu + 1;
          exp_hi = v4;
          exp_lo = exp + 1 - 28 * v4;
        }
      }
      v5 = 26;
      num_hi = 11;
    }
    if ( v4 )
    {
      v15 = v5 - 1;
      do
      {
        p_num_hi = &num_hi;
        if ( num_hi >= v4 )
          p_num_hi = &exp_hi;
        v4 -= *p_num_hi;
        v7 = v15 + *p_num_hi;
        HIDWORD(v9) = HIDWORD(Stl_tenpow[v7]);
        LODWORD(v9) = Stl_tenpow[v7];
        v8 = *p;
        exp_hi = v4;
        stlp_std::priv::_Stl_mult64(&prodlo, v8, v9, &prodhi);
        stlp_std::priv::_Stl_norm_and_round(p, &norm, prodhi, prodlo);
        *bexp += Stl_twoexp[v7] - norm;
      }
      while ( v4 );
      v3 = bexp;
    }
    if ( exp_lo )
    {
      HIDWORD(v10) = dword_8175EC[2 * exp_lo];
      LODWORD(v10) = *((_DWORD *)&dword_8175E8 + 2 * exp_lo);
      stlp_std::priv::_Stl_mult64(&prodlo, *p, v10, &prodhi);
      stlp_std::priv::_Stl_norm_and_round(p, &norm, prodhi, prodlo);
      *v3 += *((__int16 *)&Stl_tenpow[79] + exp_lo + 3) - norm;
    }
  }
}
