void __cdecl vostok::render::draw_text(
        vostok::ui::font *in_font,
        const char *str,
        unsigned int pos_x,
        unsigned int pos_y,
        int clr)
{
  unsigned int v5; // edi
  vostok::buffer_vector<vostok::render::ui::vertex> v6; // [esp+8h] [ebp-E01Ch] BYREF
  _BYTE v7[57344]; // [esp+14h] [ebp-E010h] BYREF
  char v8; // [esp+E014h] [ebp-10h] BYREF
  vostok::math::float2 v9; // [esp+E018h] [ebp-Ch] BYREF

  v5 = strlen(str);
  v6.m_begin = (vostok::render::ui::vertex *)v7;
  v6.m_end = (vostok::render::ui::vertex *)v7;
  v6.m_max_end = (vostok::render::ui::vertex *)&v8;
  vostok::buffer_vector<vostok::render::ui::vertex>::resize(&v6, 4 * v5);
  v9.x = (float)pos_x;
  v9.y = (float)pos_y;
  vostok::render::make_ui_vertices(
    in_font,
    &v9,
    v6.m_begin,
    str,
    (const vostok::math::color *)&clr,
    (const vostok::math::color *)&clr,
    v5);
  clr = v6.m_end - v6.m_begin;
  vostok::render::system_renderer::draw_ui_vertices(
    (vostok::render::system_renderer *)0x1C,
    (vostok::render::vertex_formats::TL *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
    (unsigned __int8 *)v6.m_begin,
    (unsigned int *)&clr,
    0,
    0);
}
