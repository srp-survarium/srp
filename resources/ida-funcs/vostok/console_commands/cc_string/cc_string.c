void __userpurge vostok::console_commands::cc_string::cc_string(
        vostok::console_commands::cc_string *this@<ecx>,
        int a2@<eax>,
        const char *name,
        char *value,
        unsigned int size,
        bool serializable,
        const vostok::console_commands::command_type command_type,
        const vostok::console_commands::execution_filter execution_filter)
{
  int v8; // eax

  vostok::console_commands::console_command::console_command(
    this,
    a2,
    name,
    1,
    command_type_user_specific,
    execution_filter_general);
  *(_DWORD *)(v8 + 64) = value;
  *(_DWORD *)v8 = &vostok::console_commands::cc_string::`vftable';
  *(_DWORD *)(v8 + 68) = size;
  *(_BYTE *)(v8 + 28) = 1;
}
