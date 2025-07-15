void __thiscall survarium::damage_model::reset(
        survarium::damage_model *this,
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> current_time_in_ms,
        survarium::loose_ptr_base *a3)
{
  survarium::loose_ptr_data *m_object; // ebx
  survarium::loose_ptr_base *i; // edi
  survarium::loose_ptr_data *m_pointer; // eax
  double v6; // st7
  survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *v7; // edi
  survarium::loose_ptr_base *v8; // eax
  survarium::loose_ptr_base *v9; // [esp+Ch] [ebp-4h]

  m_object = current_time_in_ms.m_object;
  for ( i = current_time_in_ms.m_object[34].m_pointer; i; i = v9 )
  {
    m_pointer = i->m_pointer;
    v6 = *(float *)&i[36].m_pointer;
    i[41].m_pointer = 0;
    *(float *)&i[37].m_pointer = v6;
    v9 = (survarium::loose_ptr_base *)m_pointer;
    i[10].m_pointer = i[9].m_pointer;
    survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=(
      0,
      (int *)&i[55]);
    v7 = (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)i[7].m_pointer;
    if ( v7 )
    {
      current_time_in_ms.m_object = 0;
      do
      {
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=(
          v7 + 4,
          &current_time_in_ms);
        survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>((survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&current_time_in_ms);
        v7 = (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v7->m_object;
      }
      while ( v7 );
    }
  }
  v8 = a3;
  LOBYTE(m_object[218].m_pointer) = 0;
  BYTE1(m_object[218].m_pointer) = 0;
  m_object[206].m_pointer = v8;
}
