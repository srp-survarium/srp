void __thiscall vostok::physics::animated_model_instance_cook::animated_model_instance_cook(
        vostok::physics::animated_model_instance_cook *this)
{
  int v1; // ecx

  animated_model_cook.__vftable = (vostok::physics::animated_model_instance_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  animated_model_cook.m_cook_users_count.m_count = 0;
  animated_model_cook.m_class_id = physics_animated_model_instance_class;
  animated_model_cook.m_reuse_type = reuse_false;
  animated_model_cook.m_creation_thread_id = -1;
  animated_model_cook.m_allocate_thread_id = GetCurrentThreadId();
  animated_model_cook.m_flags.m_flags = 8;
  animated_model_cook.m_next = 0;
  animated_model_cook.__vftable = (vostok::physics::animated_model_instance_cook_vtbl *)&vostok::physics::animated_model_instance_cook::`vftable';
  animated_model_cook.m_allocator = vostok::physics::g_ph_allocator;
  vostok::resources::resources_manager::register_cook(v1, &animated_model_cook);
}
