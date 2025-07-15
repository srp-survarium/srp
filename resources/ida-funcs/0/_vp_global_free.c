void __usercall _vp_global_free(vorbis_look_psy_global *look@<esi>, vostok::memory *a2@<ecx>)
{
  if ( look )
  {
    look->ampmax = 0.0;
    look->channels = 0;
    look->gi = 0;
    *(_QWORD *)&look->coupling_pointlimit[0][0] = 0;
    look->coupling_pointlimit[0][2] = 0;
    *(_QWORD *)&look->coupling_pointlimit[1][0] = 0;
    look->coupling_pointlimit[1][2] = 0;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(a2);
    vostok::memory::doug_lea_mt_allocator::free_impl((vostok::memory::doug_lea_mt_allocator *)a2, look);
  }
}
