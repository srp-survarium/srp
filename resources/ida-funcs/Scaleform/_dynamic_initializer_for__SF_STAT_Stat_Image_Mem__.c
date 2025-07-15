Scaleform::StatDesc *Scaleform::_dynamic_initializer_for__SF_STAT_Stat_Image_Mem__()
{
  Scaleform::StatDesc *result; // eax

  Scaleform::StatDescRegistry::RegisterDesc(&Scaleform::StatDescRegistryInstance, &Scaleform::SF_STAT_Stat_Image_Mem);
  result = Stats_pLastDesc;
  Stats_pLastDesc = &Scaleform::SF_STAT_Stat_Image_Mem;
  if ( result )
    result->pNextSibling = &Scaleform::SF_STAT_Stat_Image_Mem;
  else
    Stats_pFirstDesc = &Scaleform::SF_STAT_Stat_Image_Mem;
  return result;
}
