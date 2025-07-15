void __cdecl stlp_std::__pop_heap_aux<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  float second; // eax
  int v5; // [esp-Ch] [ebp-28h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> v6; // [esp+0h] [ebp-1Ch] BYREF
  int *v7; // [esp+8h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *v8; // [esp+10h] [ebp-Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *v9; // [esp+14h] [ebp-8h]

  v8 = __last - 1;
  v9 = &v6;
  v6 = __last[-1];
  second = __first->second;
  __last[-1].first = __first->first;
  __last[-1].second = second;
  v7 = &v5;
  stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
    __first,
    0,
    &__last[-1] - __first,
    v6,
    __comp);
}


void __cdecl stlp_std::__pop_heap_aux<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  unsigned int second; // ecx
  int v5; // [esp-Ch] [ebp-28h] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> v6; // [esp+0h] [ebp-1Ch] BYREF
  int *v7; // [esp+8h] [ebp-14h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v8; // [esp+10h] [ebp-Ch]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v9; // [esp+14h] [ebp-8h]

  v8 = __last - 1;
  v9 = &v6;
  v6 = __last[-1];
  second = __first->second;
  __last[-1].first = __first->first;
  __last[-1].second = second;
  v7 = &v5;
  stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,int,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
    __first,
    0,
    &__last[-1] - __first,
    v6,
    __comp);
}
