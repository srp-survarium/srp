char __thiscall Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String *ppath)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  unsigned int Size; // edx
  unsigned int v4; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // ecx
  const __m128i *v6; // eax

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v4 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data->Level )
    {
      ++v4;
      ++Data;
      if ( v4 >= Size )
        goto LABEL_9;
    }
    if ( pMovieImpl->MovieLevels.Data.Data[v4].pSprite.pObject )
    {
      v6 = (const __m128i *)pMovieImpl->pMainMovieDef.pObject->GetFileURL(pMovieImpl->pMainMovieDef.pObject);
      Scaleform::String::operator=(ppath, v6);
      if ( Scaleform::GFx::URLBuilder::ExtractFilePath(ppath) )
        return 1;
    }
  }
LABEL_9:
  Scaleform::String::Clear(ppath);
  return 0;
}
