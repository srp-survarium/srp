void __thiscall survarium::collision_sensor::query_overlapping_objects(
        survarium::collision_sensor *this,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> time_delta,
        unsigned int current_time,
        vostok::physics::loose_ptr_data *current_timea)
{
  vostok::physics::loose_ptr_base *m_pointer; // ecx
  vostok::physics::loose_ptr_base *v6; // esi
  int v7; // eax
  volatile int m_reference_count; // edx
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v9; // ecx
  int v10; // edi
  void *v11; // esp
  vostok::physics::loose_ptr_data *v12; // ecx
  void *v13; // esp
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *m_begin; // edi
  survarium::collision_sensor *v15; // ecx
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v16; // ecx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> v17; // [esp-4h] [ebp-28h] BYREF
  _BYTE v18[12]; // [esp+0h] [ebp-24h] BYREF
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > v19; // [esp+Ch] [ebp-18h] BYREF
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > sensed_objects; // [esp+18h] [ebp-Ch] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> object; // [esp+2Ch] [ebp+8h]

  survarium::collision_sensor::remove_loosed_ptrs(
    this,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)time_delta.m_object);
  m_pointer = time_delta.m_object[3].m_pointer;
  v6 = 0;
  v7 = 0;
  if ( !m_pointer )
    goto LABEL_5;
  m_reference_count = time_delta.m_object[2].m_reference_count;
  do
  {
    v7 += *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)m_reference_count + 20) + 24) + 276);
    m_reference_count += 4;
    m_pointer = (vostok::physics::loose_ptr_base *)((char *)m_pointer - 1);
  }
  while ( m_pointer );
  if ( v7 )
  {
    v10 = 4 * v7;
    v11 = alloca(4 * v7);
    sensed_objects.m_begin = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v18;
    sensed_objects.m_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v18;
    sensed_objects.m_max_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&v18[4 * v7];
    do
    {
      survarium::collision_geometry::get_overlapping_objects(
        (survarium::collision_geometry *)m_pointer,
        *(_DWORD *)(time_delta.m_object[2].m_reference_count + 4 * (_DWORD)v6),
        &sensed_objects);
      v6 = (vostok::physics::loose_ptr_base *)((char *)v6 + 1);
    }
    while ( v6 < time_delta.m_object[3].m_pointer );
    survarium::collision_sensor::filter_sensed_objects(
      (survarium::collision_sensor *)m_pointer,
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)time_delta.m_object,
      &sensed_objects);
    v13 = alloca(v10);
    v19.m_begin = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v18;
    v19.m_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v18;
    v19.m_max_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&v18[v10];
    if ( sensed_objects.m_end - sensed_objects.m_begin )
    {
      m_begin = sensed_objects.m_begin;
      object.m_object = (vostok::physics::loose_ptr_data *)(sensed_objects.m_end - sensed_objects.m_begin);
      do
      {
        v17.m_object = v12;
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>(
          &v17,
          m_begin,
          (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v12);
        if ( survarium::collision_sensor::contact_test(v15, time_delta, v17) )
          vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::push_back(
            m_begin,
            (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v12,
            &v19);
        ++m_begin;
        --object.m_object;
      }
      while ( object.m_object );
    }
    survarium::collision_sensor::notify_and_erase_left_objects(
      (survarium::collision_sensor *)v12,
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)time_delta.m_object,
      &v19,
      (unsigned int)current_timea);
    if ( LOBYTE(time_delta.m_object[3].m_reference_count) )
    {
      survarium::collision_sensor::notify_and_add_incoming_objects(
        &v19,
        v16,
        (survarium::collision_sensor *)time_delta.m_object,
        (unsigned int)current_timea);
      if ( LOBYTE(time_delta.m_object[3].m_reference_count) )
      {
        survarium::collision_sensor::notify_objects_inside(
          (survarium::collision_sensor *)v16,
          (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)time_delta.m_object,
          current_time,
          (unsigned int)current_timea);
        if ( LOBYTE(time_delta.m_object[3].m_reference_count) )
          survarium::collision_sensor::notify_and_erase_just_removed_objects(
            (survarium::collision_sensor *)v16,
            (unsigned int)time_delta.m_object,
            (int)current_timea);
      }
    }
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
      v16,
      (int **)&v19);
  }
  else
  {
LABEL_5:
    memset((void *)&sensed_objects, 0, sizeof(sensed_objects));
    survarium::collision_sensor::notify_and_erase_left_objects(
      (survarium::collision_sensor *)m_pointer,
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)time_delta.m_object,
      &sensed_objects,
      (unsigned int)current_timea);
  }
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
    v9,
    (int **)&sensed_objects);
}
