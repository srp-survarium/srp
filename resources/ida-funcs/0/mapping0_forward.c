int __usercall mapping0_forward@<eax>(__int128 a1@<xmm6>, vorbis_block *vb)
{
  vorbis_dsp_state *vd; // eax
  vorbis_info *vi; // ebx
  char *v5; // edi
  int v6; // eax
  void *v7; // esp
  int v8; // eax
  void *v9; // esp
  int W; // eax
  vorbis_look_psy *v11; // edi
  bool v12; // cc
  char *v13; // eax
  char *v14; // eax
  int *v15; // edx
  int *v16; // eax
  float *v17; // ecx
  double v18; // st7
  float *v19; // edx
  float *v20; // eax
  double v21; // st6
  double v22; // st6
  float v23; // xmm0_4
  float *v24; // eax
  oggpack_buffer *v25; // ecx
  float *v26; // ecx
  char *v27; // eax
  float *v28; // ecx
  int v29; // edx
  double v30; // st7
  float *v31; // ecx
  int *v32; // edi
  int v33; // edx
  int *v34; // eax
  int v35; // ecx
  int *v36; // eax
  int *v37; // eax
  char *v38; // eax
  float *v39; // edx
  char **v40; // ecx
  char *v41; // eax
  float *v42; // edx
  char **v43; // ecx
  void *v44; // esp
  void *v45; // esp
  BOOL v46; // eax
  int v47; // ecx
  float *v48; // ecx
  char *v49; // edx
  int v51; // eax
  float *v52; // edx
  vorbis_info_mapping0 *v53; // eax
  float v54; // ecx
  float v55; // eax
  vorbis_block *v56; // edx
  float v57; // ecx
  int v58; // ecx
  vorbis_block *v59; // eax
  int v60; // ecx
  const vorbis_func_residue *v61; // eax
  int v62; // eax
  BOOL v63; // eax
  float *v64; // [esp-28h] [ebp-9Ch]
  float *v65; // [esp-24h] [ebp-98h]
  float *v66; // [esp-20h] [ebp-94h]
  int v67; // [esp-8h] [ebp-7Ch]
  float *v68; // [esp+4h] [ebp-70h]
  _BYTE v69[12]; // [esp+8h] [ebp-6Ch] BYREF
  vorbis_block *v70; // [esp+14h] [ebp-60h]
  float v71; // [esp+18h] [ebp-5Ch] BYREF
  unsigned int value; // [esp+1Ch] [ebp-58h]
  float v73; // [esp+20h] [ebp-54h] BYREF
  unsigned __int8 *v74; // [esp+24h] [ebp-50h]
  float **v75; // [esp+28h] [ebp-4Ch]
  int v76; // [esp+2Ch] [ebp-48h]
  float v77; // [esp+30h] [ebp-44h]
  float v78; // [esp+34h] [ebp-40h]
  _BYTE *v79; // [esp+38h] [ebp-3Ch]
  char *codec_setup; // [esp+3Ch] [ebp-38h]
  float *internal; // [esp+40h] [ebp-34h]
  float v82; // [esp+44h] [ebp-30h]
  int **v83; // [esp+48h] [ebp-2Ch]
  float *v84; // [esp+4Ch] [ebp-28h]
  int pcmend; // [esp+50h] [ebp-24h]
  oggpack_buffer *b; // [esp+54h] [ebp-20h]
  float v87; // [esp+58h] [ebp-1Ch]
  int v88; // [esp+5Ch] [ebp-18h]
  float *in; // [esp+60h] [ebp-14h]
  float *logmdct; // [esp+64h] [ebp-10h]
  vorbis_info_mapping0 *v91; // [esp+68h] [ebp-Ch]
  _DWORD *backend_state; // [esp+6Ch] [ebp-8h]
  int v93; // [esp+70h] [ebp-4h]
  vorbis_block *vba; // [esp+7Ch] [ebp+8h]
  vorbis_block *vbb; // [esp+7Ch] [ebp+8h]
  vorbis_block *vbe; // [esp+7Ch] [ebp+8h]
  vorbis_block *vbc; // [esp+7Ch] [ebp+8h]
  vorbis_block *vbd; // [esp+7Ch] [ebp+8h]

  vd = vb->vd;
  vi = vd->vi;
  backend_state = vd->backend_state;
  internal = (float *)vb->internal;
  pcmend = vb->pcmend;
  v6 = 4 * vi->channels;
  codec_setup = (char *)vi->codec_setup;
  v5 = codec_setup;
  v7 = alloca(v6);
  v74 = v69;
  v75 = (float **)_vorbis_block_alloc(vb, v6);
  v87 = COERCE_FLOAT(_vorbis_block_alloc(vb, 4 * vi->channels));
  v76 = (int)_vorbis_block_alloc(vb, 4 * vi->channels);
  v8 = 4 * vi->channels;
  v82 = internal[1];
  v9 = alloca(v8);
  W = vb->W;
  vba = 0;
  v91 = *(vorbis_info_mapping0 **)&v5[4 * W + 544];
  v11 = (vorbis_look_psy *)(backend_state[14] + 52 * (*((_DWORD *)internal + 2) + (W != 0 ? 2 : 0)));
  vb->mode = W;
  v12 = vi->channels <= 0;
  v79 = v69;
  value = W;
  v88 = (int)v11;
  if ( !v12 )
  {
    logmdct = (float *)(4 * (pcmend / 2));
    v73 = 4.0 / (float)pcmend;
    v77 = todB(&v73) + 0.345;
    b = (oggpack_buffer *)((char *)v75 - v69);
    v84 = (float *)v69;
    LODWORD(v73) = LODWORD(v87) - (_DWORD)v75;
    do
    {
      in = vb->pcm[(_DWORD)vba];
      v83 = (int **)((char *)b + (_DWORD)v84);
      v13 = _vorbis_block_alloc(vb, (int)logmdct);
      *(int **)((char *)v83 + LODWORD(v73)) = (int *)v13;
      v14 = _vorbis_block_alloc(vb, (int)logmdct);
      v15 = (int *)codec_setup;
      *v83 = (int *)v14;
      _vorbis_apply_window(v15, vb->W, in, backend_state + 1, vb->lW, vb->nW);
      mdct_forward(*(mdct_lookup **)backend_state[vb->W + 3], in, (float *)*v83);
      v16 = &backend_state[3 * vb->W + 5];
      if ( *v16 != 1 )
      {
        v68 = (float *)backend_state[3 * vb->W + 6];
        drftf1(&v68[*v16], (int *)backend_state[3 * vb->W + 7], *v16, in, v68);
        v11 = (vorbis_look_psy *)v88;
      }
      v18 = todB(in);
      v19 = v84;
      v20 = (float *)(pcmend - 1);
      v12 = pcmend - 1 <= 1;
      v21 = v18 + v77 + 0.345;
      v93 = 1;
      *v17 = v21;
      v83 = (int **)v20;
      *v19 = v21;
      if ( !v12 )
      {
        do
        {
          v71 = (float)(v17[v93 + 1] * v17[v93 + 1]) + (float)(v17[v93] * v17[v93]);
          v22 = todB(&v71);
          v78 = v22 * 0.5 + v77 + 0.345;
          v23 = v78;
          v12 = v78 <= *v19;
          v17[(v93 + 1) >> 1] = v78;
          if ( !v12 )
            *v19 = v23;
          v93 += 2;
        }
        while ( v93 < (int)v83 );
      }
      if ( *v19 > 0.0 )
        *v19 = 0.0;
      if ( *v19 > v82 )
        v82 = *v19;
      vba = (vorbis_block *)((char *)vba + 1);
      v12 = (int)vba < vi->channels;
      v84 = v19 + 1;
    }
    while ( v12 );
  }
  LODWORD(v78) = pcmend / 2;
  logmdct = (float *)(4 * (pcmend / 2));
  v84 = (float *)_vorbis_block_alloc(vb, (int)logmdct);
  v24 = (float *)_vorbis_block_alloc(vb, (int)logmdct);
  vbb = 0;
  v12 = vi->channels <= 0;
  v83 = (int **)v24;
  if ( v12 )
  {
LABEL_28:
    internal[1] = v82;
    vbe = (vorbis_block *)(4 * vi->channels);
    v44 = alloca((int)vbe);
    v83 = (int **)v69;
    v45 = alloca((int)vbe);
    v82 = COERCE_FLOAT(v69);
    v88 = vorbis_bitrate_managed(vb) ? 0 : 7;
    v46 = vorbis_bitrate_managed(vb);
    if ( v47 <= (v46 ? 14 : 7) )
    {
      v84 = &internal[v47 + 3];
      do
      {
        b = *(oggpack_buffer **)v84;
        oggpack_write(b, 0, 1u);
        oggpack_write(b, value, backend_state[11]);
        if ( vb->W )
        {
          oggpack_write(b, vb->lW, 1u);
          oggpack_write(b, vb->nW, 1u);
        }
        vbc = 0;
        if ( vi->channels > 0 )
        {
          v48 = (float *)v76;
          LODWORD(v77) = v91->chmuxlist;
          v49 = (char *)(LODWORD(v87) - v76);
          internal = (float *)v76;
          v70 = (vorbis_block *)(LODWORD(v87) - v76);
          LODWORD(v71) = &v74[-v76];
          while ( 1 )
          {
            v51 = floor1_encode(
                    b,
                    vb,
                    *(vorbis_look_floor1 **)(backend_state[12] + 4 * v91->floorsubmap[*(_DWORD *)LODWORD(v77)]),
                    *(unsigned int **)(*(_DWORD *)v48 + 4 * v88),
                    *(int **)((char *)v48 + (_DWORD)v49));
            v52 = internal;
            LODWORD(v77) += 4;
            ++internal;
            vbc = (vorbis_block *)((char *)vbc + 1);
            *(_DWORD *)((char *)v52 + LODWORD(v71)) = v51;
            if ( (int)vbc >= vi->channels )
              break;
            v49 = (char *)v70;
            v48 = internal;
          }
        }
        _vp_couple_quantize_normalize(
          v88,
          (vorbis_info_psy_global *)(codec_setup + 2868),
          v11,
          v91,
          v75,
          (int **)LODWORD(v87),
          v74,
          *(_DWORD *)&codec_setup[60 * vb->W + 3240 + 4 * v88],
          vi->channels);
        v53 = v91;
        vbd = 0;
        if ( v91->submaps > 0 )
        {
          internal = (float *)v91->residuesubmap;
          do
          {
            v12 = vi->channels <= 0;
            v54 = *internal;
            v79 = 0;
            pcmend = LODWORD(v54);
            v93 = 0;
            if ( !v12 )
            {
              LODWORD(v77) = v53->chmuxlist;
              v78 = v87;
              v70 = (vorbis_block *)&v74[-LODWORD(v87)];
              v73 = v82;
              LODWORD(v71) = (char *)v83 - LODWORD(v82);
              do
              {
                if ( *(vorbis_block **)LODWORD(v77) == vbd )
                {
                  v55 = v73;
                  v56 = v70;
                  v57 = v78;
                  *(_DWORD *)LODWORD(v73) = 0;
                  if ( *(float ***)((char *)&v56->pcm + LODWORD(v57)) )
                    *(_DWORD *)LODWORD(v55) = 1;
                  v58 = *(_DWORD *)LODWORD(v57);
                  ++v79;
                  *(_DWORD *)(LODWORD(v71) + LODWORD(v55)) = v58;
                  v54 = *(float *)&pcmend;
                  LODWORD(v73) = LODWORD(v55) + 4;
                }
                ++v93;
                LODWORD(v77) += 4;
                LODWORD(v78) += 4;
              }
              while ( v93 < vi->channels );
            }
            v59 = (vorbis_block *)&codec_setup[4 * LODWORD(v54) + 1312];
            v60 = 4 * LODWORD(v54);
            v67 = *(_DWORD *)(backend_state[13] + v60);
            v70 = v59;
            v61 = _residue_P[(int)v59->pcm];
            v73 = *(float *)&v60;
            v71 = COERCE_FLOAT(
                    ((int (__cdecl *)(vorbis_block *, int, int **, float, _BYTE *))v61->class)(
                      vb,
                      v67,
                      v83,
                      COERCE_FLOAT(LODWORD(v82)),
                      v79));
            v62 = 0;
            v12 = vi->channels <= 0;
            v93 = 0;
            if ( !v12 )
            {
              LODWORD(v77) = v91->chmuxlist;
              do
              {
                if ( *(vorbis_block **)LODWORD(v77) == vbd )
                  v83[v62++] = *(int **)(LODWORD(v87) + 4 * v93);
                ++v93;
                LODWORD(v77) += 4;
              }
              while ( v93 < vi->channels );
            }
            _residue_P[(int)v70->pcm]->forward(
              b,
              vb,
              *(void **)(backend_state[13] + LODWORD(v73)),
              v83,
              (int *)LODWORD(v82),
              v62,
              (int **)LODWORD(v71),
              (int)vbd);
            v53 = v91;
            ++internal;
            vbd = (vorbis_block *)((char *)vbd + 1);
          }
          while ( (int)vbd < v91->submaps );
        }
        ++v88;
        ++v84;
        v63 = vorbis_bitrate_managed(vb);
      }
      while ( v88 <= (v63 ? 14 : 7) );
    }
    return 0;
  }
  else
  {
    LODWORD(v77) = v91->chmuxlist;
    v25 = (oggpack_buffer *)((char *)v75 - v79);
    v79 -= v76;
    v93 = v76;
    for ( b = v25; ; v25 = b )
    {
      v70 = *(vorbis_block **)LODWORD(v77);
      LODWORD(v71) = &v79[v93];
      pcmend = *(_DWORD *)&v79[v93 + (_DWORD)v25];
      v26 = &vb->pcm[(_DWORD)vbb][LODWORD(v78)];
      in = vb->pcm[(_DWORD)vbb];
      vb->mode = value;
      logmdct = v26;
      v27 = _vorbis_block_alloc(vb, 60);
      *(_DWORD *)v93 = v27;
      memset((int)v27, 0, 0x3Cu);
      if ( SLODWORD(v78) > 0 )
      {
        v28 = logmdct;
        v29 = pcmend - (_DWORD)logmdct;
        v73 = v78;
        do
        {
          v30 = todB((float *)((char *)v28 + v29));
          *v31 = v30 + 0.345;
          v28 = v31 + 1;
          --LODWORD(v73);
        }
        while ( v73 != 0.0 );
      }
      _vp_noisemask(v11, logmdct, v84);
      _vp_tonemask((vorbis_look_psy *)v88, in, (float *)v83, v82, *(float *)LODWORD(v71));
      _vp_offset_and_mix((float *)v83, 1, (vorbis_look_psy *)v88, v84, in, (float *)pcmend, logmdct);
      v32 = &v91->floorsubmap[(_DWORD)v70];
      if ( *(_DWORD *)&codec_setup[4 * *v32 + 800] != v33 )
        break;
      v34 = floor1_fit(a1, vb, *(vorbis_look_floor1 **)(backend_state[12] + 4 * *v32), logmdct, in);
      *(_DWORD *)(*(_DWORD *)v93 + 28) = v34;
      if ( vorbis_bitrate_managed(vb) && *(_DWORD *)(*(_DWORD *)v35 + 28) )
      {
        _vp_offset_and_mix((float *)v83, 2, (vorbis_look_psy *)v88, v84, in, (float *)pcmend, logmdct);
        v36 = floor1_fit(a1, vb, *(vorbis_look_floor1 **)(backend_state[12] + 4 * *v32), logmdct, in);
        v66 = logmdct;
        v65 = (float *)pcmend;
        v64 = in;
        *(_DWORD *)(*(_DWORD *)v93 + 56) = v36;
        _vp_offset_and_mix((float *)v83, 0, (vorbis_look_psy *)v88, v84, v64, v65, v66);
        v37 = floor1_fit(a1, vb, *(vorbis_look_floor1 **)(backend_state[12] + 4 * *v32), logmdct, in);
        **(_DWORD **)v93 = v37;
        in = (float *)4;
        pcmend = (int)&_sbh_sizeHeaderList;
        do
        {
          v38 = floor1_interpolate_fit(
                  vb,
                  *(vorbis_look_floor1 **)(backend_state[12] + 4 * *v32),
                  **(char ***)v93,
                  *(char **)(*(_DWORD *)v93 + 28),
                  pcmend / 7);
          v39 = in;
          pcmend += (int)&_sbh_sizeHeaderList;
          v40 = *(char ***)v93;
          ++in;
          v12 = pcmend < (int)&loc_6FFFB + 5;
          *(char **)((char *)v40 + (_DWORD)v39) = v38;
        }
        while ( v12 );
        in = (float *)32;
        pcmend = (int)&_sbh_sizeHeaderList;
        do
        {
          v41 = floor1_interpolate_fit(
                  vb,
                  *(vorbis_look_floor1 **)(backend_state[12] + 4 * *v32),
                  *(char **)(*(_DWORD *)v93 + 28),
                  *(char **)(*(_DWORD *)v93 + 56),
                  pcmend / 7);
          v42 = in;
          pcmend += (int)&_sbh_sizeHeaderList;
          v43 = *(char ***)v93;
          ++in;
          v12 = pcmend < (int)&loc_6FFFB + 5;
          *(char **)((char *)v43 + (_DWORD)v42) = v41;
        }
        while ( v12 );
      }
      vbb = (vorbis_block *)((char *)vbb + 1);
      LODWORD(v77) += 4;
      v93 += 4;
      v11 = (vorbis_look_psy *)v88;
      if ( (int)vbb >= vi->channels )
        goto LABEL_28;
    }
    return -1;
  }
}
