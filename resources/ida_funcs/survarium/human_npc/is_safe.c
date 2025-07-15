int __thiscall survarium::human_npc::is_safe(survarium::human_npc *this)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp-4h] [ebp-8h] BYREF

  v3.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v3,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_brain_unit);
  return ((int (__thiscall *)(vostok::ai::world *, vostok::configs::binary_config *))this->m_ai_world->is_npc_safe)(
           this->m_ai_world,
           v3.m_object);
}
