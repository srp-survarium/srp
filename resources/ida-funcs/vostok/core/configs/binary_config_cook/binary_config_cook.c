void __thiscall vostok::core::configs::binary_config_cook::binary_config_cook(
        vostok::core::configs::binary_config_cook *this)
{
  cook.m_cook_users_count.m_count = 0;
  cook.m_next = 0;
  cook.m_class_id = ltx_config_class;
  cook.m_reuse_type = reuse_true;
  cook.m_creation_thread_id = -1;
  cook.m_allocate_thread_id = -4;
  cook.m_flags.m_flags = 8;
  cook.__vftable = (vostok::core::configs::binary_config_cook_vtbl *)&vostok::core::configs::binary_config_cook::`vftable';
}
