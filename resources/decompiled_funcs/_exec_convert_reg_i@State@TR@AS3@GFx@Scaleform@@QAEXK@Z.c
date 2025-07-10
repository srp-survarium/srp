void __thiscall Scaleform::GFx::AS3::TR::State::exec_convert_reg_i(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int reg_num)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edx
  Scaleform::GFx::AS3::Value *v3; // ecx
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value other; // [esp+0h] [ebp-10h] BYREF

  pObject = this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
  v3 = &this->Registers.Data.Data[reg_num];
  other.Bonus.pWeakProxy = 0;
  other.value.VS._1.VInt = (int)pObject;
  other.Flags = 8;
  Scaleform::GFx::AS3::Value::Assign(v3, &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      pWeakProxy = other.Bonus.pWeakProxy;
      if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}
