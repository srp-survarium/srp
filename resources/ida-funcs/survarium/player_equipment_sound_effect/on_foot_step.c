void __userpurge survarium::player_equipment_sound_effect::on_foot_step(
        survarium::player_equipment_sound_effect *this@<ecx>,
        int a2@<esi>,
        const vostok::math::float3 *toe_position,
        const vostok::math::float3 *toe_rotation)
{
  unsigned __int16 v4; // di
  const vostok::math::float3 *v5; // eax
  survarium::step_manager *v6; // ecx
  unsigned __int8 v7; // [esp+4h] [ebp-4h]

  v7 = !survarium::player::is_first_view((survarium::player *)this, *(_DWORD *)(a2 + 60));
  v4 = *(_WORD *)(*(_DWORD *)(a2 + 60) + 2 * (v7 + 2 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 56) + 24) + 32) + 35104));
  v5 = (const vostok::math::float3 *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 64) + 52))(*(_DWORD *)(a2 + 64));
  if ( v5 )
    survarium::step_manager::on_step(v6, v5, toe_position, (int)toe_rotation, v4, v7);
}
