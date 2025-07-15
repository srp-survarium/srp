void __usercall dradf2(int ido@<eax>, float *cc@<edx>, int l1, float *ch, float *wa1)
{
  int v5; // ecx
  float *v6; // edi
  float *v7; // esi
  float *v8; // esi
  unsigned int v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  int v17; // ecx
  float *v18; // ebx
  float *v19; // edx
  int v20; // esi
  int v21; // eax
  float *v22; // edi
  int v23; // [esp+10h] [ebp-24h]
  int v24; // [esp+14h] [ebp-20h]
  float *v25; // [esp+14h] [ebp-20h]
  float *v26; // [esp+18h] [ebp-1Ch]
  float *v27; // [esp+1Ch] [ebp-18h]
  float *v28; // [esp+20h] [ebp-14h]
  float *v29; // [esp+24h] [ebp-10h]
  float *v30; // [esp+24h] [ebp-10h]
  float *v31; // [esp+28h] [ebp-Ch]
  float *v32; // [esp+28h] [ebp-Ch]
  float *v33; // [esp+2Ch] [ebp-8h]
  float *v34; // [esp+2Ch] [ebp-8h]
  float *v35; // [esp+30h] [ebp-4h]

  v5 = l1 * ido;
  v6 = ch;
  if ( l1 > 0 )
  {
    v29 = ch;
    v33 = &ch[2 * ido - 1];
    v31 = cc;
    v7 = &cc[v5];
    v24 = l1;
    do
    {
      *v29 = *v31 + *v7;
      *v33 = *v31 - *v7;
      v29 += 2 * ido;
      v31 += ido;
      v7 += ido;
      v33 += 2 * ido;
      --v24;
    }
    while ( v24 );
    v6 = ch;
  }
  if ( ido >= 2 )
  {
    if ( ido == 2 )
      goto L105;
    if ( l1 > 0 )
    {
      v26 = &cc[v5];
      v25 = v6;
      v27 = cc;
      v28 = &v6[2 * ido];
      v23 = l1;
      do
      {
        v8 = v27;
        v32 = v28;
        v34 = v25;
        v35 = v26;
        v30 = wa1 + 1;
        v9 = ((unsigned int)(ido - 3) >> 1) + 1;
        do
        {
          v10 = *(v30 - 1);
          v35 += 2;
          v11 = *(v35 - 1);
          v12 = *v30;
          v34 += 2;
          v32 -= 2;
          v30 += 2;
          v13 = v10;
          v8 += 2;
          --v9;
          v14 = *v35;
          v15 = (float)(v10 * *v35) - (float)(v12 * v11);
          *v34 = *v8 + v15;
          *v32 = v15 - *v8;
          v16 = (float)(v13 * v11) + (float)(v14 * v12);
          *(v34 - 1) = v16 + *(v8 - 1);
          *(v32 - 1) = *(v8 - 1) - v16;
        }
        while ( v9 );
        v28 += 2 * ido;
        v25 += 2 * ido;
        v27 += ido;
        v26 += ido;
        --v23;
      }
      while ( v23 );
    }
    if ( (ido & 1) != 1 )
    {
L105:
      if ( l1 > 0 )
      {
        v17 = 4 * ido;
        v18 = &cc[ido - 1];
        v19 = &cc[l1 * ido - 1 + ido];
        v20 = l1;
        v21 = 8 * ido;
        v22 = &v6[v17 / 4u];
        do
        {
          *(_DWORD *)v22 = *(_DWORD *)v19 ^ _mask__NegFloat_;
          *(v22 - 1) = *v18;
          v22 = (float *)((char *)v22 + v21);
          v19 = (float *)((char *)v19 + v17);
          v18 = (float *)((char *)v18 + v17);
          --v20;
        }
        while ( v20 );
      }
    }
  }
}
