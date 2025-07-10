void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> *__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(&__val, __next); --__next )
  {
    *__last = *__next;
    __last = __next;
  }
  *__last = __val;
}
