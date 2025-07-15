void __usercall vostok::render::scene::set_sky_material(
        vostok::render::scene *this@<eax>,
        const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *in_material@<edi>,
        vostok::render::material_manager *a3@<ecx>)
{
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *p_m_sky_material; // esi
  vostok::render::material_effects_instance *m_object; // eax
  vostok::resources::unmanaged_resource *v5; // edx

  p_m_sky_material = &this->m_sky_material;
  if ( this->m_sky_material.m_object )
    vostok::render::material_manager::remove_material_effects(
      a3,
      (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
  m_object = 0;
  if ( in_material->m_object )
  {
    m_object = in_material->m_object;
    _InterlockedExchangeAdd(&in_material->m_object->m_reference_count, 1u);
  }
  v5 = p_m_sky_material->m_object;
  p_m_sky_material->m_object = m_object;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  if ( p_m_sky_material->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::material_manager::add_material_effects(
        (vostok::render::material_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y,
        p_m_sky_material,
        &in_material->m_object->m_material_name);
  }
}
