void __thiscall vostok::sound::sound_instance_proxy_internal::set_matrix(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float4x4 *matrix)
{
  vostok::sound::sound_instance_proxy_internal::set_quality_for_resource(
    this,
    (const vostok::math::float3 *)&matrix->lines[3]);
  this->m_collision->set_matrix(this->m_collision, matrix);
}
