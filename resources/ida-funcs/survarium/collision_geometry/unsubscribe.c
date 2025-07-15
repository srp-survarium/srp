void __usercall survarium::collision_geometry::unsubscribe(
        survarium::collision_geometry *this@<esi>,
        survarium::collision_geometry_subscriber *subscriber@<edx>)
{
  void **M_finish; // ebx
  void **M_start; // eax
  int i; // ecx
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-1h] BYREF

  M_finish = this->m_subscribers._M_impl._M_finish;
  M_start = this->m_subscribers._M_impl._M_start;
  for ( i = ((char *)M_finish - (char *)M_start) >> 4; i > 0; --i )
  {
    if ( *M_start == subscriber )
      goto LABEL_17;
    if ( *++M_start == subscriber )
      goto LABEL_17;
    if ( *++M_start == subscriber )
      goto LABEL_17;
    if ( *++M_start == subscriber )
      goto LABEL_17;
    ++M_start;
  }
  switch ( M_finish - M_start )
  {
    case 1:
      goto LABEL_15;
    case 2:
LABEL_13:
      if ( *M_start == subscriber )
        goto LABEL_17;
      ++M_start;
LABEL_15:
      if ( *M_start == subscriber )
        goto LABEL_17;
      break;
    case 3:
      if ( *M_start == subscriber )
        goto LABEL_17;
      ++M_start;
      goto LABEL_13;
  }
  M_start = this->m_subscribers._M_impl._M_finish;
LABEL_17:
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_erase(
    &this->m_subscribers._M_impl,
    M_start,
    &__formal);
  if ( this->m_subscribers._M_impl._M_start == this->m_subscribers._M_impl._M_finish )
  {
    this->m_ghost_object->m_physics_world->m_dynamicsWorld->removeCollisionObject(
      this->m_ghost_object->m_physics_world->m_dynamicsWorld,
      this->m_ghost_object->m_bt_object);
    this->m_physics_world = 0;
  }
}
