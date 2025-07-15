void __cdecl stlp_std::_Destroy_Moved_Range<stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *>>(
        stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> __first,
        stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> __last)
{
  int v2; // [esp-Ch] [ebp-90h] BYREF
  _DWORD v3[35]; // [esp-8h] [ebp-8Ch] BYREF

  v3[32] = v3;
  v3[31] = &v2;
  stlp_std::__destroy_mv_srcs<stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *>,vostok::sound::unique_propagator_info>(
    __first,
    __last,
    0);
}
