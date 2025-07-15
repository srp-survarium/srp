bool __thiscall vostok::ui::ui_scroll_bar::on_self_size_changed(
        vostok::ui::ui_scroll_bar *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_window *v5; // esi
  const vostok::math::float2 *v6; // ebp
  const vostok::math::float2 *v7; // eax
  void (__thiscall *set_position)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  float *v9; // ebp
  const vostok::math::float2 *v10; // eax
  const vostok::math::float2 *(__thiscall *get_size)(struct vostok::ui::ui_window *); // edx
  float *p_y; // esi
  float v13; // xmm0_4
  void (__thiscall *v14)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  vostok::ui::ui_scroll_bar *v15; // ecx
  float v17[2]; // [esp+10h] [ebp-10h] BYREF
  _DWORD v18[2]; // [esp+18h] [ebp-8h] BYREF

  v5 = &this->vostok::ui::ui_window;
  v6 = this->get_size(&this->vostok::ui::ui_window);
  v7 = this->m_btn_lt.get_size(&this->m_btn_lt);
  set_position = this->m_btn_lt.set_position;
  v17[0] = v6->x - v7->x;
  v17[1] = 0.0;
  set_position(&this->m_btn_lt, (const vostok::math::float2 *)v17);
  v9 = (float *)v5->get_size(v5);
  v10 = this->m_btn_rb.get_size(&this->m_btn_rb);
  get_size = v5->get_size;
  v17[0] = *v9 - v10->x;
  p_y = &get_size(v5)->y;
  v13 = *p_y - this->m_btn_rb.get_size(&this->m_btn_rb)->y;
  v14 = this->m_btn_rb.set_position;
  *(float *)v18 = v17[0];
  *(float *)&v18[1] = v13;
  v14(&this->m_btn_rb, (const vostok::math::float2 *)v18);
  vostok::ui::ui_scroll_bar::update_self(v15, (int)this);
  return 0;
}
