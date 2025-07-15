void __thiscall survarium::victory_item::picked_up_by_player(survarium::victory_item *this)
{
  survarium::game_world *m_game_world; // eax
  vostok::render::skeleton_model_instance *m_object; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_render_scene; // ebx
  int v5; // eax
  const vostok::math::float4x4 *v6; // eax
  vostok::render::scene_renderer *v7; // [esp+Ch] [ebp-84h]
  vostok::math::float4x4 v8[2]; // [esp+10h] [ebp-80h] BYREF

  survarium::victory_item_core::picked_up_by_player(this);
  vostok::render::scene_renderer::remove_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_static_model.m_object->m_render_model,
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
  m_game_world = this->m_game_world;
  m_object = this->m_skeleton_model.m_object;
  p_m_render_scene = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_game_world->m_render_scene;
  v7 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)m_game_world->m_game->m_renderer);
  v5 = ((int (__thiscall *)(survarium::victory_item *))this->get_transform)(this);
  v6 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::victory_item *, float *, int))this->get_transform)(
                                         this,
                                         &v8[0].lines[3].elements[3],
                                         v5);
  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_render_model,
    v7,
    p_m_render_scene,
    v6,
    v8);
  this->m_skeleton_model.m_object->m_render_model.m_object->m_is_foreground = *((_BYTE *)&loc_11439
                                                                              + (unsigned int)this->m_user) == 0;
  this->m_skeleton_model.m_object->m_render_model.m_object->m_is_movable_static = 1;
}
