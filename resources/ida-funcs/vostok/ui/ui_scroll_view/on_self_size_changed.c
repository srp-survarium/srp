bool __thiscall vostok::ui::ui_scroll_view::on_self_size_changed(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_window *v4; // edi
  vostok::ui::ui_window *v5; // esi
  const vostok::math::float2 *v6; // ebx
  float v7; // xmm0_4
  vostok::ui::ui_window_vtbl *v8; // eax
  float x; // xmm0_4
  vostok::ui::ui_window_vtbl *v10; // eax
  float y; // xmm0_4
  vostok::ui::ui_window_vtbl *v12; // eax
  _DWORD v14[2]; // [esp+Ch] [ebp-18h] BYREF
  _DWORD v15[2]; // [esp+14h] [ebp-10h] BYREF
  float v16; // [esp+1Ch] [ebp-8h]

  v4 = &this->vostok::ui::ui_window;
  v5 = &this->m_scroll_bar_v.vostok::ui::ui_window;
  v6 = this->get_size(&this->vostok::ui::ui_window);
  v7 = v6->x - v5->get_size(v5)->x;
  v8 = v5->__vftable;
  *(float *)v15 = v7;
  v15[1] = 0;
  v8->set_position(v5, (const vostok::math::float2 *)v15);
  x = v5->get_size(v5)->x;
  v10 = v4->__vftable;
  v16 = x;
  y = v10->get_size(v4)->y;
  v12 = v5->__vftable;
  *(float *)v14 = v16;
  *(float *)&v14[1] = y;
  v12->set_size(v5, (const vostok::math::float2 *)v14);
  return 0;
}
