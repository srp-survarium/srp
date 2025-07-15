void __thiscall survarium::profile_skin_visual_cook::profile_skin_visual_cook(
        survarium::profile_skin_visual_cook *this,
        survarium::game *g)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x56,
    &s_profile_skin_visual_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_profile_skin_visual_cook.__vftable = (survarium::profile_skin_visual_cook_vtbl *)&survarium::profile_skin_visual_cook::`vftable';
  s_profile_skin_visual_cook.m_game = g;
  vostok::resources::resources_manager::register_cook(&s_profile_skin_visual_cook, v2);
}
