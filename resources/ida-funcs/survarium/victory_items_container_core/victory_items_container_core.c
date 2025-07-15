void __userpurge survarium::victory_items_container_core::victory_items_container_core(
        survarium::victory_items_container_core *this@<ecx>,
        int a2@<esi>,
        vostok::physics::world *physics_world,
        survarium::gather_victory_items_rule *rule,
        const vostok::configs::binary_config_value *cfg_val)
{
  vostok::resources::unmanaged_resource *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // ecx

  survarium::usable_object::usable_object(this, a2, 0);
  vostok::resources::unmanaged_resource::unmanaged_resource(v5, (_DWORD *)(a2 + 72), fs_iterator_class);
  v6 = survarium::g_allocator;
  *(_DWORD *)a2 = &survarium::victory_items_container_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)(a2 + 4) = &survarium::victory_items_container_core::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 72) = &survarium::victory_items_container_core::`vftable';
  *(_DWORD *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 340) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 344) = v6;
  *(_DWORD *)(a2 + 356) = physics_world;
  *(_DWORD *)(a2 + 352) = 3;
  *(_DWORD *)(a2 + 360) = rule;
  survarium::victory_items_container_core::load((survarium::victory_items_container_core *)a2, cfg_val);
}
