void __thiscall Scaleform::GFx::MovieBindProcess::FinishBinding_::_5_::ImagePackVisitor::Visit(
        Scaleform::GFx::MovieBindProcess::FinishBinding::__l5::ImagePackVisitor *this,
        Scaleform::GFx::MovieDef *pmovieDef,
        Scaleform::GFx::ImageResource *presource,
        Scaleform::GFx::ResourceId rid,
        char *pexportName)
{
  const Scaleform::GFx::ASString *v6; // eax
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *pTempBindData; // esi
  int v8; // eax
  int v9; // eax
  bool v10; // bl
  int v11; // eax
  int v12; // eax
  bool v13; // al

  v6 = (const Scaleform::GFx::ASString *)this->pImagePacker->GetResourceDataNode(this->pImagePacker, presource);
  pTempBindData = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)this->pTempBindData;
  v8 = Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::findIndex<unsigned int>(
         pTempBindData,
         v6 + 2);
  if ( v8 < 0 )
    v9 = 0;
  else
    v9 = (int)&pTempBindData->pTable[2] + 12 * v8;
  v10 = v9 == 0;
  v13 = 0;
  if ( pexportName )
  {
    strstr((unsigned __int8 *)pexportName, "-forcepack");
    if ( v11 || (strstr((unsigned __int8 *)pexportName, ".forcepack"), v12) )
      v13 = 1;
  }
  if ( v10 || v13 )
    this->pImagePacker->AddImageFromResource(this->pImagePacker, presource, pexportName);
}
