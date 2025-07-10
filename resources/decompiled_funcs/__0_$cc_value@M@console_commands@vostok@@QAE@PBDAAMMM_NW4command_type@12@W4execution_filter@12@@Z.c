int __userpurge vostok::console_commands::cc_value<float>::cc_value<float>@<eax>(
        int result@<eax>,
        int a2@<xmm0>,
        const char *name,
        float *value,
        float max,
        bool serializable,
        vostok::console_commands::command_type command_type,
        vostok::console_commands::execution_filter execution_filter)
{
  int v8; // ecx

  *(_DWORD *)(result + 12) = vostok::console_commands::s_console_command_root;
  *(_DWORD *)(result + 16) = name;
  *(_DWORD *)(result + 20) = command_type;
  *(_DWORD *)(result + 24) = execution_filter;
  *(_BYTE *)(result + 29) = serializable;
  *(_DWORD *)result = stru_95AF78.m_key_bindings[37].m_keyboard;
  *(_DWORD *)(result + 8) = 0;
  *(_BYTE *)(result + 28) = 0;
  *(_DWORD *)(result + 32) = 0;
  v8 = *(_DWORD *)(result + 12);
  if ( v8 )
    *(_DWORD *)(v8 + 8) = result;
  *(_DWORD *)(result + 68) = a2;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)result;
  *(_DWORD *)result = &vostok::console_commands::cc_value<float>::`vftable';
  *(_DWORD *)(result + 64) = value;
  *(float *)(result + 72) = max;
  *(_BYTE *)(result + 28) = 1;
  return result;
}
