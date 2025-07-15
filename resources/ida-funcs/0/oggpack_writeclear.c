void __usercall oggpack_writeclear(oggpack_buffer *b@<esi>, vostok::memory::doug_lea_mt_allocator *a2@<ecx>)
{
  unsigned __int8 *buffer; // edi
  vostok::memory *v3; // [esp+0h] [ebp-4h]

  buffer = b->buffer;
  if ( buffer )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v3);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, buffer);
  }
  *(_QWORD *)&b->endbyte = 0;
  *(_QWORD *)&b->buffer = 0;
  b->storage = 0;
}
