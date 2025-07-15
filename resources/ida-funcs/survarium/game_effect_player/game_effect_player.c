void __usercall survarium::game_effect_player::game_effect_player(
        survarium::game_effect_player *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = -1;
  *(_DWORD *)(a2 + 8) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)(a2 + 16));
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
}
