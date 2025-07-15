unsigned int __cdecl vostok::network_core::udp_match_connection::time_in_ms(
        const unsigned __int8 message_type,
        vostok::network_core::buffer_reader reader,
        const bool skip_message_type_and_order)
{
  const unsigned __int8 *v3; // esi

  if ( message_type == 70 )
  {
    if ( !skip_message_type_and_order )
      ++reader.m_pointer;
    v3 = reader.m_pointer + 12;
    return *(_DWORD *)v3;
  }
  if ( message_type == 84 )
  {
    if ( !skip_message_type_and_order )
      ++reader.m_pointer;
    v3 = reader.m_pointer + 13;
    return *(_DWORD *)v3;
  }
  return -1;
}
