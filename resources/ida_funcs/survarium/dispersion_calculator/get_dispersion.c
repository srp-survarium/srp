double __thiscall survarium::dispersion_calculator::get_dispersion(survarium::dispersion_calculator *this)
{
  survarium::weapon_user_animations_container *v2; // ecx
  float v3; // [esp+0h] [ebp-4Ch]
  float aim_multiplier; // [esp+8h] [ebp-44h]
  bool v5; // [esp+Ch] [ebp-40h]
  float m_value; // [esp+18h] [ebp-34h]
  survarium::weapon_user_animations_container **p_m_ammunition; // [esp+2Ch] [ebp-20h]
  survarium::weapon_core *m_weapon; // [esp+30h] [ebp-1Ch]
  char v10; // [esp+34h] [ebp-18h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp+38h] [ebp-14h] BYREF
  float v12; // [esp+3Ch] [ebp-10h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+40h] [ebp-Ch] BYREF
  bool v14; // [esp+47h] [ebp-5h]
  const survarium::weapon_dispersion_params *weapon_params; // [esp+48h] [ebp-4h]

  v10 = 0;
  v5 = 1;
  if ( this->m_weapon )
  {
    v10 = 1;
    m_weapon = this->m_weapon;
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_weapon->m_ammunition);
    if ( v13.m_object )
    {
      if ( s_dispersion_enabled_value )
        v5 = 0;
    }
  }
  v14 = v5;
  if ( (v10 & 1) != 0 )
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13);
  if ( v14 )
    return 0.0;
  weapon_params = &this->m_weapon->m_dispersion_params;
  if ( survarium::weapon_core::is_aimed((survarium::weapon_core *)this, (int)this->m_weapon) )
    aim_multiplier = weapon_params->aim_multiplier;
  else
    aim_multiplier = weapon_params->from_the_hip_multiplier;
  p_m_ammunition = (survarium::weapon_user_animations_container **)&this->m_weapon->m_ammunition;
  v11.m_object = 0;
  v2 = (survarium::weapon_user_animations_container *)p_m_ammunition;
  if ( *p_m_ammunition )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
    v2 = *p_m_ammunition;
    v11.m_object = *p_m_ammunition;
    if ( v11.m_object )
      vostok::threading::interlocked_increment(&v11.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  m_value = this->m_character_calculator.m_value;
  v3 = weapon_params->base_dispersion * *(float *)&v11.m_object->m_stand_animations[0][5].m_object * aim_multiplier;
  v12 = (survarium::weapon_dispersion_calculator::get_value(&this->m_weapon_calculator) + m_value)
      * this->m_shooting_skill_coeff
      + v3;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
  return v12;
}
