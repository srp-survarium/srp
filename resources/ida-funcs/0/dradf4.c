void __usercall dradf4(float *cc@<eax>, float *ch@<edx>, int ido, int l1, float *wa1, float *wa2, float *wa3)
{
  int v8; // ebx
  int v9; // edi
  int v10; // esi
  int v11; // ebp
  int v12; // ebx
  double v13; // st7
  int v14; // esi
  double v15; // st7
  int v16; // edi
  int v17; // ebx
  double v18; // st7
  int v19; // esi
  double v20; // st7
  int v21; // edi
  int v22; // ebx
  double v23; // st7
  int v24; // esi
  double v25; // st7
  int v26; // edi
  int v27; // ebx
  double v28; // st7
  double v29; // st7
  bool v30; // zf
  float *v31; // edi
  int v32; // ebp
  int v33; // ebx
  double v34; // st7
  float *v35; // edi
  double v36; // st7
  int v37; // edi
  int v38; // esi
  float *v39; // esi
  int v40; // ebx
  float *v41; // edi
  int v42; // ebx
  double v43; // st7
  double v44; // st6
  int v45; // edi
  float *v46; // ebx
  double v47; // st7
  int v48; // edi
  float *v49; // ebp
  double v50; // st7
  double v51; // st3
  int v52; // esi
  int v53; // edi
  int v54; // ebx
  double v55; // st5
  int v56; // esi
  int v57; // edi
  double v58; // st5
  int v59; // esi
  float *v60; // ebp
  float *v61; // ebx
  int v62; // edi
  int v63; // ebp
  double v64; // st5
  int v65; // esi
  double v66; // st5
  float *v67; // ebp
  float *v68; // ebx
  int v69; // edi
  int v70; // ebp
  double v71; // st5
  double v72; // st5
  float *v73; // ebx
  int v74; // ebp
  float *v75; // ebx
  float *v76; // ecx
  float *v77; // eax
  float *v78; // edx
  float *v79; // edi
  double v80; // st5
  double v81; // st5
  double v82; // st5
  double v83; // st5
  float tr1; // [esp+10h] [ebp-60h]
  float tr1a; // [esp+10h] [ebp-60h]
  float tr1b; // [esp+10h] [ebp-60h]
  float tr1c; // [esp+10h] [ebp-60h]
  float tr1d; // [esp+10h] [ebp-60h]
  float tr1e; // [esp+10h] [ebp-60h]
  float tr1f; // [esp+10h] [ebp-60h]
  float tr1g; // [esp+10h] [ebp-60h]
  float tr1h; // [esp+10h] [ebp-60h]
  float tr1i; // [esp+10h] [ebp-60h]
  float tr1j; // [esp+10h] [ebp-60h]
  int t4; // [esp+14h] [ebp-5Ch]
  int t4c; // [esp+14h] [ebp-5Ch]
  int t4d; // [esp+14h] [ebp-5Ch]
  int t4e; // [esp+14h] [ebp-5Ch]
  float *t4a; // [esp+14h] [ebp-5Ch]
  float *t4b; // [esp+14h] [ebp-5Ch]
  float *t4f; // [esp+14h] [ebp-5Ch]
  float tr2a; // [esp+18h] [ebp-58h]
  float tr2b; // [esp+18h] [ebp-58h]
  float tr2c; // [esp+18h] [ebp-58h]
  float tr2d; // [esp+18h] [ebp-58h]
  float tr2e; // [esp+18h] [ebp-58h]
  float tr2f; // [esp+18h] [ebp-58h]
  float tr2g; // [esp+18h] [ebp-58h]
  float *tr2; // [esp+18h] [ebp-58h]
  float cr2; // [esp+1Ch] [ebp-54h]
  float cr2a; // [esp+1Ch] [ebp-54h]
  float cr2b; // [esp+1Ch] [ebp-54h]
  float cr2c; // [esp+1Ch] [ebp-54h]
  float cr2d; // [esp+1Ch] [ebp-54h]
  float cr2e; // [esp+1Ch] [ebp-54h]
  float cr2f; // [esp+1Ch] [ebp-54h]
  float *v117; // [esp+20h] [ebp-50h]
  float *v118; // [esp+20h] [ebp-50h]
  float *v119; // [esp+20h] [ebp-50h]
  float *v120; // [esp+20h] [ebp-50h]
  float *v121; // [esp+20h] [ebp-50h]
  float *t6; // [esp+24h] [ebp-4Ch]
  int t6a; // [esp+24h] [ebp-4Ch]
  int t0; // [esp+28h] [ebp-48h]
  int k; // [esp+2Ch] [ebp-44h]
  int ka; // [esp+2Ch] [ebp-44h]
  float *kb; // [esp+2Ch] [ebp-44h]
  int kc; // [esp+2Ch] [ebp-44h]
  float *v129; // [esp+30h] [ebp-40h]
  float *v130; // [esp+30h] [ebp-40h]
  int v131; // [esp+30h] [ebp-40h]
  int v132; // [esp+30h] [ebp-40h]
  unsigned int v133; // [esp+34h] [ebp-3Ch]
  float *v134; // [esp+34h] [ebp-3Ch]
  int v135; // [esp+34h] [ebp-3Ch]
  int v136; // [esp+38h] [ebp-38h]
  int v137; // [esp+3Ch] [ebp-34h]
  int v138; // [esp+40h] [ebp-30h]
  int v139; // [esp+44h] [ebp-2Ch]
  int v140; // [esp+48h] [ebp-28h]
  float *tr4; // [esp+4Ch] [ebp-24h]
  float tr4a; // [esp+4Ch] [ebp-24h]
  float tr4b; // [esp+4Ch] [ebp-24h]
  unsigned int v144; // [esp+50h] [ebp-20h]
  int t1; // [esp+54h] [ebp-1Ch]
  float v146; // [esp+58h] [ebp-18h]
  float v147; // [esp+58h] [ebp-18h]
  float v148; // [esp+58h] [ebp-18h]
  float v149; // [esp+58h] [ebp-18h]
  float v150; // [esp+58h] [ebp-18h]
  int v151; // [esp+58h] [ebp-18h]
  unsigned int v152; // [esp+58h] [ebp-18h]
  int v153; // [esp+5Ch] [ebp-14h]
  float ti4; // [esp+60h] [ebp-10h]
  float ti4a; // [esp+60h] [ebp-10h]
  float ti2; // [esp+64h] [ebp-Ch]
  float ti2a; // [esp+64h] [ebp-Ch]
  float tr3; // [esp+68h] [ebp-8h]
  float tr3a; // [esp+68h] [ebp-8h]
  float *v160; // [esp+6Ch] [ebp-4h]
  int t2; // [esp+74h] [ebp+4h]
  int t2d; // [esp+74h] [ebp+4h]
  int t2e; // [esp+74h] [ebp+4h]
  int t2f; // [esp+74h] [ebp+4h]
  float *t2a; // [esp+74h] [ebp+4h]
  float *t2g; // [esp+74h] [ebp+4h]
  float t2h; // [esp+74h] [ebp+4h]
  int t2b; // [esp+74h] [ebp+4h]
  int t2i; // [esp+74h] [ebp+4h]
  float *t2c; // [esp+74h] [ebp+4h]
  int l1a; // [esp+78h] [ebp+8h]

  v8 = l1;
  t0 = l1 * ido;
  v9 = l1 * ido;
  t4 = 2 * l1 * ido;
  v10 = 0;
  v11 = 3 * l1 * ido;
  t2 = v11;
  k = 0;
  if ( l1 >= 4 )
  {
    v133 = ((unsigned int)(l1 - 4) >> 2) + 1;
    k = 4 * v133;
    do
    {
      tr1 = cc[v9] + cc[v11];
      tr2a = cc[t4] + cc[v10];
      ch[4 * v10] = tr2a + tr1;
      v146 = tr2a - tr1;
      ch[4 * v10 - 1 + 4 * ido] = v146;
      v12 = 2 * ido + 4 * v10;
      v13 = cc[v10] - cc[t4];
      v14 = ido + v10;
      ch[v12 - 1] = v13;
      v15 = cc[t2] - cc[v9];
      v16 = ido + v9;
      t2d = ido + t2;
      ch[v12] = v15;
      t4c = ido + t4;
      tr1a = cc[v16] + cc[t2d];
      tr2b = cc[t4c] + cc[v14];
      ch[4 * v14] = tr2b + tr1a;
      v147 = tr2b - tr1a;
      ch[4 * v14 - 1 + 4 * ido] = v147;
      v17 = 2 * ido + 4 * v14;
      v18 = cc[v14] - cc[t4c];
      v19 = ido + v14;
      ch[v17 - 1] = v18;
      v20 = cc[t2d] - cc[v16];
      v21 = ido + v16;
      t2e = ido + t2d;
      ch[v17] = v20;
      t4d = ido + t4c;
      tr1b = cc[v21] + cc[t2e];
      tr2c = cc[t4d] + cc[v19];
      ch[4 * v19] = tr2c + tr1b;
      v148 = tr2c - tr1b;
      ch[4 * v19 - 1 + 4 * ido] = v148;
      v22 = 2 * ido + 4 * v19;
      v23 = cc[v19] - cc[t4d];
      v24 = ido + v19;
      ch[v22 - 1] = v23;
      v25 = cc[t2e] - cc[v21];
      v26 = ido + v21;
      t2f = ido + t2e;
      ch[v22] = v25;
      t4e = ido + t4d;
      tr1c = cc[v26] + cc[t2f];
      tr2d = cc[t4e] + cc[v24];
      ch[4 * v24] = tr2d + tr1c;
      v149 = tr2d - tr1c;
      ch[4 * v24 - 1 + 4 * ido] = v149;
      v27 = 2 * ido + 4 * v24;
      v28 = cc[v24] - cc[t4e];
      t4 = ido + t4e;
      v10 = ido + v24;
      ch[v27 - 1] = v28;
      v11 = ido + t2f;
      v29 = cc[t2f] - cc[v26];
      v9 = ido + v26;
      v30 = v133-- == 1;
      t2 = ido + t2f;
      ch[v27] = v29;
    }
    while ( !v30 );
    v8 = l1;
  }
  if ( k < v8 )
  {
    t2a = &cc[t2];
    v129 = &cc[t4];
    v31 = &cc[v9];
    v32 = 4 * ido;
    v134 = v31;
    ka = l1 - k;
    do
    {
      tr1d = *v31 + *t2a;
      tr2e = *v129 + cc[v10];
      ch[4 * v10] = tr2e + tr1d;
      v150 = tr2e - tr1d;
      ch[4 * v10 - 1 + v32] = v150;
      v33 = 2 * ido + 4 * v10;
      v34 = cc[v10] - *v129;
      v35 = t2a;
      t2a = (float *)((char *)t2a + v32);
      v129 = (float *)((char *)v129 + v32);
      ch[v33 - 1] = v34;
      v10 += ido;
      v36 = *v35 - *v134;
      v31 = &v134[v32 / 4u];
      v30 = ka-- == 1;
      v134 = (float *)((char *)v134 + v32);
      ch[v33] = v36;
    }
    while ( !v30 );
    v8 = l1;
  }
  if ( ido >= 2 )
  {
    if ( ido == 2 )
      goto L105;
    v37 = 0;
    t1 = 0;
    if ( v8 > 0 )
    {
      v135 = 4 * t0;
      t4a = ch;
      v151 = l1;
      do
      {
        v38 = 2 * ido + 4 * v37;
        v136 = v37 + t0;
        kb = &ch[v38];
        t6 = kb;
        v139 = (char *)wa2 - (char *)wa1;
        v140 = (char *)wa3 - (char *)wa1;
        v117 = &ch[2 * ido + v38];
        v130 = t4a;
        v138 = (char *)wa2 - (char *)wa3;
        tr4 = wa3;
        v39 = wa1 + 1;
        v137 = v37 + 2 * t0;
        v40 = v135;
        v144 = ((unsigned int)(ido - 3) >> 1) + 1;
        v41 = &cc[v37];
        while ( 1 )
        {
          v42 = v40 + 8;
          v130 += 2;
          t6 += 2;
          kb -= 2;
          v117 -= 2;
          t2g = v41 + 2;
          cr2 = *v39 * *(float *)((char *)cc + v42) + *(float *)((char *)cc + v42 - 4) * *(v39 - 1);
          v136 += 2;
          v43 = *(float *)((char *)cc + v42) * *(v39 - 1);
          v137 += 2;
          v44 = *v39 * *(float *)((char *)cc + v42 - 4);
          v45 = v42 + 4 * t0;
          v153 = v42;
          v46 = tr4;
          ti4 = v43 - v44;
          tr3 = *(float *)((char *)tr4 + v138) * *(float *)((char *)cc + v45 - 4)
              + *(float *)((char *)v39 + v139) * *(float *)((char *)cc + v45);
          v47 = *(float *)((char *)tr4 + v138) * *(float *)((char *)cc + v45)
              - *(float *)((char *)cc + v45 - 4) * *(float *)((char *)v39 + v139);
          v48 = 4 * t0 + v45;
          ti2 = v47;
          v49 = (float *)((char *)cc + v48 - 4);
          tr4a = *(float *)((char *)v39 + v140) * *(float *)((char *)cc + v48) + *v49 * *tr4;
          tr2f = *v46 * *(float *)((char *)cc + v48) - *v49 * *(float *)((char *)v39 + v140);
          tr1e = tr4a + cr2;
          tr4b = tr4a - cr2;
          cr2a = tr2f + ti4;
          v41 = t2g;
          ti4a = ti4 - tr2f;
          v39 += 2;
          v30 = v144-- == 1;
          v50 = ti2;
          ti2a = *t2g + ti2;
          t2h = *t2g - v50;
          tr2g = *(v41 - 1) + tr3;
          tr3a = *(v41 - 1) - tr3;
          *(v130 - 1) = tr2g + tr1e;
          *v130 = ti2a + cr2a;
          *(kb - 1) = tr3a - ti4a;
          *kb = tr4b - t2h;
          *(t6 - 1) = tr3a + ti4a;
          v51 = t2h + tr4b;
          tr4 = v46 + 2;
          *t6 = v51;
          *(v117 - 1) = tr2g - tr1e;
          *v117 = cr2a - ti2a;
          if ( v30 )
            break;
          v40 = v153;
        }
        t4a += 4 * ido;
        v135 += 4 * ido;
        v37 = ido + t1;
        v30 = v151-- == 1;
        t1 += ido;
      }
      while ( !v30 );
    }
    if ( (ido & 1) == 0 )
    {
L105:
      v52 = t0 + ido - 1;
      t2b = v52 + 2 * t0;
      v53 = ido;
      t6a = ido;
      kc = 0;
      if ( l1 >= 4 )
      {
        t4b = &ch[3 * ido];
        tr2 = &cc[v52 + t0];
        v131 = 4 * ido;
        v54 = ido;
        v118 = &cc[ido - 1];
        v152 = ((unsigned int)(l1 - 4) >> 2) + 1;
        kc = 4 * v152;
        do
        {
          cr2b = (cc[v52] + cc[t2b]) * -0.7071067690849304;
          v55 = cc[v52];
          v56 = ido + v52;
          tr1f = (v55 - cc[t2b]) * 0.7071067690849304;
          ch[v53 - 1] = *v118 + tr1f;
          *(t4b - 1) = *v118 - tr1f;
          ch[v53] = cr2b - *tr2;
          v57 = 4 * ido + v53;
          *t4b = cr2b + *tr2;
          v119 = &v118[ido];
          cr2c = (cc[v56] + cc[ido + t2b]) * -0.7071067690849304;
          v58 = cc[v56];
          v59 = ido + v56;
          v60 = &t4b[v131];
          tr1g = (v58 - cc[ido + t2b]) * 0.7071067690849304;
          ch[v57 - 1] = *v119 + tr1g;
          v61 = &tr2[v54];
          *(v60 - 1) = *v119 - tr1g;
          ch[v57] = cr2c - *v61;
          *v60 = cr2c + *v61;
          v62 = 4 * ido + v57;
          v63 = ido + ido + t2b;
          v120 = &v119[ido];
          t2i = ido + v63;
          t6a += ido + ido + ido + ido;
          cr2d = (cc[v59] + cc[v63]) * -0.7071067690849304;
          v64 = cc[v59];
          v65 = ido + v59;
          v66 = v64 - cc[v63];
          v67 = &t4b[v131 + v131];
          tr1h = v66 * 0.7071067690849304;
          ch[v62 - 1] = *v120 + tr1h;
          v68 = &v61[ido];
          *(v67 - 1) = *v120 - tr1h;
          ch[v62] = cr2d - *v68;
          *v67 = cr2d + *v68;
          v69 = 4 * ido + v62;
          t4f = &v67[v131];
          v70 = t2i;
          v71 = cc[v65] + cc[t2i];
          v121 = &v120[ido];
          t2b = ido + t2i;
          cr2e = v71 * -0.7071067690849304;
          v72 = cc[v65];
          v52 = ido + v65;
          tr1i = (v72 - cc[v70]) * 0.7071067690849304;
          ch[v69 - 1] = *v121 + tr1i;
          v73 = &v68[ido];
          *(t4f - 1) = *v121 - tr1i;
          ch[v69] = cr2e - *v73;
          *t4f = cr2e + *v73;
          tr2 = &v73[ido];
          v53 = 4 * ido + v69;
          t4b = &t4f[v131];
          v54 = ido;
          v118 = &v121[ido];
          --v152;
        }
        while ( v152 );
      }
      if ( kc < l1 )
      {
        v74 = 4 * ido;
        v132 = 16 * ido;
        v160 = &ch[2 * ido + v53];
        t2c = &cc[t2b];
        v75 = &cc[v52];
        v76 = &cc[t0 + v52];
        v77 = &cc[t6a - 1];
        v78 = &ch[v53];
        v79 = v160;
        l1a = l1 - kc;
        do
        {
          cr2f = (*v75 + *t2c) * -0.7071067690849304;
          v80 = *v75;
          v75 = (float *)((char *)v75 + v74);
          v81 = v80 - *t2c;
          t2c = (float *)((char *)t2c + v74);
          tr1j = v81 * 0.7071067690849304;
          *(v78 - 1) = *v77 + tr1j;
          v82 = *v77 - tr1j;
          v77 = (float *)((char *)v77 + v74);
          *(v79 - 1) = v82;
          *v78 = cr2f - *v76;
          v78 = (float *)((char *)v78 + v132);
          v83 = cr2f + *v76;
          v76 = (float *)((char *)v76 + v74);
          *v79 = v83;
          v79 = (float *)((char *)v79 + v132);
          --l1a;
        }
        while ( l1a );
      }
    }
  }
}
