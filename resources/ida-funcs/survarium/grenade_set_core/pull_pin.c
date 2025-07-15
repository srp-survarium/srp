void __userpurge survarium::grenade_set_core::pull_pin(
        survarium::grenade_set_core *this@<ecx>,
        int a2@<eax>,
        const unsigned int current_time_in_ms)
{
  unsigned int v4; // ebx
  unsigned __int16 *v5; // edi
  survarium::inventory_item *v6; // ecx
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v8; // [esp+18h] [ebp+8h]

  v4 = current_time_in_ms + *(unsigned __int16 *)(a2 + 364);
  v5 = (unsigned __int16 *)(a2 + 280);
  v6 = (survarium::inventory_item *)*(unsigned __int16 *)(a2 + 280);
  LOWORD(v6) = (_WORD)v6 - 1;
  v8 = *(_DWORD *)(*(_DWORD *)(a2 + 264) + 51184);
  survarium::inventory_item::set_amount(v6, a2);
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *)&v7,
    (const vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 288) + 4 * *v5));
  ((void (__fastcall *)(survarium::grenade_core *, unsigned int, unsigned int))v7.m_object->pull_pin)(
    v7.m_object,
    (v8 < v4 ? v4 - v8 - 1 : 0) % 0x32,
    v8 + 50 * ((v8 < v4 ? v4 - v8 - 1 : 0) / 0x32 + 1));
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
}
