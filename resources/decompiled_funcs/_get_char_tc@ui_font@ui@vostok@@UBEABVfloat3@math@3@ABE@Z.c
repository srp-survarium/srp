const vostok::math::float3 *__thiscall vostok::ui::ui_font::get_char_tc(
        vostok::ui::ui_font *this,
        const unsigned __int8 *ch)
{
  return &this->m_char_map[*ch];
}
