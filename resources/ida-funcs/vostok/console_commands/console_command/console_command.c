void __userpurge vostok::console_commands::console_command::console_command(
        vostok::console_commands::console_command *this@<ecx>,
        int a2@<eax>,
        const char *name,
        bool serializable,
        const vostok::console_commands::command_type command_type,
        const vostok::console_commands::execution_filter execution_filter)
{
  int v6; // ecx

  *(_DWORD *)(a2 + 12) = vostok::console_commands::s_console_command_root;
  *(_DWORD *)(a2 + 16) = name;
  *(_DWORD *)(a2 + 20) = command_type;
  *(_DWORD *)(a2 + 24) = execution_filter;
  *(_BYTE *)(a2 + 29) = serializable;
  *(_DWORD *)a2 = &vostok::console_commands::console_command::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  v6 = *(_DWORD *)(a2 + 12);
  if ( v6 )
    *(_DWORD *)(v6 + 8) = a2;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)a2;
}
