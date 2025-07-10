void __thiscall survarium::weapon_core::~weapon_core(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx

  this->__vftable = (survarium::weapon_core_vtbl *)&survarium::weapon_core::`vftable';
  vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,unsigned char>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    &this->m_weapon_fire_queue_types);
  vostok::ai::fsm::clear_transitions(this->m_logic);
  while ( vostok::ai::fsm::pop_state(this->m_logic) )
    ;
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::fsm,vostok::memory::detail::call_destructor_predicate>(
    v2,
    &this->m_logic);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::clear(&this->m_logic_states);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_skeleton);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
  survarium::breath_vibration_calculator::~breath_vibration_calculator(&this->m_breath_vibration_calculator);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_animations_selector::~weapon_user_animations_selector(&this->m_user_animations_selector);
  survarium::legs_ik_processor::~legs_ik_processor(&this->m_legs_ik_processor);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_hand_ik_processor);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_action_behaviuor);
  survarium::interactive_object::~interactive_object(&this->survarium::inventory_item);
}
