void __usercall vostok::render::make_ui_vertices(
        vostok::ui::font *in_font@<edi>,
        const vostok::math::float2 *in_position@<eax>,
        vostok::render::ui::vertex *const out_vertices,
        const char *in_text,
        const vostok::math::color *in_color,
        const vostok::math::color *in_selection_color,
        unsigned int max_line_width)
{
  float v7; // xmm0_4
  vostok::ui::font_vtbl *v8; // eax
  unsigned int v9; // eax
  const vostok::math::color *v11; // ecx
  unsigned int m_value; // ebx
  int v13; // eax
  char v14; // cl
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  vostok::render::ui::vertex *v22; // esi
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  _DWORD v27[3]; // [esp+0h] [ebp-44h] BYREF
  __int64 v28; // [esp+Ch] [ebp-38h]
  float v29; // [esp+14h] [ebp-30h]
  float v30; // [esp+18h] [ebp-2Ch]
  float v31; // [esp+1Ch] [ebp-28h]
  float v32; // [esp+20h] [ebp-24h]
  int v33; // [esp+24h] [ebp-20h]
  int v34; // [esp+28h] [ebp-1Ch] BYREF
  int v35; // [esp+2Ch] [ebp-18h] BYREF
  unsigned int v36; // [esp+30h] [ebp-14h]
  float v37; // [esp+34h] [ebp-10h]
  const char *v38; // [esp+38h] [ebp-Ch]
  unsigned int v39; // [esp+3Ch] [ebp-8h]
  char v40; // [esp+43h] [ebp-1h] BYREF

  v29 = 0.0;
  v30 = 0.0;
  v28 = (__int64)*in_position;
  v36 = strlen(in_text);
  v7 = *in_font->get_height(in_font);
  v8 = in_font->__vftable;
  v37 = v7;
  v31 = v8->get_height_ts(in_font);
  v35 = 0;
  v9 = 0;
  v34 = 0;
  v39 = 0;
  if ( v36 )
  {
    v32 = *((float *)&v28 + 1) + v37;
    while ( 1 )
    {
      v11 = in_selection_color;
      if ( v9 >= max_line_width )
        v11 = in_color;
      m_value = v11->m_value;
      v38 = &in_text[v9];
      v40 = in_text[v9];
      in_font->get_char_tc_ts(in_font, (vostok::math::float3 *)v27, (const unsigned __int8 *)&v40);
      v40 = *v38;
      v13 = in_font->get_char_tc(in_font, (const unsigned __int8 *)&v40);
      v14 = *v38;
      v33 = v13;
      if ( v14 == 10 || v14 == 2573 )
      {
        in_font->parse_word(in_font, v38, (float *)&v34, (const char **)&v35);
        v13 = v33;
        v29 = 0.0;
        v30 = v30 + v37;
      }
      v15 = s_bm_current_air_resistance;
      v16 = *(float *)&v27[1];
      v17 = *(float *)&v28 + v29;
      v18 = v32 + v30;
      v19 = *(float *)v27;
      out_vertices->m_position.x = *(float *)&v28 + v29;
      out_vertices->m_position.y = v18;
      out_vertices->m_position.z = 0.0;
      out_vertices->m_position.w = v15;
      v20 = *((float *)&v28 + 1) + v30;
      out_vertices->m_uv.x = v19;
      v21 = v16 + v31;
      out_vertices->m_uv.y = v16 + v31;
      out_vertices->m_color = m_value;
      v22 = out_vertices + 1;
      v22->m_position.x = v17;
      v22->m_position.z = 0.0;
      v22->m_position.y = v20;
      v22->m_position.w = v15;
      v22->m_uv.x = v19;
      v22->m_uv.y = v16;
      v22->m_color = m_value;
      ++v22;
      v22->m_position.x = (float)(*(float *)(v13 + 8) + *(float *)&v28) + v29;
      v23 = *(float *)&v27[2];
      v22->m_position.y = v18;
      v22->m_position.z = 0.0;
      v22->m_position.w = v15;
      v22->m_uv.y = v21;
      v24 = v23 + v19;
      v22->m_uv.x = v24;
      v22->m_color = m_value;
      v25 = (float)(*(float *)(v13 + 8) + *(float *)&v28) + v29;
      ++v22;
      v22->m_position.z = 0.0;
      v22->m_position.x = v25;
      v22->m_position.y = v20;
      v22->m_position.w = v15;
      v22->m_uv.x = v24;
      v22->m_uv.y = v16;
      v22->m_color = m_value;
      v26 = *(float *)(v13 + 8) + v29;
      out_vertices = v22 + 1;
      ++v39;
      v29 = v26;
      if ( v39 >= v36 )
        break;
      v9 = v39;
    }
  }
}


void __usercall vostok::render::make_ui_vertices(
        vostok::ui::font *in_font@<edi>,
        const vostok::math::float2 *in_position@<eax>,
        int a3@<esi>,
        vostok::render::ui::vertex *const out_vertices,
        const char *in_text,
        const vostok::math::color *in_color,
        const vostok::math::color *in_selection_color,
        unsigned int max_line_width,
        bool is_multiline,
        unsigned int start_selection_index,
        unsigned int end_selection_index)
{
  vostok::ui::font_vtbl *v11; // eax
  float v12; // xmm0_4
  vostok::ui::font_vtbl *v13; // eax
  unsigned int v14; // eax
  bool v16; // cf
  const vostok::math::color *v17; // eax
  unsigned int m_value; // ebx
  char v19; // al
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  int v26; // ecx
  float v27; // xmm4_4
  vostok::render::ui::vertex *v28; // esi
  float v29; // xmm2_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  _DWORD v33[3]; // [esp+0h] [ebp-48h] BYREF
  __int64 v34; // [esp+Ch] [ebp-3Ch]
  float v35; // [esp+14h] [ebp-34h]
  float v36; // [esp+18h] [ebp-30h]
  int v37; // [esp+20h] [ebp-28h]
  float v38; // [esp+24h] [ebp-24h]
  float v39; // [esp+28h] [ebp-20h]
  unsigned int v40; // [esp+2Ch] [ebp-1Ch]
  float v41; // [esp+30h] [ebp-18h]
  float v42; // [esp+34h] [ebp-14h] BYREF
  const char *v43; // [esp+38h] [ebp-10h] BYREF
  unsigned int v44; // [esp+3Ch] [ebp-Ch]
  const char *v45; // [esp+40h] [ebp-8h]
  char v46; // [esp+47h] [ebp-1h] BYREF

  v35 = 0.0;
  v36 = 0.0;
  v34 = (__int64)*in_position;
  v40 = strlen(in_text);
  v11 = in_font->__vftable;
  v45 = in_text;
  v12 = *(float *)((int (__thiscall *)(vostok::ui::font *, int))v11->get_height)(in_font, a3);
  v13 = in_font->__vftable;
  v41 = v12;
  v38 = v13->get_height_ts(in_font);
  v43 = 0;
  v42 = 0.0;
  if ( is_multiline )
    in_font->parse_word(in_font, in_text, &v42, &v43);
  v14 = 0;
  v44 = 0;
  if ( v40 )
  {
    v39 = *((float *)&v34 + 1) + v41;
    while ( 1 )
    {
      if ( v14 < start_selection_index || (v16 = v14 < end_selection_index, v17 = in_selection_color, !v16) )
        v17 = in_color;
      m_value = v17->m_value;
      v46 = *v45;
      in_font->get_char_tc_ts(in_font, (vostok::math::float3 *)v33, (const unsigned __int8 *)&v46);
      v46 = *v45;
      v37 = in_font->get_char_tc(in_font, (const unsigned __int8 *)&v46);
      v19 = in_text[v44];
      if ( v19 == 10 || v19 == 2573 )
      {
        in_font->parse_word(in_font, v45, &v42, &v43);
        v35 = 0.0;
        v36 = v36 + v41;
      }
      if ( is_multiline && v45 == v43 )
      {
        in_font->parse_word(in_font, v45, &v42, &v43);
        if ( v35 + v42 > (double)max_line_width )
        {
          v35 = 0.0;
          v36 = v36 + v41;
        }
      }
      v20 = s_bm_current_air_resistance;
      v21 = *(float *)&v33[1];
      v22 = *(float *)&v34 + v35;
      v23 = v39 + v36;
      v24 = *(float *)v33;
      out_vertices->m_position.x = *(float *)&v34 + v35;
      out_vertices->m_position.y = v23;
      out_vertices->m_position.z = 0.0;
      out_vertices->m_position.w = v20;
      v25 = *((float *)&v34 + 1) + v36;
      v26 = v37;
      out_vertices->m_uv.x = v24;
      v27 = v21 + v38;
      out_vertices->m_uv.y = v21 + v38;
      out_vertices->m_color = m_value;
      v28 = out_vertices + 1;
      v28->m_position.x = v22;
      v28->m_position.z = 0.0;
      v28->m_position.y = v25;
      v28->m_position.w = v20;
      v28->m_uv.x = v24;
      v28->m_uv.y = v21;
      v28->m_color = m_value;
      ++v28;
      v28->m_position.x = (float)(*(float *)(v26 + 8) + *(float *)&v34) + v35;
      v29 = *(float *)&v33[2];
      v28->m_position.y = v23;
      v28->m_position.z = 0.0;
      v28->m_position.w = v20;
      v28->m_uv.y = v27;
      v30 = v29 + v24;
      v28->m_uv.x = v30;
      v28->m_color = m_value;
      v31 = (float)(*(float *)(v26 + 8) + *(float *)&v34) + v35;
      ++v28;
      v28->m_position.z = 0.0;
      v28->m_position.x = v31;
      v28->m_position.y = v25;
      v28->m_position.w = v20;
      v28->m_uv.x = v30;
      v28->m_uv.y = v21;
      v28->m_color = m_value;
      v32 = *(float *)(v26 + 8) + v35;
      out_vertices = v28 + 1;
      ++v44;
      ++v45;
      v35 = v32;
      if ( v44 >= v40 )
        break;
      v14 = v44;
    }
  }
}
