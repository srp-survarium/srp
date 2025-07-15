void __usercall vostok::render::stage_light_propagation_volumes::propagate_lighting(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        unsigned int cascade_index@<eax>)
{
  vostok::render::radiance_volume::propagate_lighting(
    (vostok::render::radiance_volume *)this,
    (unsigned int)&this->m_radiance_volume[cascade_index],
    cascade_index);
}
