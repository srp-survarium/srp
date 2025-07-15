char __usercall survarium::weapon_core::can_reload@<al>(
        survarium::weapon_core *this@<ecx>,
        survarium::weapon_core *a2@<esi>)
{
  survarium::base_player *m_user; // ecx
  char v3; // bl
  survarium::weapon_core *v4; // ecx
  survarium::weapon_core *v5; // ecx
  unsigned __int16 m_ammo_in_magazine; // di
  bool v7; // al
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+10h] [ebp-8h] BYREF
  int v11; // [esp+14h] [ebp-4h]

  m_user = a2->m_user;
  v3 = 0;
  v11 = 0;
  if ( (unsigned __int8)survarium::weapon_core::could_be_used(
                          (survarium::weapon_core *)m_user,
                          (const survarium::base_player *)a2) )
  {
    if ( a2->m_user->m_is_alive
      && a2->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size != 3
      && !survarium::weapon_core::is_going_to_jump(v4, (int)a2)
      && !survarium::weapon_core::is_going_to_sprint(v5, (int)a2) )
    {
      m_ammo_in_magazine = a2->m_ammo_in_magazine;
      if ( m_ammo_in_magazine < a2->m_magazine_capacity )
      {
        v7 = a2->m_is_there_chamber_a_round_state && !a2->m_chamber_a_round_on_reload;
        if ( (unsigned __int16)(m_ammo_in_magazine + a2->m_is_round_chambered) < (unsigned __int16)(a2->m_magazine_capacity
                                                                                                  + v7) )
        {
          v11 = 1;
          if ( survarium::weapon_core::ammunition(a2, &v9)->m_object )
          {
            if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
            {
              v11 = 3;
              if ( LOWORD(survarium::weapon_core::ammunition(a2, &v10)->m_object->m_lods[0].m_emitter_instance_list.m_last) )
                v3 = 1;
            }
          }
        }
      }
    }
  }
  if ( (v11 & 2) != 0 )
  {
    v11 &= ~2u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
  }
  if ( (v11 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  return v3;
}
