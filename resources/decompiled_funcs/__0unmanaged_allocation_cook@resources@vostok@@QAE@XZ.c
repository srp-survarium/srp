void __thiscall vostok::resources::unmanaged_allocation_cook::unmanaged_allocation_cook(
        vostok::resources::unmanaged_allocation_cook *this)
{
  s_unmanaged_allocation_cook.m_cook_users_count.m_count = 0;
  s_unmanaged_allocation_cook.m_reuse_type = reuse_false;
  s_unmanaged_allocation_cook.m_flags.m_flags = 0;
  s_unmanaged_allocation_cook.m_next = 0;
  s_unmanaged_allocation_cook.m_class_id = unmanaged_allocation_class;
  s_unmanaged_allocation_cook.m_creation_thread_id = -4;
  s_unmanaged_allocation_cook.m_allocate_thread_id = -4;
  s_unmanaged_allocation_cook.__vftable = (vostok::resources::unmanaged_allocation_cook_vtbl *)&vostok::resources::unmanaged_allocation_cook::`vftable';
}
