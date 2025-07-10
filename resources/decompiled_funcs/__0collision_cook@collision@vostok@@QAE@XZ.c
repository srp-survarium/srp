void __thiscall vostok::collision::collision_cook::collision_cook(vostok::collision::collision_cook *this)
{
  collision_cooker.m_cook_users_count.m_count = 0;
  collision_cooker.m_next = 0;
  collision_cooker.m_class_id = collision_geometry_class;
  collision_cooker.m_reuse_type = reuse_true;
  collision_cooker.m_creation_thread_id = -1;
  collision_cooker.m_allocate_thread_id = -4;
  collision_cooker.m_flags.m_flags = 8;
  collision_cooker.__vftable = (vostok::collision::collision_cook_vtbl *)&vostok::collision::collision_cook::`vftable';
}
