vostok::math::float4x4 *__thiscall vostok::particle::particle_action_source::get_transform(
        vostok::particle::particle_action_source *this,
        vostok::math::float4x4 *result)
{
  vostok::particle::particle_domain_complex::get_transform(&this->m_domain, result);
  return result;
}
