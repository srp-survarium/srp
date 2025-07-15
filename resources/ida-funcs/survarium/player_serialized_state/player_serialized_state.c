void __usercall survarium::player_serialized_state::player_serialized_state(
        survarium::player_serialized_state *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 2048) = 0;
  *(_DWORD *)(a2 + 2060) = 0;
  *(_DWORD *)(a2 + 2052) = a2;
  *(_DWORD *)(a2 + 2056) = 2048;
  *(_DWORD *)(a2 + 2064) = 0;
  *(_DWORD *)(a2 + 2072) = 0;
  *(_DWORD *)(a2 + 2076) = 0;
  *(_BYTE *)(a2 + 2080) = -1;
  *(_DWORD *)(a2 + 2084) = a2 + 2048;
}
