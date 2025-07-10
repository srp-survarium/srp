void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>>(
        stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> __first,
        stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> __last)
{
  int v2; // [esp-Ch] [ebp-40h] BYREF
  _DWORD v3[15]; // [esp-8h] [ebp-3Ch] BYREF

  v3[12] = v3;
  v3[11] = &v2;
  stlp_std::__destroy_mv_srcs<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>,vostok::fixed_vector<unsigned int,32>>(
    __first,
    __last,
    0);
}
