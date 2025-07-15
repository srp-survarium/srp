char __thiscall Scaleform::GFx::AS3::MovieRoot::GetRootFilePath(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::String *ppath)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  const __m128i *v4; // eax

  pMovieImpl = this->pMovieImpl;
  if ( pMovieImpl->pMainMovie )
  {
    v4 = (const __m128i *)pMovieImpl->pMainMovieDef.pObject->GetFileURL(pMovieImpl->pMainMovieDef.pObject);
    Scaleform::String::operator=(ppath, v4);
    if ( Scaleform::GFx::URLBuilder::ExtractFilePath(ppath) )
      return 1;
  }
  Scaleform::String::Clear(ppath);
  return 0;
}
