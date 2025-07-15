void __thiscall vostok::render::renderer::draw_stages_stats(
        vostok::render::renderer *this,
        vostok::ui::font *default_font)
{
  int v2; // eax
  unsigned int v3; // esi
  vostok::render::stage_stat *v4; // ebx
  unsigned __int64 v5; // st7
  vostok::buffer_string *v6; // ecx
  vostok::buffer_string *v7; // ecx
  double v8; // st7
  float v9; // xmm0_4
  double v10; // st7
  long double v11; // xmm0_8
  unsigned int v12; // esi
  int v13; // ebx
  vostok::buffer_string *v14; // ecx
  vostok::buffer_string *v15; // ecx
  vostok::buffer_string *v16; // ecx
  float v17; // [esp+0h] [ebp-148h]
  float v18; // [esp+4h] [ebp-144h]
  const char *v19[3]; // [esp+1Ch] [ebp-12Ch] BYREF
  _BYTE v20[32]; // [esp+28h] [ebp-120h] BYREF
  const char *v21[3]; // [esp+48h] [ebp-100h] BYREF
  _BYTE v22[32]; // [esp+54h] [ebp-F4h] BYREF
  const char *v23[3]; // [esp+74h] [ebp-D4h] BYREF
  _BYTE v24[32]; // [esp+80h] [ebp-C8h] BYREF
  const char *v25[3]; // [esp+A0h] [ebp-A8h] BYREF
  _BYTE v26[32]; // [esp+ACh] [ebp-9Ch] BYREF
  const char *v27[3]; // [esp+CCh] [ebp-7Ch] BYREF
  _BYTE v28[32]; // [esp+D8h] [ebp-70h] BYREF
  const char *v29[3]; // [esp+F8h] [ebp-50h] BYREF
  _BYTE v30[32]; // [esp+104h] [ebp-44h] BYREF
  long double v31; // [esp+124h] [ebp-24h] BYREF
  long double v32; // [esp+12Ch] [ebp-1Ch]
  const char *v33; // [esp+134h] [ebp-14h]
  int v34; // [esp+138h] [ebp-10h]
  unsigned int v35; // [esp+13Ch] [ebp-Ch]
  int v36; // [esp+140h] [ebp-8h]

  v2 = 0;
  v34 = 0;
  v31 = 0.0;
  v32 = 0.0;
  v33 = 0;
  v35 = 0;
  v3 = 5;
  do
  {
    if ( v35 == 28 )
      v4 = &s_visibility_stage_stats;
    else
      v4 = &s_render_stages[v35];
    if ( v4->stg )
    {
      v5 = *(unsigned __int64 *)&v4->elapsed_gpu_msec[0];
      v21[0] = v22;
      v21[1] = v22;
      v21[2] = (const char *)v23;
      v25[0] = v26;
      v25[1] = v26;
      v25[2] = (const char *)v27;
      v29[0] = v30;
      v29[1] = v30;
      v29[2] = (const char *)&v31;
      v22[0] = 0;
      v26[0] = 0;
      v30[0] = 0;
      vostok::fs_new::path_string_impl::assignf(
        v21,
        (vostok::buffer_string *)this,
        (vostok::buffer_string *)"all: %4.4f",
        (const char *)v5,
        (_DWORD)HIDWORD(v5));
      vostok::fs_new::path_string_impl::assignf(
        v25,
        v6,
        (vostok::buffer_string *)"cpu: %4.4f",
        (const char *)COERCE_UNSIGNED_INT64(v4->elapsed_cpu_msec[0]),
        (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v4->elapsed_cpu_msec[0])));
      vostok::fs_new::path_string_impl::assignf(
        v29,
        v7,
        (vostok::buffer_string *)"dips: %d",
        (const char *)(unsigned __int64)(double)v4->dips[0]);
      v8 = 1.0;
      if ( (v34 & 1) != 0 )
      {
        v9 = FLOAT_0_75;
        v18 = 1.0;
        v8 = 0.75;
      }
      else
      {
        v9 = c_anim_center;
        v18 = 0.75;
      }
      v17 = v8;
      v36 = vostok::math::color_rgba(v9, (vostok::math *)LODWORD(v17), v18, 1.0);
      vostok::render::draw_text_shadowed(5u, v3, default_font, vostok::render::render_stage_names[v35], v36);
      vostok::render::draw_text_shadowed(0xC9u, v3, default_font, v21[0], v36);
      vostok::render::draw_text_shadowed(0x11Du, v3, default_font, v25[0], v36);
      vostok::render::draw_text_shadowed(0x171u, v3, default_font, v29[0], v36);
      v10 = (double)v4->dips[0];
      v11 = v4->elapsed_gpu_msec[0] + v31;
      ++v34;
      v31 = v11;
      v3 += 12;
      v32 = v4->elapsed_cpu_msec[0] + v32;
      v33 += (unsigned __int64)v10;
      v2 = v34;
    }
    ++v35;
  }
  while ( v35 < 0x1D );
  v27[0] = v28;
  v27[1] = v28;
  v27[2] = (const char *)v29;
  v23[0] = v24;
  v23[1] = v24;
  v23[2] = (const char *)v25;
  v19[0] = v20;
  v19[1] = v20;
  v28[0] = 0;
  v24[0] = 0;
  v19[2] = (const char *)v21;
  v20[0] = 0;
  v12 = 12 * v2 + 5;
  v13 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 1.0, 1.0);
  vostok::fs_new::path_string_impl::assignf(
    v27,
    v14,
    (vostok::buffer_string *)"all: %4.4f",
    (const char *)LODWORD(v31),
    HIDWORD(v31));
  vostok::fs_new::path_string_impl::assignf(
    v23,
    v15,
    (vostok::buffer_string *)"cpu: %4.4f",
    (const char *)LODWORD(v32),
    HIDWORD(v32));
  vostok::fs_new::path_string_impl::assignf(v19, v16, (vostok::buffer_string *)"dips: %d", v33);
  vostok::render::draw_text_shadowed(5u, v12, default_font, "total", v13);
  vostok::render::draw_text_shadowed(0xC9u, v12, default_font, v27[0], v13);
  vostok::render::draw_text_shadowed(0x11Du, v12, default_font, v23[0], v13);
  vostok::render::draw_text_shadowed(0x171u, v12, default_font, v19[0], v13);
}
