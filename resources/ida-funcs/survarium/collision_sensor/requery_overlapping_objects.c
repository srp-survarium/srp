void __userpurge survarium::collision_sensor::requery_overlapping_objects(
        survarium::collision_sensor *this@<ecx>,
        const stlp_std::__false_type *edi0@<edi>,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> a2)
{
  int v4; // edi
  int v5; // esi
  survarium::collision_geometry *v6; // ecx
  vostok::physics::loose_ptr_base *v7; // esi
  int v8; // edi
  void *v9; // esp
  vostok::physics::loose_ptr_data *v10; // ecx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *i; // edi
  survarium::collision_sensor *v12; // ecx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> v13; // [esp-4h] [ebp-20h] BYREF
  _BYTE v14[12]; // [esp+0h] [ebp-1Ch] BYREF
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > __x; // [esp+Ch] [ebp-10h] BYREF
  vostok::physics::loose_ptr_base *v16; // [esp+24h] [ebp+8h]

  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::erase(
    (stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)this,
    edi0,
    (int)&a2.m_object[1],
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)a2.m_object[1].m_pointer,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)a2.m_object[1].m_reference_count);
  v4 = 0;
  v16 = 0;
  if ( a2.m_object[3].m_pointer )
  {
    do
    {
      v5 = *(_DWORD *)(a2.m_object[2].m_reference_count + 4 * (_DWORD)v16);
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v5 + 20) + 24) + 304) + 36))(
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 20) + 24) + 304),
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 20) + 24) + 200),
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 4) + 56) + 24));
      v4 += *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 20) + 24) + 276);
      v16 = (vostok::physics::loose_ptr_base *)((char *)v16 + 1);
    }
    while ( v16 < a2.m_object[3].m_pointer );
    v7 = 0;
    if ( v4 )
    {
      v8 = 4 * v4;
      v9 = alloca(v8);
      __x.m_begin = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v14;
      __x.m_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v14;
      __x.m_max_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&v14[v8];
      if ( a2.m_object[3].m_pointer )
      {
        do
        {
          survarium::collision_geometry::get_overlapping_objects(
            v6,
            *(_DWORD *)(a2.m_object[2].m_reference_count + 4 * (_DWORD)v7),
            &__x);
          v7 = (vostok::physics::loose_ptr_base *)((char *)v7 + 1);
        }
        while ( v7 < a2.m_object[3].m_pointer );
      }
      survarium::collision_sensor::filter_sensed_objects(
        (survarium::collision_sensor *)v6,
        (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)a2.m_object,
        &__x);
      for ( i = __x.m_begin; i != __x.m_end; ++i )
      {
        v13.m_object = v10;
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>(
          &v13,
          i,
          (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v10);
        if ( survarium::collision_sensor::contact_test(v12, a2, v13) )
          stlp_std::vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::push_back(
            (const stlp_std::__false_type *)i,
            (stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)v10,
            (stlp_std::vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)&a2.m_object[1]);
      }
      vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
        (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v10,
        (int **)&__x);
    }
  }
}
