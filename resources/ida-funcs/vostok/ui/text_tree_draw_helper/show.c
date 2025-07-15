void __userpurge vostok::ui::text_tree_draw_helper::show(
        vostok::ui::text_tree_draw_helper *this@<ecx>,
        vostok::ui::text_tree_draw_helper *a2@<edi>,
        vostok::strings::text_tree_item *itm,
        vostok::vectora<float> *cols,
        unsigned int indent,
        unsigned int cur_indent,
        char separator)
{
  vostok::strings::text_tree_item *v8; // ebx
  double v9; // st7
  char *m_column_value; // eax
  float v11; // xmm0_4
  vostok::ui::font *m_font; // edi
  float v13; // xmm0_4
  float row_height; // xmm2_4
  float m_page_width; // xmm3_4
  float *p_m_page_width; // ecx
  float *M_start; // ecx
  vostok::strings::text_tree_column_item *m_first; // eax
  vostok::strings::text_tree_column_item *v19; // ebx
  vostok::ui::font *v20; // edi
  unsigned int v21; // xmm0_4
  vostok::ui::text_tree_draw_helper *v22; // ecx
  char *value; // eax
  vostok::ui::font *v24; // edi
  unsigned int v25; // xmm0_4
  vostok::ui::text_tree_draw_helper *v26; // ecx
  float *v27; // ecx
  bool v28; // zf
  vostok::strings::text_tree_item *i; // ebx
  vostok::math::float2 v30; // [esp-18h] [ebp-54h]
  vostok::buffer_string v31; // [esp+0h] [ebp-3Ch] BYREF
  _BYTE v32[8]; // [esp+Ch] [ebp-30h] BYREF
  float v33; // [esp+14h] [ebp-28h] BYREF
  float v34; // [esp+1Ch] [ebp-20h]
  float v35; // [esp+24h] [ebp-18h]
  float y; // [esp+28h] [ebp-14h]
  float v37; // [esp+2Ch] [ebp-10h]
  char *v38; // [esp+30h] [ebp-Ch]
  float v39; // [esp+34h] [ebp-8h] BYREF
  float v40; // [esp+38h] [ebp-4h] BYREF

  v8 = itm;
  v9 = (double)cur_indent * this->m_space_width;
  m_column_value = itm->m_column_value;
  v38 = m_column_value;
  v40 = v9;
  if ( m_column_value )
  {
    v11 = this->m_params.start_pos.x + v40;
    m_font = (vostok::ui::font *)this->m_font;
    ++this->m_cur_row;
    v37 = v11;
    y = this->m_params.start_pos.y;
    v13 = y;
    vostok::ui::calc_string_length(m_font, m_column_value);
    row_height = this->m_params.row_height;
    m_page_width = this->m_page_width;
    v39 = y + v40;
    p_m_page_width = &this->m_page_width;
    if ( m_page_width <= (float)(y + v40) )
      p_m_page_width = &v39;
    this->m_page_width = *p_m_page_width;
    a2 = this;
    vostok::ui::text_tree_draw_helper::create_window(
      (vostok::ui::text_tree_draw_helper *)p_m_page_width,
      this,
      v38,
      (vostok::math::float2)__PAIR64__(LODWORD(y), LODWORD(v37)),
      (vostok::math::float2)__PAIR64__(LODWORD(row_height), LODWORD(v13)));
    M_start = cols->_M_impl._M_start;
    m_first = itm->m_column_items.m_first;
    if ( m_first )
    {
      v40 = *M_start;
      LODWORD(v39) = M_start + 1;
      v19 = m_first;
      do
      {
        v31.m_begin = v32;
        v31.m_end = v32;
        v31.m_max_end = (char *)&v33;
        v32[0] = 0;
        vostok::buffer_string::operator+=(&v31, " ");
        *v31.m_end++ = separator;
        *v31.m_end = 0;
        vostok::buffer_string::operator+=(&v31, " ");
        v20 = (vostok::ui::font *)this->m_font;
        y = this->m_params.start_pos.y;
        v34 = this->m_params.start_pos.x + v40;
        *(float *)&v21 = v34;
        vostok::ui::calc_string_length(v20, v31.m_begin);
        v30 = (vostok::math::float2)__PAIR64__(LODWORD(this->m_params.row_height), v21);
        LODWORD(v37) = v21;
        vostok::ui::text_tree_draw_helper::create_window(
          v22,
          this,
          v31.m_begin,
          (vostok::math::float2)__PAIR64__(LODWORD(y), LODWORD(v34)),
          v30);
        value = v19->value;
        v24 = (vostok::ui::font *)this->m_font;
        v40 = v37 + v40;
        v35 = this->m_params.start_pos.y;
        v33 = this->m_params.start_pos.x + v40;
        *(float *)&v25 = v33;
        vostok::ui::calc_string_length(v24, value);
        a2 = this;
        vostok::ui::text_tree_draw_helper::create_window(
          v26,
          this,
          v19->value,
          (vostok::math::float2)__PAIR64__(LODWORD(v35), LODWORD(v33)),
          (vostok::math::float2)__PAIR64__(LODWORD(this->m_params.row_height), v25));
        if ( (float *)LODWORD(v39) != cols->_M_impl._M_finish )
          v40 = *(float *)LODWORD(v39) + v40;
        v19 = v19->next;
        LODWORD(v39) += 4;
      }
      while ( v19 );
      v27 = &this->m_page_width;
      if ( this->m_page_width <= v40 )
        v27 = &v40;
      v8 = itm;
      this->m_page_width = *v27;
    }
  }
  v28 = !this->m_params.is_multipaged;
  this->m_params.start_pos.y = this->m_params.row_height + this->m_params.start_pos.y;
  if ( !v28 && (this->m_params.start_pos.y >= this->m_window->get_size(this->m_window)->y || v8->m_is_page_breaker) )
  {
    this->m_params.start_pos.x = (float)(this->m_params.space_between_pages + this->m_page_width)
                               + this->m_params.start_pos.x;
    this->m_params.start_pos.y = 0.0;
    this->m_page_width = 0.0;
  }
  for ( i = v8->m_sub_items.m_first; i; i = i->m_next_brother )
  {
    if ( i->m_is_visible )
      vostok::ui::text_tree_draw_helper::show(
        this,
        a2,
        i,
        cols,
        indent,
        cur_indent + (v38 != 0 ? indent : 0),
        separator);
  }
}
