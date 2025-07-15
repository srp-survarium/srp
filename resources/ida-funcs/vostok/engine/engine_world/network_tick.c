void __thiscall vostok::engine::engine_world::network_tick(vostok::engine::engine_world *this)
{
  vostok::resources::dispatch_callbacks((vostok::command_line::key *)this);
  this->m_network_world->tick(this->m_network_world, 0);
}
