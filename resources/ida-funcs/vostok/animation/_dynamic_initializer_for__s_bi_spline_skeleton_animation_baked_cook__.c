int vostok::animation::_dynamic_initializer_for__s_bi_spline_skeleton_animation_baked_cook__()
{
  s_bi_spline_skeleton_animation_baked_cook.m_cook_users_count.m_count = 0;
  s_bi_spline_skeleton_animation_baked_cook.m_class_id = bi_spline_skeleton_animation_baked_class;
  s_bi_spline_skeleton_animation_baked_cook.m_reuse_type = reuse_true;
  s_bi_spline_skeleton_animation_baked_cook.m_creation_thread_id = -4;
  s_bi_spline_skeleton_animation_baked_cook.m_allocate_thread_id = -4;
  s_bi_spline_skeleton_animation_baked_cook.m_flags.m_flags = 16;
  s_bi_spline_skeleton_animation_baked_cook.m_next = 0;
  s_bi_spline_skeleton_animation_baked_cook.__vftable = (vostok::animation::bi_spline_skeleton_animation_baked_cook_vtbl *)&vostok::animation::bi_spline_skeleton_animation_baked_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_bi_spline_skeleton_animation_baked_cook, 0);
  return atexit(vostok::animation::_dynamic_atexit_destructor_for__s_bi_spline_skeleton_animation_baked_cook__);
}
