void __usercall survarium::object_weapon::~object_weapon(survarium::object_weapon *this@<ecx>, int a2@<esi>)
{
  void *v2; // eax

  *(_DWORD *)a2 = &survarium::object_weapon::`vftable'{for `vostok::ai::weapon'};
  *(_DWORD *)(a2 + 4) = &survarium::object_weapon::`vftable'{for `vostok::ai::game_object'};
  if ( --*(_DWORD *)(*(_DWORD *)(a2 + 8) + 4) )
  {
    **(_DWORD **)(a2 + 8) = 0;
  }
  else
  {
    v2 = *(void **)(a2 + 8);
    if ( v2 )
    {
      pt3free(v2);
      *(_DWORD *)(a2 + 8) = 0;
    }
  }
}
