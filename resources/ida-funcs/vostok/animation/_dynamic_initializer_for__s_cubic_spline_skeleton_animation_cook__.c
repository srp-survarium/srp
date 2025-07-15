int __thiscall vostok::animation::_dynamic_initializer_for__s_cubic_spline_skeleton_animation_cook__(
        vostok::buffer_vector<vostok::resources::cook_base *> *this)
{
  s_cubic_spline_skeleton_animation_cook.m_allocate_thread_id = -1;
  s_cubic_spline_skeleton_animation_cook.m_cook_users_count.m_count = 0;
  s_cubic_spline_skeleton_animation_cook.m_class_id = cubic_spline_skeleton_animation_class;
  s_cubic_spline_skeleton_animation_cook.m_reuse_type = reuse_true;
  s_cubic_spline_skeleton_animation_cook.m_creation_thread_id = -4;
  s_cubic_spline_skeleton_animation_cook.m_flags.m_flags = 33;
  s_cubic_spline_skeleton_animation_cook.m_next = 0;
  s_cubic_spline_skeleton_animation_cook.__vftable = (vostok::animation::cubic_spline_skeleton_animation_cook_vtbl *)&vostok::animation::cubic_spline_skeleton_animation_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_cubic_spline_skeleton_animation_cook, this);
  return atexit(vostok::animation::_dynamic_atexit_destructor_for__s_cubic_spline_skeleton_animation_cook__);
}
