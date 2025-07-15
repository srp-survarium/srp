void __usercall survarium::animation_analysis_result::~animation_analysis_result(
        survarium::animation_analysis_result *this@<ecx>,
        const char *a2@<esi>)
{
  void **p_m_buffer; // ebx
  char *m_buffer; // eax
  const char *v5; // [esp+0h] [ebp-8h]
  unsigned int v6; // [esp+4h] [ebp-4h]

  this->__vftable = (survarium::animation_analysis_result_vtbl *)&survarium::animation_analysis_result::`vftable';
  p_m_buffer = &this->m_buffer;
  this->m_leg_key_times.m_end = this->m_leg_key_times.m_begin;
  m_buffer = (char *)this->m_buffer;
  if ( m_buffer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      m_buffer,
      a2,
      v5,
      v6);
    *p_m_buffer = 0;
  }
  this->m_leg_key_times.m_end = this->m_leg_key_times.m_begin;
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
