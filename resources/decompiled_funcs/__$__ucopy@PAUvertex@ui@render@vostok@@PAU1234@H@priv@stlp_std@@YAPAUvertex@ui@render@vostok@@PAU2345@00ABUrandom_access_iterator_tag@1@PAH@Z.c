vostok::render::ui::vertex *__usercall stlp_std::priv::__ucopy<vostok::render::ui::vertex *,vostok::render::ui::vertex *,int>@<eax>(
        const vostok::render::ui::vertex *__last@<eax>,
        vostok::render::ui::vertex *__result@<ecx>,
        vostok::render::ui::vertex *__first)
{
  vostok::render::ui::vertex *v3; // esi
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      *__result = *v3;
    --i;
    ++v3;
  }
  return __result;
}
