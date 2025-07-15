double __thiscall vostok::ui::ui_font::get_height_ts(vostok::ui::ui_font *this)
{
  return *this->get_height(this) / this->m_ts_size.y;
}
