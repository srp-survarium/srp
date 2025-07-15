int __usercall accumulate_fit@<eax>(
        int x0@<eax>,
        lsfit_acc *a@<esi>,
        const float *flr,
        const float *mdct,
        int x1,
        int n,
        vorbis_info_floor1 *info)
{
  const float *v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int result; // eax
  int v14; // [esp+Ch] [ebp-2Ch]
  int v15; // [esp+10h] [ebp-28h]
  int v16; // [esp+14h] [ebp-24h]
  int v17; // [esp+18h] [ebp-20h]
  int v18; // [esp+1Ch] [ebp-1Ch]
  int v19; // [esp+20h] [ebp-18h]
  int v20; // [esp+24h] [ebp-14h]
  int v21; // [esp+28h] [ebp-10h]
  int v22; // [esp+2Ch] [ebp-Ch]
  int v23; // [esp+30h] [ebp-8h]
  int v24; // [esp+34h] [ebp-4h]
  int v25; // [esp+48h] [ebp+10h]
  const float *v26; // [esp+4Ch] [ebp+14h]

  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  memset((int)a, 0, sizeof(lsfit_acc));
  a->x0 = x0;
  a->x1 = x1;
  if ( x1 >= n )
    x1 = n - 1;
  if ( x0 <= x1 )
  {
    v9 = &flr[x0];
    v26 = v9;
    do
    {
      v10 = vorbis_dBquant(v9);
      if ( v10 )
      {
        v12 = v11 * v11;
        if ( (float)(*(const float *)((char *)v9 + (char *)mdct - (char *)flr) + info->twofitatten) < *v9 )
        {
          v17 += v12;
          v18 += v10;
          v19 += v11;
          v16 += v10 * v10;
          v15 += v11 * v10;
          ++v14;
        }
        else
        {
          v23 += v12;
          v24 += v10;
          v25 += v11;
          v22 += v10 * v10;
          v21 += v11 * v10;
          ++v20;
        }
      }
      v9 = ++v26;
    }
    while ( v11 + 1 <= x1 );
  }
  a->xa = v25;
  a->xb = v19;
  a->ya = v24;
  a->yb = v18;
  a->x2a = v23;
  a->x2b = v17;
  a->y2a = v22;
  a->y2b = v16;
  a->xya = v21;
  result = v20;
  a->xyb = v15;
  a->an = v20;
  a->bn = v14;
  return result;
}
