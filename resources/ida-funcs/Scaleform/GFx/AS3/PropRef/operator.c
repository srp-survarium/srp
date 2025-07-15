Scaleform::GFx::AS3::PropRef *__thiscall Scaleform::GFx::AS3::PropRef::operator=(
        Scaleform::GFx::AS3::PropRef *this,
        const Scaleform::GFx::AS3::PropRef *__that)
{
  this->pSI = __that->pSI;
  this->pSI = __that->pSI;
  this->pSI = __that->pSI;
  this->SlotIndex = __that->SlotIndex;
  Scaleform::GFx::AS3::Value::Assign(&this->This, &__that->This);
  return this;
}


BOOL __thiscall Scaleform::GFx::AS3::PropRef::operator bool(Scaleform::GFx::AS3::PropRef *this)
{
  const Scaleform::GFx::AS3::SlotInfo *pSI; // ecx
  BOOL result; // eax

  result = 0;
  if ( (this->This.Flags & 0x1F) != 0 && (((int)this->pSI & 1) == 0 || ((int)this->pSI & 0xFFFFFFFE) != 0) )
  {
    pSI = this->pSI;
    if ( ((unsigned __int8)pSI & 2) == 0 || ((unsigned int)pSI & 0xFFFFFFFD) != 0 )
      return 1;
  }
  return result;
}
