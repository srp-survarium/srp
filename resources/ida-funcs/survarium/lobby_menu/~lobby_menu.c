void __thiscall survarium::lobby_menu::~lobby_menu(survarium::lobby_menu *this)
{
  survarium::flash_external_handler *v2; // ebp
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  survarium::first_person_game_effect_presenter *v7; // ecx
  survarium::flash_function_handler *v8; // ecx
  const char *v9; // [esp-8h] [ebp-18h]
  vostok::memory::doug_lea_allocator *v10; // [esp-4h] [ebp-14h]
  vostok::memory::doug_lea_allocator *v11; // [esp-4h] [ebp-14h]
  const char *v12; // [esp-4h] [ebp-14h]
  const char *v13; // [esp-4h] [ebp-14h]
  const char *v14; // [esp+0h] [ebp-10h]
  const char *v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+0h] [ebp-10h]
  const char *v17; // [esp+4h] [ebp-Ch]
  unsigned int v18; // [esp+4h] [ebp-Ch]
  unsigned int v19; // [esp+8h] [ebp-8h]

  v2 = &this->survarium::flash_external_handler;
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::lobby_menu_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::base_game_scene'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::lobby_menu::`vftable'{for `vostok::input::handler'};
  this->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::flash_external_handler'};
  this->survarium::flash_function_handler::__vftable = (survarium::flash_function_handler_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::flash_function_handler'};
  v3 = survarium::g_allocator;
  if ( this->m_camera )
  {
    v4 = __RTCastToVoid((void **)&this->m_camera->__vftable);
    vostok::memory::doug_lea_allocator::free_impl(v10, (int)v3, v4, v14, v17, v19);
    this->m_camera = 0;
  }
  v5 = survarium::g_allocator;
  if ( this->m_demo_camera )
  {
    v6 = __RTCastToVoid((void **)&this->m_demo_camera->__vftable);
    vostok::memory::doug_lea_allocator::free_impl(v11, (int)v5, v6, v14, v17, v19);
    this->m_demo_camera = 0;
  }
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::lobby_character>(
    survarium::g_allocator,
    &this->m_character,
    v14,
    v17,
    v19);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::lobby_character>(
    survarium::g_allocator,
    this->m_squad_member,
    v12,
    v15,
    v18);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::lobby_character>(
    survarium::g_allocator,
    &this->m_squad_member[1],
    v9,
    v13,
    v16);
  vostok::physics::destroy_world(this->m_physics_world);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skills_tree_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_static_game_parameters_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_lobby_menu_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_cursor_ui);
  survarium::first_person_game_effect_presenter::~first_person_game_effect_presenter(
    v7,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_effect_presenter);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_effect_player.m_effects.vostok::threading::mutex);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_lobby_game_project);
  survarium::flash_function_handler::~flash_function_handler(v8, &this->survarium::flash_function_handler::__vftable);
  survarium::flash_external_handler::~flash_external_handler(v2);
  survarium::base_game_scene::~base_game_scene(this);
}
