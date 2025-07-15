char __thiscall vostok::ui::ui_scroll_view::on_keyb_action(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_scroll_bar *v6; // ecx
  float v7; // xmm0_4
  vostok::ui::ui_scroll_bar *p_m_scroll_bar_v; // esi
  vostok::ui::ui_scroll_bar *v10; // ecx
  float size; // [esp+0h] [ebp-Ch]
  float sizea; // [esp+0h] [ebp-Ch]
  float v13; // [esp+1Ch] [ebp+10h]
  float v14; // [esp+1Ch] [ebp+10h]

  if ( p2 == 1 || p2 == 3 )
  {
    switch ( p1 )
    {
      case 208:
        v13 = ((double (*)(void))this->m_scroll_source_v.get_step_size)();
        v7 = v13;
        if ( p2 == 3 )
          v7 = v13 * 0.1;
        LODWORD(size) = LODWORD(v7) ^ _mask__NegFloat_;
LABEL_7:
        vostok::ui::ui_scroll_bar::move(v6, (int)&this->m_scroll_bar_v, size);
LABEL_8:
        this->set_follow_last_line(this, 0);
        return 1;
      case 200:
        v14 = ((double (*)(void))this->m_scroll_source_v.get_step_size)();
        if ( p2 == 3 )
          v14 = v14 * 0.1;
        size = v14;
        goto LABEL_7;
      case 207:
        vostok::ui::ui_scroll_bar::move_end((vostok::ui::ui_scroll_bar *)this, (int)&this->m_scroll_bar_v);
        this->set_follow_last_line(this, 1);
        return 1;
      case 199:
        p_m_scroll_bar_v = &this->m_scroll_bar_v;
        sizea = this->m_scroll_bar_v.m_source->get_length(this->m_scroll_bar_v.m_source);
        vostok::ui::ui_scroll_bar::move(v10, (int)p_m_scroll_bar_v, sizea);
        goto LABEL_8;
    }
  }
  return 0;
}
