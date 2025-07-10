bool __cdecl vostok::render::is_not_occluded_predicate_vostok::particle::render_particle_emitter_instance_(
        vostok::particle::render_particle_emitter_instance *obj)
{
  return !obj->is_occluded(obj);
}
