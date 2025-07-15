void __thiscall survarium::weapon_cook::weapon_cook(survarium::weapon_cook *this, survarium::game *g)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x46,
    &s_weapon_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_weapon_cook.__vftable = (survarium::weapon_cook_vtbl *)&survarium::weapon_core_cook::`vftable';
  s_weapon_cook.m_animations_registry = &survarium::g_animations_registry;
  vostok::resources::resources_manager::register_cook(&s_weapon_cook, v2);
  s_weapon_cook.m_game = g;
  s_weapon_cook.__vftable = (survarium::weapon_cook_vtbl *)&survarium::weapon_cook::`vftable';
}
