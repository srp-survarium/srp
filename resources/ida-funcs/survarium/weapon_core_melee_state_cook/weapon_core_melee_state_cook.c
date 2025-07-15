void __thiscall survarium::weapon_core_melee_state_cook::weapon_core_melee_state_cook(
        survarium::weapon_core_melee_state_cook *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx

  vostok::resources::unmanaged_cook::unmanaged_cook(
    weapon_melee_state_class,
    0xFFFFFFFD,
    &s_weapon_core_melee_state_cook,
    reuse_false,
    0xFFFFFFFD,
    0);
  s_weapon_core_melee_state_cook.__vftable = (survarium::weapon_core_melee_state_cook_vtbl *)&survarium::weapon_core_melee_state_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_weapon_core_melee_state_cook, v1);
}
