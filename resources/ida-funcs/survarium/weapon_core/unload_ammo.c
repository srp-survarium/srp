void __thiscall survarium::weapon_core::unload_ammo(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::inventory_item *v3; // ecx
  unsigned __int16 v4; // ax
  survarium::weapon_user_animations_container *v6; // [esp+Ch] [ebp-28h]
  vostok::ai::behaviour *m_object; // [esp+18h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+20h] [ebp-14h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+24h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+28h] [ebp-Ch] BYREF
  bool v11; // [esp+2Fh] [ebp-5h]
  unsigned __int16 ammo_to_add; // [esp+30h] [ebp-4h]

  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
  v11 = v10.m_object == 0;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
  if ( !v11 )
  {
    ammo_to_add = this->m_ammo_in_magazine;
    this->m_ammo_in_magazine = 0;
    if ( this->m_is_round_chambered )
    {
      ++ammo_to_add;
      this->m_is_round_chambered = 0;
    }
    v8.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v8,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
    survarium::weapon_user_dead_state::finalize(v1);
    m_object = v8.m_object;
    v9.m_object = 0;
    v2 = 0;
    if ( this->m_ammunition.m_object )
    {
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
      v9.m_object = (survarium::weapon_user_animations_container *)this->m_ammunition.m_object;
      if ( v9.m_object )
        vostok::threading::interlocked_increment(&v9.m_object->vostok::resources::unmanaged_intrusive_base);
    }
    survarium::weapon_user_dead_state::finalize(v2);
    v6 = v9.m_object;
    v4 = survarium::inventory_item::amount(v3, (int)m_object);
    survarium::inventory_item::set_amount((survarium::inventory_item *)(ammo_to_add + v4), (int)v6);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
  }
}
