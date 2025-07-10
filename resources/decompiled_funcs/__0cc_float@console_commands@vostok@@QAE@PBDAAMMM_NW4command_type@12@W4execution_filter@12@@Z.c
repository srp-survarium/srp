_DWORD *__userpurge vostok::console_commands::cc_float::cc_float@<eax>(
        vostok::console_commands::command_type command_type@<ecx>,
        vostok::console_commands::execution_filter a2@<eax>,
        _DWORD *a3@<esi>,
        int a4@<xmm0>,
        const char *name,
        float *value,
        float max,
        BOOL serializable,
        bool a9,
        enum vostok::console_commands::command_type a10,
        enum vostok::console_commands::execution_filter a11)
{
  vostok::console_commands::cc_value<float>::cc_value<float>(
    (int)a3,
    a4,
    name,
    value,
    max,
    serializable,
    command_type,
    a2);
  *a3 = &stru_95AF78.m_key_bindings[48];
  return a3;
}
