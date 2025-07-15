void __userpurge survarium::damage_zone::stop_particle(
        survarium::damage_zone *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *particle_instance,
        bool force)
{
  int v4; // eax

  v4 = *(_DWORD *)(a2 + 564);
  if ( force )
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)(v4 + 4),
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(v4 + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v4 + 4),
      particle_instance);
  else
    vostok::render::scene_renderer::stop_particle_system(
      (vostok::render::scene_renderer *)(v4 + 4),
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(v4 + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v4 + 4),
      particle_instance,
      COERCE_INT(60.0));
}
