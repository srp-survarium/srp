void __thiscall vostok::network_core::udp_match_connection::handle_send(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *error_code,
        unsigned int bytes_transferred)
{
  survarium::game_camera *v4; // ecx
  survarium::base_project::resolve_link_object *v5; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  unsigned int v9; // [esp+38h] [ebp-A8h]
  vostok::network_core::udp_match_packet *v10; // [esp+3Ch] [ebp-A4h]
  char v11; // [esp+6Ch] [ebp-74h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+70h] [ebp-70h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+90h] [ebp-50h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v14; // [esp+B4h] [ebp-2Ch] BYREF
  vostok::network_core::base_packet v15; // [esp+CCh] [ebp-14h] BYREF
  char v16; // [esp+D7h] [ebp-9h]
  unsigned __int8 *buffer; // [esp+D8h] [ebp-8h]
  bool success; // [esp+DFh] [ebp-1h]

  v11 = 0;
  --this->m_pending_operations_count;
  success = vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
              (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_outgoing_packets,
              (vostok::ai::sensed_visual_object *)packet);
  v16 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( (*((_BYTE *)packet + 42) & 0x40) != 0 )
  {
    if ( this->m_state == connected
      || (v10 = packet,
          v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                 (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)((*((_BYTE *)packet + 42) & 0x40) != 0),
                 (int)packet),
          v9 = (unsigned int)v5 + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(v10),
          v15.m_buffer = packet->m_buffer.elems,
          v15.m_buffer_size = v9,
          vostok::network_core::udp_match_connection::is_low_level_packet(&v15)) )
    {
      buffer = packet->m_buffer.elems;
      packet->m_buffer.elems[0] = (*(_WORD *)&packet->m_buffer.elems[4] & 1) != 0;
      vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_unacknowledged_packets,
        (survarium::game_camera *)packet,
        0);
    }
    else
    {
      vostok::network_core::delete_udp_match_packet(
        this->m_packets_allocator,
        (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
    }
  }
  else
  {
    vostok::network_core::delete_udp_match_packet(
      this->m_packets_allocator,
      (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
  }
  v6 = error_code;
  if ( (error_code->vtable != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 vostok::core::g_log_filter_tree,
                                 "network_core:",
                                 error),
          (v6 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)has_passed_filters) != 0) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
      v11 = 3;
      (*((void (__thiscall **)(boost::detail::function::vtable_base *, stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *, boost::detail::function::vtable_base *))(&error_code->vtable)[1]->manager
       + 2))(
        (&error_code->vtable)[1],
        &v14,
        error_code->vtable);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[348],
        0x77u,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[172],
        "network_core:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[416],
        v14._M_start_of_storage._M_data);
    }
    if ( (v11 & 2) != 0 )
    {
      v11 &= ~2u;
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v14);
    }
    if ( (v11 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v6,
        (int *)&log_callback);
    vostok::network_core::udp_match_connection::on_error(
      this,
      unable_to_write_to_socket,
      *(boost::system::error_code *)&error_code->vtable);
  }
  else if ( !bytes_transferred )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
      v11 = 4;
      vostok::logging::append(
        &v12,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[348],
        0x7Du,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[172],
        "network_core:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[2].m_store[312]);
    }
    if ( (v11 & 4) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v6,
        (int *)&v12);
    vostok::network_core::udp_match_connection::on_error(
      this,
      unable_to_write_to_socket,
      *(boost::system::error_code *)&error_code->vtable);
  }
}
