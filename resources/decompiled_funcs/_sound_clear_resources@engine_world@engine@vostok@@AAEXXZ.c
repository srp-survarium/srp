void __thiscall vostok::engine::engine_world::sound_clear_resources(vostok::engine::engine_world *this)
{
  vostok::resources::dispatch_callbacks((vostok::resources::resources_manager *)this);
  this->m_sound_world->clear_resources(this->m_sound_world);
}
