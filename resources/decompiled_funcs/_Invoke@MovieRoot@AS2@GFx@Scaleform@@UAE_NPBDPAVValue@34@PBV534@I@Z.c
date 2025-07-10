int __thiscall Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // esi
  unsigned int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v9; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v7 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v9 = Data;
    while ( v9->Level )
    {
      ++v7;
      ++v9;
      if ( v7 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v7].pSprite.pObject;
  }
  else
  {
LABEL_5:
    pObject = 0;
  }
  return ((int (__thiscall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::InteractiveObject *, const char *, Scaleform::GFx::Value *, const Scaleform::GFx::Value *, unsigned int))this->Invoke)(
           this,
           pObject,
           pmethodName,
           presult,
           pargs,
           numArgs);
}
