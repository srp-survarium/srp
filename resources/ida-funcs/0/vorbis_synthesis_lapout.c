int __cdecl vorbis_synthesis_lapout(vorbis_dsp_state *v, float ***pcm)
{
  vorbis_info *vi; // edx
  int *codec_setup; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // edi
  int result; // eax
  int v9; // edi
  float *v10; // ecx
  float *v11; // eax
  int v12; // edx
  float *v13; // edx
  float v14; // xmm0_4
  int lW; // eax
  float *v16; // ecx
  int v17; // eax
  float *v18; // ecx
  int v19; // eax
  float *v20; // ecx
  int v21; // [esp+Ch] [ebp-14h]
  int v22; // [esp+10h] [ebp-10h]
  unsigned int v23; // [esp+10h] [ebp-10h]
  int v24; // [esp+14h] [ebp-Ch]
  vorbis_info *v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp-4h]
  int v27; // [esp+1Ch] [ebp-4h]
  int v28; // [esp+1Ch] [ebp-4h]
  int i; // [esp+28h] [ebp+8h]
  int v30; // [esp+28h] [ebp+8h]
  int j; // [esp+28h] [ebp+8h]
  int k; // [esp+28h] [ebp+8h]

  vi = v->vi;
  codec_setup = (int *)vi->codec_setup;
  v5 = codec_setup[914] + 1;
  v6 = *codec_setup >> v5;
  v25 = vi;
  v21 = codec_setup[v->W] >> v5;
  v7 = codec_setup[1];
  result = 0;
  v9 = v7 >> v5;
  if ( v->pcm_returned < 0 )
    return result;
  if ( v->centerW == v9 )
  {
    for ( i = 0; i < vi->channels; ++i )
    {
      v26 = 0;
      v10 = v->pcm[i];
      if ( v9 > 0 )
      {
        v11 = &v10[v9];
        do
        {
          v12 = v26++;
          v13 = &v10[v12];
          v14 = *v13;
          *v13 = *v11;
          *v11++ = v14;
        }
        while ( v26 < v9 );
        vi = v25;
      }
    }
    v->pcm_current -= v9;
    v->pcm_returned -= v9;
    v->centerW = 0;
  }
  lW = v->lW;
  if ( (lW ^ v->W) == 1 )
  {
    v30 = 0;
    if ( vi->channels > 0 )
    {
      v24 = 4 * ((v9 - v6) / 2);
      v22 = (v9 + v6) / 2 - 1;
      do
      {
        v27 = (v9 + v6) / 2 - 1;
        if ( v22 >= 0 )
        {
          v16 = &v->pcm[v30][v24 / 4u + v22];
          do
          {
            --v27;
            *v16 = v16[v24 / 0xFFFFFFFC];
            --v16;
          }
          while ( v27 >= 0 );
        }
        ++v30;
      }
      while ( v30 < v25->channels );
    }
    vi = v25;
    v17 = (v9 - v6) / 2;
    v->pcm_returned += v17;
LABEL_26:
    v->pcm_current += v17;
    goto LABEL_27;
  }
  if ( !lW )
  {
    for ( j = 0; j < vi->channels; ++j )
    {
      v23 = 4 * (v9 - v6);
      v28 = v6 - 1;
      if ( v6 - 1 >= 0 )
      {
        v18 = &v->pcm[j][v23 / 4 - 1 + v6];
        do
        {
          --v28;
          *v18 = v18[v23 / 0xFFFFFFFC];
          --v18;
        }
        while ( v28 >= 0 );
        vi = v25;
      }
    }
    v->pcm_returned += v9 - v6;
    v17 = v9 - v6;
    goto LABEL_26;
  }
LABEL_27:
  if ( pcm )
  {
    for ( k = 0; k < vi->channels; v->pcmret[v19] = &v20[v->pcm_returned] )
    {
      v19 = k;
      v20 = v->pcm[k++];
    }
    *pcm = v->pcmret;
  }
  return v21 + v9 - v->pcm_returned;
}
