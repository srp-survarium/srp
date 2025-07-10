char __thiscall Scaleform::GFx::AS3::MovieRoot::GetRootFilePath(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::String *ppath)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  char *v4; // eax

  pMovieImpl = this->pMovieImpl;
  if ( pMovieImpl->pMainMovie )
  {
    v4 = (char *)pMovieImpl->pMainMovieDef.pObject->GetFileURL(pMovieImpl->pMainMovieDef.pObject);
    Scaleform::String::operator=(ppath, v4);
    if ( Scaleform::GFx::URLBuilder::ExtractFilePath(ppath) )
      return 1;
  }
  Scaleform::String::Clear(ppath);
  return 0;
}
