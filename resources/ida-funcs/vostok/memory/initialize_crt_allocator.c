void __cdecl vostok::memory::initialize_crt_allocator()
{
  if ( !vostok::memory::g_crt_allocator )
  {
    vostok::debug::preinitialize();
    vostok::core::logging_preinitialize();
    if ( !vostok::memory::g_crt_allocator )
    {
      if ( _InterlockedExchange(&s_crt_allocator_creation, 1) )
      {
        while ( !vostok::memory::g_crt_allocator )
          ;
      }
      else
      {
        vostok::memory::inplace_constructor::operator()((vostok::memory::inplace_constructor *)&s_crt_allocator_creation);
        _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
      }
    }
  }
}
