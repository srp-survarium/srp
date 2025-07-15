BOOL __usercall vostok::resources::sorting_predicate::operator()@<eax>(
        const vostok::resources::resource_base *left@<ecx>,
        const vostok::resources::resource_base *right@<eax>)
{
  float m_current_satisfaction; // xmm1_4

  m_current_satisfaction = right->m_current_satisfaction;
  if ( fabs(left->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
    return left->m_current_satisfaction > m_current_satisfaction;
  else
    return left->m_reconstruction_size < right->m_reconstruction_size;
}
