void __thiscall survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>(
        survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state> *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx

  vostok::resources::unmanaged_cook::unmanaged_cook(
    double_barreled_weapon_idle_state_class,
    0xFFFFFFFD,
    &s_double_barreled_weapon_core_idle_state_cook,
    reuse_false,
    0xFFFFFFFD,
    0);
  s_double_barreled_weapon_core_idle_state_cook.__vftable = (survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>_vtbl *)&survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_double_barreled_weapon_core_idle_state_cook, v1);
}


void __thiscall survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>(
        survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state> *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx

  vostok::resources::unmanaged_cook::unmanaged_cook(
    pistol_weapon_idle_state_class,
    0xFFFFFFFD,
    &s_pistol_weapon_core_idle_state_cook,
    reuse_false,
    0xFFFFFFFD,
    0);
  s_pistol_weapon_core_idle_state_cook.__vftable = (survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>_vtbl *)&survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_pistol_weapon_core_idle_state_cook, v1);
}


void __thiscall survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::weapon_core_state_cook_template<survarium::weapon_core_idle_state>(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx

  vostok::resources::unmanaged_cook::unmanaged_cook(
    weapon_idle_state_class,
    0xFFFFFFFD,
    &s_weapon_core_idle_state_cook,
    reuse_false,
    0xFFFFFFFD,
    0);
  s_weapon_core_idle_state_cook.__vftable = (survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>_vtbl *)&survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_weapon_core_idle_state_cook, v1);
}
