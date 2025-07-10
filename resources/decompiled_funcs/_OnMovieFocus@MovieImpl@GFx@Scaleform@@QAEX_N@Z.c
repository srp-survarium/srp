void __thiscall Scaleform::GFx::MovieImpl::OnMovieFocus(Scaleform::GFx::MovieImpl *this, BOOL set)
{
  Scaleform::GFx::KeyboardState *KeyboardStates; // esi
  int v4; // ebp
  Scaleform::GFx::MouseState *mMouseState; // esi
  int v6; // ebp
  Scaleform::RefCountVImpl *v7; // esi

  if ( set )
  {
    this->Flags |= 0x40000u;
  }
  else
  {
    KeyboardStates = this->KeyboardStates;
    v4 = 6;
    do
    {
      Scaleform::GFx::KeyboardState::ResetState(KeyboardStates++);
      --v4;
    }
    while ( v4 );
    mMouseState = this->mMouseState;
    v6 = 6;
    do
    {
      Scaleform::GFx::MouseState::ResetState(mMouseState++);
      --v6;
    }
    while ( v6 );
    this->Flags &= ~0x40000u;
  }
  v7 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
  if ( v7 )
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::MovieImpl *))v7->__vftable[9].Release)(v7, this);
  this->pASMovieRoot.pObject->OnMovieFocus(this->pASMovieRoot.pObject, set);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
}
