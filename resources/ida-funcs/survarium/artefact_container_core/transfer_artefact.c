void __userpurge survarium::artefact_container_core::transfer_artefact(
        survarium::artefact_container_core *this@<ecx>,
        int a2@<esi>,
        survarium::inventory_holder *holder)
{
  int v3; // eax
  vostok::particle::particle_system_instance_impl *v4; // edi
  survarium::inventory_holder *v5; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+4h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(a2 + 80);
  v6.m_object = 0;
  *(_BYTE *)(v3 + 304) = -1;
  v4 = *(vostok::particle::particle_system_instance_impl **)(a2 + 80);
  if ( v4 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
    v6.m_object = v4;
    this = (survarium::artefact_container_core *)_InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  survarium::inventory::take_artefact(
    (survarium::inventory *)this,
    holder->m_inventory.m_object,
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  v5 = *(survarium::inventory_holder **)(a2 + 80);
  *(_DWORD *)(a2 + 80) = 0;
  holder = v5;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&holder);
}
