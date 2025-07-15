void __usercall survarium::weapon_core::check_for_no_ammo_message(
        survarium::weapon_core *this@<ecx>,
        survarium::weapon_core *a2@<esi>)
{
  char v2; // bl
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp+4h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h]

  v2 = 0;
  v3.m_object = 0;
  v5 = ((a2->m_user->m_input.actions_mask & 0x20) != 0 || (a2->m_user->m_input.actions_mask & 0x80) != 0)
    && !(a2->m_ammo_in_magazine + a2->m_is_round_chambered)
    && ((v2 = 1, !survarium::weapon_core::ammunition(a2, &v3)->m_object)
     || (v2 = 3, !LOWORD(survarium::weapon_core::ammunition(a2, &v4)->m_object->m_lods[0].m_emitter_instance_list.m_last)));
  if ( (v2 & 2) != 0 )
  {
    v2 &= ~2u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  }
  if ( (v2 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v3);
  if ( v5 )
    a2->on_ammo_empty(a2);
}
