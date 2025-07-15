void __thiscall survarium::victory_item::drop(survarium::victory_item *this)
{
  survarium::victory_item *v2; // ecx
  survarium::game_world *m_game_world; // eax
  vostok::render::static_model_instance *m_object; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_render_scene; // ebx
  int v6; // eax
  const vostok::math::float4x4 *v7; // eax
  vostok::render::scene_renderer *v8; // [esp+Ch] [ebp-84h]
  vostok::math::float4x4 v9[2]; // [esp+10h] [ebp-80h] BYREF

  survarium::victory_item_core::drop(this);
  survarium::victory_item::reset_bone_matrices(
    v2,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
  vostok::render::scene_renderer::remove_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skeleton_model.m_object->m_render_model,
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
  m_game_world = this->m_game_world;
  m_object = this->m_static_model.m_object;
  p_m_render_scene = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_game_world->m_render_scene;
  v8 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)m_game_world->m_game->m_renderer);
  v6 = ((int (__thiscall *)(survarium::victory_item *))this->get_transform)(this);
  v7 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::victory_item *, float *, int))this->get_transform)(
                                         this,
                                         &v9[0].lines[3].elements[3],
                                         v6);
  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_render_model,
    v8,
    p_m_render_scene,
    v7,
    v9);
}
