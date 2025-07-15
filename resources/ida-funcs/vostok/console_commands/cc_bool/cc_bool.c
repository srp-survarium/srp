void __userpurge vostok::console_commands::cc_bool::cc_bool(
        vostok::console_commands::cc_bool *this@<ecx>,
        int a2@<eax>,
        const char *name,
        bool *value,
        bool serializable,
        const vostok::console_commands::command_type command_type,
        const vostok::console_commands::execution_filter execution_filter)
{
  int v7; // eax

  vostok::console_commands::console_command::console_command(
    this,
    a2,
    name,
    serializable,
    command_type,
    execution_filter_general);
  *(_DWORD *)(v7 + 64) = value;
  *(_BYTE *)(v7 + 68) = 0;
  *(_BYTE *)(v7 + 69) = 1;
  *(_DWORD *)v7 = &vostok::console_commands::cc_bool::`vftable';
  *(_BYTE *)(v7 + 28) = 1;
}
