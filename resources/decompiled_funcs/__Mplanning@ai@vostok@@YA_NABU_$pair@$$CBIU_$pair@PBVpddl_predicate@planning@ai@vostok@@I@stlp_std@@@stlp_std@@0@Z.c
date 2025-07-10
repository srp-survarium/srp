BOOL __cdecl vostok::ai::planning::operator<(
        const stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > *predicate1,
        const stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > *predicate2)
{
  return predicate1->second.second < predicate2->second.second;
}
