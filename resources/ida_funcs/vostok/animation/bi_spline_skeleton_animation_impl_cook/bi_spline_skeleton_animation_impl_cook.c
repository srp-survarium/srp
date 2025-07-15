void __thiscall vostok::animation::bi_spline_skeleton_animation_impl_cook::bi_spline_skeleton_animation_impl_cook(
        vostok::animation::bi_spline_skeleton_animation_impl_cook *this)
{
  s_bi_spline_skeleton_animation_impl_cook.m_cook_users_count.m_count = 0;
  s_bi_spline_skeleton_animation_impl_cook.m_class_id = bi_spline_skeleton_animation_class;
  s_bi_spline_skeleton_animation_impl_cook.m_reuse_type = reuse_true;
  s_bi_spline_skeleton_animation_impl_cook.m_creation_thread_id = -1;
  s_bi_spline_skeleton_animation_impl_cook.m_allocate_thread_id = -4;
  s_bi_spline_skeleton_animation_impl_cook.m_flags.m_flags = 8;
  s_bi_spline_skeleton_animation_impl_cook.m_next = 0;
  s_bi_spline_skeleton_animation_impl_cook.__vftable = (vostok::animation::bi_spline_skeleton_animation_impl_cook_vtbl *)&vostok::animation::bi_spline_skeleton_animation_impl_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_bi_spline_skeleton_animation_impl_cook);
}
