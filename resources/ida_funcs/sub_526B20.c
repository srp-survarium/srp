int __cdecl sub_526B20(int a1, int a2, int a3, unsigned __int8 **a4, int *a5)
{
  int result; // eax
  int v6; // eax
  int v8; // ecx
  int v11; // edx
  int v14; // [esp+0h] [ebp-A4h]
  int v15; // [esp+8h] [ebp-9Ch]
  int v16; // [esp+Ch] [ebp-98h]
  _DWORD *ii; // [esp+10h] [ebp-94h]
  _BYTE *v18; // [esp+14h] [ebp-90h]
  char *m; // [esp+18h] [ebp-8Ch]
  unsigned __int8 v20; // [esp+1Fh] [ebp-85h]
  unsigned __int8 v21; // [esp+26h] [ebp-7Eh]
  unsigned __int8 v22; // [esp+27h] [ebp-7Dh]
  int v23; // [esp+28h] [ebp-7Ch]
  int v24; // [esp+2Ch] [ebp-78h]
  unsigned __int8 *v25; // [esp+34h] [ebp-70h]
  _BYTE *v26; // [esp+34h] [ebp-70h]
  int v27; // [esp+34h] [ebp-70h]
  int v28; // [esp+38h] [ebp-6Ch]
  int j; // [esp+3Ch] [ebp-68h]
  int k; // [esp+3Ch] [ebp-68h]
  int v31; // [esp+3Ch] [ebp-68h]
  int v32; // [esp+40h] [ebp-64h]
  int v33; // [esp+40h] [ebp-64h]
  int v34; // [esp+44h] [ebp-60h]
  int v35; // [esp+48h] [ebp-5Ch]
  _DWORD **v36; // [esp+4Ch] [ebp-58h]
  int v37; // [esp+50h] [ebp-54h]
  signed int i; // [esp+54h] [ebp-50h]
  _DWORD *v39; // [esp+60h] [ebp-44h]
  int v40; // [esp+64h] [ebp-40h]
  int v41; // [esp+68h] [ebp-3Ch]
  int v42; // [esp+6Ch] [ebp-38h]
  int v43; // [esp+70h] [ebp-34h]
  signed int v44; // [esp+74h] [ebp-30h]
  int v45; // [esp+74h] [ebp-30h]
  int v46; // [esp+74h] [ebp-30h]
  int v47; // [esp+74h] [ebp-30h]
  signed int v48; // [esp+78h] [ebp-2Ch]
  int v49; // [esp+7Ch] [ebp-28h]
  int v50; // [esp+80h] [ebp-24h]
  int v51; // [esp+84h] [ebp-20h]
  unsigned int v52; // [esp+88h] [ebp-1Ch]
  unsigned __int8 *dst; // [esp+8Ch] [ebp-18h]
  unsigned __int8 *dsta; // [esp+8Ch] [ebp-18h]
  unsigned __int8 *dstb; // [esp+8Ch] [ebp-18h]
  signed int count; // [esp+90h] [ebp-14h]
  signed int counta; // [esp+90h] [ebp-14h]
  signed int countb; // [esp+90h] [ebp-14h]
  signed int countc; // [esp+90h] [ebp-14h]
  unsigned int countd; // [esp+90h] [ebp-14h]
  int v61; // [esp+94h] [ebp-10h]
  signed int v62; // [esp+94h] [ebp-10h]
  int n; // [esp+98h] [ebp-Ch]
  int v64; // [esp+98h] [ebp-Ch]
  int v65; // [esp+9Ch] [ebp-8h]
  unsigned __int8 *src; // [esp+A0h] [ebp-4h]

  v51 = *(_DWORD *)(a1 + 356);
  v44 = 0;
  v49 = 0;
  v50 = sub_52D5B0(a1, v51 + 20, *a4, 0);
  if ( !v50 )
  {
    v43 = sub_52DCF0(v51 + 80, *a4);
    if ( !v43 )
      return 1;
    v50 = sub_52D5B0(a1, v51 + 20, v43, 0x18u);
    if ( !v50 )
      return 1;
    if ( *(_BYTE *)(a1 + 236) && !sub_52C490(a1, v50) )
      return 1;
  }
  v48 = *(_DWORD *)(v50 + 12);
  v61 = (*(int (__cdecl **)(int, int, _DWORD, _DWORD))(a2 + 40))(a2, a3, *(_DWORD *)(a1 + 380), *(_DWORD *)(a1 + 392));
  if ( v48 + v61 > *(_DWORD *)(a1 + 380) )
  {
    v41 = *(_DWORD *)(a1 + 380);
    *(_DWORD *)(a1 + 380) = v61 + v48 + 16;
    v42 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(*(_DWORD *)(a1 + 392), 16 * *(_DWORD *)(a1 + 380));
    if ( !v42 )
      return 1;
    *(_DWORD *)(a1 + 392) = v42;
    if ( v61 > v41 )
      (*(void (__cdecl **)(int, int, int, _DWORD))(a2 + 40))(a2, a3, v61, *(_DWORD *)(a1 + 392));
  }
  v65 = *(_DWORD *)(a1 + 392);
  for ( count = 0; count < v61; ++count )
  {
    v39 = (_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count);
    v6 = (*(int (__cdecl **)(int, _DWORD))(a2 + 32))(a2, *v39);
    v40 = sub_52C610(a1, a2, *v39, *v39 + v6);
    if ( !v40 )
      return 1;
    if ( *(_BYTE *)(*(_DWORD *)v40 - 1) )
    {
      if ( a2 == *(_DWORD *)(a1 + 144) )
        *(_DWORD *)(a1 + 288) = *(_DWORD *)(16 * count + *(_DWORD *)(a1 + 392));
      return 8;
    }
    *(_BYTE *)(*(_DWORD *)v40 - 1) = 1;
    *(_DWORD *)(v65 + 4 * v44) = *(_DWORD *)v40;
    v45 = v44 + 1;
    if ( *(_BYTE *)(*(_DWORD *)(a1 + 392) + 16 * count + 12) )
    {
      *(_DWORD *)(v65 + 4 * v45) = sub_52DE00(
                                     a1 + 416,
                                     a2,
                                     *(_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count + 4),
                                     *(_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count + 8));
      if ( !*(_DWORD *)(v65 + 4 * v45) )
        return 1;
      *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
    }
    else
    {
      if ( *(_BYTE *)(v40 + 8) )
      {
        for ( i = 0; i < v48; ++i )
        {
          if ( v40 == *(_DWORD *)(12 * i + *(_DWORD *)(v50 + 20)) )
          {
            result = sub_52B440(
                       a1,
                       a2,
                       *(_BYTE *)(*(_DWORD *)(v50 + 20) + 12 * i + 4),
                       *(_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count + 4),
                       *(_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count + 8),
                       a1 + 416);
            goto LABEL_31;
          }
        }
      }
      result = sub_52B440(
                 a1,
                 a2,
                 1,
                 *(_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count + 4),
                 *(_DWORD *)(*(_DWORD *)(a1 + 392) + 16 * count + 8),
                 a1 + 416);
LABEL_31:
      if ( result )
        return result;
      *(_DWORD *)(v65 + 4 * v45) = *(_DWORD *)(a1 + 432);
      *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
    }
    if ( *(_DWORD *)(v40 + 4) )
    {
      if ( *(_BYTE *)(v40 + 9) )
      {
        v37 = sub_527990(a1, *(_DWORD *)(v40 + 4), v40, *(unsigned __int8 **)(v65 + 4 * v45), (int)a5);
        if ( v37 )
          return v37;
        v44 = v45 - 1;
      }
      else
      {
        v44 = v45 + 1;
        ++v49;
        *(_BYTE *)(*(_DWORD *)v40 - 1) = 2;
      }
    }
    else
    {
      v44 = v45 + 1;
    }
  }
  *(_DWORD *)(a1 + 384) = v44;
  if ( *(_DWORD *)(v50 + 8) && *(_BYTE *)(**(_DWORD **)(v50 + 8) - 1) )
  {
    for ( counta = 0; counta < v44; counta += 2 )
    {
      if ( *(_DWORD *)(v65 + 4 * counta) == **(_DWORD **)(v50 + 8) )
      {
        *(_DWORD *)(a1 + 388) = counta;
        break;
      }
    }
  }
  else
  {
    *(_DWORD *)(a1 + 388) = -1;
  }
  for ( countb = 0; countb < v48; ++countb )
  {
    v36 = (_DWORD **)(*(_DWORD *)(v50 + 20) + 12 * countb);
    if ( !*(_BYTE *)(**v36 - 1) && v36[2] )
    {
      if ( (*v36)[1] )
      {
        if ( *((_BYTE *)*v36 + 9) )
        {
          v35 = sub_527990(a1, (*v36)[1], (int)*v36, (unsigned __int8 *)v36[2], (int)a5);
          if ( v35 )
            return v35;
        }
        else
        {
          *(_BYTE *)(**v36 - 1) = 2;
          ++v49;
          *(_DWORD *)(v65 + 4 * v44) = **v36;
          v46 = v44 + 1;
          *(_DWORD *)(v65 + 4 * v46) = v36[2];
          v44 = v46 + 1;
        }
      }
      else
      {
        *(_BYTE *)(**v36 - 1) = 1;
        *(_DWORD *)(v65 + 4 * v44) = **v36;
        v47 = v44 + 1;
        *(_DWORD *)(v65 + 4 * v47) = v36[2];
        v44 = v47 + 1;
      }
    }
  }
  *(_DWORD *)(v65 + 4 * v44) = 0;
  countc = 0;
  if ( v49 )
  {
    v32 = *(_DWORD *)(a1 + 400);
    v34 = 1 << *(_BYTE *)(a1 + 404);
    if ( (2 * v49) >> *(_BYTE *)(a1 + 404) )
    {
      while ( v49 >> (*(_BYTE *)(a1 + 404))++ )
        ;
      if ( *(unsigned __int8 *)(a1 + 404) < 3u )
        *(_BYTE *)(a1 + 404) = 3;
      v34 = 1 << *(_BYTE *)(a1 + 404);
      v28 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(*(_DWORD *)(a1 + 396), 12 * v34);
      if ( !v28 )
        return 1;
      *(_DWORD *)(a1 + 396) = v28;
      v32 = 0;
    }
    if ( !v32 )
    {
      v32 = -1;
      for ( j = v34; j; *(_DWORD *)(12 * j + *(_DWORD *)(a1 + 396)) = -1 )
        --j;
    }
    v33 = v32 - 1;
    *(_DWORD *)(a1 + 400) = v33;
    while ( countc < v44 )
    {
      v25 = *(unsigned __int8 **)(v65 + 4 * countc);
      if ( *(v25 - 1) == 2 )
      {
        v24 = *(_DWORD *)(a1 + 496);
        *(v25 - 1) = 0;
        v23 = *(_DWORD *)(*(_DWORD *)(sub_52D5B0(a1, v51 + 40, v25, 0) + 4) + 4);
        if ( !v23 )
          return 27;
        for ( k = 0; k < *(_DWORD *)(v23 + 20); ++k )
        {
          v22 = *(_BYTE *)(*(_DWORD *)(v23 + 16) + k);
          if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
          {
            *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = v22;
            v16 = 1;
          }
          else
          {
            v16 = 0;
          }
          if ( !v16 )
            return 1;
          v24 = v22 ^ (1000003 * v24);
        }
        do
          v8 = (char)*v25++;
        while ( v8 != 58 );
        do
        {
          v21 = *v25;
          if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
          {
            *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *v25;
            v15 = 1;
          }
          else
          {
            v15 = 0;
          }
          if ( !v15 )
            return 1;
          v24 = v21 ^ (1000003 * v24);
        }
        while ( *v25++ );
        v20 = 0;
        v31 = (v34 - 1) & v24;
        while ( *(_DWORD *)(12 * v31 + *(_DWORD *)(a1 + 396)) == v33 )
        {
          if ( v24 == *(_DWORD *)(*(_DWORD *)(a1 + 396) + 12 * v31 + 4) )
          {
            v18 = *(_BYTE **)(a1 + 432);
            for ( m = *(char **)(*(_DWORD *)(a1 + 396) + 12 * v31 + 8); (char)*v18 == *m && *v18; ++m )
              ++v18;
            if ( !*v18 )
              return 8;
          }
          if ( !v20 )
            v20 = ((unsigned int)(v34 - 1) >> 2) & ((v24 & (unsigned int)~(v34 - 1)) >> (*(_BYTE *)(a1 + 404) - 1)) | 1;
          if ( v31 >= v20 )
            v31 -= v20;
          else
            v31 += v34 - v20;
        }
        if ( *(_BYTE *)(a1 + 237) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428) - 1) = *(_BYTE *)(a1 + 472);
          v26 = **(_BYTE ***)v23;
          do
          {
            if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
            {
              *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = *v26;
              v14 = 1;
            }
            else
            {
              v14 = 0;
            }
            if ( !v14 )
              return 1;
          }
          while ( *v26++ );
        }
        v27 = *(_DWORD *)(a1 + 432);
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
        *(_DWORD *)(v65 + 4 * countc) = v27;
        *(_DWORD *)(12 * v31 + *(_DWORD *)(a1 + 396)) = v33;
        *(_DWORD *)(*(_DWORD *)(a1 + 396) + 12 * v31 + 4) = v24;
        *(_DWORD *)(*(_DWORD *)(a1 + 396) + 12 * v31 + 8) = v27;
        if ( !--v49 )
        {
          countc += 2;
          break;
        }
      }
      else
      {
        *(v25 - 1) = 0;
      }
      countc += 2;
    }
  }
  while ( countc < v44 )
  {
    *(_BYTE *)(*(_DWORD *)(v65 + 4 * countc) - 1) = 0;
    countc += 2;
  }
  for ( n = *a5; n; n = *(_DWORD *)(n + 4) )
    *(_BYTE *)(**(_DWORD **)(n + 12) - 1) = 0;
  if ( !*(_BYTE *)(a1 + 236) )
    return 0;
  if ( *(_DWORD *)(v50 + 4) )
  {
    v64 = *(_DWORD *)(*(_DWORD *)(v50 + 4) + 4);
    if ( !v64 )
      return 27;
    src = *a4;
    do
      v11 = (char)*src++;
    while ( v11 != 58 );
  }
  else
  {
    if ( !*(_DWORD *)(v51 + 156) )
      return 0;
    v64 = *(_DWORD *)(v51 + 156);
    src = *a4;
  }
  v52 = 0;
  if ( *(_BYTE *)(a1 + 237) && **(_DWORD **)v64 )
  {
    while ( *(char *)(**(_DWORD **)v64 + v52++) )
      ;
  }
  a4[1] = src;
  a4[4] = *(unsigned __int8 **)(v64 + 20);
  a4[2] = **(unsigned __int8 ***)v64;
  a4[5] = (unsigned __int8 *)v52;
  countd = 0;
  while ( src[countd++] )
    ;
  v62 = v52 + *(_DWORD *)(v64 + 20) + countd;
  if ( v62 > *(_DWORD *)(v64 + 24) )
  {
    dst = (unsigned __int8 *)(*(int (__cdecl **)(int))(a1 + 12))(v62 + 24);
    if ( !dst )
      return 1;
    *(_DWORD *)(v64 + 24) = v62 + 24;
    memcpy(dst, *(unsigned __int8 **)(v64 + 16), *(_DWORD *)(v64 + 20));
    for ( ii = *(_DWORD **)(a1 + 364); ii; ii = (_DWORD *)*ii )
    {
      if ( ii[3] == *(_DWORD *)(v64 + 16) )
        ii[3] = dst;
    }
    (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(v64 + 16));
    *(_DWORD *)(v64 + 16) = dst;
  }
  dsta = (unsigned __int8 *)(*(_DWORD *)(v64 + 20) + *(_DWORD *)(v64 + 16));
  memcpy(dsta, src, countd);
  if ( v52 )
  {
    dstb = &dsta[countd - 1];
    *dstb = *(_BYTE *)(a1 + 472);
    memcpy(dstb + 1, **(unsigned __int8 ***)v64, v52);
  }
  *a4 = *(unsigned __int8 **)(v64 + 16);
  return 0;
}
