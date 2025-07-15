void __thiscall vostok::render::renderer::draw_stages_stats(
        vostok::render::renderer *this,
        const vostok::ui::font *default_font)
{
  unsigned int v2; // esi
  vostok::render::stage_stat *v3; // edi
  long double v4; // st7
  int v5; // edi
  int v6; // edi
  unsigned int v7; // eax
  const char *v8; // edi
  unsigned int string_index; // [esp+1Ch] [ebp-19Ch]
  vostok::render::stage_stat *v10; // [esp+28h] [ebp-190h]
  unsigned int v11; // [esp+2Ch] [ebp-18Ch]
  unsigned int total_dips; // [esp+30h] [ebp-188h]
  const char *m_begin; // [esp+48h] [ebp-170h]
  const char *v14; // [esp+48h] [ebp-170h]
  const char *v15; // [esp+48h] [ebp-170h]
  const char *v16; // [esp+48h] [ebp-170h]
  const char *v17; // [esp+48h] [ebp-170h]
  const char *v18; // [esp+48h] [ebp-170h]
  unsigned int y_pos; // [esp+4Ch] [ebp-16Ch]
  unsigned int clr; // [esp+5Ch] [ebp-15Ch]
  unsigned int v21; // [esp+64h] [ebp-154h]
  unsigned int char_color; // [esp+68h] [ebp-150h]
  unsigned int stage_index; // [esp+94h] [ebp-124h]
  double total_gpu_time; // [esp+98h] [ebp-120h]
  double total_cpu_time; // [esp+A8h] [ebp-110h]
  vostok::fixed_string<32> result_string_cpu_time; // [esp+B0h] [ebp-108h] BYREF
  vostok::fixed_string<32> total_result_string_gpu_time; // [esp+DCh] [ebp-DCh] BYREF
  vostok::fixed_string<32> result_string_gpu_time; // [esp+108h] [ebp-B0h] BYREF
  vostok::fixed_string<32> total_result_string_cpu_time; // [esp+134h] [ebp-84h] BYREF
  vostok::fixed_string<32> result_string_dips; // [esp+160h] [ebp-58h] BYREF
  vostok::fixed_string<32> total_result_string_dips; // [esp+18Ch] [ebp-2Ch] BYREF
  _UNKNOWN *retaddr; // [esp+1B8h] [ebp+0h] BYREF

  v2 = 0;
  string_index = 0;
  total_gpu_time = 0.0;
  total_cpu_time = 0.0;
  total_dips = 0;
  stage_index = 0;
  v21 = 5;
  do
  {
    if ( v2 == 29 )
    {
      v3 = &s_visibility_stage_stats;
      v10 = &s_visibility_stage_stats;
    }
    else
    {
      v10 = &s_render_stages[v2];
      v3 = v10;
    }
    if ( v3->stg )
    {
      v4 = v3->elapsed_gpu_msec[0];
      result_string_gpu_time.m_begin = result_string_gpu_time.m_buffer;
      result_string_gpu_time.m_end = result_string_gpu_time.m_buffer;
      result_string_cpu_time.m_begin = result_string_cpu_time.m_buffer;
      result_string_gpu_time.m_max_end = (char *)&total_result_string_cpu_time;
      result_string_cpu_time.m_end = result_string_cpu_time.m_buffer;
      result_string_dips.m_begin = result_string_dips.m_buffer;
      result_string_cpu_time.m_max_end = (char *)&total_result_string_gpu_time;
      result_string_gpu_time.m_buffer[0] = 0;
      result_string_cpu_time.m_buffer[0] = 0;
      result_string_dips.m_end = result_string_dips.m_buffer;
      result_string_dips.m_max_end = (char *)&total_result_string_dips;
      result_string_dips.m_buffer[0] = 0;
      vostok::buffer_string::assignf(&result_string_gpu_time, "all: %4.4f", (double)v4);
      vostok::buffer_string::assignf(&result_string_cpu_time, "cpu: %4.4f", (double)v3->elapsed_cpu_msec[0]);
      vostok::buffer_string::assignf(&result_string_dips, "dips: %d", (unsigned int)(__int64)(double)v3->dips[0]);
      if ( (string_index & 1) != 0 )
      {
        v6 = (unsigned __int8)vostok::math::floor(191.25);
        v7 = vostok::math::floor(255.0);
        clr = v6 | (((unsigned __int8)v7 | ((v6 | (v7 << 8)) << 8)) << 8);
      }
      else
      {
        v11 = vostok::math::floor(255.0);
        v5 = ((v11 << 8) | (unsigned __int8)vostok::math::floor(127.5)) << 8;
        clr = (unsigned __int8)v11 | (((unsigned __int8)vostok::math::floor(191.25) | v5) << 8);
      }
      v8 = vostok::render::render_stage_names[v2];
      vostok::render::draw_text(v8, default_font, 6u, v21 + 1, (vostok::math::color)-16777216);
      vostok::render::draw_text(v8, default_font, 5u, v21, (vostok::math::color)clr);
      m_begin = result_string_gpu_time.m_begin;
      vostok::render::draw_text(
        result_string_gpu_time.m_begin,
        default_font,
        0xCAu,
        v21 + 1,
        (vostok::math::color)-16777216);
      vostok::render::draw_text(m_begin, default_font, 0xC9u, v21, (vostok::math::color)clr);
      v14 = result_string_cpu_time.m_begin;
      vostok::render::draw_text(
        result_string_cpu_time.m_begin,
        default_font,
        0x11Eu,
        v21 + 1,
        (vostok::math::color)-16777216);
      vostok::render::draw_text(v14, default_font, 0x11Du, v21, (vostok::math::color)clr);
      v15 = result_string_dips.m_begin;
      vostok::render::draw_text(
        result_string_dips.m_begin,
        default_font,
        0x172u,
        v21 + 1,
        (vostok::math::color)-16777216);
      vostok::render::draw_text(v15, default_font, 0x171u, v21, (vostok::math::color)clr);
      ++string_index;
      total_gpu_time = v10->elapsed_gpu_msec[0] + total_gpu_time;
      v21 += 12;
      total_cpu_time = v10->elapsed_cpu_msec[0] + total_cpu_time;
      v2 = stage_index;
      total_dips += (__int64)(double)v10->dips[0];
    }
    stage_index = ++v2;
  }
  while ( v2 < 0x1E );
  total_result_string_gpu_time.m_begin = total_result_string_gpu_time.m_buffer;
  total_result_string_gpu_time.m_end = total_result_string_gpu_time.m_buffer;
  total_result_string_cpu_time.m_begin = total_result_string_cpu_time.m_buffer;
  total_result_string_cpu_time.m_end = total_result_string_cpu_time.m_buffer;
  total_result_string_gpu_time.m_max_end = (char *)&result_string_gpu_time;
  total_result_string_dips.m_begin = total_result_string_dips.m_buffer;
  total_result_string_dips.m_end = total_result_string_dips.m_buffer;
  total_result_string_cpu_time.m_max_end = (char *)&result_string_dips;
  total_result_string_dips.m_max_end = (char *)&retaddr;
  y_pos = 12 * string_index + 5;
  total_result_string_gpu_time.m_buffer[0] = 0;
  total_result_string_cpu_time.m_buffer[0] = 0;
  total_result_string_dips.m_buffer[0] = 0;
  char_color = (unsigned int)&vostok::memory::s_CRT_arena[5508664] & 0x7F0000 | 0xFF00FF7F;
  vostok::buffer_string::assignf(&total_result_string_gpu_time, "all: %4.4f", total_gpu_time);
  vostok::buffer_string::assignf(&total_result_string_cpu_time, "cpu: %4.4f", total_cpu_time);
  vostok::buffer_string::assignf(&total_result_string_dips, "dips: %d", total_dips);
  vostok::render::draw_text("total", default_font, 6u, 12 * string_index + 6, (vostok::math::color)-16777216);
  vostok::render::draw_text("total", default_font, 5u, y_pos, (vostok::math::color)char_color);
  v16 = total_result_string_gpu_time.m_begin;
  vostok::render::draw_text(
    total_result_string_gpu_time.m_begin,
    default_font,
    0xCAu,
    12 * string_index + 6,
    (vostok::math::color)-16777216);
  vostok::render::draw_text(v16, default_font, 0xC9u, y_pos, (vostok::math::color)char_color);
  v17 = total_result_string_cpu_time.m_begin;
  vostok::render::draw_text(
    total_result_string_cpu_time.m_begin,
    default_font,
    0x11Eu,
    12 * string_index + 6,
    (vostok::math::color)-16777216);
  vostok::render::draw_text(v17, default_font, 0x11Du, y_pos, (vostok::math::color)char_color);
  v18 = total_result_string_dips.m_begin;
  vostok::render::draw_text(
    total_result_string_dips.m_begin,
    default_font,
    0x172u,
    12 * string_index + 6,
    (vostok::math::color)-16777216);
  vostok::render::draw_text(v18, default_font, 0x171u, y_pos, (vostok::math::color)char_color);
}
