void __thiscall vostok::network::match_client_impl::on_packet_received(
        vostok::network::match_client_impl *this,
        unsigned __int8 message_type,
        vostok::network_core::packet_reader *reader)
{
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  survarium::game_camera *v5; // [esp-4h] [ebp-2C0h]
  char v7; // [esp+290h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+294h] [ebp-28h] BYREF
  char v9; // [esp+2BBh] [ebp-1h]

  v7 = 0;
  v3 = *(survarium::game_camera **)&this->m_packets_storage.elems[0][(_DWORD)&loc_258B9D + 3];
  if ( message_type == 128 )
  {
    v9 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    if ( *v4 )
    {
      v5 = (survarium::game_camera *)vostok::network_core::packet_reader::eof(reader);
      survarium::weapon_user_dead_state::finalize(v5);
    }
    *(_DWORD *)&this->m_packets_storage.elems[0][(_DWORD)&loc_258B9D + 3] = 1;
    boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
      (boost::function<void __cdecl(unsigned int,unsigned int)> *)((char *)this + (_DWORD)&loc_258B7F + 1),
      (boost::function2<void,unsigned int,unsigned int> *)((char *)this + (_DWORD)&loc_25856F + 1));
    if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)Scaleform::Render::TreeNode::NodeData::operator= + (_DWORD)this)) )
      boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>::operator()(
        (boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum> *)((char *)Scaleform::Render::TreeNode::NodeData::operator= + (_DWORD)this),
        0,
        successfully_handshaked,
        host_cannot_be_resolved,
        connection_successful);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3);
      v7 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\match_client_impl.cpp",
        0x38u,
        "void __thiscall vostok::network::match_client_impl::on_packet_received(unsigned char,class vostok::network_core:"
        ":packet_reader &)",
        "network:",
        error,
        "connection forbidden");
    }
    if ( (v7 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v3,
        (int *)&log_callback);
    if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)Scaleform::Render::TreeNode::NodeData::operator= + (_DWORD)this))
        ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
        : 0) != 0 )
      boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>::operator()(
        (boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum> *)((char *)Scaleform::Render::TreeNode::NodeData::operator= + (_DWORD)this),
        0,
        successfully_handshaked,
        host_cannot_be_resolved,
        invalid_session_id);
  }
}
