char __thiscall vostok::collision::aabb_object::cuboid_query(
        vostok::collision::aabb_object *this,
        const vostok::math::cuboid *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_result *M_finish; // eax
  const stlp_std::__true_type *v6; // [esp+0h] [ebp-Ch]
  vostok::collision::ray_object_result __x; // [esp+4h] [ebp-8h] BYREF

  if ( vostok::math::cuboid::test_inexact((vostok::math::cuboid *)this, &this->m_aabb) == intersection_outside )
    return 0;
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
      v6,
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
