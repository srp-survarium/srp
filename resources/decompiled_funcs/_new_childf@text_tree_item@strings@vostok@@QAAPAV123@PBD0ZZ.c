vostok::strings::text_tree_item *__usercall vostok::strings::text_tree_item::new_childf@<eax>(
        vostok::strings::text_tree_item *this@<ecx>,
        const char *name@<eax>,
        const char *format,
        ...)
{
  vostok::strings::text_tree_item *v3; // esi
  vostok::fixed_string<512> string; // [esp+8h] [ebp-210h] BYREF
  char v6; // [esp+214h] [ebp-4h] BYREF
  va_list argptr; // [esp+220h] [ebp+8h] BYREF

  va_start(argptr, format);
  string.m_begin = string.m_buffer;
  string.m_end = string.m_buffer;
  v3 = vostok::strings::text_tree_item::new_child(this, name, 0);
  string.m_max_end = &v6;
  string.m_buffer[0] = 0;
  vostok::buffer_string::appendf_va_list(&string, format, argptr);
  vostok::strings::text_tree_item::add_column_impl(v3, string.m_begin);
  return v3;
}
