vostok::render::culling::aab_rect *__fastcall stlp_std::priv::__ucopy<vostok::render::culling::aab_rect *,vostok::render::culling::aab_rect *,int>(
        vostok::render::culling::aab_rect *__first,
        vostok::render::culling::aab_rect *__last,
        vostok::render::culling::aab_rect *__result)
{
  vostok::render::culling::aab_rect *result; // eax
  int i; // edx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
      *result = *__first;
    --i;
    ++__first;
  }
  return result;
}
