vostok::math::float3 *__thiscall vostok::sound::sound_instance_proxy_internal::get_volumetric_position(
        vostok::sound::sound_instance_proxy_internal *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *listener_position)
{
  const vostok::math::float4x4 *v3; // eax

  v3 = this->m_collision->get_matrix(this->m_collision);
  this->m_collision->get_closest_point_to(this->m_collision, result, listener_position, v3);
  return result;
}
