vostok::render::geometry_batch *__usercall stlp_std::priv::__ucopy<vostok::render::geometry_batch *,vostok::render::geometry_batch *,int>@<eax>(
        vostok::render::geometry_batch *__last@<eax>,
        vostok::render::geometry_batch *__result@<ecx>,
        vostok::render::geometry_batch *__first)
{
  vostok::render::geometry_batch *v3; // ebx
  int i; // esi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::geometry_batch::geometry_batch(v3, (int)__result);
    --i;
    ++v3;
  }
  return __result;
}
