void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::setInterval(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v4; // ebx
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  const Scaleform::GFx::AS3::Value *v8; // ebp
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::IntervalTimer *v10; // eax
  Scaleform::GFx::AS3::IntervalTimer *v11; // eax
  Scaleform::GFx::AS3::IntervalTimer *v12; // edi
  void (__thiscall *v13)(Scaleform::GFx::AS3::VM *); // esi
  Scaleform::StringDataPtr v14; // [esp-14h] [ebp-34h]
  Scaleform::GFx::AS3::Value v15; // [esp+10h] [ebp-10h] BYREF

  v4 = argc;
  if ( argc >= 2 )
  {
    v8 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2UInt32(
           (Scaleform::GFx::AS3::Value *)&argv[1],
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           (unsigned int *)&argv)->Result )
    {
      MHeap = this->pTraits.pObject->pVM->MHeap;
      v10 = (Scaleform::GFx::AS3::IntervalTimer *)MHeap->Alloc(MHeap, 72u, 0);
      if ( v10 )
      {
        Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(v10, v8, (unsigned int)argv, 0);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( v4 > 2 )
        Scaleform::GFx::AS3::IntervalTimer::SetArguments(v12, v4 - 2, v8 + 2);
      v13 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
      v15.Flags = 3;
      v15.Bonus.pWeakProxy = 0;
      v15.value.VS._1.VInt = Scaleform::GFx::MovieImpl::AddIntervalTimer(
                               (Scaleform::GFx::MovieImpl *)v13,
                               (Scaleform::GFx::Resource *)v12);
      Scaleform::GFx::AS3::Value::Assign(result, &v15);
      if ( (v15.Flags & 0x1F) > 9 )
      {
        if ( (v15.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
      }
      v12->Start(v12, (Scaleform::GFx::MovieImpl *)v13);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
    }
  }
  else
  {
    v14.pStr = "GlobalObjectCPP::setInterval";
    v14.Size = 28;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v15,
      eWrongArgumentCountError,
      this->pTraits.pObject->pVM,
      v14,
      2,
      4095,
      argc);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v6);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v15.Bonus.pWeakProxy;
    --v15.Bonus.pWeakProxy[1].pObject;
    if ( !pWeakProxy->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
}
