char __thiscall survarium::lobby_client::read_players_elo_list(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // esi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  survarium::player_elo_stats *v9; // eax
  unsigned int v11; // [esp+0h] [ebp-70h]
  bool v12; // [esp+4h] [ebp-6Ch]
  _BYTE __formal[72]; // [esp+10h] [ebp-60h] BYREF
  void *v14; // [esp+58h] [ebp-18h] BYREF
  survarium::player_elo_stats *__x; // [esp+5Ch] [ebp-14h]
  vostok::memory::doug_lea_allocator *v16; // [esp+60h] [ebp-10h]
  survarium::player_elo_stats *v17; // [esp+64h] [ebp-Ch]
  int v18; // [esp+68h] [ebp-8h]
  int v19; // [esp+6Ch] [ebp-4h]
  __int16 v20; // [esp+7Ch] [ebp+Ch]
  unsigned __int8 v21; // [esp+7Fh] [ebp+Fh]

  m_pointer = a3->m_pointer;
  v5 = m_pointer + 1;
  v21 = *m_pointer;
  v6 = survarium::g_allocator;
  a3->m_pointer = v5;
  v14 = 0;
  __x = 0;
  v16 = v6;
  v17 = 0;
  if ( v21 )
  {
    v19 = v21;
    do
    {
      vostok::network_core::buffer_reader::r_string(
        (vostok::network_core::buffer_reader *)this,
        (char *)a3,
        &__formal[4]);
      v7 = a3->m_pointer;
      v18 = *(_DWORD *)v7;
      a3->m_pointer = v7 + 4;
      *(_DWORD *)__formal = v18;
      *(_WORD *)&__formal[68] = vostok::network_core::buffer_reader::r<unsigned short>(a3);
      v8 = a3->m_pointer;
      v20 = *(_WORD *)v8;
      a3->m_pointer = v8 + 2;
      *(_WORD *)&__formal[70] = v20;
      if ( __x == v17 )
      {
        stlp_std::priv::_Impl_vector<survarium::player_elo_stats,vostok::vectora_allocator<survarium::player_elo_stats>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<survarium::player_elo_stats,vostok::vectora_allocator<survarium::player_elo_stats> > *)__formal,
          (unsigned int)&v14,
          __x,
          (const stlp_std::__true_type *)__formal,
          v11,
          v12);
      }
      else
      {
        v9 = __x + 1;
        qmemcpy(__x, __formal, sizeof(survarium::player_elo_stats));
        this = 0;
        __x = v9;
      }
      --v19;
    }
    while ( v19 );
    v6 = v16;
  }
  survarium::lobby_menu::fill_players_rating_page(
    (survarium::lobby_menu *)this,
    *((vostok::vectora<survarium::player_elo_stats> **)reader[5].m_pointer + 3460),
    &v14);
  if ( v14 )
    v6->call_free(
      v6,
      v14,
      "vostok::detail::std_allocator<struct survarium::player_elo_stats>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102u);
  return 1;
}
