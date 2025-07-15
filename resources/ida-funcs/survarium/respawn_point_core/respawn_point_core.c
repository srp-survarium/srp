void __usercall survarium::respawn_point_core::respawn_point_core(
        survarium::respawn_point_core *this@<edi>,
        vostok::physics::world *physics_world@<eax>,
        unsigned int a3@<ebx>,
        const char *a4@<ebp>,
        const char *a5@<esi>)
{
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  survarium::collision_sensor *v9; // ecx
  int v10; // eax
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // eax
  survarium::collision_sensor *v15; // ecx
  int v16; // eax
  const char *v18; // [esp-Ch] [ebp-Ch]
  const char *v19; // [esp-8h] [ebp-8h]
  unsigned int v20; // [esp-4h] [ebp-4h]

  this->point_id = -1;
  v5 = survarium::g_allocator;
  this->__vftable = (survarium::respawn_point_core_vtbl *)&survarium::respawn_point_core::`vftable';
  *(_QWORD *)&this->position.x = 0;
  this->position.z = 0.0;
  this->point_priority = 0;
  this->orientation = 0.0;
  this->team_owner = team_undefined;
  this->m_physics_world = physics_world;
  v6 = type_info::raw_name(&survarium::players_checker `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x28u, v6, a5, a4, a3);
  if ( v8 )
  {
    survarium::collision_sensor::collision_sensor(v9, (int)v8);
    *(_DWORD *)v10 = &survarium::players_checker::`vftable'{for `survarium::collision_geometry_subscriber'};
    *(_DWORD *)(v10 + 4) = &survarium::players_checker::`vftable'{for `survarium::link_resolver'};
    *(_BYTE *)(v10 + 32) = 0;
    *(_DWORD *)(v10 + 36) = 3;
  }
  else
  {
    v10 = 0;
  }
  v11 = survarium::g_allocator;
  this->m_ally_checker = (survarium::players_checker *)v10;
  v12 = type_info::raw_name(&survarium::players_checker `RTTI Type Descriptor');
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v11, 0x28u, v12, v18, v19, v20);
  if ( v14 )
  {
    survarium::collision_sensor::collision_sensor(v15, (int)v14);
    *(_DWORD *)v16 = &survarium::players_checker::`vftable'{for `survarium::collision_geometry_subscriber'};
    *(_DWORD *)(v16 + 4) = &survarium::players_checker::`vftable'{for `survarium::link_resolver'};
    *(_BYTE *)(v16 + 32) = 0;
    *(_DWORD *)(v16 + 36) = 3;
  }
  else
  {
    v16 = 0;
  }
  this->m_enemy_checker = (survarium::players_checker *)v16;
}
