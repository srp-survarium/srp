void __thiscall vostok::ui::ui_scroll_v_source::set_position(vostok::ui::ui_scroll_v_source *this, const float value)
{
  const vostok::math::float2 *v3; // eax
  vostok::ui::ui_scroll_pad *m_pad; // ecx
  _DWORD v5[2]; // [esp+4h] [ebp-8h] BYREF

  v3 = this->m_pad->get_position(this->m_pad);
  m_pad = this->m_pad;
  v5[0] = LODWORD(v3->x);
  *(float *)&v5[1] = value;
  m_pad->set_position(m_pad, (const vostok::math::float2 *)v5);
}
