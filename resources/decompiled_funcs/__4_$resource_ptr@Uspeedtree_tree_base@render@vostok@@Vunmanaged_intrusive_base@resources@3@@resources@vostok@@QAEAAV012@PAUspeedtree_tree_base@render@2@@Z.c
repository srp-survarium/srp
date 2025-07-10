vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  vostok::resources::unmanaged_resource *v3; // ecx
  vostok::resources::unmanaged_resource *v4; // eax

  v2 = 0;
  if ( this )
  {
    v2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[52], 1u);
  }
  v3 = (vostok::resources::unmanaged_resource *)v2;
  v4 = *a2;
  *a2 = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return (vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *)a2;
}
