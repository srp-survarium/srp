char __usercall vostok::resources::releasing_functionality::release_all_resources@<al>(
        vostok::resources::releasing_functionality *this@<ecx>,
        vostok::resources::releasing_functionality *a2@<edi>)
{
  vostok::resources::memory_type *m_first; // esi
  char i; // bl
  vostok::resources::release_unconditionaly predicate; // [esp+10h] [ebp-4h]

  m_first = a2->m_data->memory_types.m_first;
  for ( i = 1; m_first; m_first = m_first->m_next )
  {
    vostok::resources::releasing_functionality::release_resources_of_memory_type<vostok::resources::release_unconditionaly>(
      m_first,
      a2,
      predicate);
    if ( m_first->resources.m_first )
      i = 0;
  }
  return i;
}
