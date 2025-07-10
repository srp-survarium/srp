void __cdecl stlp_std::__make_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &),stlp_std::pair<vostok::ai::npc const *,float>,int>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v3[3]; // [esp-Ch] [ebp-20h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *v4; // [esp+0h] [ebp-14h]
  _DWORD *v5; // [esp+4h] [ebp-10h]
  int __parent; // [esp+Ch] [ebp-8h]
  int __len; // [esp+10h] [ebp-4h]

  if ( __last - __first >= 2 )
  {
    __len = __last - __first;
    for ( __parent = (__len - 2) / 2; ; --__parent )
    {
      v3[2] = __comp;
      v4 = &__first[__parent];
      v5 = v3;
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        __first,
        __parent,
        __len,
        *v4,
        __comp);
      if ( !__parent )
        break;
    }
  }
}
