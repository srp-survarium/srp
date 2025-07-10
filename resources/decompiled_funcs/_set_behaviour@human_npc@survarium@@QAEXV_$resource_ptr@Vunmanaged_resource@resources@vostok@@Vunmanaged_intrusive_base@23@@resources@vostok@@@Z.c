void __userpurge survarium::human_npc::set_behaviour(
        survarium::human_npc *this@<ecx>,
        const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> new_behaviour)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp-4h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    a2 + 85);
  v3.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v3,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&new_behaviour);
  ((void (__thiscall *)(vostok::configs::binary_config *, vostok::configs::binary_config *, vostok::configs::binary_config *))a2[81].m_object->decrease_quality)(
    a2[81].m_object,
    v3.m_object,
    v4.m_object);
  if ( new_behaviour.m_object )
  {
    if ( !_InterlockedExchangeAdd(&new_behaviour.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &new_behaviour.m_object->vostok::resources::unmanaged_intrusive_base,
        new_behaviour.m_object);
  }
}
