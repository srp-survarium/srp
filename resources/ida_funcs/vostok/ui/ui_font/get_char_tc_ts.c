vostok::math::float3 *__thiscall vostok::ui::ui_font::get_char_tc_ts(
        vostok::ui::ui_font *this,
        vostok::math::float3 *result,
        const unsigned __int8 *ch)
{
  int v4; // ecx
  vostok::math::float3 *v5; // eax
  __int64 v6; // xmm0_8
  float v7; // ecx

  v4 = this->get_char_tc(this, ch);
  v5 = result;
  v6 = *(_QWORD *)v4;
  v7 = *(float *)(v4 + 8);
  *(_QWORD *)&result->x = v6;
  *(float *)&v6 = *(float *)&clear_value / this->m_ts_size.x;
  result->z = v7;
  result->x = result->x * *(float *)&v6;
  result->y = result->y / this->m_ts_size.y;
  result->z = result->z * *(float *)&v6;
  return v5;
}
