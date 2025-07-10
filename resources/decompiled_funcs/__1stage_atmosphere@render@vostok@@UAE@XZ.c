void __thiscall vostok::render::stage_atmosphere::~stage_atmosphere(
        vostok::render::stage_atmosphere *this,
        vostok::render::stage_atmosphere *thisa)
{
  vostok::render::res_geometry *m_object; // eax
  bool v3; // zf
  vostok::render::untyped_buffer *v4; // eax
  vostok::render::res_effect *v5; // eax
  vostok::render::box_geometry *v6; // ecx

  thisa->__vftable = (vostok::render::stage_atmosphere_vtbl *)&stru_965008.m_name.m_string.m_buffer[88];
  m_object = thisa->m_screen_vertex_geometry.m_object;
  if ( m_object )
  {
    v3 = m_object->m_reference_count-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_screen_vertex_geometry.m_object);
  }
  v4 = thisa->m_screen_vertex_ib.m_object;
  if ( v4 )
  {
    v3 = v4->m_reference_count-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_screen_vertex_ib.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v5 = thisa->m_atmospheric_scattering_effect.m_object;
  if ( v5 )
  {
    this = (vostok::render::stage_atmosphere *)_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->m_atmospheric_scattering_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->m_atmospheric_scattering_effect.m_object);
  }
  vostok::render::box_geometry::~box_geometry((vostok::render::box_geometry *)this, (int)&thisa->m_clouds_geometry);
  vostok::render::box_geometry::~box_geometry(v6, (int)&thisa->m_sky_dome_geometry);
  thisa->__vftable = (vostok::render::stage_atmosphere_vtbl *)&vostok::render::stage::`vftable';
}
