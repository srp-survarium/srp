int __usercall ov_d_seek_lap@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        long double pos,
        int (__cdecl *localseek)(OggVorbis_File *, long double))
{
  void *v5; // esp
  void *v6; // esp
  int v7; // eax
  _DWORD v8[2]; // [esp+8h] [ebp-3Ch] BYREF
  float *w2; // [esp+14h] [ebp-30h]
  int n2; // [esp+18h] [ebp-2Ch]
  int ch2; // [esp+1Ch] [ebp-28h]
  int ch1; // [esp+20h] [ebp-24h]
  float **lappcm; // [esp+24h] [ebp-20h]
  int v14; // [esp+28h] [ebp-1Ch]
  int lapsize; // [esp+2Ch] [ebp-18h]
  float *w1; // [esp+30h] [ebp-14h]
  vorbis_info *vi; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  int v19; // [esp+3Ch] [ebp-8h]
  float **pcm; // [esp+40h] [ebp-4h] BYREF

  if ( vf->ready_state < 2 )
    return -131;
  v14 = ov_initset(a1, vf);
  if ( v14 )
    return v14;
  vi = ov_info(vf, -1);
  v19 = ov_halfrate_p(vf);
  ch1 = vi->channels;
  lapsize = vorbis_info_blocksize(vi, 0) >> (v19 + 1);
  w1 = (float *)vorbis_window(&vf->vd, 0);
  v5 = alloca(4 * ch1);
  v8[1] = v8;
  lappcm = (float **)v8;
  for ( i = 0; i < ch1; ++i )
  {
    v6 = alloca(4 * lapsize);
    v8[0] = v8;
    lappcm[i] = (float *)v8;
  }
  ov_getlap(a1, vf, vi, &vf->vd, lappcm, lapsize);
  v14 = ((int (__cdecl *)(OggVorbis_File *, _DWORD, _DWORD))localseek)(vf, LODWORD(pos), HIDWORD(pos));
  if ( v14 )
    return v14;
  v14 = ov_initprime(a1, vf);
  if ( v14 )
    return v14;
  vi = ov_info(vf, -1);
  ch2 = vi->channels;
  v7 = vorbis_info_blocksize(vi, 0);
  n2 = v7 >> (v19 + 1);
  w2 = (float *)vorbis_window(&vf->vd, 0);
  vorbis_synthesis_lapout(&vf->vd, &pcm);
  ov_splice(pcm, lappcm, lapsize, n2, ch1, ch2, w1, w2);
  return 0;
}
