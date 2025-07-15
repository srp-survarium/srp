void __thiscall survarium::damage_zone_core::on_enter(
        survarium::damage_zone_core *this,
        const vostok::buffer_vector<vostok::physics::base_physics_object *> *objects)
{
  vostok::physics::base_physics_object **m_begin; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::hit_receiver *receiver; // [esp+1Ch] [ebp-18h]
  survarium::hit_receiver_info info; // [esp+20h] [ebp-14h] BYREF
  vostok::physics::base_physics_object *const *end; // [esp+2Ch] [ebp-8h]
  vostok::physics::base_physics_object *const *it; // [esp+30h] [ebp-4h]

  m_begin = objects->m_begin;
  it = objects->m_begin;
  end = objects->m_end;
  while ( it != end )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_begin);
    receiver = (*it)->user_data->cast_to_hit_receiver((*it)->user_data);
    survarium::weapon_user_dead_state::finalize(v3);
    survarium::weapon_user_dead_state::finalize(v4);
    if ( this->m_owner )
    {
      if ( this )
        receiver->subscribe_on_actions(receiver, &this->survarium::player_actions_subscriber);
      else
        receiver->subscribe_on_actions(receiver, 0);
      survarium::generic_anomaly_core::on_hit_receiver_enter(this->m_owner->owner->owner, receiver, this);
    }
    survarium::hit_receiver_info::hit_receiver_info(&info, receiver, *it);
    survarium::weapon_user_dead_state::finalize(v5);
    stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::push_back(
      &this->m_receivers._M_impl,
      &info);
    m_begin = (vostok::physics::base_physics_object **)++it;
  }
}
