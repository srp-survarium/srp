void __thiscall vostok::sound::sound_world::start_destruction(vostok::sound::sound_world *this)
{
  this->m_is_destroying = 1;
  vostok::sound::sound_world::process_orders(this, (int)this);
}
