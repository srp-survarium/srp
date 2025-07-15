void __usercall survarium::game_state_history_item::game_state_history_item(
        survarium::game_state_history_item *this@<ecx>,
        survarium::player_history_item *a2@<esi>)
{
  survarium::player_history_item *v2; // edi
  int i; // ebx
  unsigned __int8 *v4; // edx
  unsigned __int8 *v5; // ecx
  char *v6; // edx
  _DWORD *v7; // ecx
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // ecx
  char *v10; // edx
  _DWORD *v11; // ecx
  unsigned __int8 *v12; // ecx

  v2 = a2;
  for ( i = 19; i >= 0; --i )
    survarium::player_history_item::player_history_item(v2++);
  v4 = &a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B468F + 1];
  v5 = &a2->animation_player_state[(_DWORD)&loc_B468F + 1 + 5036];
  *((_DWORD *)v5 + 1) = (char *)a2 + (_DWORD)&loc_B468F + 1;
  *(_DWORD *)v5 = 0;
  *((_DWORD *)v5 + 3) = 0;
  *((_DWORD *)v5 + 2) = 9216;
  *((_DWORD *)v4 + 2313) = v5;
  *((_DWORD *)v4 + 2310) = 0;
  *((_DWORD *)v4 + 2311) = 0;
  v4[9248] = -1;
  *(_DWORD *)&a2->animation_player_state[(_DWORD)&loc_B468F + 1 + 5052] = 0;
  v6 = (char *)&loc_B6AB8 + (_DWORD)a2;
  v7 = (_DWORD *)((char *)&loc_B6AB8 + (_DWORD)a2 + 3072);
  v7[1] = (char *)&loc_B6AB8 + (_DWORD)a2;
  *v7 = 0;
  v7[3] = 0;
  v7[2] = 3072;
  *((_DWORD *)v6 + 777) = v7;
  *((_DWORD *)v6 + 774) = 0;
  *((_DWORD *)v6 + 775) = 0;
  v6[3104] = -1;
  *(_DWORD *)((char *)&loc_B6AB8 + (_DWORD)a2 + 3088) = 0;
  v8 = &a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B76DC + 4];
  v9 = &a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B76DC + 4 + 512];
  *((_DWORD *)v9 + 1) = (char *)a2 + (_DWORD)&loc_B76DC + 4;
  *(_DWORD *)v9 = 0;
  *((_DWORD *)v9 + 3) = 0;
  *((_DWORD *)v9 + 2) = 512;
  *((_DWORD *)v8 + 137) = v9;
  *((_DWORD *)v8 + 134) = 0;
  *((_DWORD *)v8 + 135) = 0;
  v8[544] = -1;
  *(_DWORD *)&a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B76DC + 4 + 528] = 0;
  v10 = (char *)&loc_B7908 + (_DWORD)a2;
  v11 = (_DWORD *)((char *)&loc_B7908 + (_DWORD)a2 + 0x2000);
  v11[1] = (char *)&loc_B7908 + (_DWORD)a2;
  *v11 = 0;
  v11[3] = 0;
  v11[2] = 0x2000;
  *((_DWORD *)v10 + 2057) = v11;
  *((_DWORD *)v10 + 2054) = 0;
  *((_DWORD *)v10 + 2055) = 0;
  v10[8224] = -1;
  *(_DWORD *)((char *)&loc_B7908 + (_DWORD)a2 + 8208) = 0;
  *(_DWORD *)&a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] = -1;
  *(_DWORD *)&a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B992B + 5] = 0;
  *(_DWORD *)&a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B9933 + 1] = 0;
  *(_DWORD *)((char *)&loc_B993C + (_DWORD)a2) = 0;
  a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 1] = 0;
  a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 2] = 0;
  a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 3] = 0;
  v12 = &a2->player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 5];
  *(_DWORD *)v12 = 0;
  *((_DWORD *)v12 + 2) = 0;
  *((_DWORD *)v12 + 3) = 0;
}
