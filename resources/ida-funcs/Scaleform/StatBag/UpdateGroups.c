void __thiscall Scaleform::StatBag::UpdateGroups(Scaleform::StatBag *this)
{
  if ( !Stats_InitDone )
    Scaleform::StatDesc::InitChildTree();
  if ( !Stats_InitDone )
    Scaleform::StatDesc::InitChildTree();
  if ( Scaleform::StatDescRegistryInstance.IdPageTable[0] )
    Scaleform::StatBag::RecursiveGroupUpdate(
      this,
      (Scaleform::StatDesc::Iterator)Scaleform::StatDescRegistryInstance.DescMem[Scaleform::StatDescRegistryInstance.IdPageTable[0]
                                                                               - 1]);
  else
    Scaleform::StatBag::RecursiveGroupUpdate(this, 0);
}
