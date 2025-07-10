char __thiscall Scaleform::GFx::AS3::MovieRoot::FindLibrarySymbolInAllABCs(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dobj,
        Scaleform::GFx::CharacterCreateInfo *pccinfo)
{
  Scaleform::GFx::MovieDefRootNode *i; // esi
  Scaleform::ArrayDefaultPolicy *v5; // eax

  for ( i = this->pMovieImpl->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v5 = this->pMovieImpl == (Scaleform::GFx::MovieImpl *)-56 ? 0 : &this->pMovieImpl->MovieLevels.Data.Policy;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v5 )
      break;
    if ( Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(dobj, pccinfo, i->pDefImpl) )
      return 1;
  }
  return 0;
}
