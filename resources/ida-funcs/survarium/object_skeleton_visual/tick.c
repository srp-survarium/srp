void __userpurge survarium::object_skeleton_visual::tick(
        survarium::object_skeleton_visual *this@<ecx>,
        __m128i a2@<xmm0>,
        const unsigned int __formal,
        unsigned int current_time_ms)
{
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_object; // eax
  vostok::particle::particle_system_instance_impl *v6; // ecx
  vostok::resources::unmanaged_resource *v7; // edi
  _BYTE *v8; // ebx
  vostok::particle::particle_emitter_instance *m_last; // [esp+10h] [ebp+Ch]

  if ( this->m_current_target )
  {
    survarium::object_skeleton_visual::calculate_animation_bone_matrices_if_needs(this, a2, current_time_ms);
    m_object = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_model.m_object;
    v6 = m_object[67].m_object;
    v7 = v6->m_lods[0].m_template.m_object;
    v8 = &v6->m_lods[0].m_emitter_instance_list.gap4;
    m_last = v6->m_lods[0].m_emitter_instance_list.m_last;
    vostok::render::scene_renderer::update_model(
      m_object + 66,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
      &this->m_transform,
      &this->m_transform);
    vostok::render::scene_renderer::update_skeleton(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
      *(vostok::memory::base_allocator **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
      this->m_animation_bone_matrices,
      this->m_animation_bone_matrices,
      (unsigned int)v7 - ((char *)m_last - v8) / 28);
  }
}
