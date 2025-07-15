vostok::ui::ui_image *__thiscall vostok::ui::ui_image::`scalar deleting destructor'(
        vostok::ui::ui_image *this,
        char a2)
{
  vostok::ui::ui_window *v3; // ecx

  v3 = &this->vostok::ui::ui_window;
  this->vostok::ui::image::__vftable = (vostok::ui::ui_image_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::image'};
  v3->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
