vostok::variant<32> *__usercall stlp_std::priv::__ucopy_ptrs<vostok::variant<32> *,vostok::variant<32> *>@<eax>(
        vostok::variant<32> *__last@<eax>,
        vostok::variant<32> *__result@<ecx>,
        vostok::variant<32> *__first)
{
  int v4; // ecx
  int v5; // edi
  int v6; // ebx

  v4 = 48;
  v5 = __last - __first;
  if ( v5 > 0 )
  {
    v6 = (char *)__first - (char *)__result;
    do
    {
      if ( __result )
        vostok::variant<32>::variant<32>(
          __result,
          (vostok::variant<32> *)((char *)__result + v6),
          (vostok::variant<32> *)v4);
      ++__result;
      --v5;
    }
    while ( v5 > 0 );
  }
  return __result;
}
