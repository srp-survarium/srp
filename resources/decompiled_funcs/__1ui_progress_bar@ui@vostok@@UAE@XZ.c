void __thiscall vostok::ui::ui_progress_bar::~ui_progress_bar(vostok::ui::ui_progress_bar *this)
{
  vostok::ui::ui_window *v1; // ecx

  this->vostok::ui::progress_bar::__vftable = (vostok::ui::ui_progress_bar_vtbl *)&vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::progress_bar'};
  v1 = &this->vostok::ui::ui_window;
  v1->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v1);
}
