void __cdecl stlp_std::priv::__linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v4[8]; // [esp-Ch] [ebp-20h] BYREF

  if ( __comp(&__val, __first) )
  {
    stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
      (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
      (vostok::particle::curve_point<vostok::math::float4_pod> *)__last,
      (vostok::particle::curve_point<vostok::math::float4_pod> *)&__last[1]);
    *__first = __val;
  }
  else
  {
    v4[3] = v4;
    stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      (stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)__last,
      (stlp_std::pair<vostok::ai::weapon const *,unsigned int>)__val,
      (bool (__cdecl *)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))__comp);
  }
}
