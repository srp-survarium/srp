void __thiscall Scaleform::GFx::AS2::MovieRoot::NotifyQueueSetFocus(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  unsigned int v6; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v8; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // eax

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v6 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v8 = Data;
    while ( v8->Level )
    {
      ++v6;
      ++v8;
      if ( v6 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v6].pSprite.pObject;
  }
  else
  {
LABEL_5:
    pObject = 0;
  }
  v10 = (int)pObject + 4 * pObject->AvmObjOffset;
  v11 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 124))(v10);
  Scaleform::GFx::AS2::Selection::QueueSetFocus(v11, ch, controllerIdx, fmt);
}
