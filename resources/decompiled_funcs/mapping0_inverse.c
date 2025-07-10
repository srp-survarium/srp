int __cdecl mapping0_inverse(vorbis_block *vb, _DWORD *l)
{
  vorbis_dsp_state *vd; // eax
  vorbis_info *v4; // ecx
  codec_setup_info *codec_setup; // edx
  int W; // eax
  float *v7; // edx
  int channels; // edi
  void *v9; // esp
  void *v10; // esp
  void *v11; // esp
  void *v12; // esp
  int v13; // esi
  BOOL *v14; // edi
  int v15; // eax
  void *v16; // eax
  BOOL v17; // ecx
  float **pcm; // eax
  _DWORD *v19; // esi
  int v20; // ecx
  _DWORD *v21; // eax
  int v22; // esi
  bool v23; // zf
  _DWORD *v24; // esi
  int v25; // edi
  bool v26; // cc
  int v27; // eax
  int v28; // esi
  float v29; // ecx
  float *v30; // edi
  int v31; // ecx
  int v32; // edx
  _DWORD *v33; // edi
  float *v34; // esi
  float *v35; // eax
  float **v36; // edi
  float *v37; // ecx
  int v38; // edi
  unsigned int v39; // esi
  float *v40; // edx
  char v41; // fps^1
  double v42; // st6
  bool v43; // c0
  char v44; // c2
  bool v45; // c3
  char v46; // ah
  double v47; // st5
  bool v48; // c0
  bool v49; // c3
  double v50; // st6
  char v51; // fps^1
  double v52; // st6
  bool v53; // c0
  char v54; // c2
  bool v55; // c3
  char v56; // ah
  double v57; // st5
  bool v58; // c0
  bool v59; // c3
  double v60; // st6
  char v61; // fps^1
  double v62; // st6
  bool v63; // c0
  char v64; // c2
  bool v65; // c3
  char v66; // ah
  double v67; // st5
  bool v68; // c0
  bool v69; // c3
  double v70; // st6
  char v71; // fps^1
  double v72; // st6
  bool v73; // c0
  char v74; // c2
  bool v75; // c3
  char v76; // ah
  double v77; // st5
  bool v78; // c0
  bool v79; // c3
  double v80; // st6
  float *v81; // ecx
  int v82; // edx
  int v83; // esi
  char v84; // fps^1
  double v85; // st6
  bool v86; // c0
  char v87; // c2
  bool v88; // c3
  char v89; // ah
  double v90; // st5
  bool v91; // c0
  bool v92; // c3
  double v93; // st6
  int v94; // esi
  _DWORD *v95; // edi
  int v96; // eax
  int j; // esi
  unsigned int v99; // [esp-Ch] [ebp-44h]
  _DWORD v100[3]; // [esp+0h] [ebp-38h] BYREF
  void **floormemo; // [esp+Ch] [ebp-2Ch]
  float *pcmA; // [esp+10h] [ebp-28h]
  float *pcmM; // [esp+14h] [ebp-24h]
  float **pcmbundle; // [esp+18h] [ebp-20h]
  codec_setup_info *ci; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v106; // [esp+20h] [ebp-18h]
  private_state *b; // [esp+24h] [ebp-14h]
  int v108; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  vorbis_info *vi; // [esp+30h] [ebp-8h]
  float mag; // [esp+34h] [ebp-4h]
  float ang; // [esp+40h] [ebp+8h]
  float anga; // [esp+40h] [ebp+8h]
  float angb; // [esp+40h] [ebp+8h]
  float angc; // [esp+40h] [ebp+8h]
  float angd; // [esp+40h] [ebp+8h]

  vd = vb->vd;
  v4 = vd->vi;
  codec_setup = (codec_setup_info *)v4->codec_setup;
  b = (private_state *)vd->backend_state;
  W = vb->W;
  ci = codec_setup;
  v7 = (float *)codec_setup->blocksizes[W];
  vb->pcmend = (int)v7;
  channels = v4->channels;
  vi = v4;
  pcmM = v7;
  v9 = alloca(4 * channels);
  pcmbundle = (float **)v100;
  v10 = alloca(4 * channels);
  mag = COERCE_FLOAT(v100);
  v11 = alloca(4 * channels);
  v12 = alloca(4 * channels);
  v13 = 0;
  floormemo = (void **)v100;
  if ( channels > 0 )
  {
    v14 = v100;
    i = (unsigned int)(4 * (_DWORD)pcmM) >> 1;
    v108 = (int)(l + 1);
    v106 = 0;
    do
    {
      v15 = l[*(_DWORD *)v108 + 257];
      v16 = _floor_P[ci->floor_type[v15]]->inverse1(vb, b->flr[v15]);
      v17 = v16 != 0;
      *(BOOL *)((char *)v14 + (_DWORD)v106) = (BOOL)v16;
      pcm = vb->pcm;
      v99 = i;
      *v14 = v17;
      memset((int)pcm[v13], 0, v99);
      v108 += 4;
      ++v13;
      ++v14;
    }
    while ( v13 < vi->channels );
  }
  v19 = l;
  v20 = l[289];
  if ( v20 > 0 )
  {
    v21 = l + 546;
    do
    {
      v22 = *(v21 - 256);
      v23 = v100[v22] == 0;
      v24 = &v100[v22];
      if ( !v23 || v100[*v21] )
      {
        *v24 = 1;
        v100[*v21] = 1;
      }
      ++v21;
      --v20;
    }
    while ( v20 );
    v19 = l;
  }
  v25 = 0;
  v26 = *v19 <= 0;
  i = 0;
  if ( !v26 )
  {
    v106 = v19 + 273;
    do
    {
      v27 = 0;
      v28 = 0;
      if ( vi->channels > 0 )
      {
        v29 = mag;
        v108 = (int)(l + 1);
        pcmA = (float *)((char *)pcmbundle - LODWORD(mag));
        do
        {
          if ( *(_DWORD *)v108 == v25 )
          {
            v30 = pcmA;
            ++v28;
            LODWORD(v29) += 4;
            *(_DWORD *)(LODWORD(v29) - 4) = v100[v27] != 0;
            *(float *)((char *)v30 + LODWORD(v29) - 4) = *(float *)&vb->pcm[v27];
            v25 = i;
          }
          v108 += 4;
          ++v27;
        }
        while ( v27 < vi->channels );
      }
      _residue_P[ci->residue_type[*v106]]->inverse(vb, b->residue[*v106], pcmbundle, (int *)LODWORD(mag), v28);
      ++v106;
      v26 = ++v25 < *l;
      i = v25;
    }
    while ( v26 );
    v19 = l;
  }
  v31 = v19[289] - 1;
  i = v31;
  if ( v31 < 0 )
    goto LABEL_72;
  v32 = (int)pcmM / 2;
  v33 = &v19[v31 + 546];
  v108 = (int)pcmM / 2;
  v106 = v33;
  while ( 2 )
  {
    v34 = vb->pcm[*(v33 - 256)];
    v35 = vb->pcm[*v33];
    v36 = 0;
    pcmM = v34;
    pcmA = v35;
    if ( v32 >= 4 )
    {
      v37 = v34 + 1;
      v38 = (char *)v35 - (char *)v34;
      v39 = ((unsigned int)(v108 - 4) >> 2) + 1;
      v40 = v35 + 3;
      pcmbundle = (float **)(4 * v39);
      while ( 1 )
      {
        mag = *(v37 - 1);
        ang = *(v40 - 3);
        v42 = mag;
        v43 = mag < 0.0;
        v44 = 0;
        v45 = mag == 0.0;
        v46 = v41;
        v47 = ang;
        v48 = ang < 0.0;
        v49 = ang == 0.0;
        if ( (v46 & 0x41) != 0 )
        {
          if ( !v48 && !v49 )
          {
            *(v40 - 3) = v42 + v47;
            goto LABEL_33;
          }
          *(v40 - 3) = mag;
          v50 = v42 - ang;
        }
        else
        {
          if ( !v48 && !v49 )
          {
            *(v40 - 3) = v42 - v47;
            goto LABEL_33;
          }
          *(v40 - 3) = mag;
          v50 = ang + v42;
        }
        *(v37 - 1) = v50;
LABEL_33:
        mag = *v37;
        anga = *(float *)((char *)v37 + v38);
        v52 = mag;
        v53 = mag < 0.0;
        v54 = 0;
        v55 = mag == 0.0;
        v56 = v51;
        v57 = anga;
        v58 = anga < 0.0;
        v59 = anga == 0.0;
        if ( (v56 & 0x41) != 0 )
        {
          if ( !v58 && !v59 )
          {
            *(float *)((char *)v37 + v38) = v52 + v57;
            goto LABEL_41;
          }
          *(float *)((char *)v37 + v38) = mag;
          v60 = v52 - anga;
        }
        else
        {
          if ( !v58 && !v59 )
          {
            *(float *)((char *)v37 + v38) = v52 - v57;
            goto LABEL_41;
          }
          *(float *)((char *)v37 + v38) = mag;
          v60 = anga + v52;
        }
        *v37 = v60;
LABEL_41:
        mag = v37[1];
        angb = *(v40 - 1);
        v62 = mag;
        v63 = mag < 0.0;
        v64 = 0;
        v65 = mag == 0.0;
        v66 = v61;
        v67 = angb;
        v68 = angb < 0.0;
        v69 = angb == 0.0;
        if ( (v66 & 0x41) != 0 )
        {
          if ( !v68 && !v69 )
          {
            *(v40 - 1) = v62 + v67;
            goto LABEL_49;
          }
          *(v40 - 1) = mag;
          v70 = v62 - angb;
        }
        else
        {
          if ( !v68 && !v69 )
          {
            *(v40 - 1) = v62 - v67;
            goto LABEL_49;
          }
          *(v40 - 1) = mag;
          v70 = angb + v62;
        }
        v37[1] = v70;
LABEL_49:
        mag = v37[2];
        angc = *v40;
        v72 = mag;
        v73 = mag < 0.0;
        v74 = 0;
        v75 = mag == 0.0;
        v76 = v71;
        v77 = angc;
        v78 = angc < 0.0;
        v79 = angc == 0.0;
        if ( (v76 & 0x41) != 0 )
        {
          if ( v78 || v79 )
          {
            *v40 = mag;
            v80 = v72 - angc;
            goto LABEL_56;
          }
          *v40 = v72 + v77;
        }
        else
        {
          if ( v78 || v79 )
          {
            *v40 = mag;
            v80 = angc + v72;
LABEL_56:
            v37[2] = v80;
            goto LABEL_57;
          }
          *v40 = v72 - v77;
        }
LABEL_57:
        v37 += 4;
        v40 += 4;
        if ( !--v39 )
        {
          v35 = pcmA;
          v34 = pcmM;
          v36 = pcmbundle;
          v32 = v108;
          v31 = i;
          break;
        }
      }
    }
    if ( (int)v36 >= v32 )
      goto LABEL_71;
    v81 = &v34[(_DWORD)v36];
    v82 = (char *)v35 - (char *)v34;
    v83 = v108 - (_DWORD)v36;
    do
    {
      mag = *v81;
      angd = *(float *)((char *)v81 + v82);
      v85 = mag;
      v86 = mag < 0.0;
      v87 = 0;
      v88 = mag == 0.0;
      v89 = v84;
      v90 = angd;
      v91 = angd < 0.0;
      v92 = angd == 0.0;
      if ( (v89 & 0x41) != 0 )
      {
        if ( !v91 && !v92 )
        {
          *(float *)((char *)v81 + v82) = v85 + v90;
          goto LABEL_69;
        }
        *(float *)((char *)v81 + v82) = mag;
        v93 = v85 - angd;
      }
      else
      {
        if ( !v91 && !v92 )
        {
          *(float *)((char *)v81 + v82) = v85 - v90;
          goto LABEL_69;
        }
        *(float *)((char *)v81 + v82) = mag;
        v93 = angd + v85;
      }
      *v81 = v93;
LABEL_69:
      ++v81;
      --v83;
    }
    while ( v83 );
    v32 = v108;
    v31 = i;
LABEL_71:
    --v106;
    i = --v31;
    if ( v31 >= 0 )
    {
      v33 = v106;
      continue;
    }
    break;
  }
LABEL_72:
  v94 = 0;
  if ( vi->channels > 0 )
  {
    v95 = l + 1;
    do
    {
      v96 = l[*v95 + 257];
      _floor_P[ci->floor_type[v96]]->inverse2(vb, b->flr[v96], floormemo[v94], vb->pcm[v94]);
      ++v94;
      ++v95;
    }
    while ( v94 < vi->channels );
  }
  for ( j = 0; j < vi->channels; ++j )
    mdct_backward(*(mdct_lookup **)b->transform[vb->W], vb->pcm[j], vb->pcm[j]);
  return 0;
}
