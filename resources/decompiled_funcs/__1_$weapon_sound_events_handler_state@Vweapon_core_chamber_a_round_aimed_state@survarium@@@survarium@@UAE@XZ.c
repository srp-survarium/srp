void __usercall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>::~weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *this@<ecx>,
        int a2@<esi>)
{
  survarium::weapon_core_show_state *v2; // ecx

  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 384),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 388));
  *(_DWORD *)(a2 + 388) = *(_DWORD *)(a2 + 384);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 376),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 380));
  *(_DWORD *)(a2 + 380) = *(_DWORD *)(a2 + 376);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 368),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 372));
  *(_DWORD *)(a2 + 372) = *(_DWORD *)(a2 + 368);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 360),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 364));
  *(_DWORD *)(a2 + 364) = *(_DWORD *)(a2 + 360);
  survarium::weapon_core_chamber_a_round_state::~weapon_core_chamber_a_round_state(
    v2,
    (survarium::weapon_core_show_state *)a2);
}
