void __thiscall survarium::weapon_core::tick(survarium::weapon_core *this)
{
  survarium::weapon_core *v1; // ecx
  survarium::weapon_user_animations_selector *v2; // eax
  BOOL v3; // ecx
  bool is_ready_to_be_deactivated; // al
  survarium::base_player *user; // eax
  bool is_trying_to_aim; // al
  bool v7; // al
  survarium::weapon_user_animations_selector *v8; // eax
  bool v9; // [esp+0h] [ebp-1Ch]
  const survarium::player_input *input; // [esp+14h] [ebp-8h]
  vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base> target_active_object; // [esp+18h] [ebp-4h] BYREF

  input = this->m_user->input(this->m_user);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_user->m_target_active_object,
    (survarium::inventory **)&target_active_object);
  v2 = survarium::weapon_core::user_animations_selector(v1, (int)this);
  survarium::weapon_user_animations_selector::tick(v2);
  if ( this->m_logic->m_current_state )
  {
    v9 = this->m_is_idle || this->m_aimed && !this->m_is_firing;
    if ( v9 && (input->actions_mask & 0x20) == 0 )
    {
      if ( (input->actions_mask & 0x400) != 0 )
      {
        this->set_next_fire_queue_type(this);
      }
      else if ( (input->actions_mask & 0x800) != 0 )
      {
        this->set_next_ammo_type(this);
      }
      else
      {
        survarium::weapon_core::reset_fire_queue(this);
      }
    }
  }
  if ( this == (survarium::weapon_core *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&target_active_object)
    || (is_ready_to_be_deactivated = survarium::weapon_user_animations_selector::is_ready_to_be_deactivated(&this->m_user_animations_selector),
        !(v3 = is_ready_to_be_deactivated)) )
  {
    user = survarium::weapon_core::get_user((survarium::weapon_core *)v3, (int)this);
    if ( survarium::weapon_core::could_be_used(this, user) )
    {
      if ( (input->actions_mask & 0x20) != 0 )
      {
        is_trying_to_aim = survarium::weapon_core::is_trying_to_aim(this);
        this->set_target(
          this,
          (const survarium::weapon_targets)(is_trying_to_aim ? weapon_target_aim_fire : weapon_target_fire));
      }
      else if ( (input->actions_mask & 0x40) != 0 )
      {
        this->set_target(this, weapon_target_reload);
      }
      else
      {
        v7 = survarium::weapon_core::is_trying_to_aim(this);
        this->set_target(this, v7 ? weapon_target_aim : weapon_target_idle);
      }
    }
    else
    {
      this->set_target(this, weapon_target_idle);
    }
  }
  else
  {
    this->set_target(this, weapon_target_inactive);
  }
  vostok::ai::fsm::tick(this->m_logic);
  if ( this->m_aiming_state_transition )
  {
    v8 = survarium::weapon_core::user_animations_selector(this, (int)this);
    survarium::weapon_user_animations_selector::tick(v8);
    this->m_aiming_state_transition = 0;
  }
  this->m_old_actions_mask = input->actions_mask;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&target_active_object);
}
