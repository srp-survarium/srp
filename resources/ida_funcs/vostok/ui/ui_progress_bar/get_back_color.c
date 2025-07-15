vostok::math::color *__thiscall vostok::ui::ui_progress_bar::get_back_color(
        vostok::ui::ui_progress_bar *this,
        vostok::math::color *result)
{
  vostok::math::color *v2; // eax

  v2 = result;
  *result = this->m_back_color;
  return v2;
}
