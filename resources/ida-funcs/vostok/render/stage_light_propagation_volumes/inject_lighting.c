void __userpurge vostok::render::stage_light_propagation_volumes::inject_lighting(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        const unsigned int cascade_index@<eax>,
        const vostok::math::float3 *light_position,
        const vostok::math::float3 *light_direction,
        float light_fov)
{
  vostok::render::radiance_volume::inject_lighting(
    (vostok::render::radiance_volume *)this,
    COERCE_FLOAT((unsigned int)&this->m_radiance_volume[cascade_index]),
    *(float *)&light_position,
    light_direction,
    light_fov,
    this->m_rsm_downsampled_size);
}
