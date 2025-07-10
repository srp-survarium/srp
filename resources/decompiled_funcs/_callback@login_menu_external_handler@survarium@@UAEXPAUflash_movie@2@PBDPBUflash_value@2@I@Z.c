void __thiscall survarium::login_menu_external_handler::callback(
        survarium::login_menu_external_handler *this,
        survarium::flash_movie *pmovieView,
        const char *methodName,
        const survarium::flash_value *args,
        unsigned int argCount)
{
  vostok::network::login_client *v6; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  vostok::network::login_client *v8; // esi
  const char *v9; // edx
  const char *v10; // eax
  Scaleform::GFx::Movie *v11; // ecx
  const char *v12; // edi
  vostok::console_commands::command_type v13; // [esp+8h] [ebp-40h]
  vostok::memory::base_allocator *v14; // [esp+Ch] [ebp-3Ch]
  survarium::flash_value need_to_save_password; // [esp+18h] [ebp-30h] BYREF
  survarium::flash_value sign_in_button_enable; // [esp+30h] [ebp-18h] BYREF

  if ( !strcmp(methodName, "sign_in_button_clicked") )
  {
    if ( !this->m_login_menu->m_block_btn_time )
    {
      v6 = this->m_game->m_network_client->login_client(this->m_game->m_network_client);
      m_movie = pmovieView->m_movie;
      v8 = v6;
      *(_DWORD *)sign_in_button_enable.body = 0;
      *(_DWORD *)&sign_in_button_enable.body[4] = 2;
      sign_in_button_enable.body[8] = 0;
      Scaleform::GFx::Movie::SetVariable(
        m_movie,
        "root.sign_in_btn.enabled",
        (const Scaleform::GFx::Value *)&sign_in_button_enable,
        SV_Sticky);
      survarium::flash_movie::SetVariable(pmovieView, "root.status_str.text", "Connecting...");
      if ( (*(_DWORD *)&args->body[4] & 0x40) != 0 )
        v9 = **(const char ***)&args->body[8];
      else
        v9 = *(const char **)&args->body[8];
      v10 = *(const char **)&args[1].body[8];
      if ( (*(_DWORD *)&args[1].body[4] & 0x40) != 0 )
        v10 = *(const char **)v10;
      this->m_game->m_network_client->connect_to_login(
        this->m_game->m_network_client,
        v8->m_server_host,
        v8->m_server_port,
        v9,
        v10);
      v11 = pmovieView->m_movie;
      *(_DWORD *)need_to_save_password.body = 0;
      *(_DWORD *)&need_to_save_password.body[4] = 0;
      Scaleform::GFx::Movie::GetVariable(
        v11,
        (Scaleform::GFx::Value *)&need_to_save_password,
        "root.save_checkbox.selected");
      survarium::s_store_user_pass = need_to_save_password.body[8];
      if ( need_to_save_password.body[8] )
        vostok::network::login_client::store_user_password_in_settings(v8);
      else
        vostok::network::login_client::reset_user_password_in_settings(v8);
      v12 = s_engine_0->get_user_data_directory(s_engine_0);
      vostok::console_commands::save("user.cfg", v12, v13, v14);
      if ( (need_to_save_password.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)need_to_save_password.body + 8))(
          *(_DWORD *)need_to_save_password.body,
          &need_to_save_password,
          *(_DWORD *)&need_to_save_password.body[8]);
        *(_DWORD *)need_to_save_password.body = 0;
      }
      *(_DWORD *)&need_to_save_password.body[4] = 0;
      if ( (sign_in_button_enable.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)sign_in_button_enable.body + 8))(
          *(_DWORD *)sign_in_button_enable.body,
          &sign_in_button_enable,
          *(_DWORD *)&sign_in_button_enable.body[8]);
    }
  }
  else if ( !strcmp(methodName, "exit_button_clicked") )
  {
    this->m_game->m_engine->exit(this->m_game->m_engine, 0);
  }
}
