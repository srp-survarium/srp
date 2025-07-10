void __cdecl stlp_std::_Copy_Construct<vostok::variant<32>>(vostok::variant<32> *__p, const vostok::variant<32> *__val)
{
  vostok::variant<32> *v2; // [esp+4h] [ebp-8h]

  v2 = (vostok::variant<32> *)operator new(0x30u, __p);
  if ( v2 )
    vostok::variant<32>::variant<32>(v2, __val);
}
