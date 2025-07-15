vostok::ui::window *__thiscall vostok::ui::ui_world::create_window(vostok::ui::ui_world *this)
{
  vostok::ui::window *result; // eax
  vostok::memory::base_allocator *m_allocator; // edx

  result = (vostok::ui::window *)this->m_allocator->call_malloc(this->m_allocator, 64);
  if ( !result )
    return 0;
  m_allocator = this->m_allocator;
  result[1].__vftable = (vostok::ui::window_vtbl *)m_allocator;
  result->__vftable = (vostok::ui::window_vtbl *)&vostok::ui::ui_window::`vftable';
  result[2].__vftable = 0;
  result[3].__vftable = 0;
  result[4].__vftable = 0;
  result[5].__vftable = 0;
  result[6].__vftable = 0;
  result[7].__vftable = 0;
  result[8].__vftable = 0;
  result[9].__vftable = (vostok::ui::window_vtbl *)m_allocator;
  result[10].__vftable = 0;
  LOBYTE(result[11].__vftable) = 0;
  BYTE1(result[11].__vftable) = 1;
  BYTE2(result[11].__vftable) = 0;
  HIBYTE(result[11].__vftable) = 0;
  result[12].__vftable = 0;
  result[13].__vftable = 0;
  result[14].__vftable = (vostok::ui::window_vtbl *)m_allocator;
  result[15].__vftable = 0;
  return result;
}
