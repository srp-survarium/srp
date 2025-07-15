void __thiscall Scaleform::GFx::AS3::TR::ReadObject::~ReadObject(Scaleform::GFx::AS3::TR::ReadObject *this)
{
  Scaleform::GFx::AS3::Value *p_ArgObject; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  p_ArgObject = (Scaleform::GFx::AS3::Value *)&this->ArgObject;
  if ( (this->ArgObject.Flags & 0x1F) > 9 )
  {
    if ( (this->ArgObject.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ArgObject.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
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
}
