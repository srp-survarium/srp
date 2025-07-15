void __thiscall survarium::collision_sensor::notify_and_erase_just_removed_objects(
        survarium::collision_sensor *this,
        unsigned int current_time,
        int a3)
{
  void *v4; // esp
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v5; // edi
  int v6; // ecx
  vostok::physics::loose_ptr_base *m_pointer; // eax
  vostok::physics::loose_ptr_base *v8; // eax
  int v9; // eax
  _DWORD v10[3]; // [esp+0h] [ebp-18h] BYREF
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > v11; // [esp+Ch] [ebp-Ch] BYREF

  survarium::collision_sensor::remove_loosed_ptrs(
    this,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)current_time);
  v4 = alloca(4 * ((*(_DWORD *)(current_time + 12) - *(_DWORD *)(current_time + 8)) >> 2));
  v5 = *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(current_time + 8);
  v6 = (*(_DWORD *)(current_time + 12) - *(_DWORD *)(current_time + 8)) >> 2;
  v11.m_begin = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v10;
  v11.m_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v10;
  v11.m_max_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&v10[v6];
  if ( v5 != *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(current_time + 12) )
  {
    do
    {
      m_pointer = v5->m_object->m_pointer;
      if ( m_pointer )
        v6 = (int)&m_pointer[-1];
      else
        v6 = 0;
      if ( *(_DWORD *)(v6 + 12)
        && (!m_pointer ? (v8 = 0) : (v8 = m_pointer - 1),
            (v9 = ((int (__thiscall *)(vostok::physics::loose_ptr_data *))v8[3].m_pointer->m_pointer[2].m_pointer)(v8[3].m_pointer)) != 0
         && !*(_BYTE *)(v9 + 764)) )
      {
        vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::push_back(
          v5,
          (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v6,
          &v11);
        v5 = stlp_std::vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::erase(
               (stlp_std::vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)(current_time + 8),
               v5);
      }
      else
      {
        ++v5;
      }
    }
    while ( v5 != *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(current_time + 12) );
    if ( v11.m_begin != v11.m_end )
      (*(void (__thiscall **)(unsigned int, vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *, int))(*(_DWORD *)current_time + 40))(
        current_time,
        &v11,
        a3);
  }
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
    (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v6,
    (int **)&v11);
}
