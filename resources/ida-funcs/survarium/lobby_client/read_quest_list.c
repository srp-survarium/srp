char __thiscall survarium::lobby_client::read_quest_list(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        int __formal)
{
  unsigned __int8 *m_pointer; // eax
  stlp_std::priv::_Impl_vector<survarium::quest_instance,vostok::vectora_allocator<survarium::quest_instance> > *v4; // ebx
  unsigned int *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::quest_instance,vostok::vectora_allocator<survarium::quest_instance> > *v6; // ecx
  survarium::quest_instance *M_start; // edi
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // esi
  const survarium::quest_instance *v11; // edi
  survarium::lobby_menu *v12; // ecx
  survarium::flash_value *i; // esi
  bool v15; // [esp+0h] [ebp-28h]
  survarium::quest_instance __x; // [esp+10h] [ebp-18h] BYREF
  unsigned int __n; // [esp+24h] [ebp-4h]

  m_pointer = (unsigned __int8 *)reader[1096].m_pointer;
  v4 = (stlp_std::priv::_Impl_vector<survarium::quest_instance,vostok::vectora_allocator<survarium::quest_instance> > *)&reader[1096];
  if ( reader[1096].m_buffer != m_pointer )
    reader[1096].m_pointer = stlp_std::priv::__copy_trivial(
                               m_pointer,
                               m_pointer,
                               (unsigned __int8 *)reader[1096].m_buffer);
  v5 = *(unsigned int **)(__formal + 4);
  __n = *v5;
  *(_DWORD *)(__formal + 4) = v5 + 1;
  v6 = (stlp_std::priv::_Impl_vector<survarium::quest_instance,vostok::vectora_allocator<survarium::quest_instance> > *)reader[1096].m_pointer;
  memset(&__x, 0, sizeof(__x));
  M_start = v4->_M_start;
  v8 = ((char *)v6 - (char *)v4->_M_start) / 20;
  v9 = __n;
  if ( __n >= v8 )
  {
    __n -= v8;
    if ( v9 != v8 )
    {
      if ( (reader[1097].m_buffer - (const unsigned __int8 *)v6) / 20 < __n )
        stlp_std::priv::_Impl_vector<survarium::quest_instance,vostok::vectora_allocator<survarium::quest_instance>>::_M_insert_overflow(
          v6,
          (int)v4,
          (survarium::quest_instance *)v6,
          (const stlp_std::__true_type *)&__x,
          __n,
          v15);
      else
        stlp_std::priv::_Impl_vector<survarium::quest_instance,vostok::vectora_allocator<survarium::quest_instance>>::_M_fill_insert_aux(
          v4,
          (survarium::quest_instance *)v6,
          __n,
          &__x,
          (const stlp_std::__false_type *)&__formal + 3);
    }
  }
  else if ( &M_start[__n] != (survarium::quest_instance *)v6 )
  {
    reader[1096].m_pointer = stlp_std::priv::__copy_trivial(
                               (unsigned __int8 *)v6,
                               (unsigned __int8 *)v6,
                               (unsigned __int8 *)&M_start[__n]);
  }
  v10 = 20 * v9;
  memcpy((unsigned __int8 *)v4->_M_start, *(unsigned __int8 **)(__formal + 4), v10);
  *(_DWORD *)(__formal + 4) += v10;
  v11 = (const survarium::quest_instance *)*((_DWORD *)reader[5].m_pointer + 3460);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v11[80].id + 264) + 4),
    "root.clear_quests",
    0,
    0,
    0);
  for ( i = (survarium::flash_value *)v4->_M_start;
        i != (survarium::flash_value *)reader[1096].m_pointer;
        i = (survarium::flash_value *)((char *)i + 20) )
  {
    survarium::lobby_menu::add_quest(v12, v11, i);
  }
  return 1;
}
