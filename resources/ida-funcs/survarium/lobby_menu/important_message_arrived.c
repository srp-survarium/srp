void __thiscall survarium::lobby_menu::important_message_arrived(
        survarium::lobby_menu *this,
        int message_id,
        unsigned int message_type,
        const char *message_text,
        char *sender_name,
        char *a6)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool has_passed_filters; // al
  bool v9; // zf
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool v11; // al
  survarium::lobby_client *v12; // eax
  survarium::lobby_client *v13; // ecx
  survarium::lobby_client *v14; // eax
  survarium::lobby_client *v15; // ecx
  survarium::lobby_menu *v16; // ecx
  survarium::lobby_client *v17; // eax
  survarium::lobby_client *v18; // ecx
  survarium::lobby_menu *v19; // ecx
  survarium::lobby_client *v20; // eax
  survarium::lobby_client *v21; // ecx
  bool v22; // al
  survarium::lobby_menu *v23; // ecx
  survarium::lobby_client *v24; // eax
  survarium::lobby_client *v25; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // ecx
  bool v27; // al
  int v28; // eax
  char *token; // edi
  char *v30; // esi
  survarium::lobby_client *v31; // eax
  survarium::lobby_menu *v32; // ecx
  survarium::lobby_client *v33; // eax
  survarium::lobby_client *v34; // ecx
  survarium::lobby_menu *v35; // ecx
  survarium::lobby_client *v36; // eax
  survarium::lobby_client *v37; // ecx
  survarium::flash_value *v38; // ecx
  survarium::flash_value *v39; // ecx
  survarium::flash_value *v40; // ecx
  survarium::flash_value *v41; // ecx
  survarium::flash_value *v42; // ecx
  survarium::flash_value *v43; // ecx
  survarium::flash_value *v44; // ecx
  vostok::configs::binary_config_value *v45; // eax
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // esi
  char **v48; // eax
  int v49; // eax
  survarium::flash_value *v50; // ecx
  survarium::flash_value *v51; // ecx
  survarium::flash_value *v52; // ecx
  survarium::flash_value *v53; // ecx
  survarium::flash_value *v54; // ecx
  char *v55; // eax
  survarium::flash_value *v56; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v57; // [esp-4h] [ebp-280h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v58; // [esp-4h] [ebp-280h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v59; // [esp-4h] [ebp-280h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v60; // [esp-4h] [ebp-280h]
  survarium::lobby_menu *v61; // [esp-4h] [ebp-280h]
  survarium::flash_movie v62; // [esp+10h] [ebp-26Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v63; // [esp+210h] [ebp-6Ch] BYREF
  char nptr[16]; // [esp+230h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v65; // [esp+240h] [ebp-3Ch] BYREF
  survarium::flash_value v66; // [esp+260h] [ebp-1Ch] BYREF
  char v67; // [esp+284h] [ebp+8h]
  unsigned __int8 v68; // [esp+28Fh] [ebp+13h]

  v67 = 0;
  if ( (_BYTE)message_text == 1 )
  {
    if ( vostok::strings::starts_with(sender_name, "#+q") )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)4),
            v7 = v57,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v7,
          &v65);
        v67 = 1;
        vostok::logging::append(
          &v65,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu_ui.cpp",
          0x904u,
          "void __thiscall survarium::lobby_menu::important_message_arrived(unsigned int,unsigned char,const char *,const char *)",
          "game",
          info,
          "New quest added: %s",
          sender_name);
      }
      v9 = (v67 & 1) == 0;
    }
    else
    {
      if ( vostok::strings::starts_with(sender_name, "#!q") )
      {
        if ( !vostok::core::g_log_filter_tree
          || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
              v10 = v58,
              v11) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v10,
            &v65);
          v67 = 2;
          vostok::logging::append(
            &v65,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\lobby_menu_ui.cpp",
            0x908u,
            "void __thiscall survarium::lobby_menu::important_message_arrived(unsigned int,unsigned char,const char *,const char *)",
            "game",
            info,
            "Quest failed: %s",
            sender_name);
        }
        if ( (v67 & 2) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
            (int *)&v65);
        if ( survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v10, message_id)->m_net_client_connected )
        {
          v12 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v7, message_id);
          survarium::lobby_client::query_client_status(v13, (const vostok::network_core::tcp_packet *)v12, 0x10u);
        }
        goto LABEL_24;
      }
      if ( !vostok::strings::starts_with(sender_name, "#q!") )
      {
LABEL_24:
        if ( survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v7, message_id)->m_net_client_connected )
        {
          v24 = survarium::lobby_menu::lobby_client(v23, message_id);
          survarium::lobby_client::query_client_status(v25, (const vostok::network_core::tcp_packet *)v24, 0xEu);
        }
        return;
      }
      if ( survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v7, message_id)->m_net_client_connected )
      {
        v14 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v7, message_id);
        survarium::lobby_client::query_client_status(v15, (const vostok::network_core::tcp_packet *)v14, 0x13u);
        v17 = survarium::lobby_menu::lobby_client(v16, message_id);
        survarium::lobby_client::query_client_status(v18, (const vostok::network_core::tcp_packet *)v17, 9u);
        v20 = survarium::lobby_menu::lobby_client(v19, message_id);
        survarium::lobby_client::query_client_status(v21, (const vostok::network_core::tcp_packet *)v20, 0x10u);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
            v7 = v59,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v7,
          &v65);
        v67 = 4;
        vostok::logging::append(
          &v65,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu_ui.cpp",
          0x914u,
          "void __thiscall survarium::lobby_menu::important_message_arrived(unsigned int,unsigned char,const char *,const char *)",
          "game",
          info,
          "Quest completed: %s",
          sender_name);
      }
      v9 = (v67 & 4) == 0;
    }
    if ( !v9 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v65);
    goto LABEL_24;
  }
  if ( !(_BYTE)message_text || (_BYTE)message_text == 2 )
  {
    v49 = *(_DWORD *)(message_id + 1600);
    *(_QWORD *)&v65.functor.obj_ptr = 0;
    *(_DWORD *)v66.body = 0;
    *(_DWORD *)&v66.body[4] = 0;
    survarium::flash_movie::CreateObject(
      (survarium::flash_movie *)this,
      *(survarium::flash_value **)(v49 + 264),
      (Scaleform::GFx::Value *)&v65.functor);
    survarium::flash_value::SetUInt(v50, (int)&v66, message_type);
    survarium::flash_value::SetMember(v51, &v65.functor.obj_ptr, "id", &v66);
    survarium::flash_value::SetUInt(v52, (int)&v66, (_BYTE)message_text != 0);
    survarium::flash_value::SetMember(v53, &v65.functor.obj_ptr, "type", &v66);
    survarium::flash_value::SetString(&v66, a6);
    survarium::flash_value::SetMember(v54, &v65.functor.obj_ptr, "sender_name", &v66);
    v55 = "st_add_to_friends_request";
    if ( (_BYTE)message_text )
      v55 = "st_add_to_squad_request";
    survarium::text_translator::translate_text(
      (survarium::text_translator *)&v62,
      *(_DWORD *)(message_id + 160) + 13944,
      v55,
      (char *)&v62);
    goto LABEL_44;
  }
  if ( (_BYTE)message_text == 4 && vostok::strings::starts_with(sender_name, "#ru") )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v27 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
          v26 = v60,
          v27) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v26,
        &v63);
      v67 = 8;
      vostok::logging::append(
        &v63,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_menu_ui.cpp",
        0x936u,
        "void __thiscall survarium::lobby_menu::important_message_arrived(unsigned int,unsigned char,const char *,const char *)",
        "game",
        info,
        "Reputation level unlocked: %s",
        sender_name);
    }
    if ( (v67 & 8) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v26,
        (int *)&v63);
    strstr((unsigned __int8 *)sender_name, "[");
    token = (char *)vostok::strings::get_token(0x3Au, (char *)(v28 + 1), nptr, strlen(nptr) - 1);
    v30 = (char *)atoi(nptr);
    sender_name = v30;
    v68 = atoi(token);
    v31 = survarium::lobby_menu::lobby_client(v61, message_id);
    v32 = (survarium::lobby_menu *)(v30 - 1);
    LOBYTE(v32) = v31->m_unlocked_factions_mask;
    if ( ((unsigned __int8)(1 << ((_BYTE)v30 - 1)) & (unsigned __int8)v32) == 0
      && survarium::lobby_menu::lobby_client(v32, message_id)->m_net_client_connected )
    {
      v33 = survarium::lobby_menu::lobby_client(v32, message_id);
      survarium::lobby_client::query_client_status(v34, (const vostok::network_core::tcp_packet *)v33, 0x13u);
    }
    if ( survarium::lobby_menu::lobby_client(v32, message_id)->m_net_client_connected )
    {
      v36 = survarium::lobby_menu::lobby_client(v35, message_id);
      survarium::lobby_client::query_client_status(v37, (const vostok::network_core::tcp_packet *)v36, 9u);
    }
    *(_QWORD *)&v65.functor.obj_ptr = 0;
    *(_DWORD *)v66.body = 0;
    *(_DWORD *)&v66.body[4] = 0;
    survarium::flash_movie::CreateObject(
      (survarium::flash_movie *)v35,
      *(survarium::flash_value **)(*(_DWORD *)(message_id + 1600) + 264),
      (Scaleform::GFx::Value *)&v65.functor);
    survarium::flash_value::SetUInt(v38, (int)&v66, message_type);
    survarium::flash_value::SetMember(v39, &v65.functor.obj_ptr, "id", &v66);
    survarium::flash_value::SetUInt(v40, (int)&v66, 2u);
    survarium::flash_value::SetMember(v41, &v65.functor.obj_ptr, "type", &v66);
    survarium::flash_value::SetUInt(v42, (int)&v66, (unsigned int)sender_name);
    survarium::flash_value::SetMember(v43, &v65.functor.obj_ptr, "faction_id", &v66);
    survarium::flash_value::SetString(&v66, "reputation");
    survarium::flash_value::SetMember(v44, &v65.functor.obj_ptr, "sender_name", &v66);
    sprintf_s<16>((char (*)[16])nptr, "faction_%d", sender_name);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&sender_name,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)(message_id + 160) + 13908) + 268));
    v45 = vostok::configs::binary_config_value::operator[](
            *((vostok::configs::binary_config_value **)sender_name + 66),
            "factions_dict");
    v46 = vostok::configs::binary_config_value::operator[](v45, nptr);
    v47 = vostok::configs::binary_config_value::operator[](v46, "levels");
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&sender_name);
    v48 = (char **)vostok::configs::binary_config_value::operator[](
                     (vostok::configs::binary_config_value *)v47->data.pointer + v68,
                     "unlock_message");
    survarium::text_translator::translate_text(
      (survarium::text_translator *)&v62,
      *(_DWORD *)(message_id + 160) + 13944,
      *v48,
      (char *)&v62);
LABEL_44:
    survarium::flash_value::SetString(&v66, (const char *)&v62);
    survarium::flash_value::SetMember(v56, &v65.functor.obj_ptr, "message_body", &v66);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(message_id + 1600) + 264) + 4),
      "root.add_important_message",
      0,
      (const Scaleform::GFx::Value *)&v65.functor,
      1u);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v66);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v65.functor);
  }
}
