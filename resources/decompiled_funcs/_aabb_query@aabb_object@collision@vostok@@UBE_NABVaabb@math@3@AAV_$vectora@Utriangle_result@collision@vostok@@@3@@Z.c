char __userpurge vostok::collision::aabb_object::aabb_query@<al>(
        vostok::collision::aabb_object *this@<ecx>,
        const stlp_std::__true_type *a2@<esi>,
        const vostok::math::aabb *aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_result *M_finish; // eax
  vostok::collision::ray_object_result __x; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_aabb.max.x < aabb->min.x
    || this->m_aabb.max.y < aabb->min.y
    || this->m_aabb.max.z < aabb->min.z
    || aabb->max.x < this->m_aabb.min.x
    || aabb->max.y < this->m_aabb.min.y
    || aabb->max.z < this->m_aabb.min.z )
  {
    return 0;
  }
  M_finish = triangles->_M_impl._M_finish;
  __x.object = this;
  __x.distance = NAN;
  if ( M_finish == triangles->_M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)&__x,
      (unsigned __int8 **)triangles,
      (int)M_finish,
      &__x,
      a2,
      (unsigned int)__x.object,
      SLOBYTE(__x.distance));
    return 1;
  }
  else
  {
    if ( M_finish )
    {
      M_finish->object = this;
      M_finish->triangle_id = -1;
    }
    ++triangles->_M_impl._M_finish;
    return 1;
  }
}
