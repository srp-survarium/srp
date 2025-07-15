void __thiscall vostok::particle::particle_action_random_velocity::init(
        vostok::particle::particle_action_random_velocity *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  const vostok::math::float3 *v5; // eax
  vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // [esp+8h] [ebp-A4h]
  vostok::math::float3 *v8; // [esp+Ch] [ebp-A0h]
  vostok::math::float3 v10; // [esp+34h] [ebp-78h] BYREF
  vostok::math::float3 v11; // [esp+40h] [ebp-6Ch] BYREF
  vostok::math::float3 v12; // [esp+4Ch] [ebp-60h] BYREF
  vostok::math::float3 v13; // [esp+58h] [ebp-54h] BYREF
  vostok::math::float3_pod *right; // [esp+64h] [ebp-48h]
  vostok::math::float3 v15; // [esp+68h] [ebp-44h] BYREF
  vostok::math::float3 v16; // [esp+74h] [ebp-38h] BYREF
  vostok::math::float3 result; // [esp+80h] [ebp-2Ch] BYREF
  vostok::math::float3 *v18; // [esp+8Ch] [ebp-20h]
  char v19; // [esp+93h] [ebp-19h]
  vostok::math::float3 target_location; // [esp+94h] [ebp-18h] BYREF
  vostok::math::float3 start_location; // [esp+A0h] [ebp-Ch] BYREF

  v19 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  if ( instance->m_emitter->m_world_space )
  {
    v5 = vostok::particle::particle_domain_complex::generate(&this->m_domain, &result);
    v8 = vostok::math::float4x4::transform_direction(v5, &v16, &instance->m_transform);
  }
  else
  {
    v8 = vostok::particle::particle_domain_complex::generate(&this->m_domain, &v15);
  }
  v18 = v8;
  P->start_velocity = *v8;
  vostok::particle::particle_domain_complex::generate(&this->m_domain, &target_location);
  start_location = P->position;
  if ( instance->m_emitter->m_world_space )
  {
    v6 = vostok::math::operator-(&start_location, &target_location, &v13);
    v7 = vostok::math::float4x4::transform_direction(v6, &v12, &instance->m_transform);
  }
  else
  {
    v7 = vostok::math::operator-(&start_location, &target_location, &v11);
  }
  right = v7;
  P->start_velocity = *vostok::math::operator*(v7, &v10, &this->m_velocity_multiplier);
  vostok::math::float3_pod::operator+=(&P->start_velocity, &P->velocity);
}
