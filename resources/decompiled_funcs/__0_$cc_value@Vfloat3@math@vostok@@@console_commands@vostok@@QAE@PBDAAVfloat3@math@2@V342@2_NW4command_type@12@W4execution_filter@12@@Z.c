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
