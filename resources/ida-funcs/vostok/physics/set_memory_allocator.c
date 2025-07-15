void __thiscall vostok::physics::set_memory_allocator(vostok::physics::animated_model_instance_cook *this)
{
  int v1; // ecx
  int v2; // ecx

  vostok::physics::g_ph_allocator = &vostok::memory::g_mt_allocator;
  if ( (_S4_4 & 1) == 0 )
  {
    _S4_4 |= 1u;
    collision_shape_cooker_static.__vftable = (vostok::physics::collision_shape_cook_vtbl *)&vostok::resources::cook_base::`vftable';
    collision_shape_cooker_static.m_cook_users_count.m_count = 0;
    collision_shape_cooker_static.m_class_id = collision_bt_shape_class_static;
    collision_shape_cooker_static.m_reuse_type = reuse_true;
    collision_shape_cooker_static.m_creation_thread_id = -1;
    collision_shape_cooker_static.m_allocate_thread_id = GetCurrentThreadId();
    collision_shape_cooker_static.m_flags.m_flags = 8;
    collision_shape_cooker_static.m_next = 0;
    collision_shape_cooker_static.__vftable = (vostok::physics::collision_shape_cook_vtbl *)&vostok::physics::collision_shape_cook::`vftable';
    collision_shape_cooker_static.m_static_object = 1;
    vostok::resources::resources_manager::register_cook(v1, &collision_shape_cooker_static);
    atexit(vostok::physics::set_memory_allocator_::_6_::_dynamic_atexit_destructor_for__collision_shape_cooker_static__);
  }
  if ( (_S4_4 & 2) == 0 )
  {
    _S4_4 |= 2u;
    collision_shape_cooker_dynamic.__vftable = (vostok::physics::collision_shape_cook_vtbl *)&vostok::resources::cook_base::`vftable';
    collision_shape_cooker_dynamic.m_cook_users_count.m_count = 0;
    collision_shape_cooker_dynamic.m_class_id = collision_bt_shape_class_dynamic;
    collision_shape_cooker_dynamic.m_reuse_type = reuse_true;
    collision_shape_cooker_dynamic.m_creation_thread_id = -1;
    collision_shape_cooker_dynamic.m_allocate_thread_id = GetCurrentThreadId();
    collision_shape_cooker_dynamic.m_flags.m_flags = 8;
    collision_shape_cooker_dynamic.m_next = 0;
    collision_shape_cooker_dynamic.__vftable = (vostok::physics::collision_shape_cook_vtbl *)&vostok::physics::collision_shape_cook::`vftable';
    collision_shape_cooker_dynamic.m_static_object = 0;
    vostok::resources::resources_manager::register_cook(v2, &collision_shape_cooker_dynamic);
    atexit(vostok::physics::set_memory_allocator_::_6_::_dynamic_atexit_destructor_for__collision_shape_cooker_dynamic__);
  }
  if ( (_S4_4 & 4) == 0 )
  {
    _S4_4 |= 4u;
    vostok::physics::animated_model_instance_cook::animated_model_instance_cook(this);
    atexit(vostok::physics::set_memory_allocator_::_6_::_dynamic_atexit_destructor_for__animated_model_cook__);
  }
}
