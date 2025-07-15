void __userpurge survarium::booby_trap::booby_trap(
        survarium::booby_trap *this@<ecx>,
        int a2@<esi>,
        survarium::game_world *gw)
{
  survarium::game_world *v3; // edx

  survarium::booby_trap_core::booby_trap_core((survarium::booby_trap_core *)a2);
  *(_DWORD *)a2 = &survarium::booby_trap::`vftable'{for `survarium::game_world_object'};
  *(_DWORD *)(a2 + 272) = &survarium::booby_trap::`vftable'{for `survarium::hittable_object'};
  *(_DWORD *)(a2 + 292) = &survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  *(_DWORD *)(a2 + 296) = &survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  *(_DWORD *)(a2 + 328) = &survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  *(_DWORD *)(a2 + 332) = &survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  `vector constructor iterator'(
    (char *)(a2 + 440),
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  v3 = gw;
  *(_DWORD *)(a2 + 456) = 0;
  *(_DWORD *)(a2 + 460) = 0;
  gw = 0;
  *(_DWORD *)(a2 + 464) = v3;
  stlp_std::priv::__fill<vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>,int>(
    (vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *)(a2 + 440),
    (vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *)(a2 + 456),
    (const vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *)&gw);
}
