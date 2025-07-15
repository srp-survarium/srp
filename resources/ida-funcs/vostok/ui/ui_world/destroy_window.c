void __thiscall vostok::ui::ui_world::destroy_window(vostok::ui::ui_world *this, vostok::ui::window *w)
{
  vostok::memory::base_allocator *m_allocator; // esi
  _BYTE *v3; // ebx

  m_allocator = this->m_allocator;
  if ( w )
  {
    v3 = __RTCastToVoid((void **)&w->__vftable);
    ((void (__thiscall *)(vostok::ui::window *, _DWORD))w->~vostok::ui::window)(w, 0);
    m_allocator->call_free(m_allocator, v3, "vostok::ui::ui_world::destroy_window", ".\\ui_world_factory.cpp", 50u);
  }
}
