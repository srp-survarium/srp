BOOL __userpurge vostok::render::stage_lights::accumulate_particle_lighting_::_6_::sort_probes_by_size_predicate::operator()@<eax>(
        const vostok::render::environment_probe *right@<eax>,
        vostok::render::stage_lights::accumulate_particle_lighting::__l6::sort_probes_by_size_predicate *this,
        const vostok::render::environment_probe *left)
{
  return right->m_properties.outer_radius > *(float *)&this[520];
}
