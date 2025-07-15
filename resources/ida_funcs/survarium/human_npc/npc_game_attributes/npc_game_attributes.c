void __usercall survarium::human_npc::npc_game_attributes::npc_game_attributes(
        survarium::human_npc::npc_game_attributes *this@<ecx>,
        int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm1_4
  const char *v3; // eax
  char *v4; // ecx
  const char *v5; // eax
  char *v6; // ecx

  *(_DWORD *)a2 = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 8), 0x2710u);
  v2 = clear_value;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = v2;
  *(_DWORD *)(a2 + 64) = v2;
  *(_DWORD *)(a2 + 68) = v2;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = -16777216;
  *(_DWORD *)(a2 + 88) = a2 + 100;
  *(_DWORD *)(a2 + 92) = a2 + 100;
  *(_DWORD *)(a2 + 96) = a2 + 132;
  *(_BYTE *)(a2 + 100) = 0;
  v3 = "noname";
  do
  {
    v4 = *(char **)(a2 + 92);
    if ( (unsigned int)v4 >= *(_DWORD *)(a2 + 96) )
      break;
    *v4 = *v3;
    ++*(_DWORD *)(a2 + 92);
    ++v3;
  }
  while ( *v3 );
  **(_BYTE **)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 132) = a2 + 144;
  *(_DWORD *)(a2 + 136) = a2 + 144;
  *(_DWORD *)(a2 + 140) = a2 + 176;
  *(_BYTE *)(a2 + 144) = 0;
  v5 = "human";
  do
  {
    v6 = *(char **)(a2 + 136);
    if ( (unsigned int)v6 >= *(_DWORD *)(a2 + 140) )
      break;
    *v6 = *v5;
    ++*(_DWORD *)(a2 + 136);
    ++v5;
  }
  while ( *v5 );
  **(_BYTE **)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 184) = -1;
  *(_DWORD *)(a2 + 188) = -1;
  *(_DWORD *)(a2 + 196) = -1;
  *(_DWORD *)(a2 + 180) = 990057071;
  *(_DWORD *)(a2 + 192) = 0;
}
