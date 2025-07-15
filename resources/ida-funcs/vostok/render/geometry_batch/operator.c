vostok::render::geometry_batch *__usercall vostok::render::geometry_batch::operator=@<eax>(
        vostok::render::geometry_batch *this@<esi>,
        const vostok::render::geometry_batch *__that@<edi>)
{
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects_instance *v3; // eax
  vostok::render::material_effects_instance *v4; // edx
  vostok::render::res_geometry *v5; // ecx
  vostok::render::res_geometry *v6; // eax
  vostok::render::res_geometry *v7; // ecx
  vostok::render::res_geometry *v8; // eax

  *(_QWORD *)&this->bbox.min.x = *(_QWORD *)&__that->bbox.min.x;
  *(_QWORD *)&this->bbox.min.elements[2] = *(_QWORD *)&__that->bbox.min.elements[2];
  *(_QWORD *)&this->bbox.max.elements[1] = *(_QWORD *)&__that->bbox.max.elements[1];
  m_object = __that->mtl.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = __that->mtl.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = this->mtl.m_object;
  this->mtl.m_object = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  v5 = __that->geometry.m_object;
  v6 = 0;
  if ( v5 )
  {
    v6 = __that->geometry.m_object;
    ++v5->m_reference_count;
  }
  v7 = v6;
  v8 = this->geometry.m_object;
  this->geometry.m_object = v7;
  if ( v8 )
  {
    if ( v8->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v8);
  }
  this->num_indices = __that->num_indices;
  return this;
}
