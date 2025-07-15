void __userpurge survarium::usable_object::usable_object(
        survarium::usable_object *this@<ecx>,
        int a2@<eax>,
        bool hold_use_button)
{
  *(_DWORD *)(a2 + 4) = &survarium::link_resolver::`vftable';
  *(_DWORD *)a2 = &survarium::usable_object::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)(a2 + 4) = &survarium::usable_object::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 8) = a2 + 20;
  *(_DWORD *)(a2 + 12) = a2 + 20;
  *(_DWORD *)(a2 + 16) = a2 + 40;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 64) = hold_use_button;
}
