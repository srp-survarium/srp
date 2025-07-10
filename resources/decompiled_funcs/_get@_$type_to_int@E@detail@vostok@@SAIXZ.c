int __cdecl vostok::detail::type_to_int<unsigned char>::get()
{
  if ( !vostok::detail::type_to_int<unsigned char>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<unsigned char>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<unsigned char>::s_id )
      vostok::detail::type_to_int<unsigned char>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                       - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<unsigned char>::s_lock, 0);
  }
  return vostok::detail::type_to_int<unsigned char>::s_id;
}
