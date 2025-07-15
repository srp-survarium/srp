// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::ui::ui_scroll_pad::tick(vostok::ui::ui_scroll_pad *this)
{
  vostok::ui::window *v2; // eax
  float y; // xmm0_4
  const vostok::math::float2 *(__thiscall *get_position)(struct vostok::ui::ui_scroll_pad *); // eax
  float v5; // xmm0_4
  const vostok::math::float2 *(__thiscall *v6)(struct vostok::ui::ui_scroll_pad *); // eax
  float v7; // xmm0_4
  vostok::ui::window **v8; // edi
  vostok::ui::window **i; // esi
  void **M_start; // [esp-14h] [ebp-28h]
  void **M_finish; // [esp-10h] [ebp-24h]
  float p; // [esp+Ch] [ebp-8h] OVERLAPPED BYREF
  float __val; // [esp+10h] [ebp-4h] BYREF

  v2 = this->get_parent(this);
  y = v2->get_size(v2)->y;
  get_position = this->get_position;
  __val = y;
  v5 = -get_position(this)->y;
  v6 = this->get_position;
  p = v5;
  v7 = __val - v6(this)->y;
  M_finish = this->m_children._M_impl._M_finish;
  M_start = this->m_children._M_impl._M_start;
  __val = v7;
  v8 = stlp_std::priv::__lower_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position,vostok::ui::pred_window_less_position,int>(
         (vostok::ui::window **)M_start,
         (vostok::ui::window **)M_finish,
         &p);
  for ( i = stlp_std::priv::__upper_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position,vostok::ui::pred_window_less_position,int>(
              (vostok::ui::window **)this->m_children._M_impl._M_start,
              (vostok::ui::window **)this->m_children._M_impl._M_finish,
              &__val); v8 != i; ++v8 )
    (*v8)->tick(*v8);
}
