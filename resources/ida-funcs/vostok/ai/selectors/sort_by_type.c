BOOL __cdecl vostok::ai::selectors::sort_by_type(
        const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *object1,
        const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *object2)
{
  return object1->second < object2->second;
}
