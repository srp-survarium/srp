void __thiscall survarium::weapon_user_animations_container_cook::delete_resource(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::resource_base *resource)
{
  boost::intrusive::rbtree_node<void *>::color color; // ebx
  unsigned int v3; // edi
  unsigned int m_size; // ebx
  unsigned int i; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  color = resource[5].grm_satisfaction_tree_hook.color_;
  v3 = 0;
  if ( color )
  {
    do
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)resource[5].grm_satisfaction_tree_hook.right_
      + v3++);
    while ( v3 < color );
  }
  m_size = resource[10].m_children_resources.m_size;
  for ( i = 0; i < m_size; ++i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(resource[10].m_uid + 4 * i));
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v6, (int)survarium::g_allocator, (char *)resource, v7, v8, v9);
}
