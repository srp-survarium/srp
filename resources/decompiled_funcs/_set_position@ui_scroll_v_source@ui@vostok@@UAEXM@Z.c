void __thiscall vostok::ui::ui_scroll_v_source::set_position(vostok::ui::ui_scroll_v_source *this, float value)
{
  const vostok::math::float2 *v3; // eax
  vostok::ui::ui_scroll_pad *m_pad; // ecx
  vostok::math::float2 pos; // [esp+4h] [ebp-8h] BYREF

  v3 = this->m_pad->get_position(this->m_pad);
  m_pad = this->m_pad;
  pos.x = v3->x;
  pos.y = value;
  m_pad->set_position(m_pad, &pos);
}
