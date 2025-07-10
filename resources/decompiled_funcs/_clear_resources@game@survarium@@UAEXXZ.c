void __thiscall survarium::game::clear_resources(survarium::game *this)
{
  survarium::main_menu *m_main_menu; // ecx
  survarium::lobby_menu *m_lobby_menu; // ecx
  survarium::login_menu *m_login_menu; // ecx
  survarium::base_game_scene *m_active_scene; // ecx
  survarium::base_network_client *m_network_client; // ecx
  survarium::base_network_client *v7; // eax
  int f; // ebp
  _BYTE *v9; // esi
  void *v10; // eax
  void *v11; // esi

  this->m_ui_world->destroy_window(this->m_ui_world, this->m_debug_window);
  m_main_menu = this->m_main_menu;
  this->m_debug_window = 0;
  m_main_menu->clear_resources(m_main_menu);
  m_lobby_menu = this->m_lobby_menu;
  if ( m_lobby_menu )
    m_lobby_menu->clear_resources(m_lobby_menu);
  m_login_menu = this->m_login_menu;
  if ( m_login_menu )
    m_login_menu->clear_resources(m_login_menu);
  m_active_scene = this->m_active_scene;
  if ( m_active_scene )
    m_active_scene->on_deactivate(m_active_scene);
  m_network_client = this->m_network_client;
  if ( m_network_client )
  {
    m_network_client->disconnect(m_network_client);
    v7 = this->m_network_client;
    f = (int)survarium::g_allocator.f_.f_;
    if ( v7 )
    {
      v9 = __RTCastToVoid((void **)&v7->__vftable);
      ((void (__thiscall *)(survarium::base_network_client *, _DWORD))this->m_network_client->~survarium::base_network_client)(
        this->m_network_client,
        0);
      if ( v9 )
      {
        v10 = v9;
        v11 = *(void **)(f + 20);
        *(_BYTE *)(f + 42) = 0;
        vostok_mspace_free(v11, v10);
      }
      this->m_network_client = 0;
    }
  }
  this->m_input_world->clear_resources(this->m_input_world);
  this->m_ui_world->clear_resources(this->m_ui_world);
  if ( this->m_game_world.m_game_project.m_object )
    survarium::game_world::unload(
      &this->m_game_world,
      (vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>)&this->m_game_world);
  this->m_game_world.clear_resources(&this->m_game_world);
}
