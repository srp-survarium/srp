boost::asio::const_buffers_1 *__cdecl vostok::network_core::buffer_to_send(
        boost::asio::const_buffers_1 *result,
        vostok::network_core::tcp_packet *packet)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  unsigned __int8 *buffer; // [esp+1Ch] [ebp-8h]
  survarium::base_project::resolve_link_object *buffer_size; // [esp+20h] [ebp-4h]

  buffer_size = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                  v2,
                  (int)packet);
  buffer = packet->m_buffer;
  if ( buffer_size )
  {
    if ( (unsigned int)buffer_size >= 0x100 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)packet->m_buffer);
      *(buffer - 3) = 0;
      *((_WORD *)buffer - 1) = (_WORD)buffer_size;
      result->data_ = buffer - 3;
      result->size_ = (unsigned int)&buffer_size->config.data.max_storage + 3;
    }
    else
    {
      *(buffer - 1) = (unsigned __int8)buffer_size;
      result->data_ = buffer - 1;
      result->size_ = (unsigned int)&buffer_size->config.data.pointer + 1;
    }
    return result;
  }
  else
  {
    result->data_ = 0;
    result->size_ = 0;
    return result;
  }
}
