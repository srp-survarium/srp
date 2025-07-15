void __thiscall survarium::collision_sensor::remove_loosed_ptrs(
        survarium::collision_sensor *this,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **a2)
{
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **v2; // esi
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v3; // edi
  int v4; // ebx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v5; // eax
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v6; // ecx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v7; // [esp-4h] [ebp-1Ch]
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v8; // [esp+Ch] [ebp-Ch]
  vostok::physics::base_physics_object *__val; // [esp+10h] [ebp-8h] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *object; // [esp+14h] [ebp-4h]

  __val = 0;
  v2 = a2 + 2;
  v3 = a2[3];
  v4 = v3 - a2[2];
  v8 = v3;
  v5 = stlp_std::priv::__find<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *,vostok::physics::base_physics_object *>(
         a2[2],
         (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this,
         v3,
         (const vostok::physics::base_physics_object *const *)&__val);
  v6 = v7;
  if ( v5 != v3 )
  {
    __val = (vostok::physics::base_physics_object *)v5;
    for ( object = v5 + 1; object != v3; ++object )
    {
      if ( !vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator==(
              v6,
              (int **)object,
              0) )
      {
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator=(
          object,
          v6,
          (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)__val);
        __val = (vostok::physics::base_physics_object *)((char *)__val + 4);
        v3 = v8;
      }
    }
    v5 = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)__val;
  }
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::erase(
    (stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)v6,
    (const stlp_std::__false_type *)v3,
    (int)v2,
    v5,
    v3);
  if ( v4 != a2[3] - a2[2] )
    ((void (__thiscall *)(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **, vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **))(*a2)[9].m_object)(
      a2,
      v2);
}
