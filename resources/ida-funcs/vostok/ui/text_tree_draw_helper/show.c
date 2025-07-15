void __thiscall vostok::ui::text_tree_draw_helper::show(
        vostok::ui::text_tree_draw_helper *this,
        vostok::strings::text_tree_item *itm,
        vostok::vectora<float> *cols,
        unsigned int indent,
        unsigned int cur_indent,
        char separator)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  const vostok::math::float2 *v9; // eax
  vostok::math::float2 v10; // [esp-10h] [ebp-154h] BYREF
  unsigned __int64 v11; // [esp-8h] [ebp-14Ch] BYREF
  float *p_offset; // [esp+0h] [ebp-144h]
  float *v13; // [esp+4h] [ebp-140h]
  __int64 v14; // [esp+8h] [ebp-13Ch]
  vostok::ui::text_tree_draw_helper *thisa; // [esp+10h] [ebp-134h]
  bool m_is_page_breaker; // [esp+17h] [ebp-12Dh]
  float *v18; // [esp+18h] [ebp-12Ch]
  float *v19; // [esp+1Ch] [ebp-128h]
  float *M_finish; // [esp+20h] [ebp-124h]
  vostok::math::float2 *v21; // [esp+28h] [ebp-11Ch]
  unsigned __int64 *v22; // [esp+2Ch] [ebp-118h]
  float v23; // [esp+30h] [ebp-114h]
  char *value; // [esp+34h] [ebp-110h]
  const vostok::ui::font *v25; // [esp+38h] [ebp-10Ch]
  char v26; // [esp+3Fh] [ebp-105h] BYREF
  float v27; // [esp+40h] [ebp-104h]
  char *v28; // [esp+44h] [ebp-100h]
  float v29; // [esp+48h] [ebp-FCh]
  float v30; // [esp+4Ch] [ebp-F8h]
  char *text; // [esp+54h] [ebp-F0h]
  vostok::math::float2 *v32; // [esp+58h] [ebp-ECh]
  unsigned __int64 *v33; // [esp+5Ch] [ebp-E8h]
  float v34; // [esp+60h] [ebp-E4h]
  const vostok::ui::font *v35; // [esp+64h] [ebp-E0h]
  char v36; // [esp+6Bh] [ebp-D9h] BYREF
  float v37; // [esp+6Ch] [ebp-D8h]
  char *v38; // [esp+70h] [ebp-D4h]
  char *m_begin; // [esp+74h] [ebp-D0h]
  float y; // [esp+78h] [ebp-CCh]
  float v41; // [esp+7Ch] [ebp-C8h]
  int v42; // [esp+80h] [ebp-C4h]
  unsigned int max_count; // [esp+84h] [ebp-C0h] BYREF
  float *M_start; // [esp+88h] [ebp-BCh]
  vostok::math::float2 *v45; // [esp+90h] [ebp-B4h]
  unsigned __int64 *v46; // [esp+94h] [ebp-B0h]
  float *p_m_page_width; // [esp+98h] [ebp-ACh]
  float *v48; // [esp+9Ch] [ebp-A8h]
  float row_height; // [esp+A0h] [ebp-A4h]
  const vostok::ui::font *m_font; // [esp+A4h] [ebp-A0h]
  char v51; // [esp+ABh] [ebp-99h] BYREF
  float v52; // [esp+ACh] [ebp-98h]
  const char *v53; // [esp+B0h] [ebp-94h]
  vostok::math::float2 v54; // [esp+B4h] [ebp-90h]
  float v55; // [esp+C4h] [ebp-80h]
  float v56; // [esp+C8h] [ebp-7Ch]
  float v57; // [esp+CCh] [ebp-78h]
  float v58; // [esp+D0h] [ebp-74h]
  float v59; // [esp+E4h] [ebp-60h] BYREF
  unsigned int new_indent; // [esp+E8h] [ebp-5Ch]
  vostok::strings::text_tree_item *child; // [esp+ECh] [ebp-58h]
  vostok::math::float2 v62; // [esp+F0h] [ebp-54h]
  vostok::fixed_string<8> buffer; // [esp+F8h] [ebp-4Ch] BYREF
  float v64; // [esp+10Ch] [ebp-38h]
  float v65; // [esp+110h] [ebp-34h]
  float v66; // [esp+114h] [ebp-30h]
  vostok::strings::text_tree_column_item *column; // [esp+118h] [ebp-2Ch]
  vostok::math::float2 pos; // [esp+11Ch] [ebp-28h]
  const vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *column_items; // [esp+124h] [ebp-20h]
  vostok::math::float2 sz; // [esp+128h] [ebp-1Ch]
  float *c; // [esp+130h] [ebp-14h]
  float string_size; // [esp+134h] [ebp-10h]
  float offset; // [esp+138h] [ebp-Ch] BYREF
  const char *name; // [esp+13Ch] [ebp-8h]
  const vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *sub_items; // [esp+140h] [ebp-4h]

  thisa = this;
  v14 = cur_indent;
  offset = (double)cur_indent * this->m_space_width;
  name = itm->m_column_value;
  if ( name )
  {
    ++thisa->m_cur_row;
    v54.x = thisa->m_params.start_pos.x + offset;
    v54.y = thisa->m_params.start_pos.y;
    pos = v54;
    m_font = thisa->m_font;
    v53 = name;
    v52 = *(float *)&FLOAT_0_0;
    while ( *v53 )
    {
      v51 = *v53;
      v6 = m_font->get_char_tc(m_font, (const unsigned __int8 *)&v51);
      v52 = v52 + *(float *)(v6 + 8);
      ++v53;
    }
    string_size = v52;
    row_height = thisa->m_params.row_height;
    sz = (vostok::math::float2)__PAIR64__(LODWORD(row_height), LODWORD(v52));
    v59 = v52 + offset;
    p_m_page_width = &thisa->m_page_width;
    v13 = thisa->m_page_width <= (float)(v52 + offset) ? &v59 : p_m_page_width;
    v48 = v13;
    thisa->m_page_width = *v13;
    v46 = &v11;
    v45 = &v10;
    vostok::ui::text_tree_draw_helper::create_window(thisa, name, pos, sz);
    M_start = cols->_M_impl._M_start;
    c = M_start;
    column_items = &itm->m_column_items;
    if ( itm->m_column_items.m_first )
    {
      offset = *c++;
      for ( column = column_items->m_first; column; column = column->next )
      {
        max_count = 8;
        vostok::buffer_string::buffer_string(&buffer, buffer.m_buffer, &max_count);
        v42 = 8;
        buffer.m_buffer[0] = 0;
        vostok::buffer_string::operator+=(&buffer, (const char *)&stru_95AF78);
        vostok::buffer_string::append(&buffer, separator);
        vostok::buffer_string::operator+=(&buffer, (const char *)&stru_95AF78);
        y = thisa->m_params.start_pos.y;
        v41 = thisa->m_params.start_pos.x + offset;
        v62 = (vostok::math::float2)__PAIR64__(LODWORD(y), LODWORD(v41));
        m_begin = buffer.m_begin;
        v35 = thisa->m_font;
        v38 = buffer.m_begin;
        v37 = *(float *)&FLOAT_0_0;
        while ( *v38 )
        {
          v36 = *v38;
          v7 = v35->get_char_tc(v35, (const unsigned __int8 *)&v36);
          v37 = v37 + *(float *)(v7 + 8);
          ++v38;
        }
        v66 = v37;
        v34 = thisa->m_params.row_height;
        v64 = v37;
        v65 = v34;
        v33 = &v11;
        v32 = &v10;
        text = buffer.m_begin;
        vostok::ui::text_tree_draw_helper::create_window(
          thisa,
          buffer.m_begin,
          v62,
          (vostok::math::float2)__PAIR64__(LODWORD(v34), LODWORD(v37)));
        offset = offset + v66;
        v29 = thisa->m_params.start_pos.y;
        v30 = thisa->m_params.start_pos.x + offset;
        v57 = v30;
        v58 = v29;
        v62 = (vostok::math::float2)__PAIR64__(LODWORD(v29), LODWORD(v30));
        value = column->value;
        v25 = thisa->m_font;
        v28 = value;
        v27 = *(float *)&FLOAT_0_0;
        while ( *v28 )
        {
          v26 = *v28;
          v8 = v25->get_char_tc(v25, (const unsigned __int8 *)&v26);
          v27 = v27 + *(float *)(v8 + 8);
          ++v28;
        }
        v66 = v27;
        v23 = thisa->m_params.row_height;
        v55 = v27;
        v56 = v23;
        v64 = v27;
        v65 = v23;
        v22 = &v11;
        v11 = __PAIR64__(LODWORD(v23), LODWORD(v27));
        v21 = &v10;
        v10 = v62;
        vostok::ui::text_tree_draw_helper::create_window(
          thisa,
          column->value,
          v62,
          (vostok::math::float2)__PAIR64__(LODWORD(v23), LODWORD(v27)));
        M_finish = cols->_M_impl._M_finish;
        if ( c != M_finish )
          offset = offset + *c;
        ++c;
      }
      v18 = &thisa->m_page_width;
      if ( thisa->m_page_width <= offset )
        p_offset = &offset;
      else
        p_offset = v18;
      v19 = p_offset;
      thisa->m_page_width = *p_offset;
    }
  }
  thisa->m_params.start_pos.y = thisa->m_params.start_pos.y + thisa->m_params.row_height;
  if ( thisa->m_params.is_multipaged )
  {
    v9 = thisa->m_window->get_size(thisa->m_window);
    if ( thisa->m_params.start_pos.y >= v9->y || (m_is_page_breaker = itm->m_is_page_breaker) )
    {
      thisa->m_params.start_pos.x = (float)(thisa->m_page_width + thisa->m_params.space_between_pages)
                                  + thisa->m_params.start_pos.x;
      thisa->m_params.start_pos.y = *(float *)&FLOAT_0_0;
      thisa->m_page_width = *(float *)&FLOAT_0_0;
    }
  }
  sub_items = &itm->m_sub_items;
  for ( child = itm->m_sub_items.m_first; child; child = child->m_next_brother )
  {
    if ( child->m_is_visible )
    {
      new_indent = cur_indent + (name != 0 ? indent : 0);
      vostok::ui::text_tree_draw_helper::show(thisa, child, cols, indent, new_indent, separator);
    }
  }
}
