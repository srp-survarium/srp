void __thiscall survarium::victory_item::remove(survarium::victory_item *this)
{
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // eax
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v3; // eax

  survarium::victory_item_core::remove(this);
  p_m_render_model = &this->m_skeleton_model.m_object->m_render_model;
  if ( p_m_render_model->m_object->m_in_scene )
    vostok::render::scene_renderer::remove_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
  v3 = &this->m_static_model.m_object->m_render_model;
  if ( v3->m_object->m_in_scene )
    vostok::render::scene_renderer::remove_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
}
