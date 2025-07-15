void __userpurge vostok::resources::inplace_unmanaged_cook::inplace_unmanaged_cook(
        vostok::resources::inplace_unmanaged_cook *this@<esi>,
        vostok::resources::class_id_enum resource_class@<ecx>,
        DWORD creation_thread_id@<eax>,
        vostok::resources::cook_base::reuse_enum reuse_type,
        DWORD allocate_thread_id,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  DWORD CurrentThreadId; // eax

  this->__vftable = (vostok::resources::inplace_unmanaged_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  this->m_cook_users_count.m_count = 0;
  this->m_class_id = resource_class;
  this->m_reuse_type = reuse_type;
  if ( creation_thread_id == -3 )
    creation_thread_id = GetCurrentThreadId();
  this->m_creation_thread_id = creation_thread_id;
  if ( allocate_thread_id == -3 )
    CurrentThreadId = GetCurrentThreadId();
  else
    CurrentThreadId = allocate_thread_id;
  this->m_allocate_thread_id = CurrentThreadId;
  this->m_flags.m_flags = flags.m_flags | 0x10;
  this->m_next = 0;
  this->__vftable = (vostok::resources::inplace_unmanaged_cook_vtbl *)&vostok::resources::inplace_unmanaged_cook::`vftable';
}
