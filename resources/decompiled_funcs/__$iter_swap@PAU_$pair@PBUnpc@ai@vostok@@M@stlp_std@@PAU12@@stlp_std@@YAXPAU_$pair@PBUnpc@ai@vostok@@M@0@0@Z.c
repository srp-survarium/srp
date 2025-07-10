void __cdecl stlp_std::iter_swap<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float> *>(
        stlp_std::pair<vostok::ai::npc const *,float> *__i1,
        stlp_std::pair<vostok::ai::npc const *,float> *__i2)
{
  float second; // eax
  stlp_std::pair<vostok::ai::npc const *,float> v3; // [esp+8h] [ebp-10h]

  v3 = *__i1;
  second = __i2->second;
  __i1->first = __i2->first;
  __i1->second = second;
  *__i2 = v3;
}
