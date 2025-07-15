void __thiscall survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *this)
{
  survarium::loose_ptr_data *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>((survarium::loose_ptr_data *)this, this->m_object);
  }
}
