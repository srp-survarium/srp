int __cdecl vorbis_synthesis_lapout(vorbis_dsp_state *v, float ***pcm)
{
  vorbis_dsp_state *v2; // ebx
  vorbis_info *v3; // esi
  int *codec_setup; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ebp
  int v8; // edx
  int v10; // ecx
  float *v11; // edi
  int v12; // edx
  unsigned int v13; // esi
  float *v14; // ecx
  float *v15; // eax
  float *v16; // eax
  double v17; // st7
  int lW; // eax
  int v19; // esi
  int v20; // edx
  float *v21; // edi
  int v22; // ecx
  float *v23; // eax
  unsigned int v24; // esi
  float *v25; // edx
  float *v26; // eax
  int v27; // edi
  float *v28; // eax
  int v29; // eax
  int v30; // eax
  float *v31; // edi
  char *v32; // ebp
  int v33; // ecx
  float *v34; // eax
  unsigned int v35; // esi
  float *v36; // edx
  float *v37; // eax
  char *v38; // edi
  int i; // eax
  float db; // [esp+10h] [ebp-20h]
  float dc; // [esp+10h] [ebp-20h]
  float dd; // [esp+10h] [ebp-20h]
  float de; // [esp+10h] [ebp-20h]
  float df; // [esp+10h] [ebp-20h]
  float *d; // [esp+10h] [ebp-20h]
  float *da; // [esp+10h] [ebp-20h]
  int j; // [esp+14h] [ebp-1Ch]
  int ja; // [esp+14h] [ebp-1Ch]
  int jb; // [esp+14h] [ebp-1Ch]
  vorbis_info *vi; // [esp+18h] [ebp-18h]
  int n0; // [esp+1Ch] [ebp-14h]
  int v52; // [esp+20h] [ebp-10h]
  char *v53; // [esp+20h] [ebp-10h]
  int n1; // [esp+24h] [ebp-Ch]
  int v55; // [esp+28h] [ebp-8h]
  int n; // [esp+2Ch] [ebp-4h]

  v2 = v;
  v3 = v->vi;
  codec_setup = (int *)v3->codec_setup;
  v5 = codec_setup[914] + 1;
  v6 = *codec_setup >> v5;
  v7 = codec_setup[1] >> v5;
  n = codec_setup[v->W] >> v5;
  v8 = 0;
  vi = v3;
  n0 = v6;
  n1 = v7;
  if ( v->pcm_returned < 0 )
    return 0;
  if ( v->centerW == v7 )
  {
    v10 = 0;
    j = 0;
    if ( v3->channels > 0 )
    {
      do
      {
        v11 = v->pcm[v10];
        v12 = 0;
        if ( v7 >= 4 )
        {
          v13 = ((unsigned int)(v7 - 4) >> 2) + 1;
          v14 = v11 + 2;
          v15 = &v11[v7];
          v12 = 4 * v13;
          do
          {
            v15 += 4;
            db = *(v14 - 2);
            v14 += 4;
            --v13;
            *(v14 - 6) = *(v15 - 4);
            *(v15 - 4) = db;
            dc = *(v14 - 5);
            *(v14 - 5) = *(v15 - 3);
            *(v15 - 3) = dc;
            dd = *(v14 - 4);
            *(v14 - 4) = *(v15 - 2);
            *(v15 - 2) = dd;
            de = *(v14 - 3);
            *(v14 - 3) = *(v15 - 1);
            *(v15 - 1) = de;
          }
          while ( v13 );
          v10 = j;
        }
        if ( v12 < v7 )
        {
          v16 = &v11[v12 + v7];
          do
          {
            v17 = v11[v12++];
            df = v17;
            v11[v12 - 1] = *v16++;
            *(v16 - 1) = df;
          }
          while ( v12 < v7 );
        }
        j = ++v10;
      }
      while ( v10 < vi->channels );
      v6 = n0;
      v3 = vi;
    }
    v->pcm_current -= v7;
    v->pcm_returned -= v7;
    v8 = 0;
    v->centerW = 0;
  }
  lW = v->lW;
  if ( (lW ^ v->W) == 1 )
  {
    ja = 0;
    if ( v3->channels > 0 )
    {
      v19 = 4 * ((v7 - v6) / 2);
      v20 = (v6 + v7) / 2 - 1;
      v52 = v19;
      v55 = v20;
      do
      {
        v21 = v2->pcm[ja];
        v22 = v20;
        v23 = (float *)((char *)v21 + v19);
        d = (float *)((char *)v21 + v19);
        if ( v20 >= 0 )
        {
          if ( v20 + 1 >= 4 )
          {
            v24 = (unsigned int)(v20 + 1) >> 2;
            v25 = &v21[v20 - 3];
            v26 = &v23[v22 - 1];
            v22 -= 4 * v24;
            do
            {
              v26 -= 4;
              v26[5] = v25[3];
              v25 -= 4;
              --v24;
              v26[4] = *(float *)((char *)v26 + (char *)v21 - (char *)d + 16);
              v26[3] = v25[5];
              v26[2] = v25[4];
            }
            while ( v24 );
            v2 = v;
            v20 = v55;
            v7 = n1;
            v23 = d;
          }
          if ( v22 >= 0 )
          {
            v27 = (char *)v21 - (char *)d;
            v28 = &v23[v22];
            do
            {
              --v22;
              *v28 = *(float *)((char *)v28 + v27);
              --v28;
            }
            while ( v22 >= 0 );
          }
          v19 = v52;
        }
        ++ja;
      }
      while ( ja < vi->channels );
      v6 = n0;
      v3 = vi;
    }
    v29 = (v7 - v6) / 2;
    v2->pcm_returned += v29;
LABEL_45:
    v2->pcm_current += v29;
    goto LABEL_46;
  }
  if ( !lW )
  {
    jb = 0;
    if ( v3->channels > 0 )
    {
      v30 = 4 * (v7 - v6);
      da = (float *)v30;
      do
      {
        v31 = v2->pcm[v8];
        v32 = (char *)v31 + v30;
        v53 = (char *)v31 + v30;
        v33 = n0 - 1;
        if ( n0 - 1 >= 0 )
        {
          if ( n0 >= 4 )
          {
            v34 = (float *)&v32[4 * v33 - 4];
            v35 = (unsigned int)n0 >> 2;
            v36 = &v31[v33 - 3];
            v33 -= 4 * ((unsigned int)n0 >> 2);
            do
            {
              v34 -= 4;
              v34[5] = v36[3];
              v36 -= 4;
              --v35;
              v34[4] = *(float *)((char *)v34 + (char *)v31 - v32 + 16);
              v34[3] = v36[5];
              v34[2] = v36[4];
            }
            while ( v35 );
            v32 = v53;
            v8 = jb;
            v2 = v;
            v30 = (int)da;
          }
          if ( v33 >= 0 )
          {
            v37 = (float *)&v32[4 * v33];
            v38 = (char *)((char *)v31 - v32);
            do
            {
              --v33;
              *v37 = *(float *)&v38[(_DWORD)v37];
              --v37;
            }
            while ( v33 >= 0 );
            v30 = (int)da;
          }
        }
        jb = ++v8;
      }
      while ( v8 < vi->channels );
      v7 = n1;
      v6 = n0;
      v3 = vi;
    }
    v2->pcm_returned += v7 - v6;
    v29 = v7 - v6;
    goto LABEL_45;
  }
LABEL_46:
  if ( pcm )
  {
    for ( i = 0; i < v3->channels; ++i )
      v2->pcmret[i] = &v2->pcm[i][v2->pcm_returned];
    *pcm = v2->pcmret;
  }
  return n + v7 - v2->pcm_returned;
}
