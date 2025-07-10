void __thiscall vostok::ui::ui_image::~ui_image(vostok::ui::ui_image *this)
{
  vostok::ui::ui_window *v1; // ecx

  this->vostok::ui::image::__vftable = (vostok::ui::ui_image_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::image'};
  v1 = &this->vostok::ui::ui_window;
  v1->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_image::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_window::~ui_window(v1);
}
