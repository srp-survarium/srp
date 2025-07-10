void __thiscall vostok::ui::text_tree_draw_helper::prepare(
        vostok::ui::text_tree_draw_helper *this,
        vostok::strings::text_tree_item *itm,
        vostok::vectora<float> *cols,
        unsigned int indent,
        unsigned int cur_indent,
        char separator)
{
  int v6; // eax
  int v7; // eax
  float *v8; // [esp+0h] [ebp-90h]
  float *p_string_size; // [esp+4h] [ebp-8Ch]
  const vostok::ui::font *v11; // [esp+1Ch] [ebp-74h]
  char v12; // [esp+23h] [ebp-6Dh] BYREF
  float v13; // [esp+24h] [ebp-6Ch]
  char *value; // [esp+28h] [ebp-68h]
  float *M_finish; // [esp+2Ch] [ebp-64h]
  float *v16; // [esp+30h] [ebp-60h]
  const vostok::ui::font *m_font; // [esp+34h] [ebp-5Ch]
  char v18; // [esp+3Bh] [ebp-55h] BYREF
  float v19; // [esp+3Ch] [ebp-54h]
  const char *v20; // [esp+40h] [ebp-50h]
  float *M_start; // [esp+44h] [ebp-4Ch]
  vostok::strings::text_tree_column_item *m_first; // [esp+58h] [ebp-38h]
  vostok::strings::text_tree_column_item *m_last; // [esp+5Ch] [ebp-34h]
  float v25; // [esp+64h] [ebp-2Ch] BYREF
  float __x; // [esp+68h] [ebp-28h] BYREF
  vostok::strings::text_tree_column_item *column; // [esp+6Ch] [ebp-24h]
  float *c; // [esp+70h] [ebp-20h]
  float string_size; // [esp+74h] [ebp-1Ch] BYREF
  unsigned int new_indent; // [esp+78h] [ebp-18h]
  vostok::strings::text_tree_item *child; // [esp+7Ch] [ebp-14h]
  const vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *column_items; // [esp+80h] [ebp-10h]
  unsigned int column_items_size; // [esp+84h] [ebp-Ch]
  const char *name; // [esp+88h] [ebp-8h]
  const vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *sub_items; // [esp+8Ch] [ebp-4h]

  name = itm->m_column_value;
  sub_items = &itm->m_sub_items;
  for ( child = itm->m_sub_items.m_first; child; child = child->m_next_brother )
  {
    if ( child->m_is_visible )
    {
      new_indent = cur_indent + (name != 0 ? indent : 0);
      vostok::ui::text_tree_draw_helper::prepare(this, child, cols, indent, new_indent, separator);
    }
  }
  column_items = &itm->m_column_items;
  m_last = itm->m_column_items.m_last;
  m_first = itm->m_column_items.m_first;
  column_items_size = m_last - m_first + 1;
  if ( cols->_M_impl._M_finish - cols->_M_impl._M_start < column_items_size )
  {
    __x = *(float *)&FLOAT_0_0;
    stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::resize(
      &cols->_M_impl,
      column_items_size,
      &__x);
  }
  if ( name && column_items->m_first )
  {
    M_start = cols->_M_impl._M_start;
    c = M_start;
    m_font = this->m_font;
    v20 = name;
    v19 = *(float *)&FLOAT_0_0;
    while ( *v20 )
    {
      v18 = *v20;
      v6 = m_font->get_char_tc(m_font, (const unsigned __int8 *)&v18);
      v19 = v19 + *(float *)(v6 + 8);
      ++v20;
    }
    string_size = (double)cur_indent * this->m_space_width + v19;
    if ( *c <= string_size )
      p_string_size = &string_size;
    else
      p_string_size = c;
    v16 = p_string_size;
    *c++ = *p_string_size;
    for ( column = column_items->m_first; column; column = column->next )
    {
      M_finish = cols->_M_impl._M_finish;
      if ( c != M_finish )
      {
        v11 = this->m_font;
        value = column->value;
        v13 = *(float *)&FLOAT_0_0;
        while ( *value )
        {
          v12 = *value;
          v7 = v11->get_char_tc(v11, (const unsigned __int8 *)&v12);
          v13 = v13 + *(float *)(v7 + 8);
          ++value;
        }
        v25 = v13;
        if ( *c <= v13 )
          v8 = &v25;
        else
          v8 = c;
        *c = *v8;
      }
      ++c;
    }
  }
}
