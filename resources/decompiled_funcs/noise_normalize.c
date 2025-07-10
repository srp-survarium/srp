double __usercall noise_normalize@<st0>(
        vorbis_look_psy *p@<eax>,
        float *q@<edi>,
        int limit,
        float *r,
        float *f,
        char *flags,
        float acc,
        int i,
        int n,
        char *out)
{
  int v10; // esi
  void *v11; // esp
  int v12; // edx
  int v13; // eax
  char *v14; // ebx
  int v15; // edx
  float *v16; // esi
  long double v17; // st7
  int v18; // eax
  int v19; // ecx
  int *v20; // esi
  float *v21; // ebx
  long double v22; // st7
  unsigned int v23; // eax
  double v24; // st7
  int v25; // edx
  signed int v26; // ecx
  long double v27; // st6
  double v28; // st5
  long double v29; // rt0
  double v30; // rt1
  long double v31; // st5
  double v32; // st6
  int v33; // esi
  int v35; // [esp+8h] [ebp-30h] BYREF
  vorbis_info_psy *vi; // [esp+10h] [ebp-28h]
  int v37; // [esp+14h] [ebp-24h]
  int v38; // [esp+18h] [ebp-20h]
  int v39; // [esp+1Ch] [ebp-1Ch]
  int v40; // [esp+20h] [ebp-18h]
  int v41; // [esp+24h] [ebp-14h]
  float v42; // [esp+28h] [ebp-10h]
  void *base; // [esp+2Ch] [ebp-Ch]
  unsigned int num; // [esp+30h] [ebp-8h]
  signed int v45; // [esp+34h] [ebp-4h]
  float v46; // [esp+50h] [ebp+18h]
  float v47; // [esp+50h] [ebp+18h]

  v10 = n;
  vi = p->vi;
  v11 = alloca(4 * n);
  v12 = 0;
  base = &v35;
  num = 0;
  if ( !vi->normal_p || (v13 = vi->normal_start - i, v13 > n) )
    v13 = n;
  v14 = out;
  v46 = 0.0;
  v45 = 0;
  if ( v13 > 0 )
  {
    v38 = (char *)f - (char *)q;
    v37 = (char *)r - (char *)q;
    v15 = flags - (char *)q;
    v16 = q;
    v39 = flags - (char *)q;
    v41 = out - (char *)q;
    v40 = v13;
    v45 = v13;
    while ( 1 )
    {
      if ( !flags || !*(_DWORD *)((char *)v16 + v15) )
      {
        v42 = *v16 / *(float *)((char *)v16 + v38);
        v17 = v42;
        if ( *(float *)((char *)v16 + v37) >= 0.0 )
          v18 = (int)floor(sqrt(v17) + 0.5);
        else
          v18 = (int)-floor(sqrt(v17) + 0.5);
        *(_DWORD *)((char *)v16 + v41) = v18;
      }
      ++v16;
      if ( !--v40 )
        break;
      v15 = v39;
    }
    v12 = v45;
    v10 = n;
  }
  if ( v12 >= v10 )
    return v46;
  v37 = flags - (char *)r;
  v40 = (char *)f - out;
  v19 = (char *)r - out;
  v20 = (int *)&out[4 * v12];
  v41 = (char *)r - out;
  v38 = (char *)q - out;
  do
  {
    if ( !flags || !*(int *)((char *)v20 + v19 + v37) )
    {
      v21 = (float *)((char *)v20 + v38);
      *(float *)&v39 = *(float *)((char *)v20 + v38) / *(float *)((char *)v20 + v40);
      v22 = *(float *)&v39;
      if ( *(float *)&v39 >= 0.25 || flags && v12 < limit - i )
      {
        if ( *(float *)((char *)v20 + v19) >= 0.0 )
          v24 = floor(sqrt(v22) + 0.5);
        else
          v24 = -floor(sqrt(v22) + 0.5);
        v25 = v40;
        v39 = (int)v24 * (int)v24;
        v19 = v41;
        *v20 = (int)v24;
        *v21 = (double)v39 * *(float *)((char *)v20 + v25);
      }
      else
      {
        v23 = num;
        *((_DWORD *)base + num) = v21;
        v46 = v22 + v46;
        num = v23 + 1;
      }
      v12 = v45;
      v14 = out;
    }
    ++v12;
    ++v20;
    v45 = v12;
  }
  while ( v12 < n );
  if ( !num )
    return v46;
  qsort((char *)base, num, 4u, (int (__cdecl *)(const void *, const void *))apsort);
  v26 = 0;
  v45 = 0;
  if ( (int)num <= 0 )
    return v46;
  v27 = v46;
  v28 = 0.0;
  while ( 1 )
  {
    v30 = v28;
    v31 = v27;
    v32 = v30;
    v33 = (*((_DWORD *)base + v26) - (int)q) >> 2;
    if ( v31 < vi->normal_thresh )
    {
      *(_DWORD *)&v14[4 * v33] = 0;
      q[v33] = v32;
    }
    else
    {
      v26 = v45;
      *(_DWORD *)&v14[4 * v33] = (int)COERCE_FLOAT(COERCE_UNSIGNED_INT(r[v33]) & 0x80000000 | 0x3F800000);
      v47 = v31 - 1.0;
      q[v33] = f[v33];
      v31 = v47;
    }
    v45 = ++v26;
    if ( v26 >= (int)num )
      break;
    v29 = v31;
    v28 = v32;
    v27 = v29;
  }
  return v31;
}
