void __thiscall survarium::object_vegetation::on_grass_loaded(
        survarium::object_vegetation *this,
        vostok::resources::queries_result *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v5; // eax
  vostok::resources::unmanaged_resource *v6; // ecx
  vostok::resources::unmanaged_resource *v7; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+Ch] [ebp-4h] BYREF

  v8.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v8,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v8.m_object;
  v5 = 0;
  if ( v8.m_object )
  {
    v5 = v8.m_object;
    _InterlockedExchangeAdd(&v8.m_object->m_reference_count, 1u);
  }
  v6 = v5;
  v7 = this->m_grass.m_object;
  this->m_grass.m_object = v6;
  if ( v7 )
  {
    v6 = (vostok::resources::unmanaged_resource *)&v7->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v6, v7);
  }
  if ( m_object )
  {
    v6 = (vostok::resources::unmanaged_resource *)&m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v6, m_object);
  }
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)v6,
    cb,
    (const char *)this);
}
