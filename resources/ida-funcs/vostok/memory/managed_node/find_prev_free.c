vostok::memory::managed_node *__usercall vostok::memory::managed_node::find_prev_free@<eax>(
        vostok::memory::managed_node *this@<ecx>,
        int a2@<eax>)
{
  vostok::memory::managed_node *result; // eax

  for ( result = *(vostok::memory::managed_node **)(a2 + 8); result; result = result->m_prev )
  {
    if ( result->m_type == 1 )
      break;
  }
  return result;
}
