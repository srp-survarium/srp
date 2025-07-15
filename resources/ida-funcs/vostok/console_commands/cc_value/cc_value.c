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


void __userpurge vostok::console_commands::cc_value<vostok::math::float3>::cc_value<vostok::math::float3>(
        vostok::console_commands::cc_value<vostok::math::float3> *this@<ecx>,
        int a2@<eax>,
        const char *name,
        vostok::math::float3 *value,
        vostok::math::float3 min,
        vostok::math::float3 max,
        bool serializable,
        vostok::console_commands::command_type command_type,
        vostok::console_commands::execution_filter execution_filter)
{
  int v9; // ecx
  __int64 v10; // xmm0_8
  float z; // edx

  *(_DWORD *)(a2 + 12) = vostok::console_commands::s_console_command_root;
  *(_DWORD *)(a2 + 16) = name;
  *(_DWORD *)(a2 + 20) = command_type;
  *(_BYTE *)(a2 + 29) = serializable;
  *(_DWORD *)a2 = stru_95AF78.m_key_bindings[37].m_keyboard;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 24) = 1;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  v9 = *(_DWORD *)(a2 + 12);
  if ( v9 )
    *(_DWORD *)(v9 + 8) = a2;
  *(_QWORD *)(a2 + 68) = *(_QWORD *)&min.x;
  v10 = *(_QWORD *)&max.x;
  *(_DWORD *)(a2 + 64) = value;
  z = max.z;
  *(_QWORD *)(a2 + 80) = v10;
  vostok::console_commands::s_console_command_root = (vostok::console_commands::console_command *)a2;
  *(_DWORD *)a2 = &stru_95AF78.m_key_bindings[56];
  *(float *)(a2 + 76) = min.z;
  *(float *)(a2 + 88) = z;
  *(_BYTE *)(a2 + 28) = 1;
}


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
