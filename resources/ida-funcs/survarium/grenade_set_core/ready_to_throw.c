bool __usercall survarium::grenade_set_core::ready_to_throw@<al>(survarium::grenade_set_core *this@<ecx>, int a2@<eax>)
{
  bool v2; // bl
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+Ch] [ebp-4h] BYREF

  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *)&v4,
    (const vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 288) + 4 * *(unsigned __int16 *)(a2 + 280) - 4));
  v2 = v4.m_object->m_explode_time_ms == -1;
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  return v2;
}
