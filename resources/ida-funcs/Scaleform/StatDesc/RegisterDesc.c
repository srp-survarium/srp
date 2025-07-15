void __cdecl Scaleform::StatDesc::RegisterDesc(Scaleform::StatDesc *pdesc)
{
  Scaleform::StatDesc *v1; // eax

  Scaleform::StatDescRegistry::RegisterDesc(&Scaleform::StatDescRegistryInstance, pdesc);
  v1 = Stats_pLastDesc;
  Stats_pLastDesc = pdesc;
  if ( v1 )
    v1->pNextSibling = pdesc;
  else
    Stats_pFirstDesc = pdesc;
}
