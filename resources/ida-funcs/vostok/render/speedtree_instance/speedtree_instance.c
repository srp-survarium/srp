void __userpurge vostok::render::speedtree_instance::speedtree_instance(
        vostok::render::speedtree_instance *this@<ecx>,
        vostok::resources::unmanaged_resource *a2@<esi>,
        vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> in_speedtree_tree_ptr)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(a2, 1u);
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&stru_966A14.m_name.m_string.m_buffer[32];
  a2[1].m_parent_resources.m_lock = 0;
  if ( in_speedtree_tree_ptr.m_object )
  {
    a2[1].m_parent_resources.m_lock = (unsigned int)in_speedtree_tree_ptr.m_object;
    _InterlockedExchangeAdd(&in_speedtree_tree_ptr.m_object->m_reference_count, 1u);
    if ( !_InterlockedExchangeAdd(&in_speedtree_tree_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &in_speedtree_tree_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        in_speedtree_tree_ptr.m_object);
  }
}
