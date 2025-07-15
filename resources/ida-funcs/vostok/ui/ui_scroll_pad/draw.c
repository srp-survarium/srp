void __thiscall vostok::ui::ui_scroll_pad::draw(
        vostok::ui::ui_scroll_pad *this,
        vostok::render::ui::renderer *renderer,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::window *v4; // eax
  float y; // xmm0_4
  vostok::ui::ui_scroll_pad_vtbl *v6; // eax
  float v7; // xmm0_4
  vostok::ui::ui_scroll_pad_vtbl *v8; // eax
  float v9; // xmm0_4
  void **M_finish; // eax
  void **M_start; // ecx
  vostok::ui::window **v12; // edi
  vostok::ui::window **v13; // esi
  float __val; // [esp+8h] [ebp-8h] BYREF
  float v15; // [esp+Ch] [ebp-4h] BYREF

  v4 = this->get_parent(this);
  y = v4->get_size(v4)->y;
  v6 = this->__vftable;
  v15 = y;
  LODWORD(v7) = LODWORD(v6->get_position(this)->y) ^ _mask__NegFloat_;
  v8 = this->__vftable;
  __val = v7;
  v9 = v15 - v8->get_position(this)->y;
  M_finish = this->m_children._M_impl._M_finish;
  M_start = this->m_children._M_impl._M_start;
  v15 = v9;
  v12 = stlp_std::lower_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position>(
          (vostok::ui::window **)M_start,
          (vostok::ui::window **)M_finish,
          &__val);
  v13 = stlp_std::upper_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position>(
          (vostok::ui::window **)this->m_children._M_impl._M_start,
          (vostok::ui::window **)this->m_children._M_impl._M_finish,
          &v15);
  while ( v12 != v13 )
  {
    (*v12)->draw(*v12, renderer, scene_view);
    ++v12;
  }
}
