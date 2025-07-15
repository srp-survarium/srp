void __userpurge vostok::render::speedtree_tree::set_material_effects(
        vostok::render::speedtree_tree *this@<eax>,
        vostok::render::speedtree_tree::component_type in_component_type@<ecx>,
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> mtl_instance_ptr,
        const char *material_name)
{
  vostok::render::speedtree_tree_component_billboard *m_branch_component; // ecx

  switch ( in_component_type )
  {
    case branch:
      m_branch_component = (vostok::render::speedtree_tree_component_billboard *)this->m_branch_component;
      break;
    case frond:
      m_branch_component = (vostok::render::speedtree_tree_component_billboard *)this->m_frond_component;
      break;
    case leafmesh:
      m_branch_component = (vostok::render::speedtree_tree_component_billboard *)this->m_leafmesh_component;
      break;
    case leafcard:
      m_branch_component = (vostok::render::speedtree_tree_component_billboard *)this->m_leafcard_component;
      break;
    case billboard:
      m_branch_component = this->m_billboard_component;
      break;
  }
  if ( m_branch_component )
  {
    if ( mtl_instance_ptr.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      _InterlockedExchangeAdd(&mtl_instance_ptr.m_object->m_reference_count, 1u);
      vostok::render::speedtree_tree_component::set_material_effects(
        m_branch_component,
        (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)m_branch_component,
        mtl_instance_ptr,
        material_name);
    }
    else
    {
      ((void (__thiscall *)(vostok::render::speedtree_tree_component_billboard *, vostok::render::speedtree_tree::component_type))m_branch_component->set_default_material)(
        m_branch_component,
        in_component_type);
    }
  }
  if ( mtl_instance_ptr.m_object )
  {
    if ( !_InterlockedExchangeAdd(&mtl_instance_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &mtl_instance_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        mtl_instance_ptr.m_object);
  }
}
