void __thiscall vostok::engine::engine_world::logic_clear_resources(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world::logic_dispatch_callbacks(this);
  this->m_engine_user_world->clear_resources(this->m_engine_user_world);
}
