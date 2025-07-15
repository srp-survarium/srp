int __cdecl intersectRectQuad2(float *h, float *ret)
{
  unsigned __int8 *v2; // ecx
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // eax
  int v6; // ecx
  float v7; // xmm2_4
  float v8; // xmm5_4
  float *v9; // ebx
  float *v10; // esi
  float *v11; // eax
  float *v12; // edx
  double v13; // st7
  unsigned __int8 *v14; // edx
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float *v19; // edx
  bool v20; // zf
  char v22; // [esp+Ch] [ebp-60h] BYREF
  unsigned __int8 *v23; // [esp+4Ch] [ebp-20h]
  unsigned __int8 *v24; // [esp+50h] [ebp-1Ch]
  unsigned __int8 *v25; // [esp+54h] [ebp-18h]
  int v26; // [esp+58h] [ebp-14h]
  int v27; // [esp+5Ch] [ebp-10h]
  unsigned __int8 *src; // [esp+60h] [ebp-Ch]
  float *v29; // [esp+64h] [ebp-8h]
  int v30; // [esp+68h] [ebp-4h]

  v3 = (unsigned __int8 *)ret;
  v4 = v2;
  v23 = v2;
  v5 = 4;
  src = (unsigned __int8 *)ret;
  v6 = 0;
  while ( 2 )
  {
    v26 = -1;
    do
    {
      v30 = 0;
      v29 = (float *)v3;
      v27 = v5;
      if ( v5 > 0 )
      {
        v7 = h[v6];
        v8 = (float)v26;
        v25 = v4 + 8;
        v9 = (float *)&v4[v6 * 4];
        v10 = (float *)&v3[-(v6 * 4) + 4];
        v24 = &v4[v6 * 4];
        v11 = (float *)&v4[-(v6 * 4) + 4];
        while ( 1 )
        {
          if ( v7 > (float)(*v9 * v8) )
          {
            v12 = v29;
            *v29 = v11[v6 - 1];
            v12 += 2;
            v13 = v11[v6];
            v10 += 2;
            ++v30;
            *(v12 - 1) = v13;
            v29 = v12;
            if ( (v30 & 8) != 0 )
              break;
          }
          v14 = v25;
          v15 = *v9;
          if ( v27 <= 1 )
            v14 = v4;
          v16 = *(float *)&v14[v6 * 4];
          if ( v7 > (float)(v15 * v8) != v7 > (float)(v16 * v8) )
          {
            v17 = *v11;
            v18 = *(float *)&v14[-(v6 * 4) + 4];
            v19 = v29;
            v29 += 2;
            *v10 = (float)((float)((float)(v18 - v17) / (float)(v16 - v15)) * (float)((float)(v7 * v8) - v15)) + v17;
            v10 += 2;
            v20 = (++v30 & 8) == 0;
            v19[v6] = v7 * v8;
            if ( !v20 )
              break;
          }
          v25 += 8;
          v9 = (float *)(v24 + 8);
          v11 += 2;
          --v27;
          v24 += 8;
          if ( v27 <= 0 )
            goto LABEL_13;
          v4 = v23;
        }
        v4 = src;
        goto done;
      }
LABEL_13:
      v4 = src;
      v3 = (unsigned __int8 *)ret;
      v23 = src;
      if ( src == (unsigned __int8 *)ret )
        v3 = (unsigned __int8 *)&v22;
      v26 += 2;
      v5 = v30;
      src = v3;
    }
    while ( v26 <= 1 );
    if ( ++v6 <= 1 )
      continue;
    break;
  }
done:
  if ( v4 != (unsigned __int8 *)ret )
    memcpy((unsigned __int8 *)ret, v4, 8 * v30);
  return v30;
}
