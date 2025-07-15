void __usercall survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *this@<ecx>,
        survarium::loose_ptr_data **a2@<eax>)
{
  survarium::loose_ptr_data *m_object; // ecx

  *a2 = 0;
  if ( this )
    m_object = this[1].m_object;
  else
    m_object = 0;
  *a2 = m_object;
  if ( m_object )
    ++m_object->m_reference_count;
}
