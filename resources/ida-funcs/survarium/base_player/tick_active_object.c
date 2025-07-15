void __thiscall survarium::base_player::tick_active_object(
        survarium::base_player *this,
        survarium::weapon_core *current_time_in_ms,
        int a3)
{
  survarium::weapon_core *v3; // ebx
  vostok::ai::fsm_state *m_last; // ecx
  vostok::ai::fsm_state *m_first; // ecx
  vostok::ai::fsm_state *v6; // ecx
  vostok::ai::fsm_state *v7; // ecx
  const survarium::base_player *v8; // esi
  unsigned int m_deallocation_thread_id; // eax
  const survarium::base_player *v10; // eax
  survarium::inventory *v11; // ecx
  int key_down; // [esp+Ch] [ebp-4h]

  v3 = current_time_in_ms;
  m_last = current_time_in_ms->m_breath_vibration_calculator.m_logic.m_states.m_last;
  if ( current_time_in_ms->m_breath_vibration_calculator.m_logic.m_states.m_first != m_last
    && !((unsigned int (__thiscall *)(vostok::ai::fsm_state *, survarium::weapon_core *))m_last->~vostok::ai::fsm_state)(
          m_last,
          current_time_in_ms) )
  {
    v3->m_breath_vibration_calculator.m_logic.m_states.m_last = v3->m_breath_vibration_calculator.m_logic.m_states.m_first;
  }
  v3->m_breath_vibration_calculator.m_logic.m_states.m_first->__vftable[1].initialize(v3->m_breath_vibration_calculator.m_logic.m_states.m_first);
  m_first = v3->m_breath_vibration_calculator.m_logic.m_states.m_first;
  if ( m_first != v3->m_breath_vibration_calculator.m_logic.m_states.m_last
    && ((unsigned __int8 (__thiscall *)(vostok::ai::fsm_state *))m_first->__vftable[1].execute)(m_first) )
  {
    ((void (__thiscall *)(vostok::ai::fsm_state *, int))v3->m_breath_vibration_calculator.m_logic.m_states.m_first->serialize)(
      v3->m_breath_vibration_calculator.m_logic.m_states.m_first,
      1);
    v6 = v3->m_breath_vibration_calculator.m_logic.m_states.m_last;
    v3->m_breath_vibration_calculator.m_logic.m_states.m_first = v6;
    ((void (__thiscall *)(vostok::ai::fsm_state *, survarium::weapon_core *))v6->initialize)(v6, v3);
    v3->m_breath_vibration_calculator.m_logic.m_states.m_first->execute(v3->m_breath_vibration_calculator.m_logic.m_states.m_first);
    ((void (__thiscall *)(vostok::ai::fsm_state *, int))v3->m_breath_vibration_calculator.m_logic.m_states.m_first->finalize)(
      v3->m_breath_vibration_calculator.m_logic.m_states.m_first,
      1);
    v3->m_breath_vibration_calculator.m_logic.m_states.m_first->__vftable[1].initialize(v3->m_breath_vibration_calculator.m_logic.m_states.m_first);
  }
  v7 = v3->m_breath_vibration_calculator.m_logic.m_states.m_first;
  if ( v7 == v3->m_breath_vibration_calculator.m_logic.m_states.m_last )
  {
    v8 = (const survarium::base_player *)((int (__thiscall *)(vostok::ai::fsm_state *))v7->__vftable[3].finalize)(v7);
    if ( v8 )
    {
      if ( *(_BYTE *)(*(_DWORD *)((int (__thiscall *)(vostok::resources::unmanaged_resource **))v3->m_prev_in_global_delay_delete_list->survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags.survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags)(&v3->m_prev_in_global_delay_delete_list)
                    + 1745)
        && !(unsigned __int8)survarium::weapon_core::could_be_used(v3, v8) )
      {
        m_deallocation_thread_id = v3->m_deallocation_thread_id;
        key_down = *(_DWORD *)(m_deallocation_thread_id + 372) != 7 ? 7 : 10;
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&current_time_in_ms,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(m_deallocation_thread_id + 4 * key_down + 272));
        if ( current_time_in_ms
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v10 = (const survarium::base_player *)((int (*)(void))current_time_in_ms->draw)();
        }
        else
        {
          v10 = 0;
        }
        if ( v10 )
        {
          if ( (unsigned __int8)survarium::weapon_core::could_be_used(v3, v10) )
            survarium::inventory::action(v11, (_DWORD *)v3->m_deallocation_thread_id, key_down, 1u, a3);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&current_time_in_ms);
      }
    }
  }
}
