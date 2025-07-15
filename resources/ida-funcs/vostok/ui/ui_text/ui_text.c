void __usercall vostok::ui::ui_text<vostok::ui::static_text>::ui_text<vostok::ui::static_text>(
        vostok::ui::ui_text<vostok::ui::static_text> *this@<esi>,
        vostok::ui::ui_world *w@<edi>)
{
  vostok::ui::ui_window *v2; // eax

  vostok::ui::ui_window::ui_window(&this->vostok::ui::ui_window, w->m_allocator);
  this->vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::static_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::text'};
  v2->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::ui_window'};
  this->m_text.m_text.m_max_end = (char *)&this->m_font;
  this->m_text.m_text.m_begin = this->m_text.m_text.m_buffer;
  this->m_text.m_text.m_end = this->m_text.m_text.m_buffer;
  this->m_text.m_text.m_buffer[0] = 0;
  this->m_color = -1;
  this->m_font = 0;
  this->m_ui_world = w;
  vostok::ui::ui_window::subscribe_event(
    v2,
    ev_text_changed,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              survarium::game_world::on_mouse_key_action,
                                                                              (unsigned int)this));
}
