void __thiscall Scaleform::GFx::AS3::PropRef::PropRef(
        Scaleform::GFx::AS3::PropRef *this,
        Scaleform::GFx::AS3::Value *_this,
        const Scaleform::GFx::AS3::SlotInfo *si,
        unsigned int index)
{
  this->SlotIndex = index;
  this->pSI = si;
  this->This = *_this;
  if ( (_this->Flags & 0x1F) > 9 )
  {
    if ( (_this->Flags & 0x200) != 0 )
      ++_this->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(_this);
  }
}
