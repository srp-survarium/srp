void __thiscall survarium::players_checker::tick(
        survarium::players_checker *this,
        unsigned int time_delta_in_ms,
        vostok::physics::loose_ptr_data *current_time_in_ms)
{
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *M_start; // edi
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *M_finish; // ebx
  vostok::physics::loose_ptr_base *m_pointer; // eax
  vostok::physics::loose_ptr_base *v7; // eax

  survarium::collision_sensor::tick(this, time_delta_in_ms, current_time_in_ms);
  this->m_inside_objects_count = 0;
  M_start = this->m_old_objects._M_impl._M_start;
  M_finish = this->m_old_objects._M_impl._M_finish;
  while ( M_start != M_finish )
  {
    m_pointer = M_start->m_object->m_pointer;
    if ( m_pointer )
      v7 = m_pointer - 1;
    else
      v7 = 0;
    this->m_inside_objects_count += *(_DWORD *)(*(_DWORD *)(((int (__thiscall *)(vostok::physics::loose_ptr_data *))v7[3].m_pointer->m_pointer[2].m_pointer)(v7[3].m_pointer)
                                                          + 69736)
                                              + 440) == this->m_team;
    ++M_start;
  }
}
