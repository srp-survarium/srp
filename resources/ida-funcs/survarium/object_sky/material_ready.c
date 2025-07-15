void __thiscall survarium::object_sky::material_ready(
        survarium::object_sky *this,
        vostok::resources::queries_result *data,
        vostok::resources::unmanaged_resource *cook_data,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::render::material_effects_instance_cook_data *v6; // eax
  vostok::resources::unmanaged_resource *v7; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax

  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (vostok::resources::unmanaged_resource ***)&cook_data);
  cook_data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cook_data,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  v5 = cook_data;
  v6 = 0;
  if ( cook_data )
  {
    v6 = (vostok::render::material_effects_instance_cook_data *)cook_data;
    _InterlockedExchangeAdd(&cook_data->m_reference_count, 1u);
  }
  v7 = (vostok::resources::unmanaged_resource *)v6;
  m_object = this->m_sky_material.m_object;
  this->m_sky_material.m_object = v7;
  if ( m_object )
  {
    v7 = (vostok::resources::unmanaged_resource *)&m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v7, m_object);
  }
  if ( v5 )
  {
    v7 = (vostok::resources::unmanaged_resource *)&v5->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v7, v5);
  }
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)v7,
    cb,
    (const char *)this);
}
