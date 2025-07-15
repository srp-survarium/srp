int vostok::resources::_dynamic_initializer_for__s_sub_fat_cook__()
{
  s_sub_fat_cook.m_allocate_thread_id = -1;
  s_sub_fat_cook.m_next = 0;
  s_sub_fat_cook.m_cook_users_count.m_count = 0;
  s_sub_fat_cook.m_class_id = vfs_sub_fat_class;
  s_sub_fat_cook.m_reuse_type = reuse_true;
  s_sub_fat_cook.m_creation_thread_id = -4;
  s_sub_fat_cook.m_flags.m_flags = 2;
  s_sub_fat_cook.__vftable = (vostok::resources::vfs_sub_fat_cook_vtbl *)&vostok::resources::vfs_sub_fat_cook::`vftable';
  return atexit(vostok::resources::_dynamic_atexit_destructor_for__s_sub_fat_cook__);
}
