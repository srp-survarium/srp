void __cdecl stlp_std::_Param_Construct<vostok::fixed_string<16>,vostok::fixed_string<16>>(
        vostok::fixed_string<16> *__p,
        const vostok::fixed_string<16> *__val)
{
  vostok::fixed_string<16> *v2; // [esp+20h] [ebp-8h]

  v2 = (vostok::fixed_string<16> *)operator new(0x1Cu, (void *)__p);
  if ( v2 )
    vostok::fixed_string<16>::fixed_string<16>(v2, __val);
}
