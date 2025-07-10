void __thiscall survarium::text_translator::on_texts_ready(
        survarium::text_translator *this,
        vostok::resources::unmanaged_resource *data)
{
  vostok::configs::binary_config *m_object; // edi
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+Ch] [ebp-4h] BYREF

  v6.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v6,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data[1].m_children_resources);
  m_object = v6.m_object;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    v6.m_object);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_text_data,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&data);
  v4 = data;
  if ( data )
  {
    v5 = &data->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&data->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, v4);
  }
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
