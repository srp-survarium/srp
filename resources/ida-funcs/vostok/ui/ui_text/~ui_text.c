void __thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::~ui_text<vostok::ui::dynamic_text>(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this)
{
  vostok::ui::ui_window *v1; // ecx

  this->vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::text'};
  v1 = &this->vostok::ui::ui_window;
  v1->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v1);
}


void __thiscall vostok::ui::ui_text<vostok::ui::static_text>::~ui_text<vostok::ui::static_text>(
        vostok::ui::ui_text<vostok::ui::static_text> *this)
{
  vostok::ui::ui_window *v1; // ecx

  this->vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::static_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::text'};
  v1 = &this->vostok::ui::ui_window;
  v1->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v1);
}
