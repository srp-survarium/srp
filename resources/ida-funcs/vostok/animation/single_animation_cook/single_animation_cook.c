void __thiscall vostok::animation::single_animation_cook::single_animation_cook(
        vostok::animation::single_animation_cook *this)
{
  s_single_animation_cook.m_cook_users_count.m_count = 0;
  s_single_animation_cook.m_class_id = single_animation_class;
  s_single_animation_cook.m_reuse_type = reuse_true;
  s_single_animation_cook.m_creation_thread_id = -1;
  s_single_animation_cook.m_allocate_thread_id = -4;
  s_single_animation_cook.m_flags.m_flags = 8;
  s_single_animation_cook.m_next = 0;
  s_single_animation_cook.__vftable = (vostok::animation::single_animation_cook_vtbl *)&vostok::animation::single_animation_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_single_animation_cook);
}
