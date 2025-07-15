char __thiscall survarium::lobby_client::read_enumerate_inventory_info(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        int __formal)
{
  int v3; // ebx
  int *v4; // esi
  unsigned int v5; // edi
  stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > *m_buffer_size; // ecx
  stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > *p_m_pointer; // esi
  const unsigned __int8 *m_pointer; // edx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // edi
  survarium::inventory_item_descr __x; // [esp+Ch] [ebp-10h] BYREF

  v3 = __formal;
  v4 = *(int **)(__formal + 4);
  __formal = *v4;
  v5 = __formal;
  *(_DWORD *)(v3 + 4) = v4 + 1;
  m_buffer_size = (stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > *)reader[1059].m_buffer_size;
  p_m_pointer = (stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > *)&reader[1059].m_pointer;
  m_pointer = reader[1059].m_pointer;
  memset(&__x, 0, 14);
  v9 = ((char *)m_buffer_size - (char *)m_pointer) >> 4;
  if ( v5 >= v9 )
  {
    v10 = v5 - v9;
    if ( v5 != v9 )
    {
      if ( (reader[1060].m_pointer - (const unsigned __int8 *)m_buffer_size) >> 4 < v10 )
        stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr>>::_M_insert_overflow(
          m_buffer_size,
          (int)p_m_pointer,
          (survarium::inventory_item_descr *)m_buffer_size,
          (const stlp_std::__true_type *)&__x,
          v10,
          0);
      else
        stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr>>::_M_fill_insert_aux(
          p_m_pointer,
          (survarium::inventory_item_descr *)m_buffer_size,
          v10,
          &__x,
          (const stlp_std::__false_type *)&__formal + 3);
    }
  }
  else if ( &m_pointer[16 * v5] != (const unsigned __int8 *)m_buffer_size )
  {
    reader[1059].m_buffer_size = (const unsigned int)stlp_std::priv::__copy_trivial(
                                                       (unsigned __int8 *)m_buffer_size,
                                                       (unsigned __int8 *)m_buffer_size,
                                                       (unsigned __int8 *)&m_pointer[16 * v5]);
  }
  v11 = 16 * v5;
  if ( __formal )
  {
    memcpy((unsigned __int8 *)p_m_pointer->_M_start, *(unsigned __int8 **)(v3 + 4), v11);
    *(_DWORD *)(v3 + 4) += v11;
  }
  return 1;
}
