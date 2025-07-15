void __thiscall survarium::base_player::unsubscribe_from_actions(
        survarium::base_player *this,
        survarium::player_actions_subscriber *subscriber)
{
  unsigned __int8 *v2; // eax
  int v3; // edi
  int i; // edx
  _DWORD *v5; // esi
  unsigned __int8 *v6; // ecx

  v2 = *(unsigned __int8 **)((char *)&dword_10D74 + (_DWORD)this);
  v3 = *(int *)((char *)&dword_10D78 + (_DWORD)this);
  for ( i = (v3 - (int)v2) >> 4; i > 0; --i )
  {
    if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
      goto LABEL_17;
    v2 += 4;
    if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
      goto LABEL_17;
    v2 += 4;
    if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
      goto LABEL_17;
    v2 += 4;
    if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
      goto LABEL_17;
    v2 += 4;
  }
  switch ( (v3 - (int)v2) >> 2 )
  {
    case 1:
      goto LABEL_15;
    case 2:
LABEL_13:
      if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
        goto LABEL_17;
      v2 += 4;
LABEL_15:
      if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
        goto LABEL_17;
      break;
    case 3:
      if ( *(survarium::player_actions_subscriber **)v2 == subscriber )
        goto LABEL_17;
      v2 += 4;
      goto LABEL_13;
  }
  v2 = *(unsigned __int8 **)((char *)&dword_10D78 + (_DWORD)this);
LABEL_17:
  v5 = (int *)((char *)&dword_10D78 + (_DWORD)this);
  v6 = *(unsigned __int8 **)((char *)&dword_10D78 + (_DWORD)this);
  if ( v2 + 4 != v6 )
    stlp_std::priv::__copy_trivial(v2 + 4, v6, v2);
  *v5 -= 4;
}
