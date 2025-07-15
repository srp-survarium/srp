vostok::engine::console *__thiscall vostok::engine::engine_world::create_game_console(
        vostok::engine::engine_world *this,
        vostok::ui::world *uw,
        vostok::input::world *iw)
{
  vostok::memory::doug_lea_allocator *v4; // eax
  int *v5; // esi
  vostok::memory::base_allocator *v6; // eax
  vostok::engine::console *result; // eax

  v4 = (vostok::memory::doug_lea_allocator *)((int (__thiscall *)(vostok::sound::world *volatile))this->m_sound_world->start_destruction)(this->m_sound_world);
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x270u);
  if ( !v5 )
    return 0;
  v6 = (vostok::memory::base_allocator *)((int (__thiscall *)(vostok::sound::world *volatile))this->m_sound_world->start_destruction)(this->m_sound_world);
  vostok::console_impl::console_impl((vostok::console_impl *)v5, uw, v6);
  result = (vostok::engine::console *)(v5 + 154);
  v5[154] = (int)&vostok::engine::console::`vftable';
  *v5 = (int)&vostok::engine::game_console::`vftable'{for `vostok::console_impl'};
  v5[155] = (int)iw;
  *((_BYTE *)v5 + 4) = 1;
  v5[154] = (int)&vostok::engine::game_console::`vftable'{for `vostok::engine::console'};
  return result;
}
