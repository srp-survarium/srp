void __userpurge vostok::render::renderer::draw_luminance_picker_info(
        vostok::render::renderer *this@<ecx>,
        float *a2@<eax>,
        const vostok::ui::font *default_font)
{
  vostok::fixed_string<64> *v4; // eax
  int v5; // edi
  char *m_buffer; // ecx
  char *v7; // ecx
  char *v8; // ecx
  unsigned int v9; // eax
  vostok::math::color v10; // ebx
  int v11; // eax
  double g; // [esp+4h] [ebp-2F8h]
  float lum_finala; // [esp+28h] [ebp-2D4h]
  char *lum_final; // [esp+28h] [ebp-2D4h]
  float lum_diffusea; // [esp+2Ch] [ebp-2D0h]
  unsigned int lum_diffuse; // [esp+2Ch] [ebp-2D0h]
  vostok::math::color *v17; // [esp+30h] [ebp-2CCh]
  const char *str; // [esp+34h] [ebp-2C8h]
  vostok::math::color *v19; // [esp+38h] [ebp-2C4h]
  unsigned int pos_y; // [esp+3Ch] [ebp-2C0h]
  vostok::math::color rgbl_colors[4]; // [esp+8Ch] [ebp-270h] BYREF
  vostok::fixed_string<64> strings[8]; // [esp+9Ch] [ebp-260h] BYREF

  v4 = &strings[2];
  v5 = 2;
  do
  {
    m_buffer = v4[-2].m_buffer;
    v4[-2].m_begin = v4[-2].m_buffer;
    v4[-2].m_end = v4[-2].m_buffer;
    v4[-2].m_max_end = (char *)&v4[-1];
    *m_buffer = 0;
    *m_buffer = 0;
    v7 = v4[-1].m_buffer;
    v4[-1].m_begin = v4[-1].m_buffer;
    v4[-1].m_end = v4[-1].m_buffer;
    v4[-1].m_max_end = (char *)v4;
    *v7 = 0;
    *v7 = 0;
    v4->m_begin = v4->m_buffer;
    v4->m_end = v4->m_buffer;
    v4->m_max_end = (char *)&v4[1];
    v4->m_buffer[0] = 0;
    v4->m_buffer[0] = 0;
    v8 = v4[1].m_buffer;
    v4[1].m_begin = v4[1].m_buffer;
    v4[1].m_end = v4[1].m_buffer;
    v4[1].m_max_end = (char *)&v4[2];
    v4 += 4;
    --v5;
    *v8 = 0;
    *v8 = 0;
  }
  while ( v5 );
  rgbl_colors[0].m_value = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(1.0), 0.5, 1.0);
  rgbl_colors[1].m_value = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 1.0, 1.0);
  rgbl_colors[2].m_value = vostok::math::color_rgba(*(float *)&clear_value, COERCE_VOSTOK_MATH_(0.5), 0.5, 1.0);
  v9 = vostok::math::color_rgba(*(float *)&clear_value, COERCE_VOSTOK_MATH_(1.0), 1.0, 1.0);
  lum_diffusea = (float)((float)(a2[40] * 0.072099999) + (float)(a2[39] * 0.71539998)) + (float)(a2[38] * 0.21250001);
  lum_finala = (float)((float)(a2[44] * 0.072099999) + (float)(a2[43] * 0.71539998)) + (float)(a2[42] * 0.21250001);
  v10 = (vostok::math::color)v9;
  g = a2[38];
  rgbl_colors[3].m_value = v9;
  vostok::buffer_string::assignf(&strings[0], "r: %f", g);
  vostok::buffer_string::assignf(&strings[1], "g: %f", a2[39]);
  vostok::buffer_string::assignf(&strings[2], "b: %f", a2[40]);
  vostok::buffer_string::assignf(&strings[3], "lum: %f", lum_diffusea);
  vostok::buffer_string::assignf(&strings[4], "r: %f", a2[42]);
  vostok::buffer_string::assignf(&strings[5], "g: %f", a2[43]);
  vostok::buffer_string::assignf(&strings[6], "b: %f", a2[44]);
  vostok::buffer_string::assignf(&strings[7], "lum: %f", lum_finala);
  v11 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 1.0);
  vostok::render::draw_text("hdr diffuse lighting only:", default_font, 6u, 6u, (vostok::math::color)v11);
  vostok::render::draw_text("hdr diffuse lighting only:", default_font, 5u, 5u, v10);
  v17 = rgbl_colors;
  lum_final = strings[0].m_buffer;
  for ( lum_diffuse = 17; lum_diffuse < 0x41; lum_diffuse += 12 )
  {
    vostok::render::draw_text(lum_final, default_font, 6u, lum_diffuse + 1, (vostok::math::color)-16777216);
    vostok::render::draw_text(lum_final, default_font, 5u, lum_diffuse, *v17);
    lum_final += 76;
    ++v17;
  }
  vostok::render::draw_text("hdr final scene:", default_font, 6u, 0x47u, (vostok::math::color)-16777216);
  vostok::render::draw_text(
    "hdr final scene:",
    default_font,
    5u,
    0x46u,
    (vostok::math::color)((unsigned int)&vostok::memory::s_CRT_arena[5508664] & 0xFF0000 | 0xFF00FFFF));
  str = strings[4].m_buffer;
  pos_y = 82;
  v19 = rgbl_colors;
  do
  {
    vostok::render::draw_text(str, default_font, 6u, pos_y + 1, (vostok::math::color)-16777216);
    vostok::render::draw_text(str, default_font, 5u, pos_y, *v19++);
    pos_y += 12;
    str += 76;
  }
  while ( pos_y < 0x82 );
}
