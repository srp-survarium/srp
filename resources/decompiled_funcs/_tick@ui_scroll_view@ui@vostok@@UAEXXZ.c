void __thiscall vostok::ui::ui_scroll_view::tick(vostok::ui::ui_scroll_view *this)
{
  if ( ((int)this->m_children._M_impl._M_end_of_storage._M_data & 1) != 0 )
    vostok::ui::ui_scroll_view::recalc(this, (int)&this[-1].m_scroll_source_v.m_step);
  vostok::ui::ui_window::tick((vostok::ui::ui_window *)this);
}
