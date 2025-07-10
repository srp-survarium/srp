void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::decal_instance>(
        vostok::render::decal_instance *const pointer@<eax>,
        vostok::render::decal_instance *a2@<ecx>,
        vostok::memory::detail::call_destructor_predicate *this)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_material; // esi
  vostok::render::material_manager *v5; // ecx

  vostok::render::decal_instance::remove_collision(a2);
  p_material = &pointer->m_properties.material;
  vostok::render::material_manager::remove_material_effects(
    v5,
    (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
  if ( p_material->m_object )
  {
    if ( !_InterlockedExchangeAdd(&p_material->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &p_material->m_object->vostok::resources::unmanaged_intrusive_base,
        p_material->m_object);
  }
}
