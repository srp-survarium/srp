vostok::math::float3 *__thiscall vostok::ui::ui_font::get_char_tc_ts(
        vostok::ui::ui_font *this,
        vostok::math::float3 *result,
        const unsigned __int8 *ch)
{
  int v4; // eax
  float v5; // xmm0_4
  vostok::math::float3 *v6; // esi
  vostok::math::float3 *v7; // eax

  v4 = this->get_char_tc(this, ch);
  v5 = s_bm_current_air_resistance / this->m_ts_size.x;
  v6 = (vostok::math::float3 *)v4;
  v7 = result;
  *result = *v6;
  result->x = result->x * v5;
  result->y = result->y / this->m_ts_size.y;
  result->z = result->z * v5;
  return v7;
}
