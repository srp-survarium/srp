survarium::player_input *__usercall survarium::player::local_input@<eax>(
        survarium::player *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>)
{
  int v3; // eax
  int v4; // eax
  survarium::player_input v6; // [esp+0h] [ebp-14h] BYREF

  v3 = *(int *)((char *)&dword_10EF4 + a2);
  if ( v3 )
    v4 = v3 + 356;
  else
    survarium::player_input::player_input(&v6);
  *(float *)a3 = *(float *)v4;
  *(float *)(a3 + 4) = *(float *)(v4 + 4);
  *(float *)(a3 + 8) = *(float *)(v4 + 8);
  *(float *)(a3 + 12) = *(float *)(v4 + 12);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(v4 + 16);
  return (survarium::player_input *)a3;
}
