void __thiscall Scaleform::GFx::DisplayObjContainer::PropagateMouseEvent(
        Scaleform::GFx::DisplayObjContainer *this,
        const Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al
  int v4; // eax

  if ( this )
    ++this->RefCount;
  if ( id->Id == 8 && this->pASRoot->pMovieImpl->MouseCursorCount )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(this, id->ControllerIndex);
  if ( this->GetVisible(this) )
  {
    Scaleform::GFx::DisplayList::PropagateMouseEvent(&this->mDisplayList, id);
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + AvmObjOffset)
                                         + 20))(
             (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset);
      (*(void (__thiscall **)(int, const Scaleform::GFx::EventId *))(*(_DWORD *)v4 + 32))(v4, id);
    }
  }
  Scaleform::RefCountNTSImpl::Release(this);
}
