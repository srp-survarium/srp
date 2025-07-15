int __cdecl ov_d_seek_lap(OggVorbis_File *vf, long double pos, int (__cdecl *localseek)(OggVorbis_File *, long double))
{
  void *v4; // esp
  void *v5; // esp
  int v6; // eax
  _DWORD v7[2]; // [esp+8h] [ebp-3Ch] BYREF
  float *w2; // [esp+14h] [ebp-30h]
  int n2; // [esp+18h] [ebp-2Ch]
  int ch2; // [esp+1Ch] [ebp-28h]
  int ch1; // [esp+20h] [ebp-24h]
  float **lappcm; // [esp+24h] [ebp-20h]
  int ret; // [esp+28h] [ebp-1Ch]
  int n1; // [esp+2Ch] [ebp-18h]
  float *w1; // [esp+30h] [ebp-14h]
  vorbis_info *vi; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  int hs; // [esp+3Ch] [ebp-8h]
  float **pcm; // [esp+40h] [ebp-4h] BYREF

  if ( vf->ready_state < 2 )
    return -131;
  ret = ov_initset(vf);
  if ( ret )
    return ret;
  vi = ov_info(vf, -1);
  hs = ov_halfrate_p(vf);
  ch1 = vi->channels;
  n1 = vorbis_info_blocksize(vi, 0) >> (hs + 1);
  w1 = vorbis_window(&vf->vd, 0);
  v4 = alloca(4 * ch1);
  v7[1] = v7;
  lappcm = (float **)v7;
  for ( i = 0; i < ch1; ++i )
  {
    v5 = alloca(4 * n1);
    v7[0] = v7;
    lappcm[i] = (float *)v7;
  }
  ov_getlap(vf, vi, &vf->vd, lappcm, n1);
  ret = ((int (__cdecl *)(OggVorbis_File *, _DWORD, _DWORD))localseek)(vf, LODWORD(pos), HIDWORD(pos));
  if ( ret )
    return ret;
  ret = ov_initprime(vf);
  if ( ret )
    return ret;
  vi = ov_info(vf, -1);
  ch2 = vi->channels;
  v6 = vorbis_info_blocksize(vi, 0);
  n2 = v6 >> (hs + 1);
  w2 = vorbis_window(&vf->vd, 0);
  vorbis_synthesis_lapout(&vf->vd, &pcm);
  ov_splice(pcm, lappcm, n1, n2, ch1, ch2, w1, w2);
  return 0;
}
