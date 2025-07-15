void __userpurge vostok::resources::unmanaged_resource::set_deleter_object(
        vostok::resources::unmanaged_resource *this@<ecx>,
        vostok::resources::cook_base *cook@<eax>,
        unsigned int deallocation_thread_id)
{
  vostok::resources::cook_base *m_deleter; // edx
  vostok::resources::class_id_enum m_class_id; // eax

  m_deleter = this->m_deleter;
  if ( m_deleter )
    _InterlockedExchangeAdd(&m_deleter->m_cook_users_count.m_count, 0xFFFFFFFF);
  this->m_deleter = cook;
  if ( cook )
    m_class_id = cook->m_class_id;
  else
    m_class_id = raw_data_class;
  this->m_class_id = m_class_id;
  this->m_deallocation_thread_id = deallocation_thread_id;
  if ( cook )
    _InterlockedExchangeAdd(&cook->m_cook_users_count.m_count, 1u);
}
