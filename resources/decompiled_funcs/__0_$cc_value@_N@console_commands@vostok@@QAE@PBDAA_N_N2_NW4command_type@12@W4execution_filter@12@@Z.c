void __userpurge vostok::console_commands::cc_value<bool>::cc_value<bool>(
        vostok::console_commands::cc_value<bool> *this@<ecx>,
        int a2@<eax>,
        const char *name,
        bool *value,
        bool min,
        vostok::console_commands::command_type max,
        vostok::console_commands::execution_filter serializable,
        const vostok::console_commands::command_type command_type,
        const vostok::console_commands::execution_filter execution_filter)
{
  int v9; // ecx

  *(_DWORD *)(a2 + 12) = vostok::console_commands::s_console_command_root;
  *(_DWORD *)(a2 + 16) = name;
  *(_DWORD *)(a2 + 20) = max;
  *(_DWORD *)(a2 + 24) = serializable;
  *(_BYTE *)(a2 + 29) = min;
  *(_DWORD *)a2 = stru_95AF78.m_key_bindings[37].m_keyboard;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  v9 = *(_DWORD *)(a2 + 12);
  if ( v9 )
    *(_DWORD *)(v9 + 8) = a2;
  *(_DWORD *)(a2 + 64) = value;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)a2;
  *(_DWORD *)a2 = &vostok::console_commands::cc_value<bool>::`vftable';
  *(_BYTE *)(a2 + 68) = 0;
  *(_BYTE *)(a2 + 69) = 1;
  *(_BYTE *)(a2 + 28) = 1;
}
