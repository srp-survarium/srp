void __thiscall survarium::lobby_menu::on_operation_denied_received(
        survarium::lobby_menu *this,
        survarium::lobby_menu *op_type,
        const char *description,
        char *a4)
{
  survarium::lobby_menu *v5; // ecx
  bool has_passed_filters; // al
  survarium::lobby_client *v7; // eax
  survarium::lobby_client *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  int v11; // edx
  Scaleform::GFx::Value *v12; // esi
  int n; // edi
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  int v16; // edx
  Scaleform::GFx::Value *v17; // esi
  int m; // edi
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  int v21; // edx
  Scaleform::GFx::Value *v22; // esi
  int k; // edi
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  int v26; // edx
  Scaleform::GFx::Value *v27; // esi
  int j; // edi
  survarium::flash_value *v29; // ecx
  survarium::flash_value *v30; // ecx
  int v31; // edx
  survarium::lobby_menu *v32; // ecx
  Scaleform::GFx::Value *v33; // esi
  int i; // edi
  survarium::lobby_menu *v35; // [esp-4h] [ebp-280h]
  char value[512]; // [esp+10h] [ebp-26Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v37; // [esp+210h] [ebp-6Ch] BYREF
  survarium::flash_value v38; // [esp+230h] [ebp-4Ch] BYREF
  survarium::flash_value v39; // [esp+248h] [ebp-34h] BYREF
  survarium::flash_value v40; // [esp+260h] [ebp-1Ch] BYREF
  char v41; // [esp+278h] [ebp-4h] BYREF
  char delay_ms; // [esp+284h] [ebp+8h]

  delay_ms = 0;
  survarium::text_translator::translate_text(
    (survarium::text_translator *)this,
    (int)&op_type->m_game->m_text_translator,
    a4,
    value);
  if ( description == (const char *)32 )
  {
    v29 = &v38;
    do
    {
      survarium::flash_value::flash_value(v29);
      v29 = v30 + 1;
    }
    while ( v31 - 1 >= 0 );
    survarium::flash_value::SetUInt(v29, (int)&v38, 0x63u);
    survarium::flash_value::SetString(&v39, (const char *)&stru_802CB8);
    survarium::flash_value::SetString(&v40, value);
    Scaleform::GFx::Movie::Invoke(
      op_type->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.show_system_message",
      0,
      (const Scaleform::GFx::Value *)&v38,
      3u);
    survarium::lobby_menu::request_status_from_server(v32, op_type, 0x1F4u);
    v33 = (Scaleform::GFx::Value *)&v41;
    for ( i = 2; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v33);
  }
  else if ( description == (const char *)35 )
  {
    v24 = &v38;
    do
    {
      survarium::flash_value::flash_value(v24);
      v24 = v25 + 1;
    }
    while ( v26 - 1 >= 0 );
    survarium::flash_value::SetUInt(v24, (int)&v38, 0x63u);
    survarium::flash_value::SetString(&v39, (const char *)&stru_802CB8);
    survarium::flash_value::SetString(&v40, value);
    Scaleform::GFx::Movie::Invoke(
      op_type->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.show_system_message",
      0,
      (const Scaleform::GFx::Value *)&v38,
      3u);
    v27 = (Scaleform::GFx::Value *)&v41;
    for ( j = 2; j >= 0; --j )
      Scaleform::GFx::Value::~Value(--v27);
  }
  else if ( description == (const char *)36 )
  {
    v19 = &v38;
    do
    {
      survarium::flash_value::flash_value(v19);
      v19 = v20 + 1;
    }
    while ( v21 - 1 >= 0 );
    survarium::flash_value::SetUInt(v19, (int)&v38, 0x63u);
    survarium::flash_value::SetString(&v39, (const char *)&stru_802CB8);
    survarium::flash_value::SetString(&v40, value);
    Scaleform::GFx::Movie::Invoke(
      op_type->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.show_system_message",
      0,
      (const Scaleform::GFx::Value *)&v38,
      3u);
    v22 = (Scaleform::GFx::Value *)&v41;
    for ( k = 2; k >= 0; --k )
      Scaleform::GFx::Value::~Value(--v22);
  }
  else if ( description == (const char *)37 )
  {
    v14 = &v38;
    do
    {
      survarium::flash_value::flash_value(v14);
      v14 = v15 + 1;
    }
    while ( v16 - 1 >= 0 );
    survarium::flash_value::SetUInt(v14, (int)&v38, 0x63u);
    survarium::flash_value::SetString(&v39, (const char *)&stru_802CB8);
    survarium::flash_value::SetString(&v40, value);
    Scaleform::GFx::Movie::Invoke(
      op_type->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.show_system_message",
      0,
      (const Scaleform::GFx::Value *)&v38,
      3u);
    v17 = (Scaleform::GFx::Value *)&v41;
    for ( m = 2; m >= 0; --m )
      Scaleform::GFx::Value::~Value(--v17);
  }
  else if ( description == (const char *)41 )
  {
    v9 = &v38;
    do
    {
      survarium::flash_value::flash_value(v9);
      v9 = v10 + 1;
    }
    while ( v11 - 1 >= 0 );
    survarium::flash_value::SetUInt(v9, (int)&v38, 0x63u);
    survarium::flash_value::SetString(&v39, (const char *)&stru_802CB8);
    survarium::flash_value::SetString(&v40, value);
    Scaleform::GFx::Movie::Invoke(
      op_type->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.show_system_message",
      0,
      (const Scaleform::GFx::Value *)&v38,
      3u);
    v12 = (Scaleform::GFx::Value *)&v41;
    for ( n = 2; n >= 0; --n )
      Scaleform::GFx::Value::~Value(--v12);
  }
  else if ( description == (const char *)42 )
  {
    v7 = survarium::lobby_menu::lobby_client(v5, (int)op_type);
    survarium::lobby_client::query_squad_info(v8, (int)v7);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          v5 = v35,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5,
        &v37);
      delay_ms = 1;
      vostok::logging::append(
        &v37,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_menu.cpp",
        0x218u,
        "void __thiscall survarium::lobby_menu::on_operation_denied_received(enum vostok::lobby::client::messages_enum,const char *)",
        "game",
        error,
        "Unknown (operation denied) type received %d",
        description);
    }
    if ( (delay_ms & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
        (int *)&v37);
  }
}
