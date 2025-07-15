vostok::ui::ui_progress_bar *__thiscall vostok::ui::ui_progress_bar::`vector deleting destructor'(
        vostok::ui::ui_progress_bar *this,
        char a2)
{
  vostok::ui::ui_window *v3; // ecx

  v3 = &this->vostok::ui::ui_window;
  this->vostok::ui::progress_bar::__vftable = (vostok::ui::ui_progress_bar_vtbl *)&vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::progress_bar'};
  v3->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_progress_bar::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::ui::ui_progress_bar *__thiscall vostok::ui::ui_progress_bar::`vector deleting destructor'(char *this, char a2)
{
  return vostok::ui::ui_progress_bar::`vector deleting destructor'((vostok::ui::ui_progress_bar *)(this - 4), a2);
}
