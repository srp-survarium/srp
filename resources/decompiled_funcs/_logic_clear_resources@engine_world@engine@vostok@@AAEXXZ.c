void __thiscall vostok::engine::engine_world::logic_clear_resources(vostok::engine::engine_world *this)
{
  vostok::sound::world_user *v2; // eax
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *v3; // ecx

  vostok::resources::dispatch_callbacks((vostok::resources::resources_manager *)this);
  v2 = this->m_sound_world->get_logic_world_user(this->m_sound_world);
  vostok::sound::world_user::dispatch_callbacks(v2);
  this->m_network_world->dispatch_callbacks(this->m_network_world);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_delete_processed_items(
    v3,
    &this->m_render_world->m_logic_channel.m_channel);
  this->m_engine_user_world->clear_resources(this->m_engine_user_world);
}
