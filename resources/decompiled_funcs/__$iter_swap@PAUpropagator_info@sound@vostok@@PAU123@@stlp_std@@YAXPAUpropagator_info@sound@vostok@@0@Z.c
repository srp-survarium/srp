void __cdecl stlp_std::iter_swap<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(
        vostok::sound::propagator_info *__i1,
        vostok::sound::propagator_info *__i2)
{
  vostok::sound::propagator_info v2; // [esp+8h] [ebp-1Ch]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}
