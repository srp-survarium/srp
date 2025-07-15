void __userpurge vostok::console_commands::cc_string::cc_string(
        vostok::console_commands::cc_string *this@<ecx>,
        int a2@<eax>,
        const char *name,
        char *value,
        unsigned int size,
        bool serializable,
        vostok::console_commands::command_type command_type,
        vostok::console_commands::execution_filter execution_filter)
{
  int v8; // ecx

  *(_DWORD *)(a2 + 12) = vostok::console_commands::s_console_command_root;
  *(_DWORD *)(a2 + 16) = name;
  *(_DWORD *)(a2 + 20) = command_type;
  *(_DWORD *)(a2 + 24) = execution_filter;
  *(_BYTE *)(a2 + 29) = serializable;
  *(_DWORD *)a2 = stru_95AF78.m_key_bindings[37].m_keyboard;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  v8 = *(_DWORD *)(a2 + 12);
  if ( v8 )
    *(_DWORD *)(v8 + 8) = a2;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)a2;
  *(_DWORD *)a2 = &stru_95AF78.m_key_bindings[42].m_keyboard[1];
  *(_DWORD *)(a2 + 64) = value;
  *(_DWORD *)(a2 + 68) = size;
  *(_BYTE *)(a2 + 28) = 1;
}
