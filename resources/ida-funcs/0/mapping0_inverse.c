int __cdecl mapping0_inverse(vorbis_block *vb, int *l)
{
  vorbis_dsp_state *vd; // eax
  vorbis_info *vi; // edi
  _DWORD *codec_setup; // ecx
  int W; // eax
  int v7; // ecx
  int channels; // ebx
  void *v9; // esp
  void *v10; // esp
  void *v11; // esp
  void *v12; // esp
  bool v13; // cc
  int v15; // eax
  void *v16; // eax
  int *v17; // ecx
  bool v18; // zf
  float **pcm; // eax
  int *v20; // eax
  int *v21; // edx
  int *v22; // ecx
  int *v23; // eax
  BOOL v24; // edx
  int v25; // ecx
  int *v26; // eax
  float **v27; // edx
  float *v28; // edx
  float *v29; // edx
  float v30; // xmm0_4
  float *v31; // ecx
  float v32; // xmm1_4
  int i; // ebx
  unsigned int v35; // [esp-Ch] [ebp-48h]
  _BYTE v36[12]; // [esp+0h] [ebp-3Ch] BYREF
  int v37; // [esp+Ch] [ebp-30h]
  _BYTE *v38; // [esp+10h] [ebp-2Ch]
  int v39; // [esp+14h] [ebp-28h]
  float **v40; // [esp+18h] [ebp-24h]
  int *v41; // [esp+1Ch] [ebp-20h]
  int *v42; // [esp+20h] [ebp-1Ch]
  _DWORD *v43; // [esp+24h] [ebp-18h]
  unsigned int count; // [esp+28h] [ebp-14h]
  int v45; // [esp+2Ch] [ebp-10h]
  int *v46; // [esp+30h] [ebp-Ch]
  int *v47; // [esp+34h] [ebp-8h]
  _DWORD *backend_state; // [esp+38h] [ebp-4h]
  int v49; // [esp+44h] [ebp+8h]
  int v50; // [esp+44h] [ebp+8h]
  int v51; // [esp+44h] [ebp+8h]
  int v52; // [esp+44h] [ebp+8h]
  int v53; // [esp+44h] [ebp+8h]
  int *v54; // [esp+48h] [ebp+Ch]
  int v55; // [esp+48h] [ebp+Ch]
  int v56; // [esp+48h] [ebp+Ch]
  int *v57; // [esp+48h] [ebp+Ch]

  vd = vb->vd;
  vi = vd->vi;
  codec_setup = vi->codec_setup;
  backend_state = vd->backend_state;
  W = vb->W;
  v43 = codec_setup;
  v7 = codec_setup[W];
  vb->pcmend = v7;
  channels = vi->channels;
  v39 = v7;
  v9 = alloca(4 * channels);
  v40 = (float **)v36;
  v10 = alloca(4 * channels);
  v41 = (int *)v36;
  v11 = alloca(4 * channels);
  v46 = (int *)v36;
  v12 = alloca(4 * channels);
  v49 = 0;
  v13 = channels <= 0;
  v38 = v36;
  if ( !v13 )
  {
    v54 = l + 1;
    count = (unsigned int)(4 * v39) >> 1;
    v47 = v46;
    v42 = (int *)(v36 - (_BYTE *)v46);
    do
    {
      v15 = l[*v54 + 257];
      v16 = _floor_P[v43[v15 + 200]]->inverse1(vb, *(_DWORD *)(backend_state[12] + 4 * v15));
      v17 = v47;
      v35 = count;
      *(int *)((char *)v47 + (_DWORD)v42) = (int)v16;
      v18 = v16 == 0;
      pcm = vb->pcm;
      *v17 = !v18;
      memset((int)pcm[v49], 0, v35);
      ++v54;
      ++v47;
      ++v49;
    }
    while ( v49 < vi->channels );
  }
  if ( l[289] > 0 )
  {
    v20 = l + 546;
    v50 = l[289];
    while ( 1 )
    {
      v21 = v46;
      v22 = &v46[*(v20 - 256)];
      if ( *v22 )
        goto LABEL_9;
      if ( v46[*v20] )
        break;
LABEL_10:
      ++v20;
      if ( !--v50 )
        goto LABEL_11;
    }
    v22 = &v46[*(v20 - 256)];
LABEL_9:
    *v22 = 1;
    v21[*v20] = 1;
    goto LABEL_10;
  }
LABEL_11:
  v51 = 0;
  if ( *l > 0 )
  {
    count = (unsigned int)(l + 273);
    do
    {
      v13 = vi->channels <= 0;
      v45 = 0;
      v55 = 0;
      if ( !v13 )
      {
        v47 = l + 1;
        v42 = v41;
        v37 = (char *)v40 - (char *)v41;
        do
        {
          if ( *v47 == v51 )
          {
            v23 = v42;
            v24 = v46[v55] != 0;
            ++v45;
            *v42 = v24;
            *(int *)((char *)v23 + v37) = (int)vb->pcm[v55];
            v42 = v23 + 1;
          }
          ++v55;
          ++v47;
        }
        while ( v55 < vi->channels );
      }
      _residue_P[v43[*(_DWORD *)count + 328]]->inverse(
        vb,
        *(void **)(backend_state[13] + 4 * *(_DWORD *)count),
        v40,
        v41,
        v45);
      count += 4;
      ++v51;
    }
    while ( v51 < *l );
  }
  v25 = l[289] - 1;
  v52 = v25;
  if ( v25 >= 0 )
  {
    v56 = v39 / 2;
    v26 = &l[v25 + 546];
    do
    {
      v27 = vb->pcm;
      v37 = (int)vb->pcm[*(v26 - 256)];
      v28 = v27[*v26];
      if ( v56 > 0 )
      {
        count = (unsigned int)v28 - v37;
        v29 = (float *)v37;
        v39 = v56;
        do
        {
          v30 = *v29;
          v31 = (float *)((char *)v29 + count);
          v32 = *(float *)((char *)v29 + count);
          if ( *v29 <= 0.0 )
          {
            if ( v32 <= 0.0 )
            {
              *v31 = v30;
              *v29 = v30 - v32;
            }
            else
            {
              *v31 = v32 + v30;
            }
          }
          else if ( v32 <= 0.0 )
          {
            *v31 = v30;
            *v29 = v32 + v30;
          }
          else
          {
            *v31 = v30 - v32;
          }
          ++v29;
          --v39;
        }
        while ( v39 );
      }
      --v52;
      --v26;
    }
    while ( v52 >= 0 );
  }
  v53 = 0;
  if ( vi->channels > 0 )
  {
    v57 = l + 1;
    do
    {
      v37 = l[*v57 + 257];
      _floor_P[v43[v37 + 200]]->inverse2(
        vb,
        *(void **)(backend_state[12] + 4 * v37),
        *(void **)&v38[4 * v53],
        vb->pcm[v53]);
      ++v57;
      ++v53;
    }
    while ( v53 < vi->channels );
  }
  for ( i = 0; i < vi->channels; ++i )
    mdct_backward(*(mdct_lookup **)backend_state[vb->W + 3], vb->pcm[i], vb->pcm[i]);
  return 0;
}
