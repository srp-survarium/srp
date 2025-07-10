void __thiscall vostok::ui::ui_scroll_pad::draw(
        vostok::ui::ui_scroll_pad *this,
        vostok::render::ui::renderer *renderer,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::window *v4; // eax
  float y; // xmm0_4
  const vostok::math::float2 *(__thiscall *get_position)(struct vostok::ui::ui_scroll_pad *); // eax
  float v7; // xmm0_4
  const vostok::math::float2 *(__thiscall *v8)(struct vostok::ui::ui_scroll_pad *); // eax
  float v9; // xmm0_4
  vostok::ui::window **v10; // edi
  vostok::ui::window **i; // esi
  void **M_start; // [esp-14h] [ebp-28h]
  void **M_finish; // [esp-10h] [ebp-24h]
  vostok::math::float2 range; // [esp+Ch] [ebp-8h] BYREF

  v4 = this->get_parent(this);
  y = v4->get_size(v4)->y;
  get_position = this->get_position;
  range.y = y;
  v7 = -get_position(this)->y;
  v8 = this->get_position;
  range.x = v7;
  v9 = range.y - v8(this)->y;
  M_finish = this->m_children._M_impl._M_finish;
  M_start = this->m_children._M_impl._M_start;
  range.y = v9;
  v10 = stlp_std::priv::__lower_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position,vostok::ui::pred_window_less_position,int>(
          (vostok::ui::window **)M_start,
          (vostok::ui::window **)M_finish,
          &range.x);
  for ( i = stlp_std::priv::__upper_bound<vostok::ui::window * *,float,vostok::ui::pred_window_less_position,vostok::ui::pred_window_less_position,int>(
              (vostok::ui::window **)this->m_children._M_impl._M_start,
              (vostok::ui::window **)this->m_children._M_impl._M_finish,
              &range.y); v10 != i; ++v10 )
    (*v10)->draw(*v10, renderer, scene_view);
}
