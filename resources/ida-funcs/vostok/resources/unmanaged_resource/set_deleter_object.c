void __userpurge vostok::resources::unmanaged_resource::set_deleter_object(
        vostok::resources::unmanaged_resource *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::resources::cook_base *cook,
        unsigned int deallocation_thread_id)
{
  int v4; // edx
  volatile int m_flags; // edx

  v4 = a2[56];
  if ( v4 )
    _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 4), 0xFFFFFFFF);
  a2[56] = this;
  if ( this )
    m_flags = this->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  else
    m_flags = 3;
  a2[33] = m_flags;
  a2[63] = cook;
  if ( this )
    _InterlockedExchangeAdd((volatile signed __int32 *)&this->type, 1u);
}
