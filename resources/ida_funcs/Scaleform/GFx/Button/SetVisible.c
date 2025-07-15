void __thiscall Scaleform::GFx::Button::SetVisible(Scaleform::GFx::Button *this, bool visible)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  bool v4; // cl
  unsigned int Flags; // eax
  unsigned int v6; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax

  Scaleform::GFx::DisplayObjectBase::SetVisible(this, visible);
  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    v4 = !visible && (pMovieImpl->Flags & 0x800) != 0;
    Flags = this->Scaleform::GFx::InteractiveObject::Flags;
    if ( v4 != ((Flags & 8) != 0) )
    {
      if ( v4 )
        v6 = Flags | 8;
      else
        v6 = Flags & 0xFFFFFFF7;
      this->Scaleform::GFx::InteractiveObject::Flags = v6;
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Button>(this);
      pParent = this->pParent;
      if ( pParent )
      {
        if ( (pParent->Flags & 8) == 0 )
          this->PropagateNoAdvanceGlobalFlag(this);
      }
    }
  }
}
