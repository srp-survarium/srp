survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *__usercall survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=@<eax>(
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *this@<esi>,
        const survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *object@<eax>)
{
  survarium::loose_ptr_data *m_object; // eax
  survarium::loose_ptr_data *v3; // eax
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> v5; // [esp+4h] [ebp-4h] BYREF

  m_object = object->m_object;
  v5.m_object = 0;
  if ( m_object )
  {
    v5.m_object = m_object;
    ++m_object->m_reference_count;
  }
  v3 = v5.m_object;
  v5.m_object = this->m_object;
  this->m_object = v3;
  survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(&v5);
  return this;
}


survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *__usercall survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=@<eax>(
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *this@<ecx>,
        int *a2@<esi>)
{
  int *v2; // eax
  int v3; // ecx
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> v5; // [esp+4h] [ebp-4h] BYREF

  survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
    this,
    &v5.m_object);
  v3 = *v2;
  *v2 = *a2;
  *a2 = v3;
  survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(&v5);
  return (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)a2;
}
