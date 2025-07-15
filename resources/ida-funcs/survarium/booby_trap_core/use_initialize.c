void __thiscall survarium::booby_trap_core::use_initialize(
        survarium::booby_trap_core *this,
        vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *user)
{
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)user->m_size + 20))(user->m_size);
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    user,
    &this->survarium::collision_sensor::m_collision_geometries_count);
  *(_DWORD *)&user->gap4 = this != (survarium::booby_trap_core *)52 ? this : 0;
  user->m_first = user->m_last;
}
