void __usercall vostok::physics::bullet_character_controller::remove(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<esi>)
{
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 20) + 60))(*(_DWORD *)(a2 + 20), a2);
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 20) + 32))(*(_DWORD *)(a2 + 20), a2 + 96);
  if ( *(_DWORD *)(a2 + 380) )
  {
    if ( *(_BYTE *)(a2 + 384) )
      btAlignedFreeInternal(*(void **)(a2 + 380));
    *(_DWORD *)(a2 + 380) = 0;
  }
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_BYTE *)(a2 + 384) = 1;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 568) = 0;
  *(_DWORD *)(a2 + 776) = 0;
  *(_DWORD *)(a2 + 840) = 0;
  *(_DWORD *)(a2 + 904) = 0;
  *(_DWORD *)(a2 + 968) = 0;
  *(_DWORD *)(a2 + 1008) = 0;
  *(_DWORD *)(a2 + 1080) = 0;
  *(_DWORD *)(a2 + 1144) = 0;
}
