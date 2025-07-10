void __thiscall survarium::network_client::on_match_disconnected(
        survarium::network_client *this,
        vostok::network_core::disconnect_event_types_enum disconnect_event_type)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(unsigned int,unsigned int)> v4; // [esp+8h] [ebp-20h] BYREF

  v4.vtable = 0;
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    &v4,
    (boost::function2<void,unsigned int,unsigned int> *)&this->m_match_client.m_client.m_on_disconnected);
  if ( v4.vtable )
  {
    if ( ((int)v4.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v4.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&v4.functor, &v4.functor, 2);
    }
  }
  if ( disconnect_event_type )
  {
    if ( disconnect_event_type > disconnected_by_timeout && disconnect_event_type <= disconnected_by_initiator )
      this->close_current_match(this, 1);
  }
  else
  {
    this->close_current_match(this, 0);
  }
}
