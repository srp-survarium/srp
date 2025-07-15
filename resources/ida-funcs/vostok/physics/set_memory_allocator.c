void __thiscall vostok::physics::set_memory_allocator(vostok::physics::animated_model_instance_cook *this)
{
  vostok::physics::animated_model_instance_cook *v1; // [esp-4h] [ebp-4h]
  vostok::physics::animated_model_instance_cook *v2; // [esp-4h] [ebp-4h]

  vostok::physics::g_allocator = &vostok::memory::g_mt_allocator;
  if ( (_S6_5 & 1) == 0 )
  {
    _S6_5 |= 1u;
    vostok::physics::collision_shape_cook::collision_shape_cook(
      (vostok::physics::collision_shape_cook *)0x1D,
      (int)&collision_shape_cooker_static);
    atexit((int (__cdecl *)())vostok::physics::set_memory_allocator_::_6_::_dynamic_atexit_destructor_for__collision_shape_cooker_static__);
    this = v1;
  }
  if ( (_S6_5 & 2) == 0 )
  {
    _S6_5 |= 2u;
    vostok::physics::collision_shape_cook::collision_shape_cook(
      (vostok::physics::collision_shape_cook *)0x1E,
      (int)&editor_collision_shape_cooker_static);
    editor_collision_shape_cooker_static.__vftable = (vostok::physics::editor_collision_shape_cook_vtbl *)&vostok::physics::editor_collision_shape_cook::`vftable';
    editor_collision_shape_cooker_static.m_fill_gmtl = 0;
    atexit((int (__cdecl *)())vostok::physics::set_memory_allocator_::_6_::_dynamic_atexit_destructor_for__editor_collision_shape_cooker_static__);
    this = v2;
  }
  if ( (_S6_5 & 4) == 0 )
  {
    _S6_5 |= 4u;
    vostok::physics::animated_model_instance_cook::animated_model_instance_cook(this);
    atexit((int (__cdecl *)())vostok::physics::set_memory_allocator_::_6_::_dynamic_atexit_destructor_for__animated_model_cook__);
  }
}
