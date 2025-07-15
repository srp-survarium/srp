void __thiscall survarium::victory_item::take(survarium::victory_item *this)
{
  vostok::render::static_model_instance *m_object; // eax
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *m_game_world; // esi
  vostok::render::scene_renderer *v4; // [esp-Ch] [ebp-10h]

  survarium::victory_item_core::take(this);
  survarium::scheduler::unregister(this->m_scheduler, &this->m_scheduler_identifier);
  m_object = this->m_model.m_object;
  this->m_scheduler = 0;
  if ( m_object )
  {
    m_game_world = (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)this->m_game_world;
    v4 = *(vostok::render::scene_renderer **)(m_game_world[42].m_object->grm_satisfaction_tree_hook.color_ + 16);
    vostok::render::scene_renderer::remove_model(
      v4,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v4,
      m_game_world + 1);
  }
}
