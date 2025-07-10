void __thiscall vostok::ui::ui_progress_bar::draw_text(
        vostok::ui::ui_progress_bar *this,
        float renderer,
        vostok::render::ui::renderer *scene_view,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_viewa)
{
  float v4; // ebx
  const char **v5; // ebp
  int v6; // eax
  float v7; // xmm1_4
  float x; // xmm0_4
  const char *v9; // eax
  const vostok::ui::font *v10; // esi
  float v11; // xmm1_4
  const vostok::ui::font *v12; // esi
  bool v13; // zf
  void (__thiscall *parse_word)(vostok::ui::font *, const char *, float *, const char **); // edx
  const float *(__thiscall *get_height)(vostok::ui::font *); // edx
  float *v16; // eax
  float v17; // xmm0_4
  vostok::render::ui::renderer *v18; // eax
  unsigned int v19; // eax
  vostok::math::float2 font_pos; // [esp+30h] [ebp-1Ch] BYREF
  const char *word; // [esp+38h] [ebp-14h] BYREF
  vostok::math::float2 pos; // [esp+3Ch] [ebp-10h] BYREF
  vostok::math::float2 size; // [esp+44h] [ebp-8h]

  v4 = renderer;
  v5 = (const char **)(LODWORD(renderer) + 104);
  if ( !vostok::buffer_string::empty((vostok::fs_new::path_string_impl *)(LODWORD(renderer) + 104)) )
  {
    pos = *(vostok::math::float2 *)(*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(v4) + 4) + 4))(LODWORD(v4) + 4);
    vostok::ui::client_to_screen((const vostok::ui::ui_window *)(LODWORD(v4) + 4), &pos);
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(v4) + 4) + 12))(LODWORD(v4) + 4);
    v7 = *(float *)(v6 + 4);
    x = *(float *)v6;
    v9 = *v5;
    v10 = *(const vostok::ui::font **)(LODWORD(v4) + 68);
    size.y = v7;
    v11 = 0.0;
    v12 = v10 + 8;
    word = v9;
    v13 = *v9 == 0;
    size.x = x;
    font_pos.x = 0.0;
    if ( !v13 )
    {
      do
      {
        parse_word = v12->parse_word;
        renderer = 0.0;
        parse_word(v12, v9, &renderer, &word);
        v9 = word;
        v13 = *word == 0;
        v11 = renderer + font_pos.x;
        font_pos.x = renderer + font_pos.x;
      }
      while ( !v13 );
      x = size.x;
    }
    get_height = v12->get_height;
    font_pos.x = (float)((float)(x - v11) * 0.5) + pos.x;
    v16 = (float *)get_height(v12);
    v17 = (float)(size.y - *v16) * 0.5;
    v18 = *(vostok::render::ui::renderer **)v5;
    font_pos.y = v17 + pos.y;
    renderer = *(float *)&v18;
    v19 = vostok::math::floor(size.x);
    vostok::render::ui::renderer::draw_text(
      scene_view,
      scene_viewa,
      (const char *const *)&renderer,
      v12,
      &font_pos,
      (const vostok::math::color *)(LODWORD(v4) + 80),
      (const vostok::math::color *)(LODWORD(v4) + 80),
      v19,
      0,
      0,
      0);
  }
}
