int __usercall os_body_expand@<eax>(ogg_stream_state *os@<esi>, int needed)
{
  int body_storage; // eax
  vostok::memory::doug_lea_mt_allocator *v3; // ecx
  unsigned __int8 *body_data; // ebx
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  vostok::memory *v8; // [esp+0h] [ebp-10h]

  body_storage = os->body_storage;
  v3 = (vostok::memory::doug_lea_mt_allocator *)(needed + os->body_fill);
  if ( body_storage <= (int)v3 )
  {
    body_data = os->body_data;
    v5 = body_storage + needed + 1024;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v8);
    v6 = (unsigned __int8 *)vostok::memory::doug_lea_mt_allocator::realloc_impl(v3, body_data, v5);
    if ( !v6 )
    {
      ogg_stream_clear(os);
      return -1;
    }
    os->body_storage += needed + 1024;
    os->body_data = v6;
  }
  return 0;
}
