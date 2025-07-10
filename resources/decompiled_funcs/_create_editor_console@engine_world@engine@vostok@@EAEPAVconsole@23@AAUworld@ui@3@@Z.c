vostok::engine::console *__thiscall vostok::engine::engine_world::create_editor_console(
        vostok::engine::engine_world *this,
        vostok::ui::world *uw)
{
  unsigned int *p_m_user_thread_id; // edi
  int *v3; // esi
  vostok::engine::console *result; // eax

  p_m_user_thread_id = &this->m_render_allocator.m_user_thread_id;
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)&this->m_render_allocator.m_user_thread_id,
         0x26Cu);
  if ( !v3 )
    return 0;
  vostok::console_impl::console_impl(
    (vostok::console_impl *)v3,
    uw,
    (vostok::memory::base_allocator *)p_m_user_thread_id);
  result = (vostok::engine::console *)(v3 + 154);
  v3[154] = (int)&vostok::engine::console::`vftable';
  *v3 = (int)&vostok::engine::editor_console::`vftable'{for `vostok::console_impl'};
  *((_BYTE *)v3 + 4) = 0;
  v3[154] = (int)&vostok::engine::editor_console::`vftable'{for `vostok::engine::console'};
  return result;
}
