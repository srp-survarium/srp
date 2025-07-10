void __userpurge vostok::render::stage_light_propagation_volumes::propagate_lighting_smoothed(
        unsigned int cascade_index@<eax>,
        vostok::render::radiance_volume *propagation_iteration_index@<ecx>,
        vostok::render::stage_light_propagation_volumes *this)
{
  vostok::render::radiance_volume::propagate_lighting_iter(
    propagation_iteration_index,
    COERCE_FLOAT((unsigned int)&this->m_radiance_volume[cascade_index]),
    cascade_index,
    (unsigned int)propagation_iteration_index);
}
