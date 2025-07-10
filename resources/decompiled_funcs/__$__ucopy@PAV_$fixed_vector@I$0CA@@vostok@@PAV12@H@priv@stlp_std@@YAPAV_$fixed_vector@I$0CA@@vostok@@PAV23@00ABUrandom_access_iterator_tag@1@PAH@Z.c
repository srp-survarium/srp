vostok::fixed_vector<unsigned int,32> *__cdecl stlp_std::priv::__ucopy<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32> *,int>(
        vostok::fixed_vector<unsigned int,32> *__first,
        vostok::fixed_vector<unsigned int,32> *__last,
        vostok::fixed_vector<unsigned int,32> *__result)
{
  stlp_std::__false_type v4; // [esp+26h] [ebp-Ah] BYREF
  char v5; // [esp+27h] [ebp-9h]
  int __n; // [esp+28h] [ebp-8h]
  vostok::fixed_vector<unsigned int,32> *__cur; // [esp+2Ch] [ebp-4h]

  __cur = __result;
  for ( __n = __last - __first; __n > 0; --__n )
  {
    v5 = 0;
    v4 = 0;
    stlp_std::_Param_Construct_aux<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
      __cur++,
      __first++,
      &v4);
  }
  return __cur;
}
