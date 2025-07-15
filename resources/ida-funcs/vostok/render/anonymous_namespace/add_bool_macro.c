void __usercall vostok::render::`anonymous namespace'::add_bool_macro(
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros@<eax>,
        vostok::render::shader_macro *a2@<ecx>,
        char *name,
        bool flag)
{
  const vostok::render::shader_macro *v5; // eax
  vostok::buffer_vector<vostok::render::shader_macro> *v6; // ecx
  vostok::render::shader_macro *v7; // eax
  char *m_begin; // ecx
  char *v9; // edx
  vostok::buffer_string *p_definition; // eax
  char *v11; // ecx
  _BYTE v12[544]; // [esp+8h] [ebp-220h] BYREF

  vostok::render::shader_macro::shader_macro(a2, (int)v12);
  vostok::buffer_vector<vostok::render::shader_macro>::push_back(v6, (int)macros, v5);
  v7 = macros->m_end - 1;
  m_begin = v7->name.m_string.m_begin;
  if ( v7->name.m_string.m_begin != name )
  {
    v7->name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&v7->name.m_string, name);
  }
  v9 = "1";
  if ( !flag )
    v9 = "0";
  p_definition = &macros->m_end[-1].definition;
  v11 = p_definition->m_begin;
  if ( p_definition->m_begin != v9 )
  {
    p_definition->m_end = v11;
    *v11 = 0;
    vostok::buffer_string::operator+=(p_definition, v9);
  }
}
