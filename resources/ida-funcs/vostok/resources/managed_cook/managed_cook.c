void __userpurge vostok::resources::managed_cook::managed_cook(
        vostok::resources::managed_cook *this@<ecx>,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> resource_class,
        vostok::resources::cook_base::reuse_enum reuse_type,
        unsigned int creation_thread_id,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  s_cubic_spline_skeleton_animation_cook.m_flags.m_flags = resource_class.m_flags | 0x21;
  s_cubic_spline_skeleton_animation_cook.m_cook_users_count.m_count = 0;
  s_cubic_spline_skeleton_animation_cook.m_class_id = cubic_spline_skeleton_animation_class;
  s_cubic_spline_skeleton_animation_cook.m_reuse_type = reuse_true;
  s_cubic_spline_skeleton_animation_cook.m_creation_thread_id = -4;
  s_cubic_spline_skeleton_animation_cook.m_allocate_thread_id = -1;
  s_cubic_spline_skeleton_animation_cook.m_next = 0;
  s_cubic_spline_skeleton_animation_cook.__vftable = (vostok::animation::cubic_spline_skeleton_animation_cook_vtbl *)&vostok::resources::managed_cook::`vftable';
}
