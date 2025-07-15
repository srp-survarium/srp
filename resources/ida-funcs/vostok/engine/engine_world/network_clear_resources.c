void __thiscall vostok::engine::engine_world::network_clear_resources(vostok::engine::engine_world *this)
{
  vostok::resources::dispatch_callbacks((vostok::command_line::key *)this);
  this->m_network_world->clear_resources(this->m_network_world);
}
