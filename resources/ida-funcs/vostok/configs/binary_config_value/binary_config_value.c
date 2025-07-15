void __usercall vostok::configs::binary_config_value::binary_config_value(
        vostok::configs::binary_config_value *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_WORD *)(a2 + 20) = 0;
  *(_WORD *)(a2 + 22) = 0;
}
