int __usercall ogg_sync_clear@<eax>(
        vostok::memory::doug_lea_mt_allocator *a1@<ecx>,
        vostok::memory *a2@<edi>,
        ogg_sync_state *oy)
{
  unsigned __int8 *data; // edi

  if ( oy )
  {
    data = oy->data;
    if ( oy->data )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(a2);
      vostok::memory::doug_lea_mt_allocator::free_impl(a1, data);
    }
    *(_QWORD *)&oy->data = 0;
    *(_QWORD *)&oy->fill = 0;
    *(_QWORD *)&oy->unsynced = 0;
    oy->bodybytes = 0;
  }
  return 0;
}
