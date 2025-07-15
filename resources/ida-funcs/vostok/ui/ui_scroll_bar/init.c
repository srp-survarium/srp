void __usercall vostok::ui::ui_scroll_bar::init(
        vostok::ui::ui_scroll_bar *this@<esi>,
        vostok::ui::scroll_source *src@<eax>)
{
  vostok::ui::ui_window_vtbl *v2; // edx
  const vostok::math::float2 *(__thiscall *get_size)(struct vostok::ui::ui_window *); // eax
  float y; // xmm0_4
  void (__thiscall *set_position)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  _DWORD v6[3]; // [esp+0h] [ebp-Ch] BYREF

  v2 = this->m_btn_lt.__vftable;
  this->m_source = src;
  get_size = v2->get_size;
  this->m_vertical = 1;
  y = get_size(&this->m_btn_lt)->y;
  set_position = this->m_track_button.set_position;
  v6[0] = 0;
  *(float *)&v6[1] = y;
  set_position(&this->m_track_button.vostok::ui::ui_window, (const vostok::math::float2 *)v6);
}
