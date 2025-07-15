void __usercall survarium::login_menu::set_status(
        survarium::login_menu *this@<edi>,
        survarium::login_menu_status_enum status@<eax>)
{
  vostok::buffer_string *v2; // ecx
  survarium::login_menu *v3; // ecx
  unsigned int v4; // eax
  vostok::buffer_string *v5; // [esp-4h] [ebp-224h]
  const char *v6; // [esp+0h] [ebp-220h]
  char *value[3]; // [esp+8h] [ebp-218h] BYREF
  _BYTE v8[512]; // [esp+14h] [ebp-20Ch] BYREF
  char v9; // [esp+214h] [ebp-Ch] BYREF
  vostok::network::login_client *v10; // [esp+218h] [ebp-8h]
  BOOL v11; // [esp+21Ch] [ebp-4h]

  this->m_status = status;
  v10 = this->m_game->m_network_client->login_client(this->m_game->m_network_client);
  value[0] = v8;
  value[1] = v8;
  value[2] = &v9;
  v8[0] = 0;
  vostok::fs_new::path_string_impl::assignf(value, v2, (vostok::buffer_string *)"Login Server: ", v6);
  switch ( this->m_status )
  {
    case login_menu_status_error_connection:
      vostok::buffer_string::append(v5, (int)value, "Connection error");
      goto LABEL_6;
    case login_menu_status_invalid_user_or_password:
      vostok::buffer_string::append(v5, (int)value, "Invalid user name or password");
      goto LABEL_6;
    case login_menu_status_sign_in_attempt_interval_violated:
      vostok::buffer_string::append(v5, (int)value, "Sign in attempt interval violated");
      v4 = this->m_game->m_current_time_in_ms + 10000;
      goto LABEL_7;
    case login_menu_status_disconnected:
      vostok::buffer_string::append(v5, (int)value, "Disconnected");
      LOBYTE(v11) = 1;
      goto LABEL_16;
    case login_menu_status_connected:
      vostok::buffer_string::append(v5, (int)value, "Connected");
      break;
    case login_menu_status_user_banned:
      vostok::buffer_string::append(v5, (int)value, "User banned");
      break;
    case login_menu_status_access_level_restriction:
      vostok::buffer_string::append(v5, (int)value, "Access level restriction");
      break;
    case login_menu_status_sign_in_already_online:
      vostok::buffer_string::append(v5, (int)value, "Connecting...");
LABEL_6:
      v4 = this->m_game->m_current_time_in_ms + 5000;
LABEL_7:
      this->m_block_btn_time = v4;
      break;
    case login_menu_status_invalid_version:
      vostok::buffer_string::append(v5, (int)value, "Invalid version");
      break;
    case login_menu_status_sign_in_eula_check_failed:
      vostok::buffer_string::append(v5, (int)value, "Reading EULA");
      Scaleform::GFx::Movie::Invoke(this->m_login_menu_ui.m_object->movie->m_movie, "root.show_eula_wnd", 0, 0, 0);
      break;
  }
  LOBYTE(v11) = 0;
LABEL_16:
  survarium::login_menu::enable_button(v3, (int)this, v11);
  survarium::flash_movie::SetVariable(value[0], this->m_login_menu_ui.m_object->movie, "root.status_str.text");
  survarium::flash_movie::SetVariable(
    s_net_client_account_name,
    this->m_login_menu_ui.m_object->movie,
    "root.login_input.text");
  survarium::flash_movie::SetVariable(
    v10->m_net_client_account_password,
    this->m_login_menu_ui.m_object->movie,
    "root.password_input.text");
}
