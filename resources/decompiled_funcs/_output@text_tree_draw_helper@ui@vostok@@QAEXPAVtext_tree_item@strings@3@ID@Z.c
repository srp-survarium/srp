void __thiscall vostok::ui::text_tree_draw_helper::output(
        vostok::ui::text_tree_draw_helper *this,
        vostok::strings::text_tree_item *itm,
        unsigned int indent,
        char separator)
{
  _DWORD v5[3]; // [esp+B0h] [ebp-28h] BYREF
  vostok::memory::base_allocator *m_allocator; // [esp+BCh] [ebp-1Ch]
  _DWORD *v7; // [esp+C0h] [ebp-18h]
  vostok::vectora<float> cols; // [esp+C8h] [ebp-10h] BYREF

  this->m_cur_row = 0;
  m_allocator = this->m_allocator;
  v7 = v5;
  v5[0] = m_allocator;
  v5[2] = m_allocator;
  cols._M_impl._M_start = 0;
  cols._M_impl._M_finish = 0;
  v5[1] = &cols._M_impl._M_end_of_storage;
  cols._M_impl._M_end_of_storage.m_allocator = m_allocator;
  cols._M_impl._M_end_of_storage._M_data = 0;
  vostok::ui::text_tree_draw_helper::prepare(this, itm, &cols, indent, 0, separator);
  vostok::ui::text_tree_draw_helper::show(this, itm, &cols, indent, 0, separator);
  stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::~_Impl_vector<float,vostok::vectora_allocator<float>>(&cols._M_impl);
}
