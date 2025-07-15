void __thiscall vostok::particle::particle_action_random_direction::init(
        vostok::particle::particle_action_random_direction *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  bool v5; // zf
  vostok::math::float4x4 *transform; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  vostok::math::float3 *p_position; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float z; // xmm2_4
  vostok::math::float3 *p_direction; // eax
  float v15; // xmm1_4
  float v16; // [esp+Ch] [ebp-64h] BYREF
  float v17; // [esp+10h] [ebp-60h]
  float v18; // [esp+14h] [ebp-5Ch]
  vostok::math::float3 v19; // [esp+18h] [ebp-58h] BYREF
  vostok::math::float3 position; // [esp+24h] [ebp-4Ch] BYREF
  vostok::math::float4x4 v21; // [esp+30h] [ebp-40h] BYREF

  vostok::particle::particle_domain_complex::generate(
    (vostok::particle::particle_domain_complex *)this,
    &this->m_domain,
    &v19.x);
  v5 = !instance->m_emitter->m_world_space;
  position = P->position;
  v16 = v19.x - position.x;
  v17 = v19.y - position.y;
  v18 = v19.z - position.z;
  if ( v5 )
  {
    p_position = (vostok::math::float3 *)&v16;
  }
  else
  {
    transform = vostok::particle::particle_emitter_instance::get_transform(
                  (vostok::particle::particle_emitter_instance *)&v21,
                  instance,
                  &v21);
    v7 = transform->j.y * v17;
    position.x = (float)((float)(transform->k.x * v18) + (float)(transform->j.x * v17)) + (float)(transform->i.x * v16);
    v8 = (float)((float)(transform->k.y * v18) + v7) + (float)(transform->i.y * v16);
    v9 = transform->j.z * v17;
    position.y = v8;
    position.z = (float)((float)(transform->k.z * v18) + v9) + (float)(transform->i.z * v16);
    p_position = &position;
  }
  v11 = s_bm_current_air_resistance;
  if ( this->m_is_reverse )
    v12 = FLOAT_N1_0;
  else
    v12 = s_bm_current_air_resistance;
  v19.x = v12 * p_position->x;
  v19.y = p_position->y * v12;
  z = p_position->z;
  p_direction = &P->direction;
  v19.z = z * v12;
  P->direction = v19;
  if ( fsqrt(
         (float)((float)(P->direction.y * P->direction.y) + (float)(P->direction.z * P->direction.z))
       + (float)(P->direction.x * P->direction.x)) > 0.0000099999997 )
  {
    v15 = v11
        / fsqrt(
            (float)((float)(p_direction->x * p_direction->x) + (float)(p_direction->y * p_direction->y))
          + (float)(p_direction->z * p_direction->z));
    p_direction->x = p_direction->x * v15;
    P->direction.y = P->direction.y * v15;
    P->direction.z = P->direction.z * v15;
    p_direction->x = p_direction->x;
    *(_QWORD *)&P->direction.elements[1] = *(_QWORD *)&P->direction.elements[1];
  }
}
