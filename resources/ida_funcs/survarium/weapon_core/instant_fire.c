void __thiscall survarium::weapon_core::instant_fire(survarium::weapon_core *this, unsigned int current_time_in_ms)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  const vostok::math::float3 *v6; // eax
  const vostok::math::float3 *v7; // [esp-1Ch] [ebp-6Ch]
  survarium::hit_initiator *m_initiator_holder; // [esp-Ch] [ebp-5Ch]
  const survarium::hit_receiver *m_receiver_holder; // [esp-8h] [ebp-58h]
  bool m_tracer; // [esp-4h] [ebp-54h]
  float value; // [esp+24h] [ebp-2Ch] BYREF
  char v13; // [esp+29h] [ebp-27h]
  char v14; // [esp+2Ah] [ebp-26h]
  char v15; // [esp+2Bh] [ebp-25h]
  const vostok::math::float3 *velocity; // [esp+2Ch] [ebp-24h]
  vostok::math::float3 result; // [esp+30h] [ebp-20h] BYREF
  vostok::math::float3 v18; // [esp+3Ch] [ebp-14h] BYREF
  const vostok::math::float3 *bullet_direction; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]

  v15 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v14 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  --this->m_bullets_in_queue;
  v13 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( i = 0; ; ++i )
  {
    survarium::weapon_user_dead_state::finalize(v3);
    if ( i >= (unsigned __int16)this->m_ammunition.m_object->m_buck_shot )
      break;
    survarium::weapon_core::get_dispersed_bullet_dir(this, &result);
    bullet_direction = &result;
    survarium::weapon_user_dead_state::finalize(v4);
    value = this->m_ammunition.m_object->m_muzzle_speed;
    vostok::math::operator*(bullet_direction, &v18, &value);
    velocity = &v18;
    survarium::weapon_user_dead_state::finalize(v5);
    m_tracer = this->m_ammunition.m_object->m_tracer;
    m_receiver_holder = this->m_receiver_holder;
    m_initiator_holder = this->m_initiator_holder;
    v7 = velocity;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)velocity);
    survarium::bullet_manager::fire(
      this->m_bullet_manager,
      v6,
      v7,
      &this->m_ammunition,
      this,
      current_time_in_ms,
      m_initiator_holder,
      m_receiver_holder,
      m_tracer);
  }
  if ( this->m_is_there_chamber_a_round_state )
    this->m_is_round_chambered = 0;
  else
    --this->m_ammo_in_magazine;
  this->on_after_fire(this);
  survarium::recoil_calculator::fire(&this->m_recoil_calculator);
  survarium::dispersion_calculator::fire(&this->m_dispersion_calculator);
  this->m_initiator_holder->on_fire(this->m_initiator_holder);
}
