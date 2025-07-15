void __thiscall survarium::login_menu_external_handler::scaleform_callback(
        survarium::login_menu_external_handler *this,
        survarium::flash_movie *pmovieView,
        char *methodName,
        const survarium::flash_value *args,
        unsigned int argCount)
{
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  int v8; // edx
  survarium::flash_value *v9; // ecx
  const char *v10; // eax
  survarium::game *m_game; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  void *v13; // ecx
  survarium::game *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  int v17; // edx
  survarium::flash_value *v18; // ecx
  survarium::game *v19; // eax
  survarium::login_menu *v20; // ecx
  survarium::login_menu *m_login_menu; // edi
  void *v22; // [esp-4h] [ebp-5Ch]
  vostok::network::login_client *v23; // [esp+Ch] [ebp-4Ch]
  const char *String; // [esp+10h] [ebp-48h]
  vostok::network::login_client *v25; // [esp+10h] [ebp-48h]
  char *m_server_host; // [esp+14h] [ebp-44h] BYREF
  unsigned __int16 m_server_port; // [esp+18h] [ebp-40h]
  const char *v28; // [esp+1Ch] [ebp-3Ch]
  const char *v29; // [esp+20h] [ebp-38h]
  int v30; // [esp+24h] [ebp-34h]
  Scaleform::GFx::Value pval; // [esp+28h] [ebp-30h] BYREF
  Scaleform::GFx::Value value; // [esp+40h] [ebp-18h] BYREF

  if ( !vostok::strings::compare(methodName, "sign_in_button_clicked") )
  {
    if ( this->m_login_menu->m_block_btn_time )
      return;
    v23 = this->m_game->m_network_client->login_client(this->m_game->m_network_client);
    value.pObjectInterface = 0;
    value.Type = VT_Undefined;
    survarium::flash_value::SetBoolean(v6, (int)&value, 0);
    Scaleform::GFx::Movie::SetVariable(pmovieView->m_movie, "root.sign_in_btn.enabled", &value, SV_Sticky);
    survarium::flash_movie::SetVariable("Connecting...", pmovieView, "root.status_str.text");
    String = survarium::flash_value::GetString(v7, (int)args);
    v10 = survarium::flash_value::GetString(v9, v8 + 24);
    m_server_host = v23->m_server_host;
    m_server_port = v23->m_server_port;
    v29 = v10;
    m_game = this->m_game;
    v28 = String;
    LOBYTE(v30) = 0;
    m_game->m_network_client->connect_to_login(m_game->m_network_client, (const vostok::sign_in_info *)&m_server_host);
    m_movie = pmovieView->m_movie;
    pval.pObjectInterface = 0;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(m_movie, &pval, "root.save_checkbox.selected");
    survarium::s_store_user_pass = pval.mValue.BValue;
    if ( pval.mValue.BValue )
    {
      vostok::strings::copy<128>((char (*)[128])s_net_client_account_password, v23->m_net_client_account_password);
      v13 = v22;
    }
    else
    {
      s_net_client_account_password[0] = 0;
    }
    cfg_save_user(v13);
    Scaleform::GFx::Value::~Value(&pval);
LABEL_14:
    Scaleform::GFx::Value::~Value(&value);
    return;
  }
  if ( !vostok::strings::compare(methodName, "exit_button_clicked") )
  {
    this->m_game->m_engine->exit(this->m_game->m_engine, 0);
    return;
  }
  if ( !vostok::strings::compare(methodName, "sound_play") )
  {
    survarium::game::play_ui_sound(v14, (int)this->m_game, args->body[8]);
    return;
  }
  if ( !vostok::strings::compare(methodName, "eula_agree_button_clicked") )
  {
    if ( this->m_login_menu->m_block_btn_time )
      return;
    v25 = this->m_game->m_network_client->login_client(this->m_game->m_network_client);
    value.pObjectInterface = 0;
    value.Type = VT_Undefined;
    survarium::flash_value::SetBoolean(v15, (int)&value, 0);
    Scaleform::GFx::Movie::SetVariable(pmovieView->m_movie, "root.sign_in_btn.enabled", &value, SV_Sticky);
    survarium::flash_movie::SetVariable("Connecting...", pmovieView, "root.status_str.text");
    v28 = survarium::flash_value::GetString(v16, (int)args);
    v29 = survarium::flash_value::GetString(v18, v17 + 24);
    m_server_host = v25->m_server_host;
    m_server_port = v25->m_server_port;
    v19 = this->m_game;
    LOBYTE(v30) = 1;
    v19->m_network_client->connect_to_login(v19->m_network_client, (const vostok::sign_in_info *)&m_server_host);
    goto LABEL_14;
  }
  if ( !vostok::strings::compare(methodName, "eula_not_agree_button_clicked") )
  {
    m_login_menu = this->m_login_menu;
    if ( !m_login_menu->m_block_btn_time )
      survarium::login_menu::enable_button(v20, (int)m_login_menu, 1);
  }
}
