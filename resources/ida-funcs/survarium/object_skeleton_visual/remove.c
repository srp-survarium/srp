void __thiscall survarium::object_skeleton_visual::remove(survarium::object_skeleton_visual *this)
{
  survarium::scheduler *v2; // ecx

  vostok::render::scene_renderer::remove_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene);
  if ( this->m_animation_scene.m_object )
    survarium::scheduler::unregister(v2, (int)&this->m_game_scene->m_scheduler, &this->m_scheduler_identifier);
}
