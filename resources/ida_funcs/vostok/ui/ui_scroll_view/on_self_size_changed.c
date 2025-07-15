bool __thiscall vostok::ui::ui_scroll_view::on_self_size_changed(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_window *v4; // edi
  vostok::ui::ui_window *v5; // esi
  const vostok::math::float2 *v6; // ebx
  float *v7; // eax
  void (__thiscall *set_position)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  float y; // xmm0_4
  void (__thiscall *set_size)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  float x; // [esp+Ch] [ebp-14h]
  vostok::math::float2 scb_pos; // [esp+10h] [ebp-10h] BYREF
  vostok::math::float2 scb_size; // [esp+18h] [ebp-8h] BYREF

  v4 = &this->vostok::ui::ui_window;
  v5 = &this->m_scroll_bar_v.vostok::ui::ui_window;
  v6 = this->get_size(&this->vostok::ui::ui_window);
  v7 = (float *)v5->get_size(v5);
  set_position = v5->set_position;
  scb_pos = (vostok::math::float2)COERCE_UNSIGNED_INT(v6->x - *v7);
  set_position(v5, &scb_pos);
  x = v5->get_size(v5)->x;
  y = v4->get_size(v4)->y;
  set_size = v5->set_size;
  scb_size = (vostok::math::float2)__PAIR64__(LODWORD(y), LODWORD(x));
  set_size(v5, &scb_size);
  return 0;
}
