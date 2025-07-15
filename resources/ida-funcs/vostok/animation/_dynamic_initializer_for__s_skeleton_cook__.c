int vostok::animation::_dynamic_initializer_for__s_skeleton_cook__()
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v0; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x2D,
    &s_skeleton_cook,
    reuse_true,
    0xFFFFFFFC,
    0,
    v2);
  s_skeleton_cook.__vftable = (vostok::animation::skeleton_cook_vtbl *)&vostok::animation::skeleton_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_skeleton_cook, v0);
  return atexit(vostok::animation::_dynamic_atexit_destructor_for__s_skeleton_cook__);
}
