void __thiscall Scaleform::GFx::AS2::MovieRoot::ClearDisplayList(Scaleform::GFx::AS2::MovieRoot *this)
{
  unsigned int i; // ebx
  Scaleform::GFx::InteractiveObject *pObject; // esi
  unsigned int j; // esi
  Scaleform::GFx::InteractiveObject *v5; // ecx

  for ( i = this->pMovieImpl->MovieLevels.Data.Size; i; --i )
  {
    pObject = this->pMovieImpl->MovieLevels.Data.Data[i - 1].pSprite.pObject;
    Scaleform::GFx::DisplayList::Clear((Scaleform::GFx::DisplayList *)&pObject[1], pObject);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pObject);
  }
  for ( j = this->pMovieImpl->MovieLevels.Data.Size; j; --j )
  {
    v5 = this->pMovieImpl->MovieLevels.Data.Data[j - 1].pSprite.pObject;
    v5->ForceShutdown(v5);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->pMovieImpl->MovieLevels.Data,
    &this->pMovieImpl->MovieLevels,
    0);
}
