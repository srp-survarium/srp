vostok::math::float2 *__thiscall vostok::ui::ui_text<vostok::ui::static_text>::measure_string(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        vostok::math::float2 *result)
{
  float v3; // xmm0_4
  vostok::ui::ui_window *v5; // ecx
  vostok::ui::ui_window_vtbl *v6; // eax
  double y; // st7
  vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *v8; // eax
  char *v9; // eax

  v3 = SNaN;
  v5 = &this->vostok::ui::ui_window;
  v6 = v5->__vftable;
  result->x = SNaN;
  result->y = v3;
  y = v6->get_size(v5)->y;
  v8 = this->vostok::ui::text::__vftable;
  result->y = y;
  v9 = (char *)v8->get_text(this);
  vostok::ui::calc_string_length(&this->m_font->vostok::ui::font, v9);
  result->x = v3;
  return result;
}
