bool __thiscall Scaleform::GFx::AS2::AvmSprite::ExecuteEvent(
        Scaleform::GFx::AS2::AvmSprite *this,
        const Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::InteractiveObject *v5; // edi
  Scaleform::GFx::InteractiveObject *v7; // eax
  bool rv; // [esp+8h] [ebp+4h]

  pDispObj = this->pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    return 0;
  v5 = this->pDispObj;
  if ( pDispObj )
    ++pDispObj->RefCount;
  if ( id->Id != 1
    || (this->pDispObj->Flags &= ~0x20u, v7 = this->pDispObj, (v7->Scaleform::GFx::DisplayObject::Flags & 8) != 0)
    || SLOBYTE(v7[1].pIndXFormData) < 0 )
  {
    rv = Scaleform::GFx::AS2::AvmCharacter::ExecuteEvent(this, id);
    if ( id->Id == 4 )
    {
      this->pDispObj->Flags |= 0x10u;
      Scaleform::GFx::InteractiveObject::SetNextUnloaded(
        this->pDispObj,
        this->pDispObj->pASRoot->pMovieImpl->pUnloadListHead);
      this->pDispObj->pASRoot->pMovieImpl->pUnloadListHead = this->pDispObj;
      ++this->pDispObj->RefCount;
    }
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
    return rv;
  }
  else
  {
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
    return 0;
  }
}
