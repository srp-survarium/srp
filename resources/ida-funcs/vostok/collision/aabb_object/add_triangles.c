void __thiscall vostok::collision::aabb_object::add_triangles(
        vostok::collision::aabb_object *this,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_result *M_finish; // eax
  const stlp_std::__true_type *v3; // [esp+0h] [ebp-Ch]
  vostok::collision::ray_object_result __x; // [esp+4h] [ebp-8h] BYREF

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
      v3,
      (unsigned int)__x.object,
      SLOBYTE(__x.distance));
  }
  else
  {
    if ( M_finish )
    {
      M_finish->object = this;
      M_finish->triangle_id = -1;
    }
    ++triangles->_M_impl._M_finish;
  }
}
