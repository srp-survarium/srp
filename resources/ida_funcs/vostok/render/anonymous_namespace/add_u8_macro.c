void __usercall vostok::render::`anonymous namespace'::add_u8_macro(
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros@<edi>,
        char *name@<ecx>,
        unsigned __int8 value)
{
  char *m_buffer; // eax
  bool v4; // zf
  vostok::render::shader_macro *m_end; // esi
  vostok::render::shader_macro macro; // [esp+8h] [ebp-220h] BYREF
  _UNKNOWN *retaddr; // [esp+228h] [ebp+0h] BYREF

  macro.name.m_string.m_begin = macro.name.m_string.m_buffer;
  macro.name.m_string.m_end = macro.name.m_string.m_buffer;
  macro.name.m_string.m_max_end = &macro.name.m_separator;
  macro.definition.m_end = macro.definition.m_buffer;
  macro.definition.m_begin = macro.definition.m_buffer;
  m_buffer = macro.name.m_string.m_buffer;
  macro.name.m_string.m_buffer[0] = 0;
  macro.name.m_separator = 47;
  macro.definition.m_max_end = (char *)&retaddr;
  macro.definition.m_buffer[0] = 0;
  if ( macro.name.m_string.m_buffer != name )
  {
    macro.name.m_string.m_end = macro.name.m_string.m_buffer;
    macro.name.m_string.m_buffer[0] = 0;
    if ( name )
    {
      if ( *name )
      {
        do
        {
          if ( m_buffer >= macro.name.m_string.m_max_end )
            break;
          *m_buffer = *name;
          m_buffer = macro.name.m_string.m_end + 1;
          v4 = *++name == 0;
          ++macro.name.m_string.m_end;
        }
        while ( !v4 );
      }
      *m_buffer = 0;
    }
  }
  vostok::buffer_string::assignf(&macro.definition, "%d", value);
  m_end = macros->m_end;
  if ( m_end )
    vostok::render::shader_macro::shader_macro(m_end, &macro);
  ++macros->m_end;
}
