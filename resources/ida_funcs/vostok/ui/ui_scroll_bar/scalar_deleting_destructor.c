vostok::ui::ui_scroll_bar *__thiscall vostok::ui::ui_scroll_bar::`scalar deleting destructor'(
        vostok::ui::ui_scroll_bar *this,
        char a2)
{
  vostok::ui::ui_window::~ui_window(&this->m_btn_rb);
  vostok::ui::ui_window::~ui_window(&this->m_btn_lt);
  this->m_track_button.__vftable = (vostok::ui::ui_image_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::image'};
  this->m_track_button.__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(&this->m_track_button.vostok::ui::ui_window);
  this->vostok::ui::ui_image::vostok::ui::image::__vftable = (vostok::ui::ui_scroll_bar_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::image'};
  this->vostok::ui::ui_image::vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(&this->vostok::ui::ui_window);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
