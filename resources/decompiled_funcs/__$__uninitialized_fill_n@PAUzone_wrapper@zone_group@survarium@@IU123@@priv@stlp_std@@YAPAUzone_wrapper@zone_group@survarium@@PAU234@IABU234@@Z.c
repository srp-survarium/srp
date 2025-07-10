survarium::zone_group::zone_wrapper *__cdecl stlp_std::priv::__uninitialized_fill_n<survarium::zone_group::zone_wrapper *,unsigned int,survarium::zone_group::zone_wrapper>(
        survarium::zone_group::zone_wrapper *__first,
        unsigned int __n,
        const survarium::zone_group::zone_wrapper *__x)
{
  int v4; // [esp+4h] [ebp-18h]
  int i; // [esp+Ch] [ebp-10h]
  survarium::zone_group::zone_wrapper *v6; // [esp+10h] [ebp-Ch]

  v6 = __first;
  for ( i = (int)(8 * __n) >> 3; i > 0; --i )
  {
    v4 = *(_DWORD *)&__x->active;
    v6->zone = __x->zone;
    *(_DWORD *)&v6->active = v4;
    ++v6;
  }
  return &__first[__n];
}
