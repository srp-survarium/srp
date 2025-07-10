void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::variant<32> *>>(
        stlp_std::reverse_iterator<vostok::variant<32> *> __first,
        stlp_std::reverse_iterator<vostok::variant<32> *> __last)
{
  int v2; // [esp-Ch] [ebp-44h] BYREF
  _DWORD v3[16]; // [esp-8h] [ebp-40h] BYREF

  v3[13] = v3;
  v3[12] = &v2;
  stlp_std::__destroy_range<stlp_std::reverse_iterator<vostok::variant<32> *>,vostok::variant<32>>(__first, __last, 0);
}
