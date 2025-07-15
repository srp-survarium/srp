void __usercall dradf4(float *cc@<eax>, float *ch@<ecx>, int ido, int l1, float *wa1, float *wa2, float *wa3)
{
  int v8; // esi
  float *v9; // edi
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // edi
  float v13; // xmm0_4
  float *v14; // edi
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  int v23; // edi
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  float *v28; // edi
  float v29; // xmm4_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm2_4
  float v33; // xmm4_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm6_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm7_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  bool v44; // zf
  float v45; // xmm1_4
  float v46; // xmm3_4
  int v47; // edi
  int v48; // ebx
  int v49; // edx
  float *v50; // ecx
  int v51; // edi
  float *v52; // edx
  float *v53; // esi
  float *v54; // eax
  float v55; // xmm2_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  int v60; // [esp+Ch] [ebp-54h]
  float *v61; // [esp+10h] [ebp-50h]
  int v62; // [esp+1Ch] [ebp-44h]
  int v63; // [esp+1Ch] [ebp-44h]
  unsigned int v64; // [esp+20h] [ebp-40h]
  float v65; // [esp+24h] [ebp-3Ch]
  float v66; // [esp+28h] [ebp-38h]
  int v67; // [esp+2Ch] [ebp-34h]
  int v68; // [esp+30h] [ebp-30h]
  int v69; // [esp+34h] [ebp-2Ch]
  int v70; // [esp+38h] [ebp-28h]
  int v71; // [esp+38h] [ebp-28h]
  float *v72; // [esp+38h] [ebp-28h]
  float *v73; // [esp+3Ch] [ebp-24h]
  float *v74; // [esp+44h] [ebp-1Ch]
  float *v75; // [esp+48h] [ebp-18h]
  float *v76; // [esp+4Ch] [ebp-14h]
  float *v77; // [esp+50h] [ebp-10h]
  float *v78; // [esp+54h] [ebp-Ch]
  float *v79; // [esp+54h] [ebp-Ch]
  float *v80; // [esp+58h] [ebp-8h]
  float *v81; // [esp+58h] [ebp-8h]
  float *v82; // [esp+5Ch] [ebp-4h]
  int v83; // [esp+5Ch] [ebp-4h]
  int v84; // [esp+68h] [ebp+8h]
  float *v85; // [esp+68h] [ebp+8h]
  float *v86; // [esp+68h] [ebp+8h]

  v84 = 0;
  v8 = l1 * ido;
  if ( l1 > 0 )
  {
    v78 = &cc[v8];
    v82 = &cc[2 * v8];
    v9 = &cc[3 * v8];
    v80 = v9;
    v70 = l1;
    while ( 1 )
    {
      v10 = *v78 + *v9;
      v11 = cc[v84] + *v82;
      v12 = 4 * v84;
      ch[v12] = v11 + v10;
      ch[4 * v84 - 1 + 4 * ido] = v11 - v10;
      v13 = cc[v84] - *v82;
      v84 += ido;
      v14 = &ch[2 * ido + v12];
      *(v14 - 1) = v13;
      *v14 = *v80 - *v78;
      v82 += ido;
      v80 += ido;
      v78 += ido;
      if ( !--v70 )
        break;
      v9 = v80;
    }
  }
  if ( ido >= 2 )
  {
    if ( ido == 2 )
      goto L105_0;
    v83 = 0;
    if ( l1 > 0 )
    {
      v73 = ch;
      v71 = 4 * v8;
      v62 = l1;
      do
      {
        v76 = &ch[4 * v83 + 2 * ido];
        v69 = v8 + v83;
        v81 = &cc[v83];
        v75 = v76;
        v68 = v83 + 2 * v8;
        v67 = v71;
        v74 = &ch[4 * v83 + 2 * ido + 2 * ido];
        v77 = v73;
        v79 = wa3;
        v85 = wa1 + 1;
        v64 = ((unsigned int)(ido - 3) >> 1) + 1;
        do
        {
          v15 = *(float *)((char *)cc + v67 + 4);
          v81 += 2;
          v69 += 2;
          v68 += 2;
          v77 += 2;
          v75 += 2;
          v76 -= 2;
          v74 -= 2;
          v16 = *(float *)((char *)cc + v67 + 8);
          v17 = *(v85 - 1);
          v67 += 8;
          v18 = (float)(v17 * v16) - (float)(*v85 * v15);
          v19 = v17 * v15;
          v20 = *(float *)((char *)&cc[v8 - 1] + v67);
          v21 = v19 + (float)(*v85 * v16);
          v22 = v18;
          v23 = v67 + 4 * v8;
          v24 = *(float *)((char *)cc + v23);
          v25 = *(float *)((char *)v79 + (char *)wa2 - (char *)wa3);
          v26 = *(float *)((char *)v85 + (char *)wa2 - (char *)wa1);
          v27 = (float)(v25 * v24) - (float)(v26 * v20);
          v28 = (float *)((char *)&cc[v8] + v23);
          v29 = v26 * v24;
          v30 = *(v28 - 1);
          v31 = v25 * v20;
          v32 = *(float *)((char *)v85 + (char *)wa3 - (char *)wa1);
          v66 = v27;
          v33 = v29 + v31;
          v34 = (float)(v32 * *v28) + (float)(*v79 * v30);
          v35 = v32 * v30;
          v36 = v34;
          v37 = (float)(*v79 * *v28) - v35;
          v65 = v34 - v21;
          v38 = v37 + v22;
          v39 = v22 - v37;
          v40 = *v81 + v66;
          v41 = v36 + v21;
          v42 = *(v81 - 1);
          v43 = *v81 - v66;
          v85 += 2;
          v79 += 2;
          v44 = v64-- == 1;
          v45 = v42 + v33;
          v46 = v42 - v33;
          *(v77 - 1) = v45 + v41;
          *v77 = v40 + v38;
          *(v76 - 1) = v46 - v39;
          *v76 = v65 - v43;
          *v75 = v43 + v65;
          *(v75 - 1) = v46 + v39;
          *(v74 - 1) = v45 - v41;
          *v74 = v38 - v40;
        }
        while ( !v44 );
        v73 += 4 * ido;
        v83 += ido;
        v71 += 4 * ido;
        --v62;
      }
      while ( v62 );
    }
    if ( (ido & 1) == 0 )
    {
L105_0:
      v47 = v8 + ido - 1;
      if ( l1 > 0 )
      {
        v60 = ido;
        v63 = 16 * ido;
        v72 = &cc[2 * v8 + v47];
        v86 = &cc[v47];
        v48 = 4 * ido;
        v61 = &ch[3 * ido];
        v49 = v47 + v8;
        v50 = &ch[v60];
        v51 = v47 - v8;
        v52 = &cc[v49];
        v53 = v61;
        v54 = &cc[v51];
        do
        {
          v55 = *v72;
          v56 = *v86;
          v86 = (float *)((char *)v86 + v48);
          v72 = (float *)((char *)v72 + v48);
          v57 = v56;
          v58 = (float)(v56 - v55) * hsqt2;
          v59 = (float)(v57 + v55) * -0.70710677;
          *(v50 - 1) = *v54 + v58;
          *(v53 - 1) = *v54 - v58;
          *v50 = v59 - *v52;
          v50 = (float *)((char *)v50 + v63);
          *v53 = *v52 + v59;
          v53 = (float *)((char *)v53 + v63);
          v54 = (float *)((char *)v54 + v48);
          v52 = (float *)((char *)v52 + v48);
          --l1;
        }
        while ( l1 );
      }
    }
  }
}
