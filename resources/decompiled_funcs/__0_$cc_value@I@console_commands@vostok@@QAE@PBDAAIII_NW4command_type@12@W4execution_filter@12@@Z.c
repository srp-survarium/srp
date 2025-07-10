void __userpurge vostok::console_commands::cc_value<unsigned int>::cc_value<unsigned int>(
        vostok::console_commands::cc_value<unsigned int> *this@<ecx>,
        int a2@<eax>,
        const char *name,
        unsigned int *value,
        unsigned int min,
        unsigned int max,
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
  *(_DWORD *)(a2 + 64) = value;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)a2;
  *(_DWORD *)a2 = &vostok::console_commands::cc_value<unsigned int>::`vftable';
  *(_DWORD *)(a2 + 68) = min;
  *(_DWORD *)(a2 + 72) = max;
  *(_BYTE *)(a2 + 28) = 1;
}
