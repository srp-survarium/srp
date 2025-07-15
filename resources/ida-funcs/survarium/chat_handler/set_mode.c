void __userpurge survarium::chat_handler::set_mode(
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *movie@<eax>,
        survarium::chat_handler *this,
        bool is_game_mode)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_current_chat_ui; // esi
  survarium::messaging_client *v5; // eax
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_movie_resource *v7; // eax
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  int v10; // edi
  survarium::flash_value *v11; // ecx
  survarium::text_translator *v12; // ecx
  survarium::text_translator *v13; // ecx
  survarium::chat_handler *v14; // ecx
  survarium::chat_tab *p_tab; // esi
  survarium::flash_function_handler_impl *impl; // [esp-8h] [ebp-4A0h]
  survarium::chat_handler v17; // [esp+10h] [ebp-488h] BYREF
  char v18[516]; // [esp+210h] [ebp-288h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+414h] [ebp-84h] BYREF
  Scaleform::GFx::Value pval; // [esp+42Ch] [ebp-6Ch] BYREF
  survarium::chat_tab tab; // [esp+444h] [ebp-54h] BYREF
  survarium::chat_handler *v22; // [esp+460h] [ebp-38h]
  int v23; // [esp+464h] [ebp-34h]
  char v24; // [esp+468h] [ebp-30h]
  unsigned int *v25; // [esp+46Ch] [ebp-2Ch]
  int v26; // [esp+470h] [ebp-28h]
  int v27; // [esp+474h] [ebp-24h]
  char v28; // [esp+478h] [ebp-20h]
  Scaleform::GFx::Value pargs; // [esp+47Ch] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *ui; // [esp+494h] [ebp-4h]
  unsigned int v31; // [esp+4A0h] [ebp+8h]
  unsigned int *v32; // [esp+4A4h] [ebp+Ch]

  p_m_current_chat_ui = &this->m_current_chat_ui;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    movie,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_current_chat_ui);
  if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client) )
  {
    v5 = this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
    survarium::chat_handler::set_local_player_name((const char (*)[64])v5->m_local_name, this);
  }
  this->m_game_ui_mode = is_game_mode;
  m_object = p_m_current_chat_ui->m_object;
  pval.pObjectInterface = 0;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(m_object->movie->m_movie, &pval, "root.chat");
  impl = this->impl;
  v7 = p_m_current_chat_ui->m_object;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateFunction(v7->movie->m_movie, &pvalue, impl, 0);
  survarium::flash_value::SetMember(v8, &pval, "send_function", (survarium::flash_value *)&pvalue);
  if ( is_game_mode )
  {
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_value::SetUInt(v9, (int)&pargs, 3u);
    Scaleform::GFx::Movie::Invoke(this->m_current_chat_ui.m_object->movie->m_movie, "root.remove_tab", 0, &pargs, 1u);
    v10 = 2;
    survarium::flash_value::SetUInt(v11, (int)&pargs, 2u);
    ui = &this->m_current_chat_ui;
    Scaleform::GFx::Movie::Invoke(this->m_current_chat_ui.m_object->movie->m_movie, "root.remove_tab", 0, &pargs, 1u);
    if ( this->m_game->m_network_client->messaging_client(this->m_game->m_network_client)->m_game_team_id )
    {
      v32 = survarium::team2_tab_chanels;
      v31 = 7;
    }
    else
    {
      v32 = survarium::team1_tab_chanels;
      v31 = 6;
    }
    survarium::text_translator::translate_text(v12, (int)&this->m_game->m_text_translator, "st_chat_channel_team", v18);
    survarium::text_translator::translate_text(
      v13,
      (int)&this->m_game->m_text_translator,
      "st_chat_channel_match",
      (char *)&v17);
    tab.name = v18;
    tab.channel_to_send = v31;
    v14 = &v17;
    tab.id = 3;
    tab.closeable = 0;
    tab.channels = v32;
    tab.channels_count = 2;
    tab.save_history = 0;
    v22 = &v17;
    v23 = 2;
    v24 = 0;
    v25 = v32;
    v26 = 2;
    v27 = 5;
    v28 = 0;
    p_tab = &tab;
    do
    {
      survarium::chat_handler::add_new_tab(v14, ui, p_tab++);
      --v10;
    }
    while ( v10 );
    Scaleform::GFx::Value::~Value(&pargs);
  }
  Scaleform::GFx::Value::~Value(&pvalue);
  Scaleform::GFx::Value::~Value(&pval);
}
