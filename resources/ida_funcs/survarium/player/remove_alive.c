void __usercall survarium::player::remove_alive(survarium::player *this@<ecx>, int a2@<esi>)
{
  vostok::physics::bullet_character_controller **v2; // eax
  vostok::physics::bullet_character_controller *v3; // ecx

  v2 = *(vostok::physics::bullet_character_controller ***)((char *)&dword_10DC8 + a2);
  *(_BYTE *)(a2 + 281) = 0;
  vostok::physics::bullet_character_controller::remove(*v2, *v2);
  if ( byte_10F36[a2] )
    vostok::physics::bullet_character_controller::remove(
      v3,
      **(vostok::physics::bullet_character_controller ***)(a2 + 34804));
  if ( !byte_10F80[a2] )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*(int *)((char *)&dword_10F00 + a2) + 176) + 52))(
      *(_DWORD *)(*(int *)((char *)&dword_10F00 + a2) + 176),
      *(_DWORD *)(*(int *)((char *)&dword_10EF0 + a2) + 36));
}
