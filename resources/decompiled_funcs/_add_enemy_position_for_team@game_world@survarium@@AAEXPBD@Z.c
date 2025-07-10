void __thiscall survarium::game_world::add_enemy_position_for_team(survarium::game_world *this, const char *team_name)
{
  survarium::keyboard_key_descr **m_keyboard; // ecx
  const char *v4; // eax
  bool v5; // cf
  unsigned __int8 v6; // dl
  int v7; // eax
  survarium::vector<vostok::math::float3> *p_m_enemies_for_team_1; // edi
  const char *v9; // eax
  bool v10; // cf
  unsigned __int8 v11; // dl
  int v12; // eax
  vostok::math::float3 *M_finish; // eax
  const stlp_std::__true_type *v14; // [esp+0h] [ebp-14h]
  unsigned int v15; // [esp+4h] [ebp-10h]
  vostok::math::float3 __x; // [esp+8h] [ebp-Ch] BYREF

  this->m_game->m_network_client->get_current_player_position(this->m_game->m_network_client, &__x);
  m_keyboard = stru_95AF78.m_key_bindings[5].m_keyboard;
  v4 = team_name;
  while ( 1 )
  {
    v5 = *v4 < *(_BYTE *)m_keyboard;
    if ( *v4 != *(_BYTE *)m_keyboard )
      break;
    if ( !*v4 )
      goto LABEL_6;
    v6 = v4[1];
    v5 = v6 < *((_BYTE *)m_keyboard + 1);
    if ( v6 != *((_BYTE *)m_keyboard + 1) )
      break;
    v4 += 2;
    m_keyboard = (survarium::keyboard_key_descr **)((char *)m_keyboard + 2);
    if ( !v6 )
    {
LABEL_6:
      v7 = 0;
      goto LABEL_8;
    }
  }
  v7 = -v5 - (v5 - 1);
LABEL_8:
  if ( !v7 )
  {
    p_m_enemies_for_team_1 = &this->m_enemies_for_team_1;
    goto LABEL_19;
  }
  m_keyboard = (survarium::keyboard_key_descr **)"2";
  v9 = team_name;
  while ( 1 )
  {
    v10 = *v9 < *(_BYTE *)m_keyboard;
    if ( *v9 != *(_BYTE *)m_keyboard )
      break;
    if ( !*v9 )
      goto LABEL_15;
    v11 = v9[1];
    v10 = v11 < *((_BYTE *)m_keyboard + 1);
    if ( v11 != *((_BYTE *)m_keyboard + 1) )
      break;
    v9 += 2;
    m_keyboard = (survarium::keyboard_key_descr **)((char *)m_keyboard + 2);
    if ( !v11 )
    {
LABEL_15:
      v12 = 0;
      goto LABEL_17;
    }
  }
  v12 = -v10 - (v10 - 1);
LABEL_17:
  if ( !v12 )
  {
    p_m_enemies_for_team_1 = &this->m_enemies_for_team_2;
LABEL_19:
    M_finish = p_m_enemies_for_team_1->_M_impl._M_finish;
    if ( M_finish == p_m_enemies_for_team_1->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::math::float3,survarium::std_allocator<vostok::math::float3>>::_M_insert_overflow(
        &p_m_enemies_for_team_1->_M_impl,
        M_finish,
        (stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *)m_keyboard,
        &__x,
        v14,
        v15,
        SLOBYTE(__x.x));
    }
    else
    {
      if ( M_finish )
        *M_finish = __x;
      ++p_m_enemies_for_team_1->_M_impl._M_finish;
    }
  }
}
