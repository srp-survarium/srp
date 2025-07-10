int __cdecl vorbis_synthesis_blockin(int v, vorbis_block *vb)
{
  private_state *v3; // edi
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int v8; // ebp
  int v9; // edi
  __int64 glue_bits; // rax
  bool v11; // cf
  int v12; // esi
  const float *v13; // edi
  int v14; // ecx
  const float *v15; // edx
  float *v16; // esi
  float *v17; // eax
  int v18; // ebp
  double v19; // st7
  float *v20; // edi
  double v21; // st6
  float *v22; // eax
  int v23; // edx
  int v24; // edi
  int v25; // edx
  float *v26; // ecx
  double v27; // st6
  const float *v28; // edi
  int v29; // ecx
  const float *v30; // edx
  float *v31; // esi
  float *v32; // eax
  char *k; // edi
  double v34; // st7
  float *v35; // ebp
  double v36; // st6
  double v37; // st7
  float *v38; // eax
  float *v39; // edx
  int v40; // edi
  int v41; // edx
  float *v42; // ecx
  double v43; // st6
  int v44; // ecx
  int v45; // eax
  int v46; // edx
  const float *v47; // esi
  float *v48; // edi
  float *v49; // ecx
  int m; // eax
  double v51; // st7
  float *v52; // ebp
  double v53; // st6
  double v54; // st7
  int v55; // eax
  int v56; // edi
  float *v57; // ecx
  float *v58; // eax
  double v59; // st6
  int v60; // ecx
  int v61; // eax
  int v62; // edi
  unsigned int v63; // ecx
  float *v64; // eax
  int v65; // ecx
  double v66; // st7
  const float *v67; // edi
  int v68; // ecx
  const float *v69; // edx
  float *v70; // esi
  float *v71; // eax
  char *ii; // edi
  double v73; // st7
  float *v74; // ebp
  double v75; // st6
  double v76; // st7
  float *v77; // eax
  float *v78; // edx
  float *v79; // edi
  int v80; // edx
  float *v81; // ecx
  double v82; // st6
  float *v83; // ecx
  float *v84; // edi
  int v85; // edx
  float *v86; // edx
  unsigned int v87; // edi
  float *v88; // eax
  float *v89; // eax
  int v90; // edi
  int v91; // ecx
  double v92; // st7
  bool v93; // zf
  int v94; // eax
  __int64 v95; // rdi
  __int64 v96; // rax
  int granulepos_high; // ecx
  int v98; // eax
  int v99; // eax
  __int64 v100; // rax
  unsigned int granulepos; // eax
  int v102; // ecx
  unsigned int v103; // edx
  int v104; // esi
  int v105; // eax
  private_state *b; // [esp+8h] [ebp-40h]
  int hs; // [esp+Ch] [ebp-3Ch]
  int j; // [esp+10h] [ebp-38h]
  float *pcm; // [esp+14h] [ebp-34h]
  float *pcma; // [esp+14h] [ebp-34h]
  float *pcmb; // [esp+14h] [ebp-34h]
  float *pcmc; // [esp+14h] [ebp-34h]
  float *p; // [esp+18h] [ebp-30h]
  float *pa; // [esp+18h] [ebp-30h]
  float *pb; // [esp+18h] [ebp-30h]
  float *pc; // [esp+18h] [ebp-30h]
  int prevCenter; // [esp+1Ch] [ebp-2Ch]
  int v118; // [esp+20h] [ebp-28h]
  int v119; // [esp+20h] [ebp-28h]
  int v120; // [esp+20h] [ebp-28h]
  int v121; // [esp+20h] [ebp-28h]
  const float *v122; // [esp+20h] [ebp-28h]
  float *v123; // [esp+20h] [ebp-28h]
  int n0; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  codec_setup_info *ci; // [esp+2Ch] [ebp-1Ch]
  float *w; // [esp+30h] [ebp-18h]
  float *wa; // [esp+30h] [ebp-18h]
  float *wb; // [esp+30h] [ebp-18h]
  float *wc; // [esp+30h] [ebp-18h]
  float *wd; // [esp+30h] [ebp-18h]
  int thisCenter; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  float *ia; // [esp+38h] [ebp-10h]
  float *ib; // [esp+38h] [ebp-10h]
  int ic; // [esp+38h] [ebp-10h]
  float *v137; // [esp+3Ch] [ebp-Ch]
  int v138; // [esp+40h] [ebp-8h]
  int v139; // [esp+40h] [ebp-8h]
  int v140; // [esp+40h] [ebp-8h]
  const float *v141; // [esp+40h] [ebp-8h]
  float *v142; // [esp+40h] [ebp-8h]
  int v143; // [esp+40h] [ebp-8h]
  vorbis_info *vi; // [esp+44h] [ebp-4h]
  int n1; // [esp+4Ch] [ebp+4h]

  vi = *(vorbis_info **)(v + 4);
  v3 = *(private_state **)(v + 104);
  ci = (codec_setup_info *)vi->codec_setup;
  b = v3;
  hs = ci->halfrate_flag;
  if ( !vb )
    return -131;
  v5 = *(_DWORD *)(v + 24);
  if ( *(_DWORD *)(v + 20) > v5 && v5 != -1 )
    return -131;
  *(_DWORD *)(v + 36) = *(_DWORD *)(v + 40);
  v6 = *(_DWORD *)(v + 68);
  *(_DWORD *)(v + 40) = vb->W;
  v7 = *(_DWORD *)(v + 64);
  *(_DWORD *)(v + 44) = -1;
  if ( (v6 & v7) == 0xFFFFFFFF || __PAIR64__(v6, v7) + 1 != vb->sequence )
  {
    *(_QWORD *)(v + 56) = -1;
    LODWORD(v3->sample_count) = -1;
    HIDWORD(v3->sample_count) = -1;
  }
  *(_QWORD *)(v + 64) = vb->sequence;
  if ( vb->pcm )
  {
    v8 = ci->blocksizes[0] >> (hs + 1);
    v9 = ci->blocksizes[1] >> (hs + 1);
    n = ci->blocksizes[*(_DWORD *)(v + 40)] >> (hs + 1);
    glue_bits = vb->glue_bits;
    v11 = __CFADD__((_DWORD)glue_bits, *(_DWORD *)(v + 72));
    *(_DWORD *)(v + 72) += glue_bits;
    n0 = v8;
    n1 = v9;
    *(_DWORD *)(v + 76) += HIDWORD(glue_bits) + v11;
    *(_QWORD *)(v + 80) += vb->time_bits;
    *(_QWORD *)(v + 88) += vb->floor_bits;
    *(_QWORD *)(v + 96) += vb->res_bits;
    v12 = 0;
    if ( *(_DWORD *)(v + 48) )
    {
      thisCenter = v9;
      prevCenter = 0;
    }
    else
    {
      thisCenter = 0;
      prevCenter = v9;
    }
    j = 0;
    if ( vi->channels > 0 )
    {
      do
      {
        if ( *(_DWORD *)(v + 36) )
        {
          if ( *(_DWORD *)(v + 40) )
          {
            v13 = vwin[b->window[1] - hs];
            pcm = (float *)(*(_DWORD *)(*(_DWORD *)(v + 8) + 4 * v12) + 4 * prevCenter);
            p = vb->pcm[v12];
            v14 = 0;
            w = (float *)v13;
            if ( n1 >= 4 )
            {
              v15 = v13 + 2;
              v16 = (float *)&v13[n1 - 2];
              v17 = pcm + 1;
              v18 = (char *)p - (char *)v13;
              v118 = (char *)v13 - (char *)pcm;
              do
              {
                v19 = p[v14] * *(v15 - 2);
                v20 = (float *)((char *)v17 + v118);
                v14 += 4;
                v21 = v16[1] * *(v17 - 1);
                v17 += 4;
                v15 += 4;
                v16 -= 4;
                *(v17 - 5) = v19 + v21;
                *(v17 - 4) = *(float *)((char *)v20 + v18) * *v20 + v16[4] * *(v17 - 4);
                *(v17 - 3) = *(const float *)((char *)v15 + v18 - 16) * *(v15 - 4) + v16[3] * *(v17 - 3);
                *(v17 - 2) = p[v14 - 1] * *(v15 - 3) + v16[2] * *(v17 - 2);
              }
              while ( v14 < n1 - 3 );
              v13 = w;
              v12 = j;
              v8 = n0;
            }
            if ( v14 < n1 )
            {
              v22 = &pcm[v14];
              wa = (float *)&v13[n1 - v14 - 1];
              v23 = (char *)p - (char *)v13;
              v24 = (char *)v13 - (char *)pcm;
              v138 = v23;
              v119 = v24;
              v25 = n1 - v14;
              while ( 1 )
              {
                v26 = (float *)((char *)v22++ + v24);
                --v25;
                v27 = *(v22 - 1) * *wa--;
                *(v22 - 1) = *(float *)((char *)v26 + v138) * *v26 + v27;
                if ( !v25 )
                  break;
                v24 = v119;
              }
            }
          }
          else
          {
            v28 = vwin[b->window[0] - hs];
            pcma = (float *)(*(_DWORD *)(*(_DWORD *)(v + 8) + 4 * v12) + 4 * (prevCenter + n1 / 2 - v8 / 2));
            pa = vb->pcm[v12];
            v29 = 0;
            i = (int)v28;
            if ( v8 >= 4 )
            {
              v30 = v28 + 2;
              v31 = (float *)&v28[v8 - 2];
              v32 = pcma + 1;
              v120 = (char *)v28 - (char *)pcma;
              for ( k = (char *)((char *)pa - (char *)v28); ; k = (char *)pa - i )
              {
                v34 = pa[v29] * *(v30 - 2);
                v35 = (float *)((char *)v32 + v120);
                v29 += 4;
                v36 = v31[1] * *(v32 - 1);
                v32 += 4;
                v30 += 4;
                v31 -= 4;
                *(v32 - 5) = v34 + v36;
                v37 = *(float *)((char *)v35 + (_DWORD)k) * *v35;
                v8 = n0;
                *(v32 - 4) = v37 + v31[4] * *(v32 - 4);
                *(v32 - 3) = *(float *)&k[(_DWORD)v30 - 16] * *(v30 - 4) + v31[3] * *(v32 - 3);
                *(v32 - 2) = pa[v29 - 1] * *(v30 - 3) + v31[2] * *(v32 - 2);
                if ( v29 >= n0 - 3 )
                  break;
              }
              v28 = (const float *)i;
              v12 = j;
            }
            if ( v29 < v8 )
            {
              v38 = &pcma[v29];
              ia = (float *)&v28[v8 - v29 - 1];
              v39 = (float *)((char *)pa - (char *)v28);
              v40 = (char *)v28 - (char *)pcma;
              wb = v39;
              v121 = v40;
              v41 = v8 - v29;
              while ( 1 )
              {
                v42 = (float *)((char *)v38++ + v40);
                --v41;
                v43 = *(v38 - 1) * *ia--;
                *(v38 - 1) = *(float *)((char *)wb + (_DWORD)v42) * *v42 + v43;
                if ( !v41 )
                  break;
                v40 = v121;
              }
            }
          }
        }
        else if ( *(_DWORD *)(v + 40) )
        {
          v122 = vwin[b->window[0] - hs];
          pcmb = (float *)(*(_DWORD *)(*(_DWORD *)(v + 8) + 4 * v12) + 4 * prevCenter);
          v44 = n1 / 2;
          v45 = v8 / 2;
          pb = &vb->pcm[v12][n1 / 2 - v8 / 2];
          v46 = 0;
          v139 = v8 / 2;
          if ( v8 >= 4 )
          {
            v47 = v122 + 2;
            v48 = (float *)&v122[v8 - 2];
            v49 = pcmb + 1;
            for ( m = (char *)pb - (char *)v122; ; m = (char *)pb - (char *)v122 )
            {
              v51 = pb[v46] * *(v47 - 2);
              v52 = (float *)((char *)v49 + (char *)v122 - (char *)pcmb);
              v46 += 4;
              v53 = v48[1] * *(v49 - 1);
              v49 += 4;
              v47 += 4;
              v48 -= 4;
              *(v49 - 5) = v51 + v53;
              v54 = *(float *)((char *)v52 + m) * *v52;
              v8 = n0;
              *(v49 - 4) = v54 + v48[4] * *(v49 - 4);
              *(v49 - 3) = *(const float *)((char *)v47 + m - 16) * *(v47 - 4) + v48[3] * *(v49 - 3);
              *(v49 - 2) = pb[v46 - 1] * *(v47 - 3) + v48[2] * *(v49 - 2);
              if ( v46 >= n0 - 3 )
                break;
            }
            v45 = v139;
            v44 = n1 / 2;
            v12 = j;
          }
          if ( v46 < v8 )
          {
            ib = (float *)&v122[v8 - v46 - 1];
            v55 = (char *)v122 - (char *)pcmb;
            v56 = v8 - v46;
            v57 = &pcmb[v46];
            v46 = v8;
            while ( 1 )
            {
              v58 = (float *)((char *)v57++ + v55);
              --v56;
              v59 = *(v57 - 1) * *ib--;
              *(v57 - 1) = *(float *)((char *)v58 + (char *)pb - (char *)v122) * *v58 + v59;
              if ( !v56 )
                break;
              v55 = (char *)v122 - (char *)pcmb;
            }
            v12 = j;
            v44 = n1 / 2;
            v45 = v139;
          }
          v60 = v45 + v44;
          v140 = v60;
          if ( v46 < v60 )
          {
            if ( v60 - v46 >= 4 )
            {
              v61 = (int)&pcmb[v46 + 1];
              v62 = (int)&pb[v46 + 3];
              v63 = ((unsigned int)(v60 - v46 - 4) >> 2) + 1;
              v46 += 4 * v63;
              do
              {
                v61 += 16;
                *(float *)(v61 - 20) = *(float *)(v62 - 12);
                v62 += 16;
                --v63;
                *(float *)(v61 - 16) = *(float *)((char *)pb - (char *)pcmb + v61 - 16);
                *(float *)(v61 - 12) = *(float *)(v62 - 20);
                *(float *)(v61 - 8) = *(float *)(v62 - 16);
              }
              while ( v63 );
              v12 = j;
              v60 = v140;
            }
            if ( v46 < v60 )
            {
              v64 = &pcmb[v46];
              v65 = v60 - v46;
              do
              {
                v66 = *(float *)((char *)v64++ + (char *)pb - (char *)pcmb);
                --v65;
                *(v64 - 1) = v66;
              }
              while ( v65 );
            }
          }
        }
        else
        {
          v67 = vwin[b->window[0] - hs];
          pc = (float *)(*(_DWORD *)(*(_DWORD *)(v + 8) + 4 * v12) + 4 * prevCenter);
          v68 = 0;
          v141 = v67;
          v123 = vb->pcm[v12];
          if ( v8 >= 4 )
          {
            v69 = v67 + 2;
            v70 = (float *)&v67[v8 - 2];
            v71 = pc + 1;
            wc = (float *)((char *)v67 - (char *)pc);
            for ( ii = (char *)((char *)v123 - (char *)v67); ; ii = (char *)((char *)v123 - (char *)v141) )
            {
              v73 = v123[v68] * *(v69 - 2);
              v74 = (float *)((int)wc + (_DWORD)v71);
              v68 += 4;
              v75 = v70[1] * *(v71 - 1);
              v71 += 4;
              v69 += 4;
              v70 -= 4;
              *(v71 - 5) = v73 + v75;
              v76 = *(float *)((char *)v74 + (_DWORD)ii) * *v74;
              v8 = n0;
              *(v71 - 4) = v76 + v70[4] * *(v71 - 4);
              *(v71 - 3) = *(float *)&ii[(_DWORD)v69 - 16] * *(v69 - 4) + v70[3] * *(v71 - 3);
              *(v71 - 2) = v123[v68 - 1] * *(v69 - 3) + v70[2] * *(v71 - 2);
              if ( v68 >= n0 - 3 )
                break;
            }
            v67 = v141;
            v12 = j;
          }
          if ( v68 < v8 )
          {
            v77 = &pc[v68];
            v142 = (float *)&v67[v8 - v68 - 1];
            v78 = (float *)((char *)v123 - (char *)v67);
            v79 = (float *)((char *)v67 - (char *)pc);
            pcmc = v78;
            wd = v79;
            v80 = v8 - v68;
            while ( 1 )
            {
              v81 = (float *)((int)v79 + (_DWORD)v77++);
              --v80;
              v82 = *(v77 - 1) * *v142--;
              *(v77 - 1) = *(float *)((char *)pcmc + (_DWORD)v81) * *v81 + v82;
              if ( !v80 )
                break;
              v79 = wd;
            }
          }
        }
        v83 = (float *)(4 * thisCenter + *(_DWORD *)(*(_DWORD *)(v + 8) + 4 * v12));
        v84 = &vb->pcm[v12][n];
        v85 = 0;
        v137 = v84;
        if ( n >= 4 )
        {
          v86 = v84 + 3;
          v143 = (char *)v84 - (char *)v83;
          v87 = ((unsigned int)(n - 4) >> 2) + 1;
          ic = 4 * v87;
          v88 = v83 + 1;
          do
          {
            v88 += 4;
            *(v88 - 5) = *(v86 - 3);
            v86 += 4;
            --v87;
            *(v88 - 4) = *(float *)((char *)v88 + v143 - 16);
            *(v88 - 3) = *(v86 - 5);
            *(v88 - 2) = *(v86 - 4);
          }
          while ( v87 );
          v12 = j;
          v84 = v137;
          v85 = ic;
        }
        if ( v85 < n )
        {
          v89 = &v83[v85];
          v90 = (char *)v84 - (char *)v83;
          v91 = n - v85;
          do
          {
            v92 = *(float *)((char *)v89++ + v90);
            --v91;
            *(v89 - 1) = v92;
          }
          while ( v91 );
        }
        j = ++v12;
      }
      while ( v12 < vi->channels );
    }
    v93 = *(_DWORD *)(v + 24) == -1;
    *(_DWORD *)(v + 48) = *(_DWORD *)(v + 48) == 0 ? n1 : 0;
    if ( v93 )
    {
      *(_DWORD *)(v + 24) = thisCenter;
      *(_DWORD *)(v + 20) = thisCenter;
    }
    else
    {
      v94 = *(_DWORD *)(v + 40);
      *(_DWORD *)(v + 24) = prevCenter;
      *(_DWORD *)(v + 20) = prevCenter + ((ci->blocksizes[*(_DWORD *)(v + 36)] / 4 + ci->blocksizes[v94] / 4) >> hs);
    }
  }
  HIDWORD(v95) = HIDWORD(b->sample_count);
  if ( (HIDWORD(v95) & b->sample_count) == -1 )
  {
    LODWORD(b->sample_count) = 0;
    HIDWORD(b->sample_count) = 0;
  }
  else
  {
    v96 = ci->blocksizes[*(_DWORD *)(v + 40)];
    LODWORD(v95) = (((BYTE4(v96) & 3) + (int)v96) >> 2) + ci->blocksizes[*(_DWORD *)(v + 36)] / 4;
    b->sample_count = __PAIR64__((int)v95 >> 31, b->sample_count) + v95;
  }
  if ( (*(_DWORD *)(v + 60) & *(_DWORD *)(v + 56)) == -1 )
  {
    granulepos_high = HIDWORD(vb->granulepos);
    if ( (granulepos_high & vb->granulepos) != 0xFFFFFFFF )
    {
      *(_DWORD *)(v + 56) = vb->granulepos;
      *(_DWORD *)(v + 60) = granulepos_high;
      if ( b->sample_count > *(_QWORD *)(v + 56) )
      {
        v98 = LODWORD(b->sample_count) - LODWORD(vb->granulepos);
        if ( v98 < 0 )
          v98 = 0;
        if ( vb->eofflag )
        {
          if ( v98 > (*(_DWORD *)(v + 20) - *(_DWORD *)(v + 24)) << hs )
            v98 = (*(_DWORD *)(v + 20) - *(_DWORD *)(v + 24)) << hs;
          *(_DWORD *)(v + 20) -= v98 >> hs;
        }
        else
        {
          *(_DWORD *)(v + 24) += v98 >> hs;
          v99 = *(_DWORD *)(v + 20);
          if ( *(_DWORD *)(v + 24) > v99 )
            *(_DWORD *)(v + 24) = v99;
        }
      }
    }
  }
  else
  {
    v100 = ci->blocksizes[*(_DWORD *)(v + 40)];
    *(_QWORD *)(v + 56) += (((BYTE4(v100) & 3) + (int)v100) >> 2) + ci->blocksizes[*(_DWORD *)(v + 36)] / 4;
    granulepos = vb->granulepos;
    v102 = HIDWORD(vb->granulepos);
    if ( (v102 & granulepos) != 0xFFFFFFFF )
    {
      v103 = *(_DWORD *)(v + 56);
      v104 = *(_DWORD *)(v + 60);
      if ( v103 != granulepos || v104 != v102 )
      {
        if ( v104 >= v102 && (v104 > v102 || v103 > granulepos) )
        {
          v105 = *(_DWORD *)(v + 56) - LODWORD(vb->granulepos);
          if ( v105 )
          {
            if ( vb->eofflag )
            {
              if ( v105 > (*(_DWORD *)(v + 20) - *(_DWORD *)(v + 24)) << hs )
                v105 = (*(_DWORD *)(v + 20) - *(_DWORD *)(v + 24)) << hs;
              if ( v105 < 0 )
                v105 = 0;
              *(_DWORD *)(v + 20) -= v105 >> hs;
            }
          }
        }
        *(_QWORD *)(v + 56) = vb->granulepos;
      }
    }
  }
  if ( vb->eofflag )
    *(_DWORD *)(v + 32) = 1;
  return 0;
}
