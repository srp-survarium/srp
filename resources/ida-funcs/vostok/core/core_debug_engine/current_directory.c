char *__usercall vostok::core::core_debug_engine::current_directory@<eax>(
        vostok::core::core_debug_engine *this@<ecx>,
        char *a2@<esi>)
{
  return vostok::fs_new::get_current_directory(a2)->m_string.m_begin;
}
