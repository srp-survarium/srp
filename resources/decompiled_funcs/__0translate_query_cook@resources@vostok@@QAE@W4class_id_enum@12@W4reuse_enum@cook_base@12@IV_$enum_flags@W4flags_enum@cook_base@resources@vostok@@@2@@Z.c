void __thiscall vostok::resources::translate_query_cook::translate_query_cook(
        vostok::resources::translate_query_cook *this,
        vostok::resources::class_id_enum resource_class,
        vostok::resources::cook_base::reuse_enum reuse_type,
        DWORD translate_query_thread,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  DWORD CurrentThreadId; // eax

  this->__vftable = (vostok::resources::translate_query_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  this->m_cook_users_count.m_count = 0;
  this->m_class_id = resource_class;
  CurrentThreadId = translate_query_thread;
  this->m_reuse_type = reuse_type;
  this->m_creation_thread_id = -1;
  if ( translate_query_thread == -3 )
    CurrentThreadId = GetCurrentThreadId();
  this->m_allocate_thread_id = CurrentThreadId;
  this->m_flags.m_flags = flags.m_flags | 8;
  this->m_next = 0;
  this->__vftable = (vostok::resources::translate_query_cook_vtbl *)&vostok::resources::translate_query_cook::`vftable';
}
