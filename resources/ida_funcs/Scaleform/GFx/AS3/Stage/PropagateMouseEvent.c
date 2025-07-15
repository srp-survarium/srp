void __thiscall Scaleform::GFx::AS3::Stage::PropagateMouseEvent(
        Scaleform::GFx::AS3::Stage *this,
        const Scaleform::GFx::EventId *id)
{
  if ( this )
    ++this->RefCount;
  if ( id->Id == 8 && this->pASRoot->pMovieImpl->MouseCursorCount )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(this, id->ControllerIndex);
  if ( this )
    Scaleform::RefCountNTSImpl::Release(this);
}
