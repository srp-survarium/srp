void __usercall survarium::login_menu::set_status(
        survarium::login_menu *this@<ecx>,
        survarium::login_menu_status_enum status@<eax>)
{
  vostok::network::login_client *v3; // eax
  vostok::network::login_client *v4; // edi
  survarium::flash_movie_resource *m_object; // ebx
  char *v6; // eax
  survarium::flash_movie_resource *v7; // esi
  char *v8; // eax
  vostok::fixed_string<512> status_str; // [esp+Ch] [ebp-210h] BYREF
  char v10; // [esp+218h] [ebp-4h] BYREF

  this->m_status = status;
  v3 = this->m_game->m_network_client->login_client(this->m_game->m_network_client);
  status_str.m_begin = status_str.m_buffer;
  v4 = v3;
  status_str.m_end = status_str.m_buffer;
  status_str.m_max_end = &v10;
  status_str.m_buffer[0] = 0;
  vostok::buffer_string::assignf(&status_str, "Login Server: ");
  switch ( this->m_status )
  {
    case login_menu_status_error_connection:
      vostok::buffer_string::append(&status_str, "Connection error");
      this->m_block_btn_time = this->m_game->m_current_time_in_ms + 5000;
      break;
    case login_menu_status_invalid_user_or_password:
      vostok::buffer_string::append(&status_str, "Invalid user name or password");
      this->m_block_btn_time = this->m_game->m_current_time_in_ms + 5000;
      break;
    case login_menu_status_sign_in_attempt_interval_violated:
      vostok::buffer_string::append(&status_str, "Sign in attempt interval violated");
      this->m_block_btn_time = this->m_game->m_current_time_in_ms + 10000;
      break;
    case login_menu_status_disconnected:
      vostok::buffer_string::append(&status_str, "Disconnected");
      this->m_block_btn_time = this->m_game->m_current_time_in_ms + 5000;
      break;
    case login_menu_status_connected:
      vostok::buffer_string::append(&status_str, "Connected");
      break;
    case login_menu_status_user_banned:
      vostok::buffer_string::append(&status_str, "User banned");
      break;
    case login_menu_status_access_level_restriction:
      vostok::buffer_string::append(&status_str, "Access level restriction");
      break;
    case login_menu_status_sign_in_already_online:
      vostok::buffer_string::append(&status_str, "Connecting...");
      this->m_block_btn_time = this->m_game->m_current_time_in_ms + 5000;
      break;
    case login_menu_status_invalid_version:
      vostok::buffer_string::append(&status_str, "Invalid version");
      break;
  }
  survarium::login_menu::enable_button(this, 0);
  survarium::flash_movie::SetVariable("root.status_str.text", status_str.m_begin, this->m_login_menu_ui.m_object->movie);
  m_object = this->m_login_menu_ui.m_object;
  v6 = vostok::network::login_client::account_name(v4);
  survarium::flash_movie::SetVariable("root.login_input.text", v6, m_object->movie);
  v7 = this->m_login_menu_ui.m_object;
  v8 = vostok::network::login_client::account_password(v4);
  survarium::flash_movie::SetVariable("root.password_input.text", v8, v7->movie);
}
