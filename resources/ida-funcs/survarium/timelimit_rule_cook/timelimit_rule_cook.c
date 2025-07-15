void __thiscall survarium::timelimit_rule_cook::timelimit_rule_cook(
        survarium::timelimit_rule_cook *this,
        survarium::game *g)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x5B,
    &s_timelimit_rule_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_timelimit_rule_cook.__vftable = (survarium::timelimit_rule_cook_vtbl *)&survarium::timelimit_rule_core_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_timelimit_rule_cook, v2);
  s_timelimit_rule_cook.m_game = g;
  s_timelimit_rule_cook.__vftable = (survarium::timelimit_rule_cook_vtbl *)&survarium::timelimit_rule_cook::`vftable';
}
