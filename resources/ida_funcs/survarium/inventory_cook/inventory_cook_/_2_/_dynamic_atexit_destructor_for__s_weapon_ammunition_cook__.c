void __cdecl survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_weapon_ammunition_cook__()
{
  vostok::resources::unmanaged_cook *v0; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&s_damage_model_cook);
  vostok::resources::unmanaged_cook::~unmanaged_cook(v0, &s_weapon_ammunition_cook);
}
