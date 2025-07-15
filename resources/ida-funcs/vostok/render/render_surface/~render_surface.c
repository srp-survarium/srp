void __thiscall vostok::render::render_surface::~render_surface(vostok::render::render_surface *this)
{
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *p_m_materail_effects_instance; // esi
  vostok::render::render_geometry *v3; // ecx
  const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *y; // [esp-8h] [ebp-10h]

  p_m_materail_effects_instance = &this->m_materail_effects_instance;
  y = (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y;
  this->__vftable = (vostok::render::render_surface_vtbl *)&stru_962594.m_declarations;
  vostok::render::material_manager::remove_material_effects((vostok::render::material_manager *)this, y);
  if ( p_m_materail_effects_instance->m_object )
  {
    v3 = (vostok::render::render_geometry *)_InterlockedExchangeAdd(
                                              &p_m_materail_effects_instance->m_object->m_reference_count,
                                              0xFFFFFFFF);
    if ( !v3 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &p_m_materail_effects_instance->m_object->vostok::resources::unmanaged_intrusive_base,
        p_m_materail_effects_instance->m_object);
  }
  vostok::render::render_geometry::~render_geometry(
    v3,
    (const vostok::render::res_geometry **)&this->m_render_geometry.geom.m_object);
}
