void __usercall dradf2(int ido@<ecx>, float *cc@<eax>, float *ch@<edi>, int l1, float *wa1)
{
  int v5; // ebp
  int v6; // esi
  int v7; // edx
  float *v8; // ebx
  double v9; // st7
  int v10; // edx
  double v11; // st7
  int v12; // esi
  float *v13; // ebx
  double v14; // st7
  int v15; // edx
  double v16; // st7
  int v17; // esi
  float *v18; // ebx
  double v19; // st7
  int v20; // edx
  double v21; // st7
  int v22; // esi
  float *v23; // ebx
  double v24; // st7
  double v25; // st7
  float *v26; // ebx
  float *v27; // esi
  float *v28; // esi
  float *v29; // ebx
  float *v30; // edx
  double v31; // st7
  double v32; // st6
  bool v33; // zf
  int v34; // ebx
  int v35; // esi
  int v36; // edx
  double v37; // st7
  int v38; // esi
  double v39; // st7
  int v40; // ebx
  int v41; // edx
  double v42; // st7
  int v43; // esi
  double v44; // st7
  int v45; // ebx
  int v46; // edx
  double v47; // st7
  int v48; // esi
  double v49; // st7
  int v50; // ebx
  int v51; // edx
  double v52; // st7
  double v53; // st7
  int v54; // ebp
  float *v55; // ebx
  float *v56; // eax
  int v57; // ecx
  int v58; // esi
  float *v59; // edx
  double v60; // st7
  double v61; // st7
  int k; // [esp+Ch] [ebp-2Ch]
  float *ka; // [esp+Ch] [ebp-2Ch]
  int kb; // [esp+Ch] [ebp-2Ch]
  float *v65; // [esp+10h] [ebp-28h]
  float *v66; // [esp+10h] [ebp-28h]
  float *v67; // [esp+14h] [ebp-24h]
  float *v68; // [esp+18h] [ebp-20h]
  int v69; // [esp+1Ch] [ebp-1Ch]
  float *v70; // [esp+1Ch] [ebp-1Ch]
  unsigned int v71; // [esp+20h] [ebp-18h]
  float *v72; // [esp+20h] [ebp-18h]
  float *v73; // [esp+20h] [ebp-18h]
  unsigned int v74; // [esp+24h] [ebp-14h]
  int v75; // [esp+28h] [ebp-10h]
  int t0; // [esp+2Ch] [ebp-Ch]
  int t0a; // [esp+2Ch] [ebp-Ch]
  float ti2; // [esp+30h] [ebp-8h]
  float tr2; // [esp+34h] [ebp-4h]

  v5 = l1;
  v6 = l1 * ido;
  v7 = 0;
  t0 = l1 * ido;
  k = 0;
  if ( l1 >= 4 )
  {
    v71 = ((unsigned int)(l1 - 4) >> 2) + 1;
    v8 = &ch[2 * ido - 1];
    k = 4 * v71;
    do
    {
      ch[2 * v7] = cc[v7] + cc[v6];
      v9 = cc[v7];
      v10 = ido + v7;
      v11 = v9 - cc[v6];
      v12 = ido + v6;
      *v8 = v11;
      v13 = &v8[2 * ido];
      ch[2 * v10] = cc[v10] + cc[v12];
      v14 = cc[v10];
      v15 = ido + v10;
      v16 = v14 - cc[v12];
      v17 = ido + v12;
      *v13 = v16;
      v18 = &v13[2 * ido];
      ch[2 * v15] = cc[v15] + cc[v17];
      v19 = cc[v15];
      v20 = ido + v15;
      v21 = v19 - cc[v17];
      v22 = ido + v17;
      *v18 = v21;
      v23 = &v18[2 * ido];
      ch[2 * v20] = cc[v20] + cc[v22];
      v24 = cc[v20];
      v7 = ido + v20;
      v25 = v24 - cc[v22];
      v6 = ido + v22;
      *v23 = v25;
      v8 = &v23[2 * ido];
      --v71;
    }
    while ( v71 );
    v5 = l1;
  }
  if ( k < v5 )
  {
    v26 = &cc[v7];
    v72 = &ch[2 * v7];
    v65 = &ch[2 * ido - 1 + 2 * v7];
    v27 = &cc[v6];
    v69 = l1 - k;
    do
    {
      *v72 = *v26 + *v27;
      *v65 = *v26 - *v27;
      v65 += 2 * ido;
      v72 += 2 * ido;
      v26 += ido;
      v27 += ido;
      --v69;
    }
    while ( v69 );
    v5 = l1;
  }
  if ( ido >= 2 )
  {
    if ( ido == 2 )
      goto L105_0;
    if ( v5 > 0 )
    {
      v70 = &cc[t0];
      v73 = ch;
      v68 = cc;
      v67 = &ch[2 * ido];
      v75 = v5;
      do
      {
        v28 = v68;
        ka = v67;
        v29 = wa1 + 1;
        v66 = v73;
        v30 = v70;
        v74 = ((unsigned int)(ido - 3) >> 1) + 1;
        do
        {
          v30 += 2;
          v31 = *v29 * *v30;
          ka -= 2;
          v32 = *(v30 - 1) * *(v29 - 1);
          v28 += 2;
          v66 += 2;
          v29 += 2;
          v33 = v74-- == 1;
          tr2 = v31 + v32;
          ti2 = *(v29 - 3) * *v30 - *(v30 - 1) * *(v29 - 2);
          *v66 = ti2 + *v28;
          *ka = ti2 - *v28;
          *(v66 - 1) = *(v28 - 1) + tr2;
          *(ka - 1) = *(v28 - 1) - tr2;
        }
        while ( !v33 );
        v5 = l1;
        v67 += 2 * ido;
        v73 += 2 * ido;
        v68 += ido;
        v70 += ido;
        --v75;
      }
      while ( v75 );
    }
    if ( (ido & 1) != 1 )
    {
L105_0:
      v34 = ido - 1;
      v35 = t0 + ido - 1;
      v36 = ido;
      kb = 0;
      if ( v5 >= 4 )
      {
        t0a = ((unsigned int)(l1 - 4) >> 2) + 1;
        kb = 4 * t0a;
        do
        {
          v37 = cc[v35];
          v38 = ido + v35;
          ch[v36] = -v37;
          v39 = cc[v34];
          v40 = ido + v34;
          ch[v36 - 1] = v39;
          v41 = 2 * ido + v36;
          v42 = cc[v38];
          v43 = ido + v38;
          ch[v41] = -v42;
          v44 = cc[v40];
          v45 = ido + v40;
          ch[v41 - 1] = v44;
          v46 = 2 * ido + v41;
          v47 = cc[v43];
          v48 = ido + v43;
          ch[v46] = -v47;
          v49 = cc[v45];
          v50 = ido + v45;
          ch[v46 - 1] = v49;
          v51 = 2 * ido + v46;
          v52 = cc[v48];
          v35 = ido + v48;
          ch[v51] = -v52;
          v53 = cc[v50];
          v34 = ido + v50;
          ch[v51 - 1] = v53;
          v36 = 2 * ido + v51;
          --t0a;
        }
        while ( t0a );
        v5 = l1;
      }
      if ( kb < v5 )
      {
        v54 = 4 * ido;
        v55 = &cc[v34];
        v56 = &cc[v35];
        v57 = 8 * ido;
        v58 = l1 - kb;
        v59 = &ch[v36];
        do
        {
          v60 = *v56;
          v56 = (float *)((char *)v56 + v54);
          *v59 = -v60;
          v61 = *v55;
          v55 = (float *)((char *)v55 + v54);
          *(v59 - 1) = v61;
          v59 = (float *)((char *)v59 + v57);
          --v58;
        }
        while ( v58 );
      }
    }
  }
}
