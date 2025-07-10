void __thiscall survarium::object_wire::resources_ready(
        survarium::object_wire *this,
        vostok::resources::queries_result *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const char *m_data; // eax
  survarium::object_wire *v4; // ebx
  char *v5; // eax
  malloc_state *v6; // esi
  vostok::configs::binary_config *v7; // esi
  vostok::configs::binary_config *m_object; // edi
  vostok::resources::unmanaged_intrusive_base *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::resources::unmanaged_resource *v11; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+10h] [ebp-10h] BYREF
  survarium::object_wire *v13; // [esp+14h] [ebp-Ch]
  vostok::const_buffer user_data_to_create; // [esp+18h] [ebp-8h] BYREF

  m_data = data->m_queries[0].m_creation_data_from_user.m_data;
  v4 = this;
  user_data_to_create.m_size = data->m_queries[0].m_creation_data_from_user.m_size;
  v13 = this;
  user_data_to_create.m_data = m_data;
  v5 = (char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&user_data_to_create);
  if ( v5 )
  {
    v6 = *(malloc_state **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v6, v5);
  }
  v7 = 0;
  v12.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v12,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v12.m_object;
  if ( v12.m_object )
  {
    v7 = v12.m_object;
    _InterlockedExchangeAdd(&v12.m_object->m_reference_count, 1u);
  }
  v9 = 0;
  if ( v7 )
  {
    v9 = (vostok::resources::unmanaged_intrusive_base *)v7;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  v10 = v9;
  v11 = v4->m_visual.m_object;
  v4->m_visual.m_object = (vostok::render::render_model_instance *)v10;
  if ( v11 )
  {
    v10 = &v11->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, v11);
    v4 = v13;
  }
  if ( v7 )
  {
    v10 = &v7->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, v7);
  }
  if ( m_object )
  {
    v10 = &m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, m_object);
  }
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)v10,
    cb,
    (const char *)v4);
}
