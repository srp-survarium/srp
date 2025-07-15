boost::asio::mutable_buffers_1 *__cdecl vostok::network_core::buffer_to_receive_into(
        boost::asio::mutable_buffers_1 *result,
        vostok::network_core::tcp_packet *packet)
{
  survarium::game_camera *v2; // ecx
  boost::asio::mutable_buffers_1 v4; // [esp+4h] [ebp-10h]

  survarium::weapon_user_dead_state::finalize(v2);
  v4.data_ = packet->m_buffer;
  v4.size_ = (unsigned int)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                             (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)packet,
                             (int)packet);
  *result = v4;
  return result;
}
