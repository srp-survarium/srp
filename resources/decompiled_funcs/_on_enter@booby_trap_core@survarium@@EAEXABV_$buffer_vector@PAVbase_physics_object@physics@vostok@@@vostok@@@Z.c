void __thiscall survarium::booby_trap_core::on_enter(
        survarium::booby_trap_core *this,
        const vostok::buffer_vector<vostok::physics::base_physics_object *> *objects)
{
  survarium::game_camera *v2; // ecx
  survarium::inventory *inventory; // eax
  survarium::inventory *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  const survarium::hit_initiator *v7; // [esp+0h] [ebp-24h]
  int v8; // [esp+4h] [ebp-20h]
  survarium::inventory_holder *v9; // [esp+8h] [ebp-1Ch]
  survarium::hit_receiver *receiver; // [esp+14h] [ebp-10h]
  vostok::physics::base_physics_object **end; // [esp+1Ch] [ebp-8h]
  vostok::physics::base_physics_object **it; // [esp+20h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  it = objects->m_begin;
  end = objects->m_end;
  while ( it != end )
  {
    inventory = survarium::inventory_item::get_inventory(
                  (survarium::inventory_item *)it,
                  *(_DWORD *)&this->m_parent_resources.gapC);
    v9 = survarium::inventory::holder(v4, (int)inventory);
    v8 = (int)v9->cast_to_base_player(v9);
    if ( v8 )
      v7 = (const survarium::hit_initiator *)(v8 + 48);
    else
      v7 = 0;
    receiver = (*it)->user_data->cast_to_hit_receiver((*it)->user_data);
    survarium::weapon_user_dead_state::finalize(v5);
    survarium::weapon_user_dead_state::finalize(v6);
    survarium::booby_trap_core::apply_damage((survarium::booby_trap_core *)((char *)this - 292), v7, receiver);
    ++it;
  }
  if ( this->m_parent_resources.m_first )
    (*(void (__thiscall **)(boost::intrusive::rbtree_node<void *>::color *, int))(this[-1].grm_satisfaction_tree_hook.color_
                                                                                + 60))(
      &this[-1].grm_satisfaction_tree_hook.color_,
      2);
}
