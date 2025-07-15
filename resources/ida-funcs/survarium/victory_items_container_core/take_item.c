void __usercall survarium::victory_items_container_core::take_item(
        survarium::victory_items_container_core *this@<eax>,
        survarium::victory_item_core *item@<edx>)
{
  void **M_finish; // edi
  vostok::vectora<survarium::victory_item_core *> *p_m_victory_items; // esi
  void **M_start; // eax
  int i; // ecx

  M_finish = this->m_victory_items._M_impl._M_finish;
  p_m_victory_items = &this->m_victory_items;
  M_start = this->m_victory_items._M_impl._M_start;
  for ( i = ((char *)M_finish - (char *)M_start) >> 4; i > 0; --i )
  {
    if ( *M_start == (void *)item )
      goto LABEL_17;
    if ( *++M_start == (void *)item )
      goto LABEL_17;
    if ( *++M_start == (void *)item )
      goto LABEL_17;
    if ( *++M_start == (void *)item )
      goto LABEL_17;
    ++M_start;
  }
  if ( M_finish - M_start == 1 )
  {
LABEL_15:
    if ( *M_start != (void *)item )
      goto LABEL_16;
    goto LABEL_17;
  }
  if ( M_finish - M_start == 2 )
  {
LABEL_13:
    if ( *M_start == (void *)item )
      goto LABEL_17;
    ++M_start;
    goto LABEL_15;
  }
  if ( M_finish - M_start != 3 )
  {
LABEL_16:
    M_start = M_finish;
    goto LABEL_17;
  }
  if ( *M_start != (void *)item )
  {
    ++M_start;
    goto LABEL_13;
  }
LABEL_17:
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(&p_m_victory_items->_M_impl, M_start);
}
