void __thiscall vostok::engine::engine_world::on_crash(vostok::engine::engine_world *this)
{
  if ( this->m_engine_user_world )
    this->m_engine_user_world->on_crash(this->m_engine_user_world);
}
