int __cdecl vorbis_synthesis_blockin(vorbis_dsp_state *v, vorbis_block *vb)
{
  _DWORD *backend_state; // ecx
  int *codec_setup; // eax
  int pcm_returned; // edx
  int W; // edx
  unsigned int sequence; // ebx
  unsigned int sequence_high; // edx
  int v11; // ebx
  __int64 res_bits; // rax
  bool v13; // cf
  int v14; // eax
  int v15; // ecx
  float *v16; // eax
  int v17; // edx
  float v18; // xmm1_4
  bool v19; // zf
  float *v20; // eax
  int v21; // edx
  float *v22; // eax
  float v23; // xmm1_4
  int v24; // edx
  float *v25; // eax
  int v26; // edx
  int v27; // ecx
  float v28; // xmm1_4
  float *v29; // ecx
  int v30; // eax
  char *v31; // eax
  int v32; // edx
  float *v33; // eax
  float v34; // xmm1_4
  __int64 v35; // rax
  __int64 v36; // rax
  unsigned int granulepos_high; // edx
  int v38; // eax
  int pcm_current; // eax
  __int64 v40; // rax
  unsigned int granulepos; // eax
  int v42; // ecx
  unsigned int v43; // ebx
  int v44; // edx
  int v45; // eax
  int v46; // [esp+Ch] [ebp-3Ch]
  float *v47; // [esp+Ch] [ebp-3Ch]
  int v48; // [esp+Ch] [ebp-3Ch]
  int v49; // [esp+10h] [ebp-38h]
  vorbis_info *vi; // [esp+14h] [ebp-34h]
  const float *v51; // [esp+18h] [ebp-30h]
  int i; // [esp+18h] [ebp-30h]
  float *v53; // [esp+18h] [ebp-30h]
  int v54; // [esp+18h] [ebp-30h]
  float *v55; // [esp+18h] [ebp-30h]
  float *v56; // [esp+18h] [ebp-30h]
  const float *v57; // [esp+18h] [ebp-30h]
  int v58; // [esp+18h] [ebp-30h]
  char *v59; // [esp+1Ch] [ebp-2Ch]
  const float *v60; // [esp+1Ch] [ebp-2Ch]
  int v61; // [esp+1Ch] [ebp-2Ch]
  int v62; // [esp+1Ch] [ebp-2Ch]
  int v63; // [esp+20h] [ebp-28h]
  int v64; // [esp+24h] [ebp-24h]
  int v65; // [esp+28h] [ebp-20h]
  const float *v66; // [esp+28h] [ebp-20h]
  int v67; // [esp+28h] [ebp-20h]
  int v68; // [esp+28h] [ebp-20h]
  char *v69; // [esp+28h] [ebp-20h]
  float *v70; // [esp+2Ch] [ebp-1Ch]
  float *v71; // [esp+2Ch] [ebp-1Ch]
  float *v72; // [esp+30h] [ebp-18h]
  int v73; // [esp+30h] [ebp-18h]
  float *v74; // [esp+30h] [ebp-18h]
  float *v75; // [esp+30h] [ebp-18h]
  float *v76; // [esp+34h] [ebp-14h]
  float *v77; // [esp+34h] [ebp-14h]
  int v78; // [esp+34h] [ebp-14h]
  int v79; // [esp+38h] [ebp-10h]
  float *v80; // [esp+38h] [ebp-10h]
  int *v81; // [esp+3Ch] [ebp-Ch]
  _DWORD *v82; // [esp+40h] [ebp-8h]
  int v83; // [esp+44h] [ebp-4h]
  int v84; // [esp+50h] [ebp+8h]
  int v85; // [esp+54h] [ebp+Ch]

  backend_state = v->backend_state;
  vi = v->vi;
  codec_setup = (int *)vi->codec_setup;
  v81 = codec_setup;
  v82 = backend_state;
  v84 = codec_setup[914];
  if ( !vb )
    return -131;
  pcm_returned = v->pcm_returned;
  if ( v->pcm_current > pcm_returned && pcm_returned != -1 )
    return -131;
  v->lW = v->W;
  W = vb->W;
  v->nW = -1;
  sequence = v->sequence;
  v->W = W;
  sequence_high = HIDWORD(v->sequence);
  if ( (sequence_high & sequence) == 0xFFFFFFFF || __PAIR64__(sequence_high, sequence) + 1 != vb->sequence )
  {
    LODWORD(v->granulepos) = -1;
    HIDWORD(v->granulepos) = -1;
    backend_state[32] = -1;
    backend_state[33] = -1;
  }
  v->sequence = vb->sequence;
  if ( vb->pcm )
  {
    v11 = *codec_setup >> (v84 + 1);
    v85 = codec_setup[1] >> (v84 + 1);
    v64 = codec_setup[v->W] >> (v84 + 1);
    v->glue_bits += vb->glue_bits;
    v->time_bits += vb->time_bits;
    v->floor_bits += vb->floor_bits;
    res_bits = vb->res_bits;
    v13 = __CFADD__((_DWORD)res_bits, v->res_bits);
    LODWORD(v->res_bits) += res_bits;
    v14 = v85;
    HIDWORD(v->res_bits) += HIDWORD(res_bits) + v13;
    v15 = 0;
    if ( v->centerW )
    {
      v63 = v85;
      v14 = 0;
    }
    else
    {
      v63 = 0;
    }
    v83 = v14;
    v79 = 0;
    if ( vi->channels > 0 )
    {
      do
      {
        if ( v->lW )
        {
          if ( v->W )
          {
            v51 = vwin[v82[2] - v84];
            v16 = &v->pcm[v15][v14];
            if ( v85 > 0 )
            {
              v76 = v16;
              v72 = (float *)&v51[v85 - 1];
              v59 = (char *)((char *)vb->pcm[v15] - (char *)v51);
              v17 = (char *)v51 - (char *)v16;
              v65 = v85;
              for ( i = (char *)v51 - (char *)v16; ; v17 = i )
              {
                v18 = *v76 * *v72--;
                *v76 = (float)(*(float *)&v59[(_DWORD)v16 + v17] * *(float *)((char *)v16 + v17)) + v18;
                v16 = v76 + 1;
                v19 = v65-- == 1;
                ++v76;
                if ( v19 )
                  break;
              }
            }
          }
          else
          {
            v66 = vwin[v82[1] - v84];
            v15 = v79;
            v20 = vb->pcm[v79];
            v53 = &v->pcm[v79][v83 + v85 / 2 - v11 / 2];
            if ( v11 > 0 )
            {
              v80 = &v->pcm[v79][v83 + v85 / 2 - v11 / 2];
              v77 = (float *)&v66[v11 - 1];
              v73 = (char *)v20 - (char *)v66;
              v21 = (char *)v66 - (char *)v53;
              v22 = v80;
              v54 = (char *)v66 - (char *)v53;
              v67 = v11;
              while ( 1 )
              {
                v23 = *v77-- * *v80;
                *v80 = (float)(*(float *)((char *)v22 + v21 + v73) * *(float *)((char *)v22 + v21)) + v23;
                v22 = v80 + 1;
                v19 = v67-- == 1;
                ++v80;
                if ( v19 )
                  break;
                v21 = v54;
              }
            }
          }
        }
        else
        {
          v24 = v82[1];
          if ( v->W )
          {
            v68 = 0;
            v60 = vwin[v24 - v84];
            v74 = &v->pcm[v15][v14];
            v78 = v85 / 2;
            v46 = v11 / 2;
            v55 = &vb->pcm[v15][v85 / 2 - v11 / 2];
            if ( v11 > 0 )
            {
              v25 = &v->pcm[v15][v14];
              v70 = (float *)&v60[v11 - 1];
              v26 = (char *)v55 - (char *)v60;
              v27 = (char *)v60 - (char *)v74;
              v49 = (char *)v60 - (char *)v74;
              v61 = v11;
              v68 = v11;
              while ( 1 )
              {
                v28 = *v70-- * *v25;
                *v25 = (float)(*(float *)((char *)v25 + v27 + v26) * *(float *)((char *)v25 + v27)) + v28;
                ++v25;
                if ( !--v61 )
                  break;
                v27 = v49;
              }
            }
            if ( v68 < v78 + v46 )
            {
              v29 = &v74[v68];
              v30 = v78 + v46 - v68;
              do
              {
                *v29 = *(float *)((char *)v29 + (char *)v55 - (char *)v74);
                ++v29;
                --v30;
              }
              while ( v30 );
            }
            v15 = v79;
          }
          else
          {
            v57 = vwin[v24 - v84];
            v47 = &v->pcm[v15][v14];
            if ( v11 > 0 )
            {
              v75 = &v->pcm[v15][v14];
              v71 = (float *)&v57[v11 - 1];
              v69 = (char *)((char *)vb->pcm[v15] - (char *)v57);
              v32 = (char *)v57 - (char *)v47;
              v33 = v75;
              v48 = (char *)v57 - (char *)v47;
              v58 = v11;
              while ( 1 )
              {
                v34 = *v71-- * *v75;
                *v75 = (float)(*(float *)&v69[(_DWORD)v33 + v32] * *(float *)((char *)v33 + v32)) + v34;
                v33 = v75 + 1;
                v19 = v58-- == 1;
                ++v75;
                if ( v19 )
                  break;
                v32 = v48;
              }
            }
          }
        }
        if ( v64 > 0 )
        {
          v56 = &v->pcm[v15][v63];
          v31 = (char *)((char *)&vb->pcm[v15][v64] - (char *)v56);
          v62 = v64;
          do
          {
            *v56 = *(float *)((char *)v56 + (_DWORD)v31);
            v19 = v62-- == 1;
            ++v56;
          }
          while ( !v19 );
        }
        ++v15;
        v14 = v83;
        v79 = v15;
      }
      while ( v15 < vi->channels );
    }
    v19 = v->pcm_returned == -1;
    v->centerW = v->centerW == 0 ? v85 : 0;
    if ( v19 )
    {
      v->pcm_returned = v63;
      v->pcm_current = v63;
    }
    else
    {
      v->pcm_returned = v14;
      v35 = v81[v->lW];
      v->pcm_current = v83 + ((v81[v->W] / 4 + (((BYTE4(v35) & 3) + (int)v35) >> 2)) >> v84);
    }
    codec_setup = v81;
    backend_state = v82;
  }
  if ( (backend_state[33] & backend_state[32]) == -1 )
  {
    backend_state[32] = 0;
    backend_state[33] = 0;
  }
  else
  {
    v36 = codec_setup[v->lW];
    *((_QWORD *)backend_state + 16) += (((BYTE4(v36) & 3) + (int)v36) >> 2) + v81[v->W] / 4;
    codec_setup = v81;
  }
  if ( (HIDWORD(v->granulepos) & v->granulepos) == -1 )
  {
    granulepos_high = HIDWORD(vb->granulepos);
    if ( (granulepos_high & vb->granulepos) != 0xFFFFFFFF )
    {
      LODWORD(v->granulepos) = vb->granulepos;
      HIDWORD(v->granulepos) = granulepos_high;
      if ( *((_QWORD *)backend_state + 16) > __SPAIR64__(granulepos_high, v->granulepos) )
      {
        v38 = backend_state[32] - LODWORD(vb->granulepos);
        if ( v38 < 0 )
          v38 = 0;
        if ( vb->eofflag )
        {
          if ( v38 > (v->pcm_current - v->pcm_returned) << v84 )
            v38 = (v->pcm_current - v->pcm_returned) << v84;
          v->pcm_current -= v38 >> v84;
        }
        else
        {
          v->pcm_returned += v38 >> v84;
          pcm_current = v->pcm_current;
          if ( v->pcm_returned > pcm_current )
            v->pcm_returned = pcm_current;
        }
      }
    }
  }
  else
  {
    v40 = codec_setup[v->lW];
    v->granulepos += (((BYTE4(v40) & 3) + (int)v40) >> 2) + v81[v->W] / 4;
    granulepos = vb->granulepos;
    v42 = HIDWORD(vb->granulepos);
    if ( (v42 & granulepos) != 0xFFFFFFFF )
    {
      v43 = v->granulepos;
      v44 = HIDWORD(v->granulepos);
      if ( v43 != granulepos || v44 != v42 )
      {
        if ( v44 >= v42 && (v44 > v42 || v43 > granulepos) )
        {
          v45 = LODWORD(v->granulepos) - LODWORD(vb->granulepos);
          if ( v45 )
          {
            if ( vb->eofflag )
            {
              if ( v45 > (v->pcm_current - v->pcm_returned) << v84 )
                v45 = (v->pcm_current - v->pcm_returned) << v84;
              if ( v45 < 0 )
                v45 = 0;
              v->pcm_current -= v45 >> v84;
            }
          }
        }
        LODWORD(v->granulepos) = vb->granulepos;
        HIDWORD(v->granulepos) = HIDWORD(vb->granulepos);
      }
    }
  }
  if ( vb->eofflag )
    v->eofflag = 1;
  return 0;
}
