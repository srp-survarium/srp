void __userpurge vostok::ui::text_tree_draw_helper::prepare(
        vostok::ui::text_tree_draw_helper *this@<ecx>,
        float a2@<xmm0>,
        vostok::strings::text_tree_item *itm,
        vostok::vectora<float> *cols,
        float indent,
        unsigned int cur_indent,
        char separator)
{
  vostok::strings::text_tree_item *m_first; // esi
  char *m_column_value; // edi
  vostok::vectora<float> *v10; // esi
  float *M_finish; // edx
  float *M_start; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned __int8 *v15; // eax
  const stlp_std::__true_type *v16; // eax
  unsigned int v17; // ecx
  float *v18; // esi
  float *p_indent; // eax
  vostok::strings::text_tree_column_item *i; // ebx
  float v21; // xmm1_4
  float *v22; // eax
  unsigned int v23; // [esp+0h] [ebp-10h]
  bool v24; // [esp+4h] [ebp-Ch]
  char *v26; // [esp+18h] [ebp+8h]

  m_first = itm->m_sub_items.m_first;
  m_column_value = itm->m_column_value;
  v26 = m_column_value;
  while ( m_first )
  {
    if ( m_first->m_is_visible )
      vostok::ui::text_tree_draw_helper::prepare(
        this,
        a2,
        m_first,
        cols,
        indent,
        cur_indent + (m_column_value != 0 ? LODWORD(indent) : 0),
        separator);
    m_first = m_first->m_next_brother;
  }
  v10 = cols;
  M_finish = cols->_M_impl._M_finish;
  M_start = cols->_M_impl._M_start;
  v13 = itm->m_column_items.m_last - itm->m_column_items.m_first + 1;
  v14 = M_finish - cols->_M_impl._M_start;
  if ( v13 > v14 )
  {
    a2 = 0.0;
    indent = 0.0;
    if ( v13 >= v14 )
    {
      v16 = (const stlp_std::__true_type *)(v13 - v14);
      if ( v16 )
      {
        v17 = cols->_M_impl._M_end_of_storage._M_data - M_finish;
        if ( v17 < (unsigned int)v16 )
          stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_insert_overflow(
            (stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *)v17,
            (unsigned __int8 **)cols,
            M_finish,
            &indent,
            v16,
            v23,
            v24);
        else
          stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
            &cols->_M_impl,
            M_finish,
            (unsigned int)v16,
            &indent,
            (const stlp_std::__false_type *)&cols + 3);
      }
    }
    else
    {
      v15 = (unsigned __int8 *)&M_start[v13];
      if ( v15 != (unsigned __int8 *)M_finish )
        v10->_M_impl._M_finish = (float *)stlp_std::priv::__copy_trivial(
                                            (unsigned __int8 *)M_finish,
                                            (unsigned __int8 *)M_finish,
                                            v15);
    }
  }
  if ( v26 && itm->m_column_items.m_first )
  {
    v18 = v10->_M_impl._M_start;
    vostok::ui::calc_string_length((vostok::ui::font *)this->m_font, v26);
    indent = a2;
    p_indent = v18;
    indent = a2 + (double)cur_indent * this->m_space_width;
    if ( *v18 <= (double)indent )
      p_indent = &indent;
    *v18 = *p_indent;
    for ( i = itm->m_column_items.m_first; ; i = i->next )
    {
      ++v18;
      if ( !i )
        break;
      if ( v18 != cols->_M_impl._M_finish )
      {
        vostok::ui::calc_string_length((vostok::ui::font *)this->m_font, i->value);
        v21 = *v18;
        indent = a2;
        v22 = v18;
        if ( v21 <= a2 )
          v22 = &indent;
        *v18 = *v22;
      }
    }
  }
}
