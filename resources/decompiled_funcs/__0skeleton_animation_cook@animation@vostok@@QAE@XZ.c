void __thiscall vostok::animation::skeleton_animation_cook::skeleton_animation_cook(
        vostok::animation::skeleton_animation_cook *this)
{
  s_skeleton_animation_cook.m_cook_users_count.m_count = 0;
  s_skeleton_animation_cook.m_class_id = animation_class;
  s_skeleton_animation_cook.m_reuse_type = reuse_true;
  s_skeleton_animation_cook.m_creation_thread_id = -1;
  s_skeleton_animation_cook.m_allocate_thread_id = -4;
  s_skeleton_animation_cook.m_flags.m_flags = 8;
  s_skeleton_animation_cook.m_next = 0;
  s_skeleton_animation_cook.__vftable = (vostok::animation::skeleton_animation_cook_vtbl *)&vostok::animation::skeleton_animation_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_skeleton_animation_cook);
}
