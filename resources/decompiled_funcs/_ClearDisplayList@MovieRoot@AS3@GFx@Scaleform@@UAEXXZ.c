void __thiscall Scaleform::GFx::AS3::MovieRoot::ClearDisplayList(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // edi

  pMainMovie = this->pMovieImpl->pMainMovie;
  Scaleform::GFx::DisplayList::Clear((Scaleform::GFx::DisplayList *)&pMainMovie[1], pMainMovie);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pMainMovie);
  this->pMovieImpl->pMainMovie->OnEventUnload(this->pMovieImpl->pMainMovie);
  this->pMovieImpl->pMainMovie->ForceShutdown(this->pMovieImpl->pMainMovie);
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->pMovieImpl->MovieLevels.Data,
    &this->pMovieImpl->MovieLevels,
    0);
}
