void __userpurge survarium::victory_item_core::victory_item_core(
        survarium::victory_item_core *this@<ecx>,
        int a2@<esi>,
        vostok::physics::world *physics_world)
{
  vostok::resources::unmanaged_resource *v3; // ecx

  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 12) = -1;
  *(_BYTE *)(a2 + 13) = 1;
  *(_BYTE *)(a2 + 14) = 0;
  survarium::usable_object::usable_object((survarium::usable_object *)this, a2 + 20, 0);
  *(_DWORD *)a2 = &survarium::carryable_object::`vftable';
  *(_DWORD *)(a2 + 20) = &survarium::carryable_object::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)(a2 + 24) = &survarium::carryable_object::`vftable'{for `survarium::link_resolver'};
  vostok::resources::unmanaged_resource::unmanaged_resource(v3, (_DWORD *)(a2 + 96), fs_iterator_class);
  *(_DWORD *)(a2 + 20) = &survarium::victory_item_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)a2 = &survarium::victory_item_core::`vftable'{for `survarium::carryable_object'};
  *(_DWORD *)(a2 + 24) = &survarium::victory_item_core::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 88) = &survarium::victory_item_core::`vftable'{for `survarium::spottable_object'};
  *(_DWORD *)(a2 + 96) = &survarium::victory_item_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 384) = 0;
  *(_DWORD *)(a2 + 416) = 0;
  *(_DWORD *)(a2 + 420) = 0;
  *(_DWORD *)(a2 + 424) = 0;
  *(_DWORD *)(a2 + 428) = 0;
  *(_DWORD *)(a2 + 432) = 0;
  *(_DWORD *)(a2 + 448) = physics_world;
  *(_DWORD *)(a2 + 436) = 0;
  *(_DWORD *)(a2 + 440) = 0;
  *(_DWORD *)(a2 + 456) = 0;
  *(_DWORD *)(a2 + 452) = 0;
  *(_BYTE *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
}
