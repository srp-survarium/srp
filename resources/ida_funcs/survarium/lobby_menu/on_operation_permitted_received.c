void __usercall survarium::lobby_menu::on_operation_permitted_received(
        survarium::lobby_menu *this@<ecx>,
        vostok::lobby_client_message_types_enum op_type@<eax>)
{
  char v3; // bl
  unsigned __int8 m_selected_profile; // bl
  survarium::lobby_client *v6; // edi
  survarium::lobby_client *v7; // eax
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v3 = 0;
  switch ( op_type )
  {
    case set_status_ready_for_match:
      survarium::lobby_menu::request_status_from_server(this, (int)this, 0x3E8u);
      break;
    case inventory_action:
      m_selected_profile = this->m_selected_profile;
      v6 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
      v7 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
      survarium::lobby_client::query_profile_contents(
        (survarium::lobby_client *)(440 * m_selected_profile),
        v7,
        v6->m_profiles[m_selected_profile].profile_id);
      break;
    case shop_action:
      return;
    case skills_tree_action:
      v8 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
      survarium::lobby_client::query_client_status(v9, v8, q_player_skills);
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v10 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v10 )
        {
          log_callback.functor.obj_ptr = v10;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v3 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x15Fu,
          "void __thiscall survarium::lobby_menu::on_operation_permitted_received(enum vostok::lobby_client_message_types_enum)",
          "game:",
          error,
          "Unknown (operation permitted) type received %d",
          op_type);
      }
      if ( (v3 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
      {
        v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v11 )
          v11(&log_callback.functor, &log_callback.functor, 2);
      }
      break;
  }
}
