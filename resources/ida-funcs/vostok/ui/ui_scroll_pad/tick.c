void __thiscall vostok::ui::ui_scroll_pad::tick(vostok::ui::ui_scroll_pad *this)
{
  vostok::ui::window *v2; // eax
  float y; // xmm0_4
  vostok::ui::ui_scroll_pad_vtbl *v4; // eax
  float v5; // xmm0_4
  vostok::ui::ui_scroll_pad_vtbl *v6; // eax
  float v7; // xmm0_4
  void **M_finish; // eax
  void **M_start; // ecx
  vostok::ui::window **v10; // edi
  vostok::ui::window **v11; // esi
  float __val; // [esp+8h] [ebp-8h] BYREF
  vostok::ui::pred_window_less_position __comp[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = this->get_parent(this);
  y = v2->get_size(v2)->y;
  v4 = this->__vftable;
  *(float *)__comp = y;
  LODWORD(v5) = LODWORD(v4->get_position(this)->y) ^ _mask__NegFloat_;
  v6 = this->__vftable;
  __val = v5;
  v7 = *(float *)__comp - v6->get_position(this)->y;
  M_finish = this->m_children._M_impl._M_finish;
  M_start = this->m_children._M_impl._M_start;
  *(float *)__comp = v7;
  v10 = stlp_std::lower_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position>(
          (vostok::ui::window **)M_start,
          (vostok::ui::window **)M_finish,
          &__val);
  v11 = stlp_std::upper_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position>(
          (vostok::ui::window **)this->m_children._M_impl._M_start,
          (vostok::ui::window **)this->m_children._M_impl._M_finish,
          (float *)__comp);
  while ( v10 != v11 )
  {
    (*v10)->tick(*v10);
    ++v10;
  }
}
