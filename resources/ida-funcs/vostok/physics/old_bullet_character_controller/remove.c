void __usercall vostok::physics::old_bullet_character_controller::remove(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        int a2@<esi>)
{
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 20) + 60))(*(_DWORD *)(a2 + 20), a2);
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 20) + 32))(*(_DWORD *)(a2 + 20), a2 + 160);
  if ( *(_DWORD *)(a2 + 444) )
  {
    if ( *(_BYTE *)(a2 + 448) )
      btAlignedFreeInternal(*(void **)(a2 + 444));
    *(_DWORD *)(a2 + 444) = 0;
  }
  *(_DWORD *)(a2 + 444) = 0;
  *(_DWORD *)(a2 + 436) = 0;
  *(_DWORD *)(a2 + 440) = 0;
  *(_BYTE *)(a2 + 448) = 1;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 4952) = 0;
}
