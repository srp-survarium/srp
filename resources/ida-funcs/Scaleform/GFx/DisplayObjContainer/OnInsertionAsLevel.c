void __thiscall Scaleform::GFx::DisplayObjContainer::OnInsertionAsLevel(
        Scaleform::GFx::DisplayObjContainer *this,
        int level)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  unsigned int Flags; // eax
  int v5; // eax

  if ( level )
  {
    if ( level > 0 )
    {
      pMainMovie = this->pASRoot->pMovieImpl->pMainMovie;
      if ( pMainMovie )
      {
        if ( pMainMovie->IsFocusRectEnabled(pMainMovie) )
          this->Scaleform::GFx::InteractiveObject::Flags |= 0x180u;
        else
          this->Scaleform::GFx::InteractiveObject::Flags = this->Scaleform::GFx::InteractiveObject::Flags & 0xFFFFFE7F
                                                         | 0x100;
      }
    }
  }
  else
  {
    this->Scaleform::GFx::InteractiveObject::Flags |= 0x180u;
  }
  Scaleform::GFx::InteractiveObject::AddToPlayList(this);
  Flags = this->Scaleform::GFx::InteractiveObject::Flags;
  LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
  v5 = this->CheckAdvanceStatus(this, Flags);
  if ( v5 == -1 )
  {
    this->Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)&loc_400000;
    this->FocusGroupMask = -1;
  }
  else
  {
    if ( v5 == 1 )
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
    this->FocusGroupMask = -1;
  }
}
