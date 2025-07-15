void __usercall vostok::render::`anonymous namespace'::add_u8_macro(
        vostok::render::shader_macro *a1@<ecx>,
        int a2@<edi>,
        char *name,
        unsigned __int8 value)
{
  vostok::buffer_string *v4; // ecx
  vostok::buffer_vector<vostok::render::shader_macro> *v5; // [esp-4h] [ebp-22Ch]
  vostok::render::shader_macro valuea; // [esp+8h] [ebp-220h] BYREF

  vostok::render::shader_macro::shader_macro(a1, (int)&valuea);
  if ( valuea.name.m_string.m_begin != name )
  {
    valuea.name.m_string.m_end = valuea.name.m_string.m_begin;
    *valuea.name.m_string.m_begin = 0;
    vostok::buffer_string::operator+=(&valuea.name.m_string, name);
  }
  vostok::fs_new::path_string_impl::assignf(
    &valuea.definition.m_begin,
    v4,
    (vostok::buffer_string *)"%d",
    (const char *)value);
  vostok::buffer_vector<vostok::render::shader_macro>::push_back(v5, a2, &valuea);
}
