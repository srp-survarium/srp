void __usercall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>::~weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> *this@<ecx>,
        int a2@<esi>)
{
  survarium::weapon_core_shotgun_reload_base_substate *v2; // ecx

  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 392),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 396));
  *(_DWORD *)(a2 + 396) = *(_DWORD *)(a2 + 392);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 384),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 388));
  *(_DWORD *)(a2 + 388) = *(_DWORD *)(a2 + 384);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 376),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 380));
  *(_DWORD *)(a2 + 380) = *(_DWORD *)(a2 + 376);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 368),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 372));
  *(_DWORD *)(a2 + 372) = *(_DWORD *)(a2 + 368);
  survarium::weapon_core_shotgun_reload_base_substate::~weapon_core_shotgun_reload_base_substate(v2);
}
