void __thiscall survarium::messaging_client::on_packet_received(
        survarium::messaging_client *this,
        vostok::network_core::packet_reader *reader)
{
  const unsigned __int8 *m_pointer; // eax
  int v4; // edi
  char v5; // bl
  const unsigned __int8 *v6; // eax
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::messaging_client *v9; // ecx
  messaging::friendship_actions_enum v10; // edi
  const unsigned __int8 *v11; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v12; // ecx
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int *v14; // esi
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v17)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-A8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+30h] [ebp-88h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v21; // [esp+50h] [ebp-68h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v22; // [esp+70h] [ebp-48h] BYREF
  int v23; // [esp+94h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v24; // [esp+98h] [ebp-20h] BYREF

  m_pointer = reader->m_pointer;
  v4 = *m_pointer;
  v5 = 0;
  v6 = m_pointer + 1;
  v23 = 0;
  reader->m_pointer = v6;
  if ( v4 == 201 )
  {
    survarium::messaging_client::process_incoming_text_message(0, (survarium::lobby_menu *)this, reader);
    return;
  }
  if ( v4 == 204 )
  {
    v9 = (survarium::messaging_client *)*v6;
    v10 = (messaging::friendship_actions_enum)v9;
    v11 = v6 + 1;
    reader->m_pointer = v11;
    if ( v9 == (survarium::messaging_client *)5 )
    {
      survarium::messaging_client::read_friend_list(this, reader);
LABEL_74:
      survarium::lobby_menu::on_friendship_status_recivied(this->m_game->m_lobby_menu, v10);
      return;
    }
    if ( v9 == (survarium::messaging_client *)7 )
    {
      survarium::messaging_client::read_friend_status(
        (survarium::messaging_client *)7,
        (vostok::network_core::packet_reader *)this);
      goto LABEL_74;
    }
    if ( v9 == (survarium::messaging_client *)6 )
    {
      survarium::messaging_client::read_ignore_list(this, reader);
      goto LABEL_74;
    }
    if ( v9 == (survarium::messaging_client *)4 )
    {
      survarium::messaging_client::read_found_players(this, reader);
      goto LABEL_74;
    }
    LOBYTE(v9) = *v11;
    reader->m_pointer = v11 + 1;
    if ( v10 )
    {
      if ( v10 != remove_friend )
      {
        if ( v10 == add_ignorable )
        {
          if ( (_BYTE)v9 != 52 )
          {
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
            {
              v16 = vostok::core::g_log_callback;
              v22.vtable = 0;
              if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                  &v22.functor,
                  &v22.functor,
                  destroy_functor_tag);
              if ( v16 )
              {
                v22.functor.obj_ptr = v16;
                v22.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                    + 1);
              }
              else
              {
                v22.vtable = 0;
              }
              v5 = 4;
              vostok::logging::append(
                &v22,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\messaging_client_process_messagess.cpp",
                0x4Cu,
                "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::packet_reader &)",
                "game:",
                info,
                "add_ignorable: operation denied ");
            }
            if ( (v5 & 4) == 0 )
              goto LABEL_74;
            v14 = (int *)&v22;
            goto LABEL_73;
          }
        }
        else if ( (_BYTE)v9 != 52 )
        {
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
          {
            v17 = vostok::core::g_log_callback;
            v24.vtable = 0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                &v24.functor,
                &v24.functor,
                destroy_functor_tag);
            if ( v17 )
            {
              v24.functor.obj_ptr = v17;
              v24.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                  + 1);
            }
            else
            {
              v24.vtable = 0;
            }
            v5 = 8;
            vostok::logging::append(
              &v24,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\messaging_client_process_messagess.cpp",
              0x55u,
              "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::packet_reader &)",
              "game:",
              info,
              "remove_ignorable: operation denied ");
          }
          if ( (v5 & 8) == 0 )
            goto LABEL_74;
          v14 = (int *)&v24;
          goto LABEL_73;
        }
        survarium::messaging_client::query_for_ignore_list(v9, (int)this);
        goto LABEL_74;
      }
      if ( (_BYTE)v9 == 52 )
        goto LABEL_26;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v15 = vostok::core::g_log_callback;
        v21.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v21.functor,
            &v21.functor,
            destroy_functor_tag);
        if ( v15 )
        {
          v21.functor.obj_ptr = v15;
          v21.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v21.vtable = 0;
        }
        v5 = 2;
        vostok::logging::append(
          &v21,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\messaging_client_process_messagess.cpp",
          0x42u,
          "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::packet_reader &)",
          "game:",
          info,
          "remove_friend: operation denied ");
      }
      if ( (v5 & 2) == 0 )
        goto LABEL_74;
      v14 = (int *)&v21;
    }
    else
    {
      if ( (_BYTE)v9 == 52 )
      {
LABEL_26:
        survarium::messaging_client::query_for_friend_list(v9, (int)this);
        goto LABEL_74;
      }
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v13 = vostok::core::g_log_callback;
        v20.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v20.functor,
            &v20.functor,
            destroy_functor_tag);
        if ( v13 )
        {
          v20.functor.obj_ptr = v13;
          v20.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v20.vtable = 0;
        }
        v5 = 1;
        vostok::logging::append(
          &v20,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\messaging_client_process_messagess.cpp",
          0x38u,
          "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::packet_reader &)",
          "game:",
          info,
          "add_friend: operation denied ");
      }
      if ( (v5 & 1) == 0 )
        goto LABEL_74;
      v14 = (int *)&v20;
    }
LABEL_73:
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v12,
      v14);
    goto LABEL_74;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
  {
    v7 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v7 )
    {
      log_callback.functor.obj_ptr = v7;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v5 = 16;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\messaging_client_process_messagess.cpp",
      0x5Fu,
      "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::packet_reader &)",
      "game:",
      error,
      "messaging_client received unknown message:%d",
      v4);
  }
  if ( (v5 & 0x10) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&log_callback.functor, &log_callback.functor, 2);
  }
}
