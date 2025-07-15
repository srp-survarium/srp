void __userpurge survarium::booby_trap_core::booby_trap_core(
        survarium::booby_trap_core *this@<ecx>,
        int a2@<esi>,
        vostok::math::float4x4 *physics_world)
{
  survarium::usable_object *v3; // ecx
  vostok::resources::unmanaged_resource *v4; // ecx

  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_WORD *)(a2 + 12) = 0;
  *(_WORD *)(a2 + 14) = 0;
  *(_DWORD *)a2 = &survarium::hittable_object::`vftable';
  survarium::collision_sensor::collision_sensor((survarium::collision_sensor *)this, a2 + 16);
  survarium::usable_object::usable_object(v3, a2 + 52, 1);
  *(_DWORD *)(a2 + 120) = &survarium::tickable_object::`vftable';
  *(_DWORD *)(a2 + 132) = &survarium::serializable_object::`vftable';
  vostok::resources::unmanaged_resource::unmanaged_resource(v4, (_DWORD *)(a2 + 144), fs_iterator_class);
  *(_DWORD *)(a2 + 492) = -1;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 412) = 0;
  *(_DWORD *)(a2 + 484) = 0;
  *(_DWORD *)(a2 + 488) = 0;
  *(_DWORD *)a2 = &survarium::booby_trap_core::`vftable'{for `survarium::hittable_object'};
  *(_DWORD *)(a2 + 16) = &survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  *(_DWORD *)(a2 + 20) = &survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  *(_DWORD *)(a2 + 52) = &survarium::booby_trap_core::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  *(_DWORD *)(a2 + 56) = &survarium::booby_trap_core::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  *(_DWORD *)(a2 + 120) = &survarium::booby_trap_core::`vftable'{for `survarium::tickable_object'};
  *(_DWORD *)(a2 + 132) = &survarium::booby_trap_core::`vftable'{for `survarium::serializable_object'};
  *(_DWORD *)(a2 + 144) = &survarium::booby_trap_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 480) = physics_world;
  vostok::math::float4x4::identity(physics_world, (vostok::math::float4x4 *)(a2 + 416));
}
