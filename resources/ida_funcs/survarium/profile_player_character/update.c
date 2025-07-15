void __usercall survarium::profile_player_character::update(
        survarium::profile_player_character *this@<eax>,
        vostok::animation::subscribed_channel **current_time_in_ms@<edx>)
{
  survarium::player *m_object; // eax

  m_object = this->m_player.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      survarium::player::tick(
        (survarium::player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        *(float *)&m_object,
        current_time_in_ms);
  }
}
