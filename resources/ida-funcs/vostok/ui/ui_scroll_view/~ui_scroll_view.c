void __thiscall vostok::ui::ui_scroll_view::~ui_scroll_view(vostok::ui::ui_scroll_view *this)
{
  vostok::ui::ui_window *v2; // ebx

  v2 = &this->vostok::ui::ui_window;
  this->vostok::ui::scroll_view::__vftable = (vostok::ui::ui_scroll_view_vtbl *)&vostok::ui::ui_scroll_view::`vftable'{for `vostok::ui::scroll_view'};
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_scroll_view::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_scroll_bar::~ui_scroll_bar((vostok::ui::ui_scroll_bar *)this, (int)&this->m_scroll_bar_v);
  vostok::ui::ui_window::~ui_window(&this->m_pad);
  vostok::ui::ui_window::~ui_window(v2);
}
