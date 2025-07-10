void __thiscall vostok::ui::text_tree_draw_helper::text_tree_draw_helper(
        vostok::ui::text_tree_draw_helper *this,
        vostok::ui::world *w,
        vostok::ui::window *wnd,
        vostok::ui::text_tree_draw_helper_params p,
        vostok::memory::base_allocator *a)
{
  int v5; // eax
  const vostok::ui::font *m_font; // [esp+4h] [ebp-18h]
  char m_action; // [esp+Bh] [ebp-11h] BYREF
  float v9; // [esp+Ch] [ebp-10h]
  const survarium::key_binder *v10; // [esp+10h] [ebp-Ch]

  this->m_world = w;
  this->m_window = wnd;
  vostok::ui::text_tree_draw_helper_params::text_tree_draw_helper_params(&this->m_params, &p);
  this->m_allocator = a;
  this->m_font = this->m_world->default_font(this->m_world);
  m_font = this->m_font;
  v10 = &stru_95AF78;
  v9 = *(float *)&FLOAT_0_0;
  while ( LOBYTE(v10->m_key_bindings[0].m_action) )
  {
    m_action = (char)v10->m_key_bindings[0].m_action;
    v5 = m_font->get_char_tc(m_font, (const unsigned __int8 *)&m_action);
    v9 = v9 + *(float *)(v5 + 8);
    v10 = (const survarium::key_binder *)((char *)v10 + 1);
  }
  this->m_space_width = v9;
  this->m_page_width = *(float *)&FLOAT_0_0;
}
