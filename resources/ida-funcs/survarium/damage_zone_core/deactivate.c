void __thiscall survarium::damage_zone_core::deactivate(survarium::damage_zone_core *this)
{
  survarium::hit_receiver_info *end; // [esp+64h] [ebp-8h]
  survarium::hit_receiver_info *it; // [esp+68h] [ebp-4h]

  survarium::collision_sensor::remove(this);
  survarium::scheduler::unregister(this->m_scheduler, &this->m_scheduler_identifier);
  this->m_scheduler = 0;
  if ( this->m_owner )
  {
    it = this->m_receivers._M_impl._M_start;
    end = this->m_receivers._M_impl._M_finish;
    while ( it != end )
    {
      if ( this )
        it->m_receiver->unsubscribe_from_actions(it->m_receiver, &this->survarium::player_actions_subscriber);
      else
        it->m_receiver->unsubscribe_from_actions(it->m_receiver, 0);
      ++it;
    }
  }
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::clear((stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *)&this->m_receivers);
  this->m_owner = 0;
}
