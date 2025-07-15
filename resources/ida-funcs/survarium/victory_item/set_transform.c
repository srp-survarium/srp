void __thiscall survarium::victory_item::set_transform(
        survarium::victory_item *this,
        const vostok::math::float3 *position,
        float orientation)
{
  vostok::render::skeleton_model_instance *m_object; // edi
  survarium::game_world *m_game_world; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_render_scene; // ebx
  int v7; // eax
  const vostok::math::float4x4 *v8; // eax
  vostok::render::static_model_instance *v9; // edi
  survarium::game_world *v10; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // ebx
  int v12; // eax
  const vostok::math::float4x4 *v13; // eax
  vostok::render::scene_renderer *v14; // [esp+10h] [ebp-84h] BYREF
  vostok::math::float4x4 v15; // [esp+14h] [ebp-80h] BYREF
  vostok::math::float4x4 v16; // [esp+54h] [ebp-40h] BYREF

  survarium::victory_item_core::set_transform(this, position, orientation);
  m_object = this->m_skeleton_model.m_object;
  if ( m_object->m_render_model.m_object->m_in_scene )
  {
    m_game_world = this->m_game_world;
    p_m_render_scene = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_game_world->m_render_scene;
    v14 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)m_game_world->m_game->m_renderer);
    v7 = ((int (__thiscall *)(survarium::victory_item *))this->get_transform)(this);
    v8 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::victory_item *, float *, int))this->get_transform)(
                                           this,
                                           &v15.lines[3].elements[3],
                                           v7);
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_render_model,
      v14,
      p_m_render_scene,
      v8,
      &v15);
  }
  v9 = this->m_static_model.m_object;
  if ( v9->m_render_model.m_object->m_in_scene )
  {
    v10 = this->m_game_world;
    v11 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10->m_render_scene;
    v14 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)v10->m_game->m_renderer);
    v12 = ((int (__thiscall *)(survarium::victory_item *))this->get_transform)(this);
    v13 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::victory_item *, vostok::render::scene_renderer **, int))this->get_transform)(
                                            this,
                                            &v14,
                                            v12);
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9->m_render_model,
      v14,
      v11,
      v13,
      &v16);
  }
}
