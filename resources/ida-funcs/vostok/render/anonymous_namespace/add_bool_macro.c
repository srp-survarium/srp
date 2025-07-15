void __usercall vostok::render::`anonymous namespace'::add_bool_macro(
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros@<edi>,
        char *name,
        bool flag)
{
  vostok::render::shader_macro *m_end; // esi
  vostok::render::shader_macro *v4; // esi
  char *m_begin; // eax
  survarium::keyboard_key_descr **m_keyboard; // edx
  vostok::render::shader_macro *v7; // ecx
  char *v8; // eax
  vostok::buffer_string *p_definition; // ecx
  vostok::render::shader_macro __that; // [esp+10h] [ebp-224h] BYREF
  char v11; // [esp+230h] [ebp-4h] BYREF

  __that.name.m_string.m_begin = __that.name.m_string.m_buffer;
  m_end = macros->m_end;
  __that.name.m_string.m_end = __that.name.m_string.m_buffer;
  __that.name.m_string.m_max_end = &__that.name.m_separator;
  __that.name.m_string.m_buffer[0] = 0;
  __that.name.m_separator = 47;
  __that.definition.m_begin = __that.definition.m_buffer;
  __that.definition.m_end = __that.definition.m_buffer;
  __that.definition.m_max_end = &v11;
  __that.definition.m_buffer[0] = 0;
  if ( m_end )
    vostok::render::shader_macro::shader_macro(m_end, &__that);
  v4 = macros->m_end++;
  m_begin = v4->name.m_string.m_begin;
  if ( v4->name.m_string.m_begin != name )
  {
    v4->name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&v4->name.m_string, name);
  }
  m_keyboard = stru_95AF78.m_key_bindings[5].m_keyboard;
  if ( !flag )
    m_keyboard = &stru_95AF78.m_key_bindings[6].m_keyboard[1];
  v7 = macros->m_end;
  v8 = v7[-1].definition.m_begin;
  p_definition = &v7[-1].definition;
  if ( v8 != (char *)m_keyboard )
  {
    p_definition->m_end = v8;
    *v8 = 0;
    vostok::buffer_string::operator+=(p_definition, (const char *)m_keyboard);
  }
}
