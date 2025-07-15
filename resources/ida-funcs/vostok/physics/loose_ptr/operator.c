vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *__userpurge vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator=@<eax>(
        const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *object@<edi>,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *a2@<ecx>,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *this)
{
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v3; // ebx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **v4; // eax
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v5; // ecx

  v3 = this;
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>(
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&this,
    object,
    a2);
  v5 = *v4;
  *v4 = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v3->m_object;
  v3->m_object = (vostok::physics::loose_ptr_data *)v5;
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::dec(
    v5,
    (int *)&this);
  return v3;
}


bool __userpurge vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator==@<al>(
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *this@<ecx>,
        int **a2@<eax>,
        const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *object)
{
  int v3; // eax
  vostok::physics::loose_ptr_base *v4; // ecx
  vostok::physics::loose_ptr_base *m_pointer; // eax
  vostok::physics::loose_ptr_base *v6; // eax

  v3 = **a2;
  if ( v3 )
    v4 = (vostok::physics::loose_ptr_base *)(v3 - 4);
  else
    v4 = 0;
  m_pointer = object->m_object->m_pointer;
  if ( m_pointer )
    v6 = m_pointer - 1;
  else
    v6 = 0;
  return v4 == v6;
}


bool __userpurge vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator==@<al>(
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *this@<ecx>,
        int **a2@<eax>,
        const vostok::physics::base_physics_object *const object)
{
  int v3; // eax
  const vostok::physics::base_physics_object *v4; // eax

  v3 = **a2;
  if ( v3 )
    v4 = (const vostok::physics::base_physics_object *)(v3 - 4);
  else
    v4 = 0;
  return v4 == object;
}
