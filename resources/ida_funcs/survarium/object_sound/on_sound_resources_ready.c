void __thiscall survarium::object_sound::on_sound_resources_ready(
        survarium::object_sound *this,
        vostok::resources::unmanaged_resource *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *callback)
{
  vostok::configs::binary_config *m_object; // ebx
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::resources::queries_result *v6; // eax
  vostok::sound::sound_emitter *v7; // ecx
  vostok::sound::sound_emitter *v8; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+10h] [ebp-4h] BYREF

  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data[1].m_children_resources);
  m_object = v9.m_object;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    v9.m_object);
  v5 = data;
  v6 = 0;
  if ( data )
  {
    v6 = (vostok::resources::queries_result *)data;
    _InterlockedExchangeAdd(&data->m_reference_count, 1u);
  }
  v7 = (vostok::sound::sound_emitter *)v6;
  v8 = this->m_sound_emitter.m_object;
  this->m_sound_emitter.m_object = v7;
  if ( v8 )
  {
    v7 = (vostok::sound::sound_emitter *)&v8->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v7, v8);
  }
  if ( v5 )
  {
    v7 = (vostok::sound::sound_emitter *)&v5->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v7, v5);
  }
  if ( m_object )
  {
    v7 = (vostok::sound::sound_emitter *)&m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v7, m_object);
  }
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)v7,
    callback,
    (const char *)this);
}
