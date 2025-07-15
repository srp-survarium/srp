int dynamic_initializer_for__s_skeleton_animation_cook__()
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v0; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x32,
    &s_skeleton_animation_cook,
    reuse_true,
    0xFFFFFFFC,
    0,
    v2);
  s_skeleton_animation_cook.__vftable = (vostok::animation::skeleton_animation_cook_vtbl *)&vostok::animation::skeleton_animation_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_skeleton_animation_cook, v0);
  return atexit(dynamic_atexit_destructor_for__s_skeleton_animation_cook__);
}
