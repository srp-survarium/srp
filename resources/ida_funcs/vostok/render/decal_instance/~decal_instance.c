void __usercall vostok::render::decal_instance::~decal_instance(
        vostok::render::decal_instance *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::unmanaged_resource **v3; // esi
  vostok::render::material_manager *v4; // ecx

  vostok::render::decal_instance::remove_collision(this, a2);
  v3 = (vostok::resources::unmanaged_resource **)(a2 + 68);
  vostok::render::material_manager::remove_material_effects(
    v4,
    (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
  if ( *v3 )
  {
    if ( !_InterlockedExchangeAdd(&(*v3)->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v3)->vostok::resources::unmanaged_intrusive_base, *v3);
  }
}
