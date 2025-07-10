char *__thiscall vostok::core::core_debug_engine::current_directory(vostok::core::core_debug_engine *this)
{
  return vostok::fs_new::get_current_directory()->m_string.m_begin;
}
