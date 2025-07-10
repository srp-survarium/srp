void __usercall survarium::human_npc::select_new_goal(
        survarium::human_npc *this@<ecx>,
        const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<esi>)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v2; // [esp-4h] [ebp-4h] BYREF

  v2.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v2,
    a2 + 85);
  ((void (__thiscall *)(vostok::configs::binary_config *, vostok::configs::binary_config *))a2[81].m_object->__vftable[3].~vostok::resources::resource_base)(
    a2[81].m_object,
    v2.m_object);
}
