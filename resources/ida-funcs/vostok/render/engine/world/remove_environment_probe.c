void __thiscall vostok::render::engine::world::remove_environment_probe(
        vostok::render::engine::world *this,
        vostok::render::environment_probe *in_scene,
        vostok::render::find_environment_probe_predicate id)
{
  vostok::render::environment_probe **v3; // edi
  vostok::render::environment_probe ***v4; // esi
  vostok::render::environment_probe **environment_probe; // eax
  vostok::render::environment_probe **v6; // ebx

  v3 = *(vostok::render::environment_probe ***)(in_scene->m_reference_count + 9135448);
  v4 = (vostok::render::environment_probe ***)&aAvbtcollisionw[in_scene->m_reference_count + 4];
  environment_probe = stlp_std::priv::__find_if<vostok::render::environment_probe * *,vostok::render::find_environment_probe_predicate>(
                        *v4,
                        v3,
                        id);
  v6 = environment_probe;
  id.m_id = (unsigned int)environment_probe;
  if ( environment_probe != v3 )
  {
    in_scene = *environment_probe;
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::environment_probe,vostok::memory::detail::call_destructor_predicate>(
      vostok::render::g_allocator,
      &in_scene);
    in_scene = (vostok::render::environment_probe *)(v6 + 1);
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      (vostok::buffer_vector<vostok::render::ambient_light *> *)v4,
      (vostok::render::ambient_light ***)&id,
      (vostok::render::ambient_light ***)&in_scene);
  }
}
