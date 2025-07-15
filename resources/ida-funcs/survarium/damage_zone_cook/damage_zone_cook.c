void __thiscall survarium::damage_zone_cook::damage_zone_cook(
        survarium::damage_zone_cook *this,
        survarium::game_world *game_world)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x72,
    &s_damage_zone_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_damage_zone_cook.__vftable = (survarium::damage_zone_cook_vtbl *)&survarium::damage_zone_core_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_damage_zone_cook, v2);
  s_damage_zone_cook.m_game_world = game_world;
  s_damage_zone_cook.__vftable = (survarium::damage_zone_cook_vtbl *)&survarium::damage_zone_cook::`vftable';
}
