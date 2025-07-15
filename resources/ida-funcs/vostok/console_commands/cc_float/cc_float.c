void __userpurge vostok::console_commands::cc_float::cc_float(
        vostok::console_commands::cc_float *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>,
        const char *name,
        float *value,
        float max,
        BOOL serializable,
        vostok::console_commands::command_type command_type,
        enum vostok::console_commands::command_type a9,
        enum vostok::console_commands::execution_filter a10)
{
  int v10; // eax

  vostok::console_commands::console_command::console_command(
    this,
    a2,
    name,
    serializable,
    command_type,
    execution_filter_general);
  *(_DWORD *)(v10 + 68) = a3;
  *(_DWORD *)(v10 + 64) = value;
  *(float *)(v10 + 72) = max;
  *(_BYTE *)(v10 + 28) = 1;
  *(_DWORD *)v10 = &vostok::console_commands::cc_float::`vftable';
}
