void __thiscall survarium::weapon_core::reload_one_round(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  survarium::inventory_item *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::inventory_item *v5; // ecx
  unsigned __int16 v6; // ax
  bool v7; // [esp+4h] [ebp-3Ch]
  survarium::weapon_user_animations_container *v9; // [esp+10h] [ebp-30h]
  vostok::ai::behaviour *m_object; // [esp+1Ch] [ebp-24h]
  char v11; // [esp+2Ch] [ebp-14h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+30h] [ebp-10h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+34h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+38h] [ebp-8h] BYREF
  bool v15; // [esp+3Fh] [ebp-1h]

  v11 = 0;
  v7 = 0;
  if ( this->m_ammo_in_magazine != this->m_magazine_capacity )
  {
    v11 = 1;
    v14.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v14,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
    survarium::weapon_user_dead_state::finalize(v1);
    if ( survarium::inventory_item::amount(v2, (int)v14.m_object) )
      v7 = 1;
  }
  v15 = v7;
  if ( (v11 & 1) != 0 )
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
  if ( v15 )
  {
    ++this->m_ammo_in_magazine;
    v12.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v12,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
    survarium::weapon_user_dead_state::finalize(v3);
    m_object = v12.m_object;
    v13.m_object = 0;
    v4 = 0;
    if ( this->m_ammunition.m_object )
    {
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
      v13.m_object = (survarium::weapon_user_animations_container *)this->m_ammunition.m_object;
      if ( v13.m_object )
        vostok::threading::interlocked_increment(&v13.m_object->vostok::resources::unmanaged_intrusive_base);
    }
    survarium::weapon_user_dead_state::finalize(v4);
    v9 = v13.m_object;
    v6 = survarium::inventory_item::amount(v5, (int)m_object);
    survarium::inventory_item::set_amount((survarium::inventory_item *)(v6 - 1), (int)v9);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12);
  }
  this->on_reload(this);
}
