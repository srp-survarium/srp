survarium::static_collision *__usercall vostok::memory::new_array_helper<survarium::static_collision>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  survarium::static_collision *result; // eax
  survarium::static_collision *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 76 * count + 8);
  *(_DWORD *)v2 = count;
  result = (survarium::static_collision *)(v2 + 8);
  result[-1].physics_rigid_body_ = (vostok::physics::bt_static_rigid_body *)76;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->shape_.m_object = 0;
  }
  return result;
}
