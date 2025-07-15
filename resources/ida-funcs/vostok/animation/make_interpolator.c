vostok::animation::base_interpolator *__usercall vostok::animation::make_interpolator@<eax>(
        unsigned int type@<eax>,
        vostok::animation::base_interpolator_vtbl *time,
        vostok::animation::base_interpolator_vtbl *epsilon)
{
  const char *v3; // eax
  vostok::animation::base_interpolator *result; // eax
  const char *v5; // eax
  const char *v6; // eax

  if ( type )
  {
    if ( type == 1 )
    {
      v5 = type_info::name(&vostok::animation::linear_interpolator `RTTI Type Descriptor', &__type_info_root_node);
      result = (vostok::animation::base_interpolator *)vostok::resources::allocate_unmanaged_memory(8u, v5);
      if ( result )
      {
        result->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
        result[1].__vftable = time;
      }
    }
    else
    {
      v3 = type_info::name(&vostok::animation::fermi_interpolator `RTTI Type Descriptor', &__type_info_root_node);
      result = (vostok::animation::base_interpolator *)vostok::resources::allocate_unmanaged_memory(0xCu, v3);
      if ( result )
      {
        result[1].__vftable = time;
        result->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::fermi_interpolator::`vftable';
        result[2].__vftable = epsilon;
      }
    }
  }
  else
  {
    v6 = type_info::name(&vostok::animation::instant_interpolator `RTTI Type Descriptor', &__type_info_root_node);
    result = (vostok::animation::base_interpolator *)vostok::resources::allocate_unmanaged_memory(4u, v6);
    if ( result )
      result->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
  }
  return result;
}
