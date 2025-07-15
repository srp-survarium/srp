char __thiscall survarium::lobby_client::read_last_played_match_stats(
        survarium::lobby_client *this,
        survarium::lobby_menu *reader,
        vostok::network_core::buffer_reader *a3)
{
  survarium::match_total_stats *v4; // ecx
  survarium::player_results_item *v5; // ecx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  unsigned __int8 sky_clouds_fog_up_limit_low; // dl
  unsigned __int8 v10; // bl
  unsigned int v12; // [esp+0h] [ebp-198h]
  bool v13; // [esp+4h] [ebp-194h]
  vostok::vectora<survarium::player_results_item> v14[17]; // [esp+10h] [ebp-188h] BYREF
  __int16 v15; // [esp+122h] [ebp-76h]
  int v16; // [esp+128h] [ebp-70h]
  _BYTE __formal[80]; // [esp+138h] [ebp-60h] BYREF
  void *v18; // [esp+188h] [ebp-10h] BYREF
  survarium::player_results_item *__x; // [esp+18Ch] [ebp-Ch]
  vostok::memory::doug_lea_allocator *v20; // [esp+190h] [ebp-8h]
  survarium::player_results_item *v21; // [esp+194h] [ebp-4h]
  int v22; // [esp+1A4h] [ebp+Ch]
  unsigned __int8 v23; // [esp+1A7h] [ebp+Fh]

  survarium::match_total_stats::match_total_stats((survarium::match_total_stats *)this, (int)v14);
  survarium::match_total_stats::deserialize(v4, (vostok::network_core::buffer_reader *)v14, a3);
  m_pointer = a3->m_pointer;
  v7 = m_pointer + 1;
  v23 = *m_pointer;
  v8 = survarium::g_allocator;
  a3->m_pointer = v7;
  v18 = 0;
  __x = 0;
  v20 = v8;
  v21 = 0;
  if ( v23 )
  {
    v22 = v23;
    do
    {
      *(_DWORD *)&__formal[64] = 0;
      *(_WORD *)&__formal[68] = 0;
      *(_WORD *)&__formal[72] = 0;
      *(_WORD *)&__formal[74] = 0;
      __formal[0] = 0;
      __formal[76] = -1;
      survarium::player_results_item::deserialize(v5, (vostok::network_core::buffer_reader *)__formal, a3);
      if ( __x == v21 )
      {
        stlp_std::priv::_Impl_vector<survarium::player_results_item,vostok::vectora_allocator<survarium::player_results_item>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<survarium::player_results_item,vostok::vectora_allocator<survarium::player_results_item> > *)v5,
          (unsigned int)&v18,
          __x,
          (const stlp_std::__true_type *)__formal,
          v12,
          v13);
      }
      else
      {
        if ( __x )
        {
          qmemcpy(__x, __formal, sizeof(survarium::player_results_item));
          v5 = 0;
        }
        ++__x;
      }
      --v22;
    }
    while ( v22 );
    v8 = v20;
  }
  sky_clouds_fog_up_limit_low = LOBYTE(reader->m_effect_presenter.m_post_process_presenter.m_result.sky_clouds_fog_up_limit);
  v10 = 0;
  if ( sky_clouds_fog_up_limit_low )
  {
    while ( *((_DWORD *)&reader->m_effect_presenter.m_post_process_presenter.m_result.sky_shadows_moving_y + 378 * v10) != v16 )
    {
      if ( ++v10 >= sky_clouds_fog_up_limit_low )
        goto LABEL_15;
    }
    LOWORD(reader[1].m_effect_presenter.m_post_process_presenter.m_result.color_grading_weights[378 * v10 + 2]) = v15;
  }
LABEL_15:
  survarium::lobby_menu::fill_match_statistic(
    reader,
    *(const survarium::match_total_stats **)(LODWORD(reader->m_inverted_view_matrix.c.y) + 13840),
    v14,
    &v18);
  if ( v18 )
    v8->call_free(
      v8,
      v18,
      "vostok::detail::std_allocator<struct survarium::player_results_item>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102u);
  return 1;
}
