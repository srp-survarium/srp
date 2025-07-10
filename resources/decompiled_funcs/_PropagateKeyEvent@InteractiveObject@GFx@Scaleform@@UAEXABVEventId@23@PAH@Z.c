void __thiscall Scaleform::GFx::InteractiveObject::PropagateKeyEvent(
        Scaleform::GFx::InteractiveObject *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  this->OnKeyEvent(this, id, pkeyMask);
}
