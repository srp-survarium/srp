int __cdecl ov_crosslap(OggVorbis_File *vf1, OggVorbis_File *vf2)
{
  void *v3; // esp
  int v4; // eax
  int v5; // eax
  void *v6; // esp
  _DWORD v7[2]; // [esp+0h] [ebp-3Ch] BYREF
  float *w2; // [esp+Ch] [ebp-30h]
  int n2; // [esp+10h] [ebp-2Ch]
  int hs2; // [esp+14h] [ebp-28h]
  vorbis_info *vi2; // [esp+18h] [ebp-24h]
  float **lappcm; // [esp+1Ch] [ebp-20h]
  int ret; // [esp+20h] [ebp-1Ch]
  int n1; // [esp+24h] [ebp-18h]
  float *w1; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  vorbis_info *vi1; // [esp+30h] [ebp-Ch]
  int hs1; // [esp+34h] [ebp-8h]
  float **pcm; // [esp+38h] [ebp-4h] BYREF

  if ( vf1 == vf2 )
    return 0;
  if ( vf1->ready_state < 2 )
    return -131;
  if ( vf2->ready_state < 2 )
    return -131;
  ret = ov_initset(vf1);
  if ( ret )
    return ret;
  ret = ov_initprime(vf2);
  if ( ret )
    return ret;
  vi1 = ov_info(vf1, -1);
  vi2 = ov_info(vf2, -1);
  hs1 = ov_halfrate_p(vf1);
  hs2 = ov_halfrate_p(vf2);
  v3 = alloca(4 * vi1->channels);
  v7[1] = v7;
  lappcm = (float **)v7;
  v4 = vorbis_info_blocksize(vi1, 0);
  n1 = v4 >> (hs1 + 1);
  v5 = vorbis_info_blocksize(vi2, 0);
  n2 = v5 >> (hs2 + 1);
  w1 = vorbis_window(&vf1->vd, 0);
  w2 = vorbis_window(&vf2->vd, 0);
  for ( i = 0; i < vi1->channels; ++i )
  {
    v6 = alloca(4 * n1);
    v7[0] = v7;
    lappcm[i] = (float *)v7;
  }
  ov_getlap(vf1, vi1, &vf1->vd, lappcm, n1);
  vorbis_synthesis_lapout(&vf2->vd, &pcm);
  ov_splice(pcm, lappcm, n1, n2, vi1->channels, vi2->channels, w1, w2);
  return 0;
}
