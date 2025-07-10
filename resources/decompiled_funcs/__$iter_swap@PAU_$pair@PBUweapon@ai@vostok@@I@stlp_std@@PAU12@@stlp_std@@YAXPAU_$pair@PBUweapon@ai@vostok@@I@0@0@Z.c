void __cdecl stlp_std::iter_swap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i1,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i2)
{
  unsigned int second; // ecx
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> v3; // [esp+8h] [ebp-10h]

  v3 = *__i1;
  second = __i2->second;
  __i1->first = __i2->first;
  __i1->second = second;
  *__i2 = v3;
}
