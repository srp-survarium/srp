void __thiscall survarium::lobby_menu::clear_resources(survarium::lobby_menu *this)
{
  survarium::simple_game_project *m_object; // esi
  unsigned int v3; // esi
  int i; // ebx
  survarium::simple_game_project *v5; // eax
  survarium::lobby_character *v6; // ecx
  survarium::lobby_character *v7; // ecx
  survarium::lobby_character *v8; // ecx
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+Ch] [ebp-4h] BYREF

  if ( *(_DWORD *)&this->m_update_status_handler < 0 )
    survarium::scheduler::unregister(
      (survarium::scheduler *)this,
      (int)&this->m_scheduler,
      &this->m_update_status_handler);
  if ( (*(_DWORD *)&this->m_update_friends_status_handler & 0x80000000) != 0 )
    survarium::scheduler::unregister(
      (survarium::scheduler *)this,
      (int)&this->m_scheduler,
      &this->m_update_friends_status_handler);
  if ( (*(_DWORD *)&this->m_update_squad_status_handler & 0x80000000) != 0 )
    survarium::scheduler::unregister(
      (survarium::scheduler *)this,
      (int)&this->m_scheduler,
      &this->m_update_squad_status_handler);
  m_object = this->m_lobby_game_project.m_object;
  this->m_in_destroying = 1;
  survarium::simple_game_project::remove_game_objects((survarium::simple_game_project *)this, m_object);
  v3 = 0;
  for ( i = 0; ; ++i )
  {
    v5 = this->m_lobby_game_project.m_object;
    if ( v3 >= v5->m_static_collision_objects_count )
      break;
    survarium::static_collision::remove(&v5->m_static_collision_objects[i], this->m_physics_world);
    ++v3;
  }
  this->m_lobby_game_project.m_object = 0;
  v9.m_object = v5;
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  survarium::lobby_character::clear_resources(
    v6,
    (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)this->m_character);
  survarium::lobby_character::clear_resources(
    v7,
    (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)this->m_squad_member[0]);
  survarium::lobby_character::clear_resources(
    v8,
    (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)this->m_squad_member[1]);
  this->show_ui(this, 0);
}
