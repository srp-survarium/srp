void __userpurge survarium::generic_anomaly_core::generic_anomaly_core(
        survarium::generic_anomaly_core *this@<ecx>,
        int a2@<esi>,
        const vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *artefacts,
        unsigned int amount,
        unsigned int seed)
{
  *(_DWORD *)a2 = &survarium::link_resolver::`vftable';
  *(_DWORD *)(a2 + 4) = &survarium::player_actions_subscriber::`vftable';
  vostok::resources::unmanaged_resource::unmanaged_resource(
    (vostok::resources::unmanaged_resource *)this,
    (_DWORD *)(a2 + 8),
    fs_iterator_class);
  *(_DWORD *)(a2 + 272) = &survarium::tickable_object::`vftable';
  *(_DWORD *)(a2 + 284) = &survarium::serializable_object::`vftable';
  *(_DWORD *)(a2 + 312) = -1;
  *(_DWORD *)(a2 + 272) = &survarium::generic_anomaly_core::`vftable'{for `survarium::tickable_object'};
  *(_DWORD *)(a2 + 284) = &survarium::generic_anomaly_core::`vftable'{for `survarium::serializable_object'};
  *(_DWORD *)(a2 + 8) = &survarium::generic_anomaly_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)a2 = &survarium::generic_anomaly_core::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 4) = &survarium::generic_anomaly_core::`vftable'{for `survarium::player_actions_subscriber'};
  *(_BYTE *)(a2 + 308) = 1;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 384) = 0;
  *(_DWORD *)(a2 + 400) = artefacts;
  *(_DWORD *)(a2 + 404) = amount;
  *(_DWORD *)(a2 + 388) = 0;
  *(_BYTE *)(a2 + 392) = 0;
  *(_BYTE *)(a2 + 393) = 0;
  *(_DWORD *)(a2 + 396) = 0;
  *(_DWORD *)(a2 + 408) = seed;
}
