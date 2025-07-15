void __thiscall survarium::victory_item_cook::victory_item_cook(
        survarium::victory_item_cook *this,
        survarium::game_world *game_world)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x57,
    &s_victory_item_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_victory_item_cook.__vftable = (survarium::victory_item_cook_vtbl *)&survarium::victory_item_core_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_victory_item_cook, v2);
  s_victory_item_cook.m_game_world = game_world;
  s_victory_item_cook.__vftable = (survarium::victory_item_cook_vtbl *)&survarium::victory_item_cook::`vftable';
}
