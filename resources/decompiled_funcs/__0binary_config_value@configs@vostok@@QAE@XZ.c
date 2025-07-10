void __usercall vostok::configs::binary_config_value::binary_config_value(
        vostok::configs::binary_config_value *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(
    (vostok::platform_pointer_selector<char const ,1>::helper *)(a2 + 8),
    0);
  *(_WORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_WORD *)(a2 + 22) = 0;
}
