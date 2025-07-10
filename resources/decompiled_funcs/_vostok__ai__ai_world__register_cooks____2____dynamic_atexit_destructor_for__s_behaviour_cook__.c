void __cdecl vostok::ai::ai_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_behaviour_cook__()
{
  vostok::resources::unmanaged_cook *v0; // ecx

  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&s_behaviour_cook.m_loaded_binary_config);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&s_behaviour_cook.m_ai_world);
  vostok::resources::unmanaged_cook::~unmanaged_cook(v0, &s_behaviour_cook);
}
