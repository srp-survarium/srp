vostok::math::float2 *__thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::measure_string(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        vostok::math::float2 *result)
{
  float v2; // xmm0_4
  const vostok::math::float2 *(__thiscall *get_size)(struct vostok::ui::ui_window *); // edx
  double y; // st7
  vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *v6; // eax
  const char *v7; // eax

  v2 = SNaN;
  get_size = this->get_size;
  result->x = SNaN;
  result->y = v2;
  y = get_size(&this->vostok::ui::ui_window)->y;
  v6 = this->vostok::ui::text::__vftable;
  result->y = y;
  v7 = v6->get_text(this);
  vostok::ui::calc_string_length(this->m_font, v7);
  result->x = v2;
  return result;
}
