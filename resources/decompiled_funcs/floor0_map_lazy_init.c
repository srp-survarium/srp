void __usercall floor0_map_lazy_init(vorbis_block *vb@<eax>, vorbis_look_floor0 *look@<edi>, int *infoX)
{
  int W; // ebp
  vostok::memory::doug_lea_mt_allocator *codec_setup; // ecx
  int v5; // esi
  int v6; // ebx
  double v7; // rt1
  int v8; // eax
  vostok::memory *v9; // [esp+8h] [ebp-30h]
  float n; // [esp+14h] [ebp-24h]
  int j; // [esp+18h] [ebp-20h]
  float ja; // [esp+18h] [ebp-20h]
  double jb; // [esp+18h] [ebp-20h]
  int *v14; // [esp+24h] [ebp-14h]
  double scalea; // [esp+28h] [ebp-10h]
  float scale; // [esp+28h] [ebp-10h]

  W = vb->W;
  if ( !look->linearmap[W] )
  {
    codec_setup = (vostok::memory::doug_lea_mt_allocator *)vb->vd->vi->codec_setup;
    v5 = *((_DWORD *)&codec_setup->__vftable + W) / 2;
    v14 = infoX + 1;
    scalea = 0.5 * (double)infoX[1];
    scale = (double)look->ln
          / (atan(scalea * 0.0007399999885819852) * 13.10000038146973
           + atan((double)infoX[1] * 0.5 * ((double)infoX[1] * 0.5) * 0.00000001849999975434002) * 2.240000009536743
           + scalea * 0.00009999999747378752);
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v9);
    v6 = 0;
    look->linearmap[W] = vostok::memory::doug_lea_mt_allocator::malloc_impl(
                           codec_setup,
                           (mutex_mt_raii *)vostok::memory::g_crt_allocator.__vftable,
                           4 * v5 + 4);
    j = 0;
    if ( v5 > 0 )
    {
      n = (float)v5;
      do
      {
        ja = (float)j;
        v7 = (double)*v14 * 0.5 / n * ja;
        jb = 0.5 * (double)*v14 / n * ja;
        v8 = (int)floor(
                    (atan(jb * 0.0007399999885819852) * 13.10000038146973
                   + atan(v7 * v7 * 0.00000001849999975434002) * 2.240000009536743
                   + jb * 0.00009999999747378752)
                  * scale);
        if ( v8 >= look->ln )
          v8 = look->ln - 1;
        look->linearmap[W][v6++] = v8;
        j = v6;
      }
      while ( v6 < v5 );
    }
    look->linearmap[W][v6] = -1;
    look->n[W] = v5;
  }
}
