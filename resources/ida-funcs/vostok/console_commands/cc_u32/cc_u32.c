void __userpurge vostok::console_commands::cc_u32::cc_u32(
        vostok::console_commands::cc_u32 *this@<ecx>,
        int a2@<eax>,
        const char *name,
        unsigned int *value,
        const unsigned int min,
        const unsigned int max,
        bool serializable,
        const vostok::console_commands::command_type command_type,
        const vostok::console_commands::execution_filter execution_filter)
{
  int v9; // eax

  vostok::console_commands::console_command::console_command(
    this,
    a2,
    name,
    serializable,
    command_type,
    execution_filter_general);
  *(_DWORD *)(v9 + 64) = value;
  *(_DWORD *)(v9 + 68) = min;
  *(_DWORD *)(v9 + 72) = max;
  *(_BYTE *)(v9 + 28) = 1;
  *(_DWORD *)v9 = &vostok::console_commands::cc_u32::`vftable';
}
