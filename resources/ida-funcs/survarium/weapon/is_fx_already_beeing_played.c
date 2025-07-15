char __userpurge survarium::weapon::is_fx_already_beeing_played@<al>(
        survarium::weapon *this@<ecx>,
        int a2@<eax>,
        const survarium::fx_history_item *item)
{
  int v4; // esi
  survarium::fx_history_item *v6; // eax
  int v7; // eax
  unsigned int v8; // ecx
  vostok::circular_buffer<survarium::fx_history_item,10>::iterator v9; // [esp-14h] [ebp-30h]
  vostok::circular_buffer<survarium::fx_history_item,10>::iterator v10; // [esp-Ch] [ebp-28h]
  vostok::circular_buffer<survarium::fx_history_item,10>::iterator result; // [esp+10h] [ebp-Ch] BYREF

  v4 = a2 + 1508;
  v10.m_container = (vostok::circular_buffer<survarium::fx_history_item,10> *)(a2 + 1508);
  v10.m_index = *(_DWORD *)(a2 + 1596);
  v9.m_container = (vostok::circular_buffer<survarium::fx_history_item,10> *)(a2 + 1508);
  v9.m_index = *(_DWORD *)(a2 + 1600);
  stlp_std::priv::__find<vostok::circular_buffer<survarium::fx_history_item,10>::iterator,survarium::fx_history_item>(
    &result,
    v9,
    v10,
    item);
  if ( result.m_index != *(_DWORD *)(a2 + 1596) )
    return 1;
  v6 = (survarium::fx_history_item *)(v4 + 8 * *(_DWORD *)(v4 + 88));
  if ( v6 )
    *v6 = *item;
  v7 = *(_DWORD *)(v4 + 92);
  v8 = (*(_DWORD *)(v4 + 88) + 1) % 0xBu;
  if ( v8 == v7 )
    *(_DWORD *)(v4 + 92) = (v7 + 1) % 0xBu;
  *(_DWORD *)(v4 + 88) = v8;
  return 0;
}
