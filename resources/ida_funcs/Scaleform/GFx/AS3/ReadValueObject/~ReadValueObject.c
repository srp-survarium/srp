void __thiscall Scaleform::GFx::AS3::ReadValueObject::~ReadValueObject(Scaleform::GFx::AS3::ReadValueObject *this)
{
  Scaleform::GFx::AS3::Value *p_ArgObject; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v4; // zf
  Scaleform::GFx::AS3::WeakProxy *v5; // eax

  p_ArgObject = (Scaleform::GFx::AS3::Value *)&this->ArgObject;
  if ( (this->ArgObject.Flags & 0x1F) > 9 )
  {
    if ( (this->ArgObject.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ArgObject.Bonus.pWeakProxy;
      v4 = pWeakProxy->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_ArgObject->Flags &= 0xFFFFFDE0;
      p_ArgObject->Bonus.pWeakProxy = 0;
      p_ArgObject->value.VS._1.VInt = 0;
      p_ArgObject->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_ArgObject);
    }
  }
  if ( (this->ArgValue.Flags & 0x1F) > 9 )
  {
    if ( (this->ArgValue.Flags & 0x200) != 0 )
    {
      v5 = this->ArgValue.Bonus.pWeakProxy;
      v4 = v5->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
      this->ArgValue.Flags &= 0xFFFFFDE0;
      this->ArgValue.Bonus.pWeakProxy = 0;
      this->ArgValue.value.VS._1.VInt = 0;
      this->ArgValue.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ArgValue);
    }
  }
}
