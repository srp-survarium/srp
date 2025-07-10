void __usercall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>::~weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state> *this@<ecx>,
        int a2@<esi>)
{
  survarium::double_barreled_weapon_core_reload_state *v2; // ecx

  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 416),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 420));
  *(_DWORD *)(a2 + 420) = *(_DWORD *)(a2 + 416);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 408),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 412));
  *(_DWORD *)(a2 + 412) = *(_DWORD *)(a2 + 408);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 400),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 404));
  *(_DWORD *)(a2 + 404) = *(_DWORD *)(a2 + 400);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 392),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 396));
  *(_DWORD *)(a2 + 396) = *(_DWORD *)(a2 + 392);
  survarium::pistol_weapon_core_reload_state::~pistol_weapon_core_reload_state(
    v2,
    (survarium::double_barreled_weapon_core_reload_state *)a2);
}
