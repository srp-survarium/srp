void __fastcall vostok::render::speedtree_tree_component::set_material_effects(
        vostok::render::speedtree_tree_component *this,
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *a2,
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> mtl_instance_ptr,
        const char *material_name)
{
  vostok::render::material_effects_instance *m_object; // eax
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *v5; // esi
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::fs_new::virtual_path_string in_material_name; // [esp+8h] [ebp-114h] BYREF

  m_object = mtl_instance_ptr.m_object;
  if ( mtl_instance_ptr.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v5 = a2 + 27;
      vostok::render::material_manager::remove_material_effects(
        (vostok::render::material_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
      _InterlockedExchangeAdd(&mtl_instance_ptr.m_object->m_reference_count, 1u);
      v6 = v5->m_object;
      v5->m_object = mtl_instance_ptr.m_object;
      if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
      vostok::fs_new::virtual_path_string::virtual_path_string(&in_material_name, &material_name);
      vostok::render::material_manager::add_material_effects(
        (vostok::render::material_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y,
        v5,
        &in_material_name);
      m_object = mtl_instance_ptr.m_object;
    }
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &mtl_instance_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
          mtl_instance_ptr.m_object);
    }
  }
}
