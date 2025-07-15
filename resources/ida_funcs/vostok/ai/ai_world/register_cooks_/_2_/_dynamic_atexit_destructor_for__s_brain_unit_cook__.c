void __cdecl vostok::ai::ai_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_brain_unit_cook__()
{
  vostok::resources::unmanaged_cook *v0; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&s_brain_unit_cook.m_ai_world);
  vostok::resources::unmanaged_cook::~unmanaged_cook(v0, &s_brain_unit_cook);
}
