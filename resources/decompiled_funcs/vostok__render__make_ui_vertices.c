void __usercall vostok::render::make_ui_vertices(
        const vostok::math::float2 *in_position@<eax>,
        vostok::vectora<vostok::render::ui::vertex> *out_vertices,
        const char *in_text,
        const vostok::ui::font *in_font,
        const vostok::math::color *in_color,
        const vostok::math::color *in_selection_color,
        unsigned int max_line_width)
{
  unsigned int v7; // esi
  const vostok::ui::font *v8; // ebx
  const float *(__thiscall *get_height)(vostok::ui::font *); // edx
  float *v10; // eax
  float (__thiscall *get_height_ts)(vostok::ui::font *); // edx
  unsigned int v12; // eax
  int v13; // esi
  unsigned int v14; // edi
  char v15; // dl
  vostok::math::float3 *(__thiscall *get_char_tc_ts)(vostok::ui::font *, vostok::math::float3 *, const unsigned __int8 *); // eax
  vostok::ui::font_vtbl *v17; // eax
  int v18; // ebx
  float x; // xmm4_4
  float v20; // xmm3_4
  float y; // xmm2_4
  vostok::render::ui::vertex *M_start; // eax
  float v23; // xmm6_4
  float v24; // xmm2_4
  const vostok::math::float4x4 *v25; // xmm7_4
  float v26; // xmm1_4
  float *v27; // eax
  float v28; // xmm2_4
  float v29; // xmm3_4
  vostok::render::ui::vertex *v30; // eax
  int v31; // esi
  float v32; // xmm0_4
  float v33; // xmm7_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float *v36; // eax
  const vostok::math::float4x4 *v37; // xmm7_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float *v41; // eax
  char v42; // [esp+Fh] [ebp-3Dh] BYREF
  unsigned int i; // [esp+10h] [ebp-3Ch]
  const char *v44; // [esp+14h] [ebp-38h]
  float height; // [esp+18h] [ebp-34h]
  float height_ts; // [esp+1Ch] [ebp-30h]
  const char *next_word; // [esp+20h] [ebp-2Ch] BYREF
  float curr_word_len; // [esp+24h] [ebp-28h] BYREF
  float v49; // [esp+28h] [ebp-24h]
  unsigned int symb_count; // [esp+2Ch] [ebp-20h]
  vostok::math::float2 pos_rt; // [esp+30h] [ebp-1Ch]
  vostok::math::float2 pos; // [esp+38h] [ebp-14h]
  vostok::math::float3 uv; // [esp+40h] [ebp-Ch] BYREF

  pos_rt = 0;
  pos = *in_position;
  v7 = strlen(in_text);
  v8 = in_font;
  get_height = in_font->get_height;
  symb_count = v7;
  v10 = (float *)get_height(in_font);
  get_height_ts = in_font->get_height_ts;
  height = *v10;
  height_ts = get_height_ts(in_font);
  v12 = 0;
  curr_word_len = 0.0;
  next_word = 0;
  i = 0;
  if ( v7 )
  {
    v49 = pos.y + height;
    v13 = 0;
    while ( 1 )
    {
      v14 = v12 >= max_line_width ? in_color->m_value : in_selection_color->m_value;
      v15 = in_text[v12];
      v44 = &in_text[v12];
      get_char_tc_ts = v8->get_char_tc_ts;
      v42 = v15;
      get_char_tc_ts(v8, &uv, (const unsigned __int8 *)&v42);
      v17 = v8->__vftable;
      v42 = *v44;
      v18 = (int)v17->get_char_tc(v8, (const unsigned __int8 *)&v42);
      if ( *v44 == 10 || *v44 == 2573 )
      {
        in_font->parse_word(in_font, v44, &curr_word_len, &next_word);
        x = 0.0;
        pos_rt.y = pos_rt.y + height;
      }
      else
      {
        x = pos_rt.x;
      }
      v20 = uv.x;
      y = uv.y;
      M_start = out_vertices->_M_impl._M_start;
      *(float *)((char *)&M_start->m_position.z + v13) = 0.0;
      v23 = pos.x;
      v24 = y + height_ts;
      v25 = clear_value;
      *(_DWORD *)((char *)&M_start->m_position.w + v13) = clear_value;
      v26 = v49 + pos_rt.y;
      *(float *)((char *)&M_start->m_position.y + v13) = v49 + pos_rt.y;
      v27 = (float *)((char *)&M_start->m_position.x + v13);
      *v27 = v23 + x;
      v27[5] = v20;
      v27[6] = v24;
      *((_DWORD *)v27 + 4) = v14;
      v28 = uv.x;
      v29 = uv.y;
      v30 = out_vertices->_M_impl._M_start;
      v31 = v13 + 28;
      *(float *)((char *)&v30->m_position.x + v31) = v23 + x;
      v32 = pos.y + pos_rt.y;
      *(_DWORD *)((char *)&v30->m_position.w + v31) = v25;
      *(float *)((char *)&v30->m_position.y + v31) = v32;
      *(float *)((char *)&v30->m_position.z + v31) = 0.0;
      *(float *)((char *)&v30->m_uv.y + v31) = v29;
      *(float *)((char *)&v30->m_uv.x + v31) = v28;
      *(unsigned int *)((char *)&v30->m_color + v31) = v14;
      v33 = *(float *)(v18 + 8);
      v34 = uv.z + uv.x;
      v35 = uv.y + height_ts;
      v31 += 28;
      v36 = (float *)((char *)&out_vertices->_M_impl._M_start->m_position.x + v31);
      v36[1] = v26;
      v36[2] = 0.0;
      *v36 = (float)(v33 + v23) + x;
      v37 = clear_value;
      *((_DWORD *)v36 + 3) = clear_value;
      v36[6] = v35;
      v36[5] = v34;
      *((_DWORD *)v36 + 4) = v14;
      v38 = *(float *)(v18 + 8);
      v39 = uv.z + uv.x;
      v40 = uv.y;
      v31 += 28;
      v41 = (float *)((char *)&out_vertices->_M_impl._M_start->m_position.x + v31);
      v41[1] = v32;
      v41[2] = 0.0;
      *((_DWORD *)v41 + 3) = v37;
      *v41 = (float)(v38 + v23) + x;
      v41[5] = v39;
      v41[6] = v40;
      *((_DWORD *)v41 + 4) = v14;
      v13 = v31 + 28;
      pos_rt.x = *(float *)(v18 + 8) + x;
      if ( ++i >= symb_count )
        break;
      v12 = i;
      v8 = in_font;
    }
  }
}
