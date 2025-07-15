void __thiscall Scaleform::GFx::AS3::ReadValueMnObject::~ReadValueMnObject(
        Scaleform::GFx::AS3::ReadValueMnObject *this)
{
  Scaleform::GFx::AS3::Value *p_ArgObject; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  p_ArgObject = (Scaleform::GFx::AS3::Value *)&this->ArgObject;
  if ( (this->ArgObject.Flags & 0x1F) <= 9 )
    goto LABEL_7;
  if ( (this->ArgObject.Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_ArgObject);
LABEL_7:
    Scaleform::GFx::AS3::ReadValueMn::~ReadValueMn(this);
    return;
  }
  pWeakProxy = this->ArgObject.Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  p_ArgObject->Flags &= 0xFFFFFDE0;
  p_ArgObject->Bonus.pWeakProxy = 0;
  p_ArgObject->value.VS._1.VInt = 0;
  p_ArgObject->value.VS._2.VObj = 0;
  Scaleform::GFx::AS3::ReadValueMn::~ReadValueMn(this);
}
