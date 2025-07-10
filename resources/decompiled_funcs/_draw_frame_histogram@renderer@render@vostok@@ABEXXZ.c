void __thiscall vostok::render::renderer::draw_frame_histogram(vostok::render::renderer *this, int a2)
{
  int v2; // ecx
  char v3; // bl
  unsigned int v4; // edx
  unsigned int v5; // eax
  double v6; // st7
  float v7; // xmm1_4
  int v8; // eax
  unsigned int v9; // esi
  double v10; // st7
  const vostok::math::float4x4 *v11; // xmm2_4
  double v12; // st6
  float v13; // xmm3_4
  float v14; // xmm1_4
  double v15; // st3
  float v16; // xmm3_4
  double v17; // st2
  int v18; // ecx
  int v19; // ebx
  double v20; // st1
  bool v21; // [esp+Ch] [ebp-3038h]
  bool v22; // [esp+Ch] [ebp-3038h]
  bool v23; // [esp+10h] [ebp-3034h]
  bool v24; // [esp+10h] [ebp-3034h]
  _WORD width[3092]; // [esp+1Ch] [ebp-3028h] BYREF
  vostok::math::float3 v26[512]; // [esp+1844h] [ebp-1800h] BYREF

  v2 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 540);
  if ( v2 )
  {
    v3 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 105);
    v4 = v3
       ? *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 27)
       : *(_DWORD *)(v2 + 144);
    *(_DWORD *)width = v4;
    *(float *)&width[2] = (float)v4;
    v5 = v3
       ? *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 28)
       : *(_DWORD *)(v2 + 148);
    *(_DWORD *)width = v5;
    v6 = (double)v5;
    *(float *)&width[4] = v6;
    v7 = *(float *)&width[2];
    v8 = *(_DWORD *)(a2 + 612);
    *(float *)&width[6] = 0.0099999998 * v6;
    v9 = 0;
    *(float *)&width[2] = *(float *)&width[2] * 0.001953125;
    v10 = v6 * 0.000099999997;
    if ( v8 )
    {
      v11 = clear_value;
      v12 = *(float *)&width[2];
      v13 = *(float *)&clear_value / v7;
      v14 = *(float *)&clear_value / *(float *)&width[4];
      *(float *)width = v13;
      v15 = v13;
      v16 = *(float *)&width[6];
      *(float *)&width[4] = *(float *)&clear_value / *(float *)&width[4];
      v17 = *(float *)&width[4];
      *(_DWORD *)&width[12] = 0;
      *(_DWORD *)&width[18] = 0;
      v18 = 0;
      do
      {
        *(_DWORD *)width = v9;
        v19 = *(_DWORD *)(v8 + 8);
        *(float *)&width[10] = (float)((float)((float)(*(float *)v8 * v14) * v16) * 2.0) - *(float *)&v11;
        *(float *)&width[8] = (double)v9 * v15 * v12 * 2.0 - 1.0;
        *(float *)&width[14] = *(float *)&width[8];
        *(_QWORD *)&width[v18 + 20] = *(_QWORD *)&width[8];
        v20 = (double)*(int *)(v8 + 8);
        *(_DWORD *)&width[v18 + 24] = 0;
        if ( v19 < 0 )
          v20 = v20 + 4294967300.0;
        v8 = *(_DWORD *)(v8 + 12);
        ++v9;
        v18 += 6;
        *(float *)&width[16] = v20 * v17 * v10 * 2.0 - 1.0;
        *(_QWORD *)&width[v18 + 3086] = *(_QWORD *)&width[14];
        *(_DWORD *)&width[v18 + 3090] = 0;
      }
      while ( v8 );
      if ( v9 > 1 )
      {
        *(_DWORD *)width = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(1.0), 0.0, 1.0);
        vostok::render::system_renderer::draw_screen_lines(
          (vostok::render::system_renderer *)width,
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          (const vostok::math::float3 *)&width[20],
          v9,
          (const vostok::math::color *)width,
          1,
          v21,
          v23);
        *(_DWORD *)width = vostok::math::color_rgba(0.1, COERCE_VOSTOK_MATH_(0.1), 0.69999999, 1.0);
        vostok::render::system_renderer::draw_screen_lines(
          (vostok::render::system_renderer *)width,
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v26,
          v9,
          (const vostok::math::color *)width,
          1,
          v22,
          v24);
      }
    }
  }
}
