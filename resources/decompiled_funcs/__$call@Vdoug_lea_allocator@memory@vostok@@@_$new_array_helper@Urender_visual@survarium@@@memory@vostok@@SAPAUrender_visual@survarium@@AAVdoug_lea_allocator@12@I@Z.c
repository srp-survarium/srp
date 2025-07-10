survarium::render_visual *__usercall vostok::memory::new_array_helper<survarium::render_visual>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  survarium::render_visual *result; // eax
  survarium::render_visual *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 68 * count + 8);
  *(_DWORD *)v2 = count;
  result = (survarium::render_visual *)(v2 + 8);
  result[-1].model.m_object = (vostok::render::static_model_instance *)68;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->model.m_object = 0;
  }
  return result;
}
