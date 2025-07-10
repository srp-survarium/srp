void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::specified_action *>>(
        stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> __first,
        stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> __last)
{
  int v2; // [esp-Ch] [ebp-D8h] BYREF
  _DWORD v3[53]; // [esp-8h] [ebp-D4h] BYREF

  v3[50] = v3;
  v3[49] = &v2;
  stlp_std::__destroy_range<stlp_std::reverse_iterator<vostok::ai::planning::specified_action *>,vostok::ai::planning::specified_action>(
    __first,
    __last,
    0);
}
