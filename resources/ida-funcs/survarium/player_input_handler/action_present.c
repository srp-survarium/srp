char __thiscall survarium::player_input_handler::action_present(
        survarium::player_input_handler *this,
        const survarium::game_action_id game_action_name,
        survarium::action_state_enum *action_state,
        _DWORD *a4)
{
  char *v4; // esi
  survarium::action_state_enum **v5; // eax
  int v6; // ecx
  survarium::action_state_enum *v7; // edx
  vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::const_iterator v9; // [esp-10h] [ebp-2Ch]
  int v10; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h]

  v9.m_index = game_action_name + 152;
  v9.m_container = *(const vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64> **)(game_action_name + 676);
  stlp_std::priv::__find_if<vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::const_iterator,survarium::first_predicate<enum survarium::game_action_id>>(
    &v10,
    (vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::const_iterator *)(game_action_name + 152),
    v9,
    (vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::const_iterator)__PAIR64__((unsigned int)action_state, *(_DWORD *)(game_action_name + 672)));
  v4 = *(char **)(game_action_name + 684);
  v5 = *(survarium::action_state_enum ***)(game_action_name + 680);
  v6 = (v4 - (char *)v5) >> 4;
  if ( v6 <= 0 )
  {
    v7 = action_state;
LABEL_9:
    if ( (v4 - (char *)v5) >> 2 != 1 )
    {
      if ( (v4 - (char *)v5) >> 2 != 2 )
      {
        if ( (v4 - (char *)v5) >> 2 != 3 )
        {
LABEL_17:
          v5 = *(survarium::action_state_enum ***)(game_action_name + 684);
          goto LABEL_18;
        }
        if ( *v5 == v7 )
          goto LABEL_18;
        ++v5;
      }
      if ( *v5 == v7 )
        goto LABEL_18;
      ++v5;
    }
    if ( *v5 == v7 )
      goto LABEL_18;
    goto LABEL_17;
  }
  while ( 1 )
  {
    v7 = action_state;
    if ( *v5 == action_state )
      break;
    if ( *++v5 == action_state )
      break;
    if ( *++v5 == action_state )
      break;
    if ( *++v5 == action_state )
      break;
    ++v5;
    if ( --v6 <= 0 )
      goto LABEL_9;
  }
LABEL_18:
  if ( v11 != *(_DWORD *)(game_action_name + 672) )
  {
    *a4 = *(_DWORD *)(v10 + 8 * v11 + 4);
    return 1;
  }
  if ( v5 != (survarium::action_state_enum **)v4 )
  {
    *a4 = 2;
    return 1;
  }
  return 0;
}
