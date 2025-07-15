void __usercall vostok::ui::ui_progress_bar::ui_progress_bar(
        vostok::ui::ui_progress_bar *this@<esi>,
        vostok::ui::ui_world *world@<edi>)
{
  _DWORD *v2; // eax

  vostok::ui::ui_window::ui_window(&this->vostok::ui::ui_window, world->m_allocator);
  *v2 = &vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::ui_window'};
  this->vostok::ui::progress_bar::__vftable = (vostok::ui::ui_progress_bar_vtbl *)&vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::progress_bar'};
  this->m_ui_world = world;
  this->m_back_color.m_value = -7401961;
  this->m_front_color.m_value = -1284079;
  this->m_text_color.m_value = -13905202;
  this->m_border_width = 1;
  this->m_border_height = 1;
  this->m_minimum = 0;
  this->m_maximum = 100;
  this->m_value = 0;
  this->m_text.m_begin = this->m_text.m_buffer;
  this->m_text.m_end = this->m_text.m_buffer;
  this->m_text.m_buffer[0] = 0;
  this->m_text.m_max_end = (char *)&this->m_draw_text;
  this->m_draw_text = 0;
}
