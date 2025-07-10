void __thiscall Scaleform::GFx::MovieImpl::UnregisterFonts(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  unsigned int v3; // esi
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::FontDesc,2,Scaleform::ArrayDefaultPolicy> *p_RegisteredFonts; // edi
  Scaleform::GFx::MovieDefRootNode *i; // esi
  Scaleform::ArrayDefaultPolicy *v6; // eax

  v3 = 0;
  if ( this->RegisteredFonts.Data.Size )
  {
    p_RegisteredFonts = &this->RegisteredFonts;
    do
    {
      if ( p_RegisteredFonts->Data.Data[v3].pMovieDef.pObject == pdefImpl )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->RegisteredFonts,
          v3);
      else
        ++v3;
    }
    while ( v3 < this->RegisteredFonts.Data.Size );
  }
  for ( i = this->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v6 = this == (Scaleform::GFx::MovieImpl *)-56 ? 0 : &this->MovieLevels.Data.Policy;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v6 )
      break;
    Scaleform::GFx::FontManager::CleanCacheFor(i->pFontManager.pObject, pdefImpl);
  }
  this->Flags2 |= 2u;
}
