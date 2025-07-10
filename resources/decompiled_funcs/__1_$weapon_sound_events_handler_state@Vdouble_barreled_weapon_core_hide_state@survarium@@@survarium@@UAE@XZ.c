void __usercall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_hide_state>::~weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_hide_state>(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state> *this@<ecx>,
        int a2@<esi>)
{
  survarium::double_barreled_weapon_core_show_state *v2; // ecx

  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 424),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *const *)(a2 + 428));
  *(_DWORD *)(a2 + 428) = *(_DWORD *)(a2 + 424);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 416),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *const *)(a2 + 420));
  *(_DWORD *)(a2 + 420) = *(_DWORD *)(a2 + 416);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)(a2 + 408),
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *const *)(a2 + 412));
  *(_DWORD *)(a2 + 412) = *(_DWORD *)(a2 + 408);
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    *(vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **)(a2 + 400),
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *const *)(a2 + 404));
  *(_DWORD *)(a2 + 404) = *(_DWORD *)(a2 + 400);
  survarium::double_barreled_weapon_core_hide_state::~double_barreled_weapon_core_hide_state(
    v2,
    (survarium::double_barreled_weapon_core_show_state *)a2);
}
