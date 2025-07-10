void __thiscall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0;
      this->value.VS._1.VInt = 0;
      this->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v5;
}
