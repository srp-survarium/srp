void __thiscall survarium::generic_anomaly_cook::generic_anomaly_cook(
        survarium::generic_anomaly_cook *this,
        survarium::game_world *game_world)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x7B,
    &s_generic_anomaly_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_generic_anomaly_cook.__vftable = (survarium::generic_anomaly_cook_vtbl *)&survarium::generic_anomaly_core_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_generic_anomaly_cook, v2);
  s_generic_anomaly_cook.m_game_world = game_world;
  s_generic_anomaly_cook.__vftable = (survarium::generic_anomaly_cook_vtbl *)&survarium::generic_anomaly_cook::`vftable';
}
