void __thiscall vostok::engine::engine_world::on_alttab(vostok::engine::engine_world *this, int activate)
{
  ((void (__thiscall *)(vostok::sound::world *volatile, int))this->m_sound_world->__vftable[1].get_speed_of_sound)(
    this->m_sound_world,
    activate);
}
