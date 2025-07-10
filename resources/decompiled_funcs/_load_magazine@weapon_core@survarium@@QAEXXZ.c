void __thiscall survarium::weapon_core::load_magazine(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  survarium::inventory_item *v2; // ecx
  survarium::weapon_user_animations_container *v3; // ecx
  unsigned __int16 v4; // [esp+6h] [ebp-2Eh]
  survarium::weapon_user_animations_container **p_m_ammunition; // [esp+10h] [ebp-24h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+20h] [ebp-14h] BYREF
  unsigned __int16 v8; // [esp+26h] [ebp-Eh]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+28h] [ebp-Ch] BYREF
  unsigned __int16 load; // [esp+2Ch] [ebp-8h]
  unsigned __int16 amount; // [esp+30h] [ebp-4h]

  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
  survarium::weapon_user_dead_state::finalize(v1);
  amount = survarium::inventory_item::amount(v2, (int)v9.m_object);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9);
  v8 = this->m_magazine_capacity - this->m_ammo_in_magazine;
  if ( amount >= (int)v8 )
    v4 = v8;
  else
    v4 = amount;
  load = v4;
  p_m_ammunition = (survarium::weapon_user_animations_container **)&this->m_ammunition;
  v7.m_object = 0;
  v3 = (survarium::weapon_user_animations_container *)&this->m_ammunition;
  if ( this->m_ammunition.m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
    v3 = *p_m_ammunition;
    v7.m_object = *p_m_ammunition;
    if ( v7.m_object )
      vostok::threading::interlocked_increment(&v7.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  survarium::inventory_item::set_amount((survarium::inventory_item *)(amount - load), (int)v7.m_object);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  this->m_ammo_in_magazine += load;
  if ( this->m_chamber_a_round_on_reload )
    survarium::weapon_core::chamber_a_round(this);
}
