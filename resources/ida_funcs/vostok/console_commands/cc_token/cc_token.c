void __userpurge vostok::console_commands::cc_token::cc_token(
        vostok::console_commands::cc_token *this@<ecx>,
        int a2@<eax>,
        const char *name,
        unsigned int *value,
        const vostok::console_commands::command_token *commands,
        unsigned int size,
        bool serializable,
        vostok::console_commands::command_type command_type,
        vostok::console_commands::execution_filter execution_filter)
{
  int v9; // ecx

  *(_DWORD *)(a2 + 12) = vostok::console_commands::s_console_command_root;
  *(_DWORD *)(a2 + 16) = name;
  *(_DWORD *)(a2 + 20) = command_type;
  *(_DWORD *)(a2 + 24) = execution_filter;
  *(_BYTE *)(a2 + 29) = serializable;
  *(_DWORD *)a2 = stru_95AF78.m_key_bindings[37].m_keyboard;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  v9 = *(_DWORD *)(a2 + 12);
  if ( v9 )
    *(_DWORD *)(v9 + 8) = a2;
  *(_DWORD *)(a2 + 64) = commands;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)a2;
  *(_DWORD *)a2 = &stru_95AF78.m_key_bindings[58].m_keyboard[1];
  *(_DWORD *)(a2 + 68) = size;
  *(_DWORD *)(a2 + 72) = value;
}
