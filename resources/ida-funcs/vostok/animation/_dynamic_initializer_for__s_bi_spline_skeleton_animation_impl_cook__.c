int vostok::animation::_dynamic_initializer_for__s_bi_spline_skeleton_animation_impl_cook__()
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v0; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x30,
    &s_bi_spline_skeleton_animation_impl_cook,
    reuse_true,
    0xFFFFFFFC,
    0,
    v2);
  s_bi_spline_skeleton_animation_impl_cook.__vftable = (vostok::animation::bi_spline_skeleton_animation_impl_cook_vtbl *)&vostok::animation::bi_spline_skeleton_animation_impl_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_bi_spline_skeleton_animation_impl_cook, v0);
  return atexit(vostok::animation::_dynamic_atexit_destructor_for__s_bi_spline_skeleton_animation_impl_cook__);
}
