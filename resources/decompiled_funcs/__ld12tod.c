INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  int v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(_DWORD *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = 0;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = DoubleFormat.precision - 1;
    v64 = v3;
    v65 = DoubleFormat.precision / 32;
    v9 = &v60 + DoubleFormat.precision / 32;
    v66 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || !v67 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = DoubleFormat.bias + v3;
          v50 = DoubleFormat.exp_width / 32;
          v51 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12g = 0;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = DoubleFormat.exp_width / 32;
          v44 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12f = 0;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = DoubleFormat.bias + DoubleFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (DoubleFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (DoubleFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = 0;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = DoubleFormat.precision - 1;
      v25 = DoubleFormat.precision / 32;
      v65 = DoubleFormat.precision / 32;
      v26 = &v60 + DoubleFormat.precision / 32;
      v64 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (DoubleFormat.exp_width + 1) / 32;
      v37 = (DoubleFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = 0;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( !*(&v60 + v6) )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  v55 = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v56 = v61;
    HIDWORD(d->x) = v55;
    LODWORD(d->x) = v56;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v55;
  }
  return result;
}
