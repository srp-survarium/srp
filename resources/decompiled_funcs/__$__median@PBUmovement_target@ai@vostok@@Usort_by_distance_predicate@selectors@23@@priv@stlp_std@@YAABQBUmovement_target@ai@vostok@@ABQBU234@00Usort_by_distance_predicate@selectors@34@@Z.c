const vostok::ai::movement_target **__cdecl stlp_std::priv::__median<vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__a,
        const vostok::ai::movement_target **__b,
        const vostok::ai::movement_target **__c,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__a, *__b) )
  {
    if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__b, *__c) )
    {
      return __b;
    }
    else if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__a, *__c) )
    {
      return __c;
    }
    else
    {
      return __a;
    }
  }
  else if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__a, *__c) )
  {
    return __a;
  }
  else if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__b, *__c) )
  {
    return __c;
  }
  else
  {
    return __b;
  }
}
