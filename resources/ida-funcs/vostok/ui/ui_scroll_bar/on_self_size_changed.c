bool __thiscall vostok::ui::ui_scroll_bar::on_self_size_changed(
        vostok::ui::ui_scroll_bar *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_window *v5; // edi
  float v6; // xmm0_4
  vostok::ui::ui_window_vtbl *v7; // eax
  const vostok::math::float2 *v8; // eax
  float v9; // xmm0_4
  vostok::ui::ui_window_vtbl *v10; // eax
  float *p_y; // edi
  float v12; // xmm0_4
  vostok::ui::ui_window_vtbl *v13; // eax
  vostok::ui::ui_scroll_bar *v14; // ecx
  float v16; // [esp+Ch] [ebp-Ch] BYREF
  float v17; // [esp+10h] [ebp-8h]
  float v18; // [esp+14h] [ebp-4h]

  v5 = &this->vostok::ui::ui_window;
  v18 = COERCE_FLOAT((int)this->get_size(&this->vostok::ui::ui_window));
  v6 = *(float *)LODWORD(v18) - this->m_btn_lt.get_size(&this->m_btn_lt)->x;
  v7 = this->m_btn_lt.__vftable;
  v16 = v6;
  v17 = 0.0;
  v7->set_position(&this->m_btn_lt, (const vostok::math::float2 *)&v16);
  v18 = COERCE_FLOAT((int)v5->get_size(v5));
  v8 = this->m_btn_rb.get_size(&this->m_btn_rb);
  v9 = *(float *)LODWORD(v18) - v8->x;
  v10 = v5->__vftable;
  v18 = v9;
  p_y = &v10->get_size(v5)->y;
  v12 = *p_y - this->m_btn_rb.get_size(&this->m_btn_rb)->y;
  v13 = this->m_btn_rb.__vftable;
  v16 = v18;
  v17 = v12;
  v13->set_position(&this->m_btn_rb, (const vostok::math::float2 *)&v16);
  vostok::ui::ui_scroll_bar::update_self(v14, (int)this);
  return 0;
}
