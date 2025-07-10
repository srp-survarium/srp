void __cdecl stlp_std::iter_swap<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float> *>(
        vostok::particle::curve_point<float> *__i1,
        vostok::particle::curve_point<float> *__i2)
{
  vostok::particle::curve_point<float> v2; // [esp+8h] [ebp-20h]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}
