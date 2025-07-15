void __thiscall vostok::particle::particle_action_animation_impulse::update(
        vostok::particle::particle_action_animation_impulse *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  float lifetime; // xmm2_4
  float m_fade_time; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // [esp+0h] [ebp-8h]
  float v18; // [esp+4h] [ebp-4h]

  lifetime = P->lifetime;
  m_fade_time = this->m_fade_time;
  if ( m_fade_time > lifetime )
  {
    v6 = (float)(m_fade_time - lifetime) / m_fade_time;
    v7 = P->animation_direction.y * v6;
    v8 = P->animation_direction.z * v6;
    v9 = (float)(this->m_magnitude * (float)(P->animation_direction.x * v6)) * time;
    v18 = (float)(this->m_magnitude * v8) * time;
    v10 = P->velocity.y * time;
    v17 = (float)(this->m_magnitude * v7) * time;
    v11 = P->velocity.z * time;
    v12 = time * P->velocity.x;
    v13 = P->position.x + v9;
    P->position.y = P->position.y + v17;
    P->position.z = P->position.z + v18;
    P->position.x = v13;
    v14 = fsqrt(
            (float)((float)((float)(v11 + v18) * (float)(v11 + v18)) + (float)((float)(v10 + v17) * (float)(v10 + v17)))
          + (float)((float)(v12 + v9) * (float)(v12 + v9)));
    v15 = fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12));
    if ( v15 > v14 )
    {
      v16 = v14 / v15;
      P->size.x = P->size.x * v16;
      P->size.y = P->size.y * v16;
      P->size.z = P->size.z * v16;
    }
  }
}
