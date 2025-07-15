void __userpurge vostok::console_commands::cc_float3::cc_float3(
        vostok::console_commands::cc_float3 *this@<ecx>,
        int a2@<eax>,
        const char *name,
        vostok::math::float3 *value,
        vostok::math::float3 min,
        vostok::math::float3 max,
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
  *(vostok::math::float3 *)(v9 + 68) = min;
  *(vostok::math::float3 *)(v9 + 80) = max;
  *(_DWORD *)(v9 + 64) = value;
  *(_BYTE *)(v9 + 28) = 1;
  *(_DWORD *)v9 = &vostok::console_commands::cc_float3::`vftable';
}
