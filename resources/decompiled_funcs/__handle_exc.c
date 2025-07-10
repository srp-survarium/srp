BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double result; // [esp+18h] [ebp-14h]
  int expn; // [esp+24h] [ebp-8h] BYREF
  int flags_p; // [esp+28h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = 1;
      goto LABEL_43;
    }
    result = _decomp(*presult, &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = result < 0.0;
      HIWORD(result) = BYTE6(result) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(result) & 1) != 0 && !v7 )
            v7 = 1;
          LODWORD(result) >>= 1;
          if ( (BYTE4(result) & 1) != 0 )
            LODWORD(result) |= 0x80000000;
          HIDWORD(result) >>= 1;
          --v11;
        }
        while ( v11 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -result;
    }
    else
    {
      v7 = 1;
      v9 = result * 0.0;
    }
    result = v9;
LABEL_41:
    *presult = result;
LABEL_43:
    if ( v7 )
      _set_statfp(0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}
