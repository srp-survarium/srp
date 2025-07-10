void __thiscall vostok::particle::particle_action_random_velocity::set_defaults(
        vostok::particle::particle_action_random_velocity *this,
        bool mt_alloc)
{
  vostok::math::float3_pod *v2; // eax
  vostok::math::float3_pod *v3; // eax
  vostok::math::float3_pod *v4; // eax
  vostok::math::float3 v6; // [esp+10h] [ebp-24h] BYREF
  vostok::math::float3 v7; // [esp+1Ch] [ebp-18h] BYREF
  vostok::math::float3 v8; // [esp+28h] [ebp-Ch] BYREF

  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::particle_domain_complex::set_defaults(&this->m_domain);
  vostok::math::float3::float3(&v8, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(10.0), 0.0);
  this->m_domain.m_translate = *v2;
  vostok::math::float3::float3(&v7, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  this->m_domain.m_scale = *v3;
  vostok::math::float3::float3(&v6, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->m_domain.m_rotate = *v4;
  this->m_domain.m_inner_radius = FLOAT_0_5;
  this->m_domain.m_outer_radius = FLOAT_0_5;
  this->m_domain.m_domain_type = 5;
  LODWORD(this->m_velocity_multiplier) = clear_value;
}
