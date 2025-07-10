void __thiscall survarium::weapon_core::load_ammo(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  survarium::inventory_item *v2; // ecx
  BOOL m_chamber_a_round_on_reload; // ecx
  survarium::game_camera *v4; // ecx
  survarium::inventory_item *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  unsigned __int16 v8; // ax
  bool v9; // [esp+0h] [ebp-4Ch]
  vostok::ai::behaviour *v11; // [esp+Ch] [ebp-40h]
  vostok::ai::behaviour *m_object; // [esp+14h] [ebp-38h]
  vostok::sound::encoded_sound_interface *(__thiscall *v13)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+2Ch] [ebp-20h]
  char v14; // [esp+30h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+34h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+38h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+3Ch] [ebp-10h] BYREF
  unsigned __int16 v18; // [esp+40h] [ebp-Ch]
  char v19; // [esp+43h] [ebp-9h]
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> v20; // [esp+44h] [ebp-8h] BYREF
  bool v21; // [esp+4Bh] [ebp-1h]

  v14 = 0;
  if ( this->m_ammunition.m_object )
    v13 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
  else
    v13 = 0;
  v9 = 0;
  if ( v13 )
  {
    v14 = 1;
    vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
      &v20,
      &this->m_ammunition);
    survarium::weapon_user_dead_state::finalize(v1);
    if ( survarium::inventory_item::amount(v2, (int)v20.m_object) )
      v9 = 1;
  }
  v21 = v9;
  if ( (v14 & 1) != 0 )
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
  if ( v21 )
  {
    if ( !this->m_ammo_in_magazine )
      survarium::weapon_core::load_magazine(this);
    if ( this->m_is_there_chamber_a_round_state )
    {
      m_chamber_a_round_on_reload = this->m_chamber_a_round_on_reload;
      if ( !this->m_chamber_a_round_on_reload )
      {
        v19 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_chamber_a_round_on_reload);
        v17.m_object = 0;
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
          &v17,
          (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
        survarium::weapon_user_dead_state::finalize(v4);
        v18 = survarium::inventory_item::amount(v5, (int)v17.m_object);
        vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v17);
        if ( v18 )
        {
          this->m_is_round_chambered = 1;
          v15.m_object = 0;
          vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
            &v15,
            (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
          survarium::weapon_user_dead_state::finalize(v6);
          m_object = v15.m_object;
          v16.m_object = 0;
          vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
            &v16,
            (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
          survarium::weapon_user_dead_state::finalize(v7);
          v11 = v16.m_object;
          v8 = survarium::inventory_item::amount((survarium::inventory_item *)v16.m_object, (int)m_object);
          survarium::inventory_item::set_amount((survarium::inventory_item *)(v8 - 1), (int)v11);
          vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
          vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15);
        }
        else if ( this->m_ammo_in_magazine )
        {
          this->m_is_round_chambered = 1;
          --this->m_ammo_in_magazine;
        }
      }
    }
  }
}
