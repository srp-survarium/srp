void __thiscall survarium::simple_game_project::on_npc_loaded(
        survarium::simple_game_project *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v3; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v4.m_object;
  if ( v4.m_object )
  {
    v3 = &v4.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v4.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v3, m_object);
  }
}
