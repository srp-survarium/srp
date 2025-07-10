void __thiscall vostok::ui::text_tree_draw_helper::create_window(
        vostok::ui::text_tree_draw_helper *this,
        const char *text,
        vostok::math::float2 pos,
        vostok::math::float2 sz)
{
  int v4; // eax
  int v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+4h] [ebp-14h]
  vostok::ui::window *v7; // [esp+8h] [ebp-10h]
  vostok::ui::text *wnd; // [esp+14h] [ebp-4h]

  wnd = this->m_world->create_text(this->m_world);
  if ( this->m_cur_row % 2 )
    wnd->set_color(wnd, this->m_params.color1);
  else
    wnd->set_color(wnd, this->m_params.color2);
  wnd->set_font(wnd, this->m_params.fnt);
  wnd->set_align(wnd, al_left);
  wnd->set_text(wnd, text);
  v7 = wnd->w(wnd);
  v7->set_position(v7, &pos);
  v6 = (int)wnd->w(wnd);
  (*(void (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)v6 + 8))(v6, &sz);
  v5 = (int)wnd->w(wnd);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 16))(v5, 1);
  v4 = ((int (__thiscall *)(vostok::ui::text *, int))wnd->w)(wnd, 1);
  ((void (__thiscall *)(vostok::ui::window *, int))this->m_window->add_child)(this->m_window, v4);
}
