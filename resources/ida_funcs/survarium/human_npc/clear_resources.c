void __thiscall survarium::human_npc::clear_resources(survarium::human_npc *this)
{
  vostok::sound::world *m_sound_world; // ecx
  vostok::sound::world_user *v3; // eax
  vostok::render::game::renderer *m_renderer; // eax
  vostok::configs::binary_config *m_object; // [esp-8h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_model; // [esp+0h] [ebp-4h]

  survarium::damage_model::unsubscribe_from_affect(
    this->m_model_instance.m_object->m_damage_model.m_object,
    affects_type_death,
    &this->m_affects_subscription);
  m_sound_world = this->m_sound_world;
  v6.m_object = (vostok::configs::binary_config *)&this->vostok::sound::sound_receiver;
  v3 = (vostok::sound::world_user *)((int (__thiscall *)(vostok::sound::world *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *))m_sound_world->get_logic_world_user)(
                                      m_sound_world,
                                      &this->m_sound_scene);
  vostok::sound::world_user::unregister_receiver(
    v3,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&this->vostok::sound::sound_receiver,
    (vostok::sound::sound_receiver *)p_m_model);
  m_renderer = this->m_renderer;
  p_m_model = &this->m_model_instance.m_object->m_render_model.m_object->m_model;
  vostok::render::scene_renderer::remove_model(
    m_renderer->m_scene,
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)m_renderer->m_scene,
    (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&this->m_scene);
  this->m_physics_world->remove(this->m_physics_world, this->m_model_instance.m_object->m_damage_collision->m_body);
  this->m_ai_world->on_destruction_event(this->m_ai_world, &this->vostok::ai::game_object);
  m_object = (vostok::configs::binary_config *)this->m_brain_unit.m_object;
  v6.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v6,
    m_object);
  ((void (__thiscall *)(vostok::ai::world *, vostok::configs::binary_config *))this->m_ai_world->remove_brain_unit)(
    this->m_ai_world,
    v6.m_object);
}
