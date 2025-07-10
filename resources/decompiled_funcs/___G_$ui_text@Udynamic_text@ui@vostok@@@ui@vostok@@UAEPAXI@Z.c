vostok::ui::ui_text<vostok::ui::dynamic_text> *__thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::`scalar deleting destructor'(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        char a2)
{
  vostok::ui::ui_window *v3; // ecx

  v3 = &this->vostok::ui::ui_window;
  this->vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::text'};
  v3->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
