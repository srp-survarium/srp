bool __cdecl vostok::ai::selectors::sort_by_confidence(
        const stlp_std::pair<vostok::ai::npc const *,float> *object1,
        const stlp_std::pair<vostok::ai::npc const *,float> *object2)
{
  return object1->second > object2->second;
}
