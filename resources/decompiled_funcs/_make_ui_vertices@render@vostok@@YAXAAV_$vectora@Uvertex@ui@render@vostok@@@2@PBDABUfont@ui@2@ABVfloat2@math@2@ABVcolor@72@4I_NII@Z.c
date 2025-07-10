void __usercall vostok::render::make_ui_vertices(
        const vostok::math::float2 *in_position@<eax>,
        vostok::vectora<vostok::render::ui::vertex> *out_vertices,
        const char *in_text,
        const vostok::ui::font *in_font,
        const vostok::math::color *in_color,
        const vostok::math::color *in_selection_color,
        unsigned int max_line_width,
        bool is_multiline,
        unsigned int start_selection_index,
        unsigned int end_selection_index)
{
  const vostok::ui::font *v10; // ebx
  const char *v11; // ebp
  unsigned int v12; // esi
  const float *(__thiscall *get_height)(vostok::ui::font *); // edx
  float *v14; // eax
  float (__thiscall *get_height_ts)(vostok::ui::font *); // edx
  unsigned int v16; // eax
  int v17; // esi
  unsigned int v18; // edi
  vostok::math::float3 *(__thiscall *get_char_tc_ts)(vostok::ui::font *, vostok::math::float3 *, const unsigned __int8 *); // edx
  const vostok::math::float3 *(__thiscall *get_char_tc)(vostok::ui::font *, const unsigned __int8 *); // edx
  int v21; // ebp
  char v22; // al
  float x; // xmm2_4
  float v24; // xmm5_4
  float y; // xmm4_4
  vostok::render::ui::vertex *M_start; // eax
  float v27; // xmm6_4
  float v28; // xmm4_4
  const vostok::math::float4x4 *v29; // xmm7_4
  float v30; // xmm1_4
  float *v31; // eax
  float v32; // xmm4_4
  float v33; // xmm5_4
  vostok::render::ui::vertex *v34; // eax
  int v35; // esi
  float v36; // xmm0_4
  float v37; // xmm7_4
  float v38; // xmm4_4
  float v39; // xmm5_4
  float *v40; // eax
  const vostok::math::float4x4 *v41; // xmm7_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  float v44; // xmm4_4
  float *v45; // eax
  const char *v46; // [esp+24h] [ebp-40h]
  const char *next_word; // [esp+28h] [ebp-3Ch] BYREF
  float curr_word_len; // [esp+2Ch] [ebp-38h] BYREF
  unsigned int i; // [esp+30h] [ebp-34h]
  float height; // [esp+34h] [ebp-30h]
  float height_ts; // [esp+38h] [ebp-2Ch]
  float v52; // [esp+3Ch] [ebp-28h]
  unsigned int symb_count; // [esp+40h] [ebp-24h]
  vostok::math::float2 pos_rt; // [esp+48h] [ebp-1Ch]
  vostok::math::float2 pos; // [esp+50h] [ebp-14h]
  vostok::math::float3 uv; // [esp+58h] [ebp-Ch] BYREF

  v10 = in_font;
  v11 = in_text;
  pos_rt = 0;
  pos = *in_position;
  v12 = strlen(in_text);
  get_height = in_font->get_height;
  symb_count = v12;
  v46 = in_text;
  v14 = (float *)get_height(in_font);
  get_height_ts = v10->get_height_ts;
  height = *v14;
  height_ts = get_height_ts(v10);
  curr_word_len = 0.0;
  next_word = 0;
  if ( is_multiline )
    v10->parse_word(v10, in_text, &curr_word_len, &next_word);
  v16 = 0;
  i = 0;
  if ( v12 )
  {
    v52 = pos.y + height;
    v17 = 0;
    while ( 1 )
    {
      v18 = v16 < start_selection_index || v16 >= end_selection_index ? in_color->m_value : in_selection_color->m_value;
      get_char_tc_ts = v10->get_char_tc_ts;
      LOBYTE(in_font) = *v11;
      get_char_tc_ts(v10, &uv, (const unsigned __int8 *)&in_font);
      get_char_tc = v10->get_char_tc;
      LOBYTE(in_font) = *v11;
      v21 = (int)get_char_tc(v10, (const unsigned __int8 *)&in_font);
      v22 = in_text[i];
      if ( v22 == 10 || v22 == 2573 )
      {
        v10->parse_word(v10, v46, &curr_word_len, &next_word);
        x = 0.0;
        pos_rt.x = 0.0;
        pos_rt.y = pos_rt.y + height;
      }
      else
      {
        x = pos_rt.x;
      }
      if ( is_multiline && v46 == next_word )
      {
        v10->parse_word(v10, v46, &curr_word_len, &next_word);
        if ( pos_rt.x + curr_word_len <= (double)max_line_width )
        {
          x = pos_rt.x;
        }
        else
        {
          x = 0.0;
          pos_rt.y = pos_rt.y + height;
        }
      }
      v24 = uv.x;
      y = uv.y;
      M_start = out_vertices->_M_impl._M_start;
      *(float *)((char *)&M_start->m_position.z + v17) = 0.0;
      v27 = pos.x;
      v28 = y + height_ts;
      v29 = clear_value;
      *(_DWORD *)((char *)&M_start->m_position.w + v17) = clear_value;
      v30 = v52 + pos_rt.y;
      *(float *)((char *)&M_start->m_position.y + v17) = v52 + pos_rt.y;
      v31 = (float *)((char *)&M_start->m_position.x + v17);
      *v31 = v27 + x;
      v31[5] = v24;
      v31[6] = v28;
      *((_DWORD *)v31 + 4) = v18;
      v32 = uv.x;
      v33 = uv.y;
      v34 = out_vertices->_M_impl._M_start;
      v35 = v17 + 28;
      *(float *)((char *)&v34->m_position.x + v35) = v27 + x;
      v36 = pos.y + pos_rt.y;
      *(_DWORD *)((char *)&v34->m_position.w + v35) = v29;
      *(float *)((char *)&v34->m_position.y + v35) = v36;
      *(float *)((char *)&v34->m_position.z + v35) = 0.0;
      *(float *)((char *)&v34->m_uv.y + v35) = v33;
      *(float *)((char *)&v34->m_uv.x + v35) = v32;
      *(unsigned int *)((char *)&v34->m_color + v35) = v18;
      v37 = *(float *)(v21 + 8);
      v38 = uv.z + uv.x;
      v39 = uv.y + height_ts;
      ++v46;
      v35 += 28;
      v40 = (float *)((char *)&out_vertices->_M_impl._M_start->m_position.x + v35);
      v40[1] = v30;
      v40[2] = 0.0;
      *v40 = (float)(v37 + v27) + x;
      v41 = clear_value;
      *((_DWORD *)v40 + 3) = clear_value;
      v40[6] = v39;
      v40[5] = v38;
      *((_DWORD *)v40 + 4) = v18;
      v42 = *(float *)(v21 + 8);
      v43 = uv.z + uv.x;
      v44 = uv.y;
      v35 += 28;
      v45 = (float *)((char *)&out_vertices->_M_impl._M_start->m_position.x + v35);
      v45[1] = v36;
      v45[2] = 0.0;
      *((_DWORD *)v45 + 3) = v41;
      *v45 = (float)(v42 + v27) + x;
      v45[5] = v43;
      v45[6] = v44;
      *((_DWORD *)v45 + 4) = v18;
      v17 = v35 + 28;
      pos_rt.x = *(float *)(v21 + 8) + x;
      if ( ++i >= symb_count )
        break;
      v16 = i;
      v11 = v46;
    }
  }
}
