void __userpurge survarium::collision_sensor::notify_objects_inside(
        survarium::collision_sensor *this@<ecx>,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **a2@<esi>,
        unsigned int time_delta,
        unsigned int current_time)
{
  void *v4; // esp
  int v5; // ecx
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v6; // ecx
  int v7; // [esp+0h] [ebp-14h] BYREF
  int *v8[3]; // [esp+4h] [ebp-10h] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *end; // [esp+10h] [ebp-4h] BYREF

  if ( a2[2] != a2[3] )
  {
    v4 = alloca(4 * (a2[3] - a2[2]));
    v5 = (char *)a2[3] - (char *)a2[2];
    v8[0] = &v7;
    v8[1] = &v7;
    v5 >>= 2;
    v8[2] = (int *)&v8[v5 - 1];
    end = a2[3];
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::assign<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *>(
      (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v5,
      v8,
      a2[2],
      &end);
    ((void (__thiscall *)(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **, int **, unsigned int, unsigned int))(*a2)[7].m_object)(
      a2,
      v8,
      time_delta,
      current_time);
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
      v6,
      v8);
  }
}
