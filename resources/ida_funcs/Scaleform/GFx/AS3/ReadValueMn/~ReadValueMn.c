void __thiscall Scaleform::GFx::AS3::ReadValueMn::~ReadValueMn(Scaleform::GFx::AS3::ReadValueMn *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_ArgValue; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  Scaleform::GFx::AS3::Multiname::~Multiname(&this->ArgMN);
  Flags = this->ArgValue.Flags;
  p_ArgValue = &this->ArgValue;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = p_ArgValue->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_ArgValue->Flags &= 0xFFFFFDE0;
      p_ArgValue->Bonus.pWeakProxy = 0;
      p_ArgValue->value.VS._1.VInt = 0;
      p_ArgValue->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_ArgValue);
    }
  }
}
