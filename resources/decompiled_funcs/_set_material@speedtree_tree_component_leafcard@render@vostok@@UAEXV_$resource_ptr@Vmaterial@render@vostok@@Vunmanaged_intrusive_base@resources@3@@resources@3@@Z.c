void __thiscall vostok::render::speedtree_tree_component_leafcard::set_material(
        vostok::render::speedtree_tree_component_leafcard *this,
        vostok::resources::resource_ptr<vostok::render::material,vostok::resources::unmanaged_intrusive_base> mtl_ptr)
{
  if ( mtl_ptr.m_object )
  {
    if ( !_InterlockedExchangeAdd(&mtl_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &mtl_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        mtl_ptr.m_object);
  }
}
