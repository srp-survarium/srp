void __usercall vostok::resources::quality_increase_functionality::update_current_satisfaction(
        vostok::resources::quality_increase_functionality *this@<ecx>,
        vostok::resources::quality_increase_functionality *a2@<eax>,
        double a3@<st0>)
{
  vostok::resources::memory_type *i; // esi

  for ( i = a2->m_data->memory_types.m_first; i; i = i->m_next )
    vostok::resources::quality_increase_functionality::update_current_satisfaction_for_memory_type(a2, i, a3);
}
