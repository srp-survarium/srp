void __thiscall Scaleform::GFx::DisplayObjContainer::PropagateKeyEvent(
        Scaleform::GFx::DisplayObjContainer *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  if ( this )
    ++this->RefCount;
  if ( this->GetVisible(this) )
  {
    Scaleform::GFx::DisplayList::PropagateKeyEvent(&this->mDisplayList, id, pkeyMask);
    this->OnKeyEvent(this, id, pkeyMask);
  }
  Scaleform::RefCountNTSImpl::Release(this);
}
