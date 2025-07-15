vostok::ui::ui_dialog *__thiscall vostok::ui::ui_dialog::`scalar deleting destructor'(
        vostok::ui::ui_dialog *this,
        char a2)
{
  vostok::ui::ui_window *v3; // ecx

  v3 = &this->vostok::ui::ui_window;
  this->vostok::ui::dialog::__vftable = (vostok::ui::ui_dialog_vtbl *)&vostok::ui::ui_dialog::`vftable'{for `vostok::ui::dialog'};
  v3->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_dialog::`vftable'{for `vostok::ui::ui_window'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&vostok::ui::ui_dialog::`vftable'{for `vostok::input::handler'};
  vostok::ui::ui_window::~ui_window(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
