void __thiscall survarium::damage_zone_core::deactivate(survarium::damage_zone_core *this, int forced, int a3)
{
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *v4; // ecx
  int **v5; // edi
  int *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int **i; // [esp+14h] [ebp+8h]

  survarium::collision_sensor::remove((survarium::collision_sensor *)this, forced + 264);
  *(_DWORD *)(forced + 424) = 0;
  if ( !(_BYTE)a3 )
  {
    if ( *(_DWORD *)(forced + 428) )
    {
      v5 = *(int ***)(forced + 344);
      for ( i = *(int ***)(forced + 348); v5 != i; ++v5 )
      {
        v6 = *v5;
        if ( *v5 && *v6 )
        {
          v7 = *v6;
          if ( v7 )
            v8 = v7 - 4;
          else
            v8 = 0;
          v9 = (***(int (__thiscall ****)(_DWORD))(v8 + 12))(*(_DWORD *)(v8 + 12));
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 40))(v9, forced + 312);
          v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 8))(v9);
          --*(_BYTE *)(v10 + 708);
        }
      }
    }
  }
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::erase(
    v4,
    forced + 344,
    *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(forced + 344),
    *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(forced + 348));
  (*(void (__thiscall **)(int, int))(*(_DWORD *)forced + 32))(forced, a3);
}
