void __userpurge survarium::object_weapon::object_weapon(
        survarium::object_weapon *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::ai::weapon_types_enum type,
        const char *name,
        unsigned int id,
        unsigned int ammo_count)
{
  _DWORD *v6; // edi
  _DWORD *v7; // eax

  v6 = a2 + 2;
  v7 = pt3malloc(8u);
  if ( v7 )
  {
    *v7 = v6;
    v7[1] = 0;
  }
  else
  {
    v7 = 0;
  }
  *v6 = v7;
  *(_DWORD *)(*v6 + 4) = v7[1] + 1;
  a2[3] = 0;
  a2[4] = type;
  *a2 = &survarium::object_weapon::`vftable'{for `vostok::ai::weapon'};
  a2[1] = &survarium::object_weapon::`vftable'{for `vostok::ai::game_object'};
  a2[5] = name;
  a2[6] = id;
  a2[7] = 32;
}
