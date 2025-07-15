BOOL __usercall survarium::base_player::can_sprint@<eax>(survarium::base_player *this@<ecx>, int a2@<esi>)
{
  survarium::player_stamina *v2; // ecx
  float current_weight; // xmm0_4
  vostok::physics::bt_character_controller *v4; // ecx
  BOOL result; // eax

  result = 0;
  if ( !*(_BYTE *)(*(_DWORD *)(*(int (__thiscall **)(int, survarium::base_player *))(*(_DWORD *)(a2 + 264) + 8))(
                                a2 + 264,
                                this)
                 + 1744)
    && !*((_BYTE *)&loc_11106 + a2 + 2) )
  {
    current_weight = *(float *)(*(_DWORD *)(a2 + 268) + 392) + *(float *)(*(_DWORD *)(a2 + 268) + 388);
    if ( !survarium::player_stamina::is_overburdened(v2, (int)&loc_1106F + a2 + 1, current_weight, current_weight)
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 320) + 80))(*(_DWORD *)(a2 + 320))
      && vostok::physics::bt_character_controller::can_stand(v4, *(int *)((char *)&dword_10E74 + a2)) )
    {
      return 1;
    }
  }
  return result;
}
