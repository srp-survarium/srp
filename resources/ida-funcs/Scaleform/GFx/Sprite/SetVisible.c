void __thiscall Scaleform::GFx::Sprite::SetVisible(Scaleform::GFx::Sprite *this, bool visible)
{
  bool v3; // cl
  unsigned int Flags; // eax
  unsigned int v5; // eax
  bool v6; // al
  int v7; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax

  Scaleform::GFx::DisplayObjectBase::SetVisible(this, visible);
  v3 = !visible && (this->pASRoot->pMovieImpl->Flags & 0x800) != 0;
  Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
  if ( v3 != ((Flags & 8) != 0) )
  {
    if ( v3 )
      v5 = Flags | 8;
    else
      v5 = Flags & 0xFFFFFFF7;
    this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags = v5;
    v6 = (v5 & 0x200000) != 0 && (v5 & 0x400000) == 0;
    v7 = Scaleform::GFx::Sprite::CheckAdvanceStatus(this, v6);
    if ( v7 == -1 )
    {
      this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)&loc_400000;
    }
    else if ( v7 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
    }
    pParent = this->pParent;
    if ( pParent )
    {
      if ( (pParent->Flags & 8) == 0 )
        this->PropagateNoAdvanceGlobalFlag(this);
    }
  }
}
