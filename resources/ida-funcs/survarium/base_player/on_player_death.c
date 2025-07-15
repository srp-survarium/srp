void __thiscall survarium::base_player::on_player_death(
        survarium::base_player *this,
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *current_time_in_ms)
{
  survarium::player_death_subscriber *m_first; // eax
  survarium::player_death_subscriber *next; // edi
  int v5; // ecx
  survarium::usable_object *current_object; // ecx

  m_first = this->m_player_death_subscribers.m_first;
  if ( m_first )
  {
    do
    {
      next = m_first->next;
      v5 = -(m_first->subscription_callback.vtable != 0);
      if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v5) != 0 )
        boost::function1<void,vostok::collision::object const &>::operator()(
          (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v5,
          m_first,
          current_time_in_ms);
      m_first = next;
    }
    while ( next );
  }
  current_object = this->m_usable_object_user_data.current_object;
  if ( current_object )
  {
    this->m_usable_object_user_data.current_time_ms = (unsigned int)current_time_in_ms;
    current_object->use_finalize(current_object, &this->m_usable_object_user_data);
  }
}
