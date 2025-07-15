Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
        Scaleform::GFx::AS2::MovieRoot *this,
        int level)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v4; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v4 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level != level; ++i )
  {
    if ( ++v4 >= Size )
      return 0;
  }
  return (Scaleform::GFx::Sprite *)Data[v4].pSprite.pObject;
}
