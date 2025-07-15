int __cdecl mapping0_forward(int vb)
{
  vorbis_dsp_state *v2; // eax
  private_state *backend_state; // edx
  vorbis_info *v4; // edi
  vorbis_block_internal *v5; // eax
  int v6; // esi
  oggpack_buffer *v7; // ecx
  void *v8; // esp
  int ***v9; // eax
  double ampmax; // st7
  int channels; // eax
  void *v12; // esp
  int v13; // ecx
  int v14; // eax
  vorbis_look_psy *v15; // eax
  bool v16; // cc
  float *v17; // eax
  int v18; // edi
  double v19; // st7
  float **v20; // edi
  float *v21; // eax
  float *v22; // eax
  float *v23; // esi
  drft_lookup *v24; // eax
  int *v25; // esi
  float *v26; // edx
  int v27; // ecx
  char *v28; // edi
  double v29; // st4
  double v30; // st3
  double v31; // st0
  double v32; // st2
  float *v33; // eax
  int ***v34; // edi
  int v35; // ecx
  int v36; // eax
  float *v37; // eax
  float **v38; // ecx
  float *v39; // eax
  float *v40; // ecx
  int **v41; // eax
  int v42; // eax
  float *v43; // esi
  float *v44; // edx
  float *v45; // ecx
  unsigned int v46; // eax
  int **v47; // esi
  float *v48; // ecx
  int v49; // edx
  vorbis_look_psy *v50; // esi
  int v51; // eax
  float *v52; // esi
  float *v53; // esi
  int *v54; // eax
  float *v55; // edx
  HINSTANCE__ *v56; // esi
  int *v57; // eax
  int **v58; // ecx
  HINSTANCE__ *v59; // esi
  int *v60; // eax
  int **v61; // ecx
  void *v62; // esp
  int **v63; // esi
  void *v64; // esp
  char *v65; // eax
  bool v66; // zf
  _DWORD *v67; // eax
  BOOL v68; // eax
  int v70; // eax
  int v71; // edx
  int ***v72; // esi
  int **v73; // ecx
  int v74; // eax
  int v75; // eax
  float *v76; // eax
  float v77; // ecx
  float v78; // eax
  int v79; // ecx
  int v80; // eax
  int v81; // eax
  int v82; // edx
  _BYTE v83[12]; // [esp+8h] [ebp-74h] BYREF
  int **classifications; // [esp+14h] [ebp-68h]
  unsigned int value; // [esp+18h] [ebp-64h]
  int j; // [esp+1Ch] [ebp-60h]
  int *nonzero; // [esp+20h] [ebp-5Ch]
  float **gmdct; // [esp+24h] [ebp-58h]
  int ***floor_posts; // [esp+28h] [ebp-54h]
  vorbis_block_internal *vbi; // [esp+2Ch] [ebp-50h]
  int ch_in_bundle; // [esp+30h] [ebp-4Ch]
  int **couple_bundle; // [esp+34h] [ebp-48h]
  int resnum; // [esp+38h] [ebp-44h]
  int *residuesubmap; // [esp+3Ch] [ebp-40h]
  float *pcm; // [esp+40h] [ebp-3Ch]
  int *zerobundle; // [esp+44h] [ebp-38h]
  vorbis_info *vi; // [esp+48h] [ebp-34h]
  float *tone; // [esp+4Ch] [ebp-30h]
  float *noise; // [esp+50h] [ebp-2Ch]
  int **iwork; // [esp+54h] [ebp-28h]
  vorbis_look_psy *psy_look; // [esp+58h] [ebp-24h]
  oggpack_buffer *opb; // [esp+5Ch] [ebp-20h]
  float *logfft; // [esp+60h] [ebp-1Ch]
  float *mdct; // [esp+64h] [ebp-18h]
  codec_setup_info *ci; // [esp+68h] [ebp-14h]
  float v106; // [esp+6Ch] [ebp-10h]
  float *logmdct; // [esp+70h] [ebp-Ch]
  vorbis_info_mapping0 *info; // [esp+74h] [ebp-8h]
  private_state *b; // [esp+78h] [ebp-4h]
  int i; // [esp+84h] [ebp+8h]
  int ia; // [esp+84h] [ebp+8h]
  int id; // [esp+84h] [ebp+8h]
  int ib; // [esp+84h] [ebp+8h]
  float **ic; // [esp+84h] [ebp+8h]

  v2 = *(vorbis_dsp_state **)(vb + 64);
  backend_state = (private_state *)v2->backend_state;
  v4 = v2->vi;
  v5 = *(vorbis_block_internal **)(vb + 104);
  v6 = 2 * v4->channels;
  ci = (codec_setup_info *)v4->codec_setup;
  v7 = *(oggpack_buffer **)(vb + 36);
  vbi = v5;
  v6 *= 2;
  vi = v4;
  b = backend_state;
  opb = v7;
  v8 = alloca(v6);
  nonzero = (int *)v83;
  gmdct = (float **)_vorbis_block_alloc((vorbis_block *)vb, v6);
  iwork = (int **)_vorbis_block_alloc((vorbis_block *)vb, 4 * v4->channels);
  v9 = (int ***)_vorbis_block_alloc((vorbis_block *)vb, 4 * v4->channels);
  ampmax = vbi->ampmax;
  floor_posts = v9;
  channels = v4->channels;
  *(float *)&zerobundle = ampmax;
  v12 = alloca(4 * channels);
  v13 = *(_DWORD *)(vb + 28);
  info = (vorbis_info_mapping0 *)ci->map_param[v13];
  v14 = vbi->blocktype + (v13 != 0 ? 2 : 0);
  couple_bundle = (int **)v83;
  v15 = &b->psy[v14];
  *(_DWORD *)(vb + 40) = v13;
  v16 = v4->channels <= 0;
  value = v13;
  psy_look = v15;
  i = 0;
  if ( !v16 )
  {
    v17 = (float *)(4 * ((int)opb / 2));
    logfft = v17;
    *(float *)&j = 4.0 / (double)(int)opb;
    classifications = (int **)(j & 0x7FFFFFFF);
    v18 = (char *)gmdct - v83;
    tone = (float *)v83;
    *(float *)&j = (double)(j & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
    residuesubmap = (int *)((char *)gmdct - v83);
    v19 = *(float *)&j;
    j = (char *)iwork - (char *)gmdct;
    *(float *)&noise = v19 + 0.345;
    while ( 1 )
    {
      pcm = *(float **)(*(_DWORD *)vb + 4 * i);
      v20 = (float **)((char *)tone + v18);
      v21 = (float *)_vorbis_block_alloc((vorbis_block *)vb, (int)v17);
      *(float **)((char *)v20 + j) = v21;
      v22 = (float *)_vorbis_block_alloc((vorbis_block *)vb, (int)logfft);
      v23 = pcm;
      *v20 = v22;
      _vorbis_apply_window(
        v23,
        b->window,
        ci->blocksizes,
        *(_DWORD *)(vb + 24),
        *(_DWORD *)(vb + 28),
        *(_DWORD *)(vb + 32));
      mdct_forward(*(mdct_lookup **)b->transform[*(_DWORD *)(vb + 28)], v23, *v20);
      v24 = &b->fft_look[*(_DWORD *)(vb + 28)];
      v25 = (int *)pcm;
      if ( v24->n != 1 )
        drftf1(
          v24->n,
          pcm,
          b->fft_look[*(_DWORD *)(vb + 28)].trigcache,
          &b->fft_look[*(_DWORD *)(vb + 28)].trigcache[v24->n],
          b->fft_look[*(_DWORD *)(vb + 28)].splitcache);
      ch_in_bundle = *v25;
      classifications = (int **)(ch_in_bundle & 0x7FFFFFFF);
      v26 = tone;
      v27 = 1;
      v28 = (char *)&opb[-1].storage + 3;
      v16 = (int)&opb[-1].storage + 3 <= 1;
      *(float *)&resnum = (double)(ch_in_bundle & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
      v29 = *(float *)&noise;
      *(float *)&resnum = *(float *)&resnum + *(float *)&noise + 0.345;
      v30 = *(float *)&resnum;
      *v25 = resnum;
      *v26 = v30;
      if ( !v16 )
      {
        do
        {
          v31 = *(float *)&v25[v27 + 1];
          *(float *)&mdct = v31 * v31 + *(float *)&v25[v27] * *(float *)&v25[v27];
          classifications = (int **)((unsigned int)mdct & 0x7FFFFFFF);
          *(float *)&resnum = (double)((unsigned int)mdct & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
          *(float *)&resnum = *(float *)&resnum * 0.5 + v29 + 0.345;
          v32 = *(float *)&resnum;
          v25[(v27 + 1) >> 1] = resnum;
          *(float *)&resnum = v32;
          if ( *v26 < (double)*(float *)&resnum )
            *v26 = *(float *)&resnum;
          v27 += 2;
        }
        while ( v27 < (int)v28 );
      }
      if ( *v26 > 0.0 )
        *v26 = 0.0;
      if ( *(float *)&zerobundle < (double)*v26 )
        zerobundle = *(int **)v26;
      v16 = ++i < vi->channels;
      tone = v26 + 1;
      if ( !v16 )
        break;
      v18 = (int)residuesubmap;
      v17 = logfft;
    }
    v4 = vi;
  }
  resnum = (int)opb / 2;
  logfft = (float *)(4 * ((int)opb / 2));
  *(float *)&noise = COERCE_FLOAT(_vorbis_block_alloc((vorbis_block *)vb, (int)logfft));
  v33 = (float *)_vorbis_block_alloc((vorbis_block *)vb, (int)logfft);
  v16 = v4->channels <= 0;
  tone = v33;
  ia = 0;
  if ( v16 )
  {
LABEL_36:
    vbi->ampmax = *(float *)&zerobundle;
    id = 4 * v4->channels;
    v62 = alloca(id);
    v63 = (int **)v83;
    couple_bundle = (int **)v83;
    v64 = alloca(id);
    v65 = *(char **)(*(_DWORD *)(vb + 64) + 104);
    v66 = v65 + 80 == 0;
    v67 = v65 + 80;
    *(float *)&zerobundle = COERCE_FLOAT(v83);
    v68 = !v66 && *v67;
    vi = v68 ? 0 : (vorbis_info *)7;
    v70 = vorbis_bitrate_managed((vorbis_block *)vb);
    if ( v71 <= (v70 != 0 ? 14 : 7) )
    {
      tone = (float *)(4 * v71);
      noise = (float *)&vbi->packetblob[v71];
      do
      {
        opb = *(oggpack_buffer **)noise;
        oggpack_write(opb, 0, 1u);
        oggpack_write(opb, value, b->modebits);
        if ( *(_DWORD *)(vb + 28) )
        {
          oggpack_write(opb, *(_DWORD *)(vb + 24), 1u);
          oggpack_write(opb, *(_DWORD *)(vb + 32), 1u);
        }
        ib = 0;
        if ( v4->channels > 0 )
        {
          v72 = floor_posts;
          v73 = (int **)((char *)iwork - (char *)floor_posts);
          vbi = (vorbis_block_internal *)info->chmuxlist;
          classifications = (int **)((char *)iwork - (char *)floor_posts);
          j = (char *)nonzero - (char *)floor_posts;
          while ( 1 )
          {
            v74 = floor1_encode(
                    opb,
                    (vorbis_block *)vb,
                    (vorbis_look_floor1 *)b->flr[info->floorsubmap[(int)vbi->pcmdelay]],
                    *(char **)((char *)tone + (_DWORD)*v72),
                    *(int **)((char *)v72 + (_DWORD)v73));
            vbi = (vorbis_block_internal *)((char *)vbi + 4);
            *(int ***)((char *)v72++ + j) = (int **)v74;
            if ( ++ib >= v4->channels )
              break;
            v73 = classifications;
          }
          v63 = couple_bundle;
        }
        _vp_couple_quantize_normalize(
          (int)vi,
          &ci->psy_g_param,
          psy_look,
          info,
          gmdct,
          iwork,
          nonzero,
          ci->blocksizes[(_DWORD)vi + 15 * *(_DWORD *)(vb + 28) + 810],
          v4->channels);
        ic = 0;
        if ( info->submaps > 0 )
        {
          residuesubmap = info->residuesubmap;
          do
          {
            v16 = v4->channels <= 0;
            v75 = *residuesubmap;
            *(float *)&ch_in_bundle = 0.0;
            resnum = v75;
            pcm = 0;
            if ( !v16 )
            {
              v76 = (float *)iwork;
              j = (int)zerobundle;
              classifications = (int **)((char *)nonzero - (char *)iwork);
              logfft = (float *)iwork;
              vbi = (vorbis_block_internal *)info->chmuxlist;
              mdct = (float *)((char *)v63 - (char *)zerobundle);
              do
              {
                if ( vbi->pcmdelay == ic )
                {
                  v66 = *(_DWORD *)((char *)v76 + (_DWORD)classifications) == 0;
                  v77 = *(float *)&j;
                  *(_DWORD *)j = 0;
                  if ( !v66 )
                    *(_DWORD *)LODWORD(v77) = 1;
                  v78 = *v76;
                  ++ch_in_bundle;
                  *(float *)((char *)mdct + LODWORD(v77)) = v78;
                  v76 = logfft;
                  j = LODWORD(v77) + 4;
                }
                vbi = (vorbis_block_internal *)((char *)vbi + 4);
                ++v76;
                v16 = (int)pcm + 1 < v4->channels;
                pcm = (float *)((char *)pcm + 1);
                logfft = v76;
              }
              while ( v16 );
              v75 = resnum;
            }
            *(float *)&classifications = COERCE_FLOAT((int)_residue_P[ci->residue_type[v75]]->class(
                                                             vb,
                                                             b->residue[v75],
                                                             v63,
                                                             zerobundle,
                                                             ch_in_bundle));
            v79 = 0;
            v80 = 0;
            if ( v4->channels > 0 )
            {
              vbi = (vorbis_block_internal *)info->chmuxlist;
              do
              {
                v63 = couple_bundle;
                if ( vbi->pcmdelay == ic )
                  couple_bundle[v80++] = iwork[v79];
                vbi = (vorbis_block_internal *)((char *)vbi + 4);
                ++v79;
              }
              while ( v79 < v4->channels );
            }
            _residue_P[ci->residue_type[resnum]]->forward(
              opb,
              (vorbis_block *)vb,
              b->residue[resnum],
              v63,
              zerobundle,
              v80,
              classifications,
              (int)ic);
            ++residuesubmap;
            ic = (float **)((char *)ic + 1);
          }
          while ( (int)ic < info->submaps );
        }
        ++tone;
        ++noise;
        vi = (vorbis_info *)((char *)vi + 1);
        v81 = vorbis_bitrate_managed((vorbis_block *)vb);
      }
      while ( v82 <= (v81 != 0 ? 14 : 7) );
    }
    return 0;
  }
  else
  {
    v34 = floor_posts;
    v35 = (char *)gmdct - (char *)couple_bundle;
    v36 = (char *)couple_bundle - (char *)floor_posts;
    ch_in_bundle = (int)info->chmuxlist;
    residuesubmap = (int *)((char *)gmdct - (char *)couple_bundle);
    for ( j = (char *)couple_bundle - (char *)floor_posts; ; v36 = j )
    {
      v37 = *(float **)((char *)v34 + v36 + v35);
      v38 = *(float ***)vb;
      opb = *(oggpack_buffer **)ch_in_bundle;
      mdct = v37;
      v39 = v38[ia];
      v40 = &v39[resnum];
      logfft = v39;
      *(_DWORD *)(vb + 40) = value;
      logmdct = v40;
      v41 = (int **)_vorbis_block_alloc((vorbis_block *)vb, 60);
      *v34 = v41;
      memset((int)v41, 0, 0x3Cu);
      v42 = resnum;
      v43 = 0;
      if ( resnum >= 4 )
      {
        v44 = mdct + 3;
        v45 = logmdct + 1;
        v46 = ((unsigned int)(resnum - 4) >> 2) + 1;
        couple_bundle = (int **)((char *)mdct - (char *)logmdct);
        pcm = (float *)(4 * v46);
        do
        {
          v106 = *(v44 - 3);
          v47 = couple_bundle;
          *(float *)&classifications = (double)(LODWORD(v106) & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
          *(v45 - 1) = *(float *)&classifications + 0.345;
          v106 = *(float *)((char *)v45 + (_DWORD)v47);
          *(float *)&classifications = (double)(LODWORD(v106) & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
          *v45 = *(float *)&classifications + 0.345;
          v106 = *(v44 - 1);
          *(float *)&classifications = (double)(LODWORD(v106) & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
          v45[1] = *(float *)&classifications + 0.345;
          v106 = *v44;
          v45 += 4;
          v44 += 4;
          --v46;
          *(float *)&classifications = (double)(LODWORD(v106) & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
          *(v45 - 2) = *(float *)&classifications + 0.345;
        }
        while ( v46 );
        v43 = pcm;
        v42 = resnum;
      }
      if ( (int)v43 < v42 )
      {
        couple_bundle = (int **)((char *)mdct - (char *)logmdct);
        v48 = &logmdct[(_DWORD)v43];
        v49 = v42 - (_DWORD)v43;
        do
        {
          v106 = *(float *)((char *)couple_bundle + (_DWORD)v48++);
          --v49;
          *(float *)&classifications = (double)(LODWORD(v106) & 0x7FFFFFFF) * 0.0000007177114298428933 - 764.6162109375;
          *(v48 - 1) = *(float *)&classifications + 0.345;
        }
        while ( v49 );
      }
      v50 = psy_look;
      _vp_noisemask(psy_look, logmdct, noise);
      _vp_tonemask(v50, logfft, tone, *(float *)&zerobundle, *(float *)((char *)v34 + j));
      _vp_offset_and_mix(v50, noise, tone, 1, logfft, mdct, logmdct);
      v51 = info->floorsubmap[(_DWORD)opb];
      if ( ci->floor_type[v51] != 1 )
        break;
      v52 = logfft;
      (*v34)[7] = floor1_fit((vorbis_block *)vb, (vorbis_look_floor1 *)b->flr[v51], logmdct, logfft);
      if ( vorbis_bitrate_managed((vorbis_block *)vb) && (*v34)[7] )
      {
        _vp_offset_and_mix(psy_look, noise, tone, 2, v52, mdct, logmdct);
        v53 = logfft;
        v54 = floor1_fit(
                (vorbis_block *)vb,
                (vorbis_look_floor1 *)b->flr[info->floorsubmap[(_DWORD)opb]],
                logmdct,
                logfft);
        v55 = logmdct;
        (*v34)[14] = v54;
        _vp_offset_and_mix(psy_look, noise, tone, 0, v53, mdct, v55);
        **v34 = floor1_fit(
                  (vorbis_block *)vb,
                  (vorbis_look_floor1 *)b->flr[info->floorsubmap[(_DWORD)opb]],
                  logmdct,
                  logfft);
        couple_bundle = (int **)4;
        v56 = &_sbh_sizeHeaderList;
        do
        {
          v57 = (int *)floor1_interpolate_fit(
                         (vorbis_look_floor1 *)b->flr[info->floorsubmap[(_DWORD)opb]],
                         (char *)**v34,
                         (vorbis_block *)vb,
                         (*v34)[7],
                         (int)v56 / 7);
          v58 = couple_bundle;
          *(int **)((char *)*v34 + (_DWORD)couple_bundle) = v57;
          v56 = (HINSTANCE__ *)((char *)&_sbh_sizeHeaderList + (_DWORD)v56);
          couple_bundle = v58 + 1;
        }
        while ( (int)v56 < (int)((char *)&loc_6FFFF + 1) );
        couple_bundle = (int **)32;
        v59 = &_sbh_sizeHeaderList;
        do
        {
          v60 = (int *)floor1_interpolate_fit(
                         (vorbis_look_floor1 *)b->flr[info->floorsubmap[(_DWORD)opb]],
                         (char *)(*v34)[7],
                         (vorbis_block *)vb,
                         (*v34)[14],
                         (int)v59 / 7);
          v61 = couple_bundle;
          *(int **)((char *)*v34 + (_DWORD)couple_bundle) = v60;
          v59 = (HINSTANCE__ *)((char *)&_sbh_sizeHeaderList + (_DWORD)v59);
          couple_bundle = v61 + 1;
        }
        while ( (int)v59 < (int)((char *)&loc_6FFFF + 1) );
      }
      ch_in_bundle += 4;
      ++v34;
      if ( ++ia >= vi->channels )
      {
        v4 = vi;
        goto LABEL_36;
      }
      v35 = (int)residuesubmap;
    }
    return -1;
  }
}
