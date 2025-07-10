void __thiscall Scaleform::GFx::AS3::ReadArgsObjectValue::~ReadArgsObjectValue(
        Scaleform::GFx::AS3::ReadArgsObjectValue *this)
{
  Scaleform::GFx::AS3::Value *p_value; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  p_value = (Scaleform::GFx::AS3::Value *)&this->value;
  if ( (this->value.Flags & 0x1F) <= 9 )
    goto LABEL_7;
  if ( (this->value.Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_value);
LABEL_7:
    Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(this);
    return;
  }
  pWeakProxy = this->value.Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  p_value->Flags &= 0xFFFFFDE0;
  p_value->Bonus.pWeakProxy = 0;
  p_value->value.VS._1.VInt = 0;
  p_value->value.VS._2.VObj = 0;
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(this);
}
