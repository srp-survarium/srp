void __thiscall survarium::game_effect_emitter_cook::game_effect_emitter_cook(
        survarium::game_effect_emitter_cook *this)
{
  vostok::fixed_string<128> *v1; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-Ch]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x6A,
    &s_game_effect_emitter_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_game_effect_emitter_cook.__vftable = (survarium::game_effect_emitter_cook_vtbl *)&survarium::game_effect_emitter_cook::`vftable';
  vostok::fixed_string<128>::fixed_string<128>(
    v1,
    &s_game_effect_emitter_cook.m_effects_path.vostok::buffer_string,
    "resources/gameplay/effects/client");
  vostok::resources::resources_manager::register_cook(&s_game_effect_emitter_cook, v2);
}
