void __cdecl stlp_std::_Param_Construct<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
        vostok::fixed_vector<unsigned int,32> *__p,
        const vostok::fixed_vector<unsigned int,32> *__val)
{
  stlp_std::__false_type __formal; // [esp+26h] [ebp-2h] BYREF
  char v3; // [esp+27h] [ebp-1h]

  v3 = 0;
  __formal = 0;
  stlp_std::_Param_Construct_aux<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
    __p,
    __val,
    &__formal);
}
