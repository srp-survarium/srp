Scaleform::StatDesc *Scaleform::_dynamic_initializer_for__SF_STAT_StatGroup_Default__()
{
  Scaleform::StatDesc *result; // eax

  Scaleform::StatDescRegistry::RegisterDesc(&Scaleform::StatDescRegistryInstance, &Scaleform::SF_STAT_StatGroup_Default);
  result = Stats_pLastDesc;
  Stats_pLastDesc = &Scaleform::SF_STAT_StatGroup_Default;
  if ( result )
    result->pNextSibling = &Scaleform::SF_STAT_StatGroup_Default;
  else
    Stats_pFirstDesc = &Scaleform::SF_STAT_StatGroup_Default;
  return result;
}
