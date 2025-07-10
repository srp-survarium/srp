void __thiscall vostok::ui::ui_dialog::~ui_dialog(vostok::ui::ui_dialog *this)
{
  vostok::ui::ui_window *v2; // ecx

  v2 = &this->vostok::ui::ui_window;
  this->vostok::ui::dialog::__vftable = (vostok::ui::ui_dialog_vtbl *)&vostok::ui::ui_dialog::`vftable'{for `vostok::ui::dialog'};
  v2->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_dialog::`vftable'{for `vostok::ui::ui_window'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&vostok::ui::ui_dialog::`vftable'{for `vostok::input::handler'};
  vostok::ui::ui_window::~ui_window(v2);
}
