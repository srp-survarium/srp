void __thiscall vostok::engine::engine_world::on_fullscreen_alttab(vostok::engine::engine_world *this, int first)
{
  ((void (__thiscall *)(vostok::sound::world *volatile, int))this->m_sound_world->__vftable[1].tick)(
    this->m_sound_world,
    first);
}
