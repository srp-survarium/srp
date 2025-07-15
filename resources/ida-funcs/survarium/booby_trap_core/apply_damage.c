void __userpurge survarium::booby_trap_core::apply_damage(
        survarium::booby_trap_core *this@<ecx>,
        float a2@<xmm0>,
        unsigned int current_time_in_ms,
        const survarium::hit_initiator *initiator,
        survarium::hit_receiver *receiver,
        int a6)
{
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  float v9; // [esp+8h] [ebp-88h]
  int v10; // [esp+10h] [ebp-80h]
  _BYTE v11[108]; // [esp+20h] [ebp-70h] BYREF
  int i; // [esp+8Ch] [ebp-4h]

  v6 = *(_DWORD *)(*(_DWORD *)(current_time_in_ms + 484) + 300);
  for ( i = *(_DWORD *)(*(_DWORD *)(current_time_in_ms + 484) + 304); v6 != i; v6 += 28 )
  {
    vostok::collision::bone_collision_data::bone_collision_data(
      (vostok::collision::bone_collision_data *)this,
      (int)v11,
      (char *)uri,
      (char *)v6);
    v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(current_time_in_ms + 484) + 272) + 376);
    v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 12))(v7);
    v10 = *(unsigned __int16 *)(*(_DWORD *)(current_time_in_ms + 484) + 282);
    v9 = *(float *)(v6 + 24);
    a2 = survarium::player_params_modifiers_container::apply_modifier(
           (survarium::player_params_modifiers_container *)(*(_DWORD *)(v8 + 69736) + 448),
           device_damage_modifier,
           a2,
           *(float *)(v6 + 20),
           1.0);
    (*(void (__thiscall **)(int, const survarium::hit_initiator *, survarium::hit_receiver *, _BYTE *, _DWORD, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)a6 + 20))(
      a6,
      initiator,
      receiver,
      v11,
      *(_DWORD *)(v6 + 16),
      LODWORD(a2),
      LODWORD(v9),
      0,
      v10);
  }
}
