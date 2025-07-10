void __usercall stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        vostok::render::shader_constant *__last@<edx>,
        vostok::render::shader_constant *__result@<eax>,
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  unsigned int v5; // edx

  if ( __result )
    *__result = *__first;
  v5 = (int)((unsigned __int64)(715827883LL * ((char *)__last - (char *)__first)) >> 32) >> 2;
  stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}
