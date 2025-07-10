void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::UpdateBindingFrame(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        LONG frame,
        volatile unsigned int bytesLoaded)
{
  this->BytesLoaded = bytesLoaded;
  InterlockedExchange((volatile LONG *)&this->BindingFrame, frame);
}
