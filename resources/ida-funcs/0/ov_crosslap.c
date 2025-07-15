int __cdecl ov_crosslap(OggVorbis_File *vf1, OggVorbis_File *vf2)
{
  void *v3; // esp
  int v4; // eax
  int v5; // eax
  void *v6; // esp
  _DWORD v7[2]; // [esp+0h] [ebp-3Ch] BYREF
  float *w2; // [esp+Ch] [ebp-30h]
  int n2; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h]
  vorbis_info *v11; // [esp+18h] [ebp-24h]
  float **lappcm; // [esp+1Ch] [ebp-20h]
  int v13; // [esp+20h] [ebp-1Ch]
  int lapsize; // [esp+24h] [ebp-18h]
  float *w1; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  vorbis_info *vi; // [esp+30h] [ebp-Ch]
  int v18; // [esp+34h] [ebp-8h]
  float **pcm; // [esp+38h] [ebp-4h] BYREF

  if ( vf1 == vf2 )
    return 0;
  if ( vf1->ready_state < 2 )
    return -131;
  if ( vf2->ready_state < 2 )
    return -131;
  v13 = ov_initset(vf1);
  if ( v13 )
    return v13;
  v13 = ov_initprime(vf2);
  if ( v13 )
    return v13;
  vi = ov_info(vf1, -1);
  v11 = ov_info(vf2, -1);
  v18 = ov_halfrate_p(vf1);
  v10 = ov_halfrate_p(vf2);
  v3 = alloca(4 * vi->channels);
  v7[1] = v7;
  lappcm = (float **)v7;
  v4 = vorbis_info_blocksize(vi, 0);
  lapsize = v4 >> (v18 + 1);
  v5 = vorbis_info_blocksize(v11, 0);
  n2 = v5 >> (v10 + 1);
  w1 = (float *)vorbis_window(&vf1->vd, 0);
  w2 = (float *)vorbis_window(&vf2->vd, 0);
  for ( i = 0; i < vi->channels; ++i )
  {
    v6 = alloca(4 * lapsize);
    v7[0] = v7;
    lappcm[i] = (float *)v7;
  }
  ov_getlap(vf1, vi, &vf1->vd, lappcm, lapsize);
  vorbis_synthesis_lapout(&vf2->vd, &pcm);
  ov_splice(pcm, lappcm, lapsize, n2, vi->channels, v11->channels, w1, w2);
  return 0;
}
