survarium::player_input *__usercall survarium::player::remote_input@<eax>(survarium::player *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  unsigned int v3; // eax
  survarium::player_input v5; // [esp+0h] [ebp-14h] BYREF

  v2 = *(int *)((char *)&dword_10E28 + (_DWORD)this);
  if ( v2 == *(int *)((char *)&dword_10E2C + (_DWORD)this) )
    survarium::player_input::player_input(&v5);
  else
    v3 = *(int *)((char *)&dword_10E1C + (_DWORD)this)
       + 96
       * ((unsigned int)(v2 + *(int *)((char *)&dword_10E24 + (_DWORD)this) - 1)
        % *(int *)((char *)&dword_10E24 + (_DWORD)this));
  *(float *)a2 = *(float *)v3;
  *(float *)(a2 + 4) = *(float *)(v3 + 4);
  *(float *)(a2 + 8) = *(float *)(v3 + 8);
  *(float *)(a2 + 12) = *(float *)(v3 + 12);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(v3 + 16);
  return (survarium::player_input *)a2;
}
