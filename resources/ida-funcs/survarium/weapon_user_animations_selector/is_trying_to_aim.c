BOOL __usercall survarium::weapon_user_animations_selector::is_trying_to_aim@<eax>(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(*(_DWORD *)(a2 + 60) + 752) & 0x100) != 0
      && *(_BYTE *)(*(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)(a2 + 60) + 264) + 8))(*(_DWORD *)(a2 + 60) + 264)
                  + 1745) != 2;
}
