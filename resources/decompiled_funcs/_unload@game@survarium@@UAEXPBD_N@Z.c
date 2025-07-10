void __thiscall survarium::game::unload(survarium::game *this, const char *__formal, bool destroying)
{
  survarium::base_game_scene *m_active_scene; // ecx
  survarium::main_menu *m_main_menu; // edi

  if ( this->m_game_world.m_game_project.m_object )
    survarium::game_world::unload(
      (survarium::game_world *)this,
      (vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>)&this->m_game_world);
  if ( !destroying )
  {
    m_active_scene = this->m_active_scene;
    m_main_menu = this->m_main_menu;
    if ( m_active_scene != m_main_menu )
    {
      if ( m_active_scene )
        m_active_scene->on_deactivate(m_active_scene);
      this->m_active_scene = m_main_menu;
      m_main_menu->on_activate(m_main_menu);
    }
  }
}
