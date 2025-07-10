char __thiscall vostok::ui::ui_scroll_view::on_keyb_action(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_scroll_bar *v6; // ecx
  float v7; // xmm0_4
  vostok::ui::ui_scroll_bar *v9; // ecx
  vostok::ui::ui_scroll_bar *v10; // ecx
  float size; // [esp+0h] [ebp-Ch]
  float v12; // [esp+4h] [ebp-8h]
  float step; // [esp+18h] [ebp+Ch]
  float stepa; // [esp+18h] [ebp+Ch]

  if ( p2 != 1 && p2 != 3 )
    return 0;
  if ( p1 == 208 )
  {
    step = this->m_scroll_source_v.get_step_size(&this->m_scroll_source_v);
    v7 = step;
    if ( p2 == 3 )
      v7 = step * 0.1;
    vostok::ui::ui_scroll_bar::move(v6, (int)this, (int)&this->m_scroll_bar_v, -v7, v12);
    this->set_follow_last_line(this, 0);
    return 1;
  }
  if ( p1 != 200 )
  {
    if ( p1 == 207 )
    {
      size = -((double (__thiscall *)(vostok::ui::scroll_source *))this->m_scroll_bar_v.m_source->get_length)(this->m_scroll_bar_v.m_source);
      vostok::ui::ui_scroll_bar::move(v10, (int)this, (int)&this->m_scroll_bar_v, size, v12);
      this->set_follow_last_line(this, 1);
      return 1;
    }
    if ( p1 == 199 )
    {
      vostok::ui::ui_scroll_bar::move_begin((vostok::ui::ui_scroll_bar *)this, (int)&this->m_scroll_bar_v, (int)this);
      this->set_follow_last_line(this, 0);
      return 1;
    }
    return 0;
  }
  stepa = this->m_scroll_source_v.get_step_size(&this->m_scroll_source_v);
  if ( p2 == 3 )
    stepa = stepa * 0.1;
  vostok::ui::ui_scroll_bar::move(v9, (int)this, (int)&this->m_scroll_bar_v, stepa, v12);
  this->set_follow_last_line(this, 0);
  return 1;
}
