void __userpurge Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::setInterval(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        unsigned int a6)
{
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::Value *v11; // ebx
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::IntervalTimer *v13; // eax
  Scaleform::GFx::AS3::IntervalTimer *v14; // eax
  Scaleform::GFx::AS3::IntervalTimer *v15; // esi
  void (__thiscall *v16)(Scaleform::GFx::AS3::VM *); // edi
  Scaleform::GFx::AS3::VM::Error v18; // [esp+Ch] [ebp-10h] BYREF
  int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]

  v6 = argc;
  if ( argc >= 2 )
  {
    v11 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2UInt32(
           (Scaleform::GFx::AS3::Value *)&argv[1],
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           (unsigned int *)&argv)->Result )
    {
      MHeap = this->pTraits.pObject->pVM->MHeap;
      v13 = (Scaleform::GFx::AS3::IntervalTimer *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))MHeap->Alloc)(
                                                    MHeap,
                                                    72,
                                                    0,
                                                    a2);
      if ( v13 )
      {
        Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(v13, v11, a6, 0);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      if ( v6 > 2 )
        Scaleform::GFx::AS3::IntervalTimer::SetArguments(v15, v6 - 2, v11 + 2);
      v16 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
      v18.Message.pNode = (Scaleform::GFx::ASStringNode *)3;
      v19 = 0;
      v20 = Scaleform::GFx::MovieImpl::AddIntervalTimer((Scaleform::GFx::MovieImpl *)v16, v15);
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)argc,
        (const Scaleform::GFx::AS3::Value *)&v18.Message);
      if ( ((int)v18.Message.pNode & 0x1F) > 9u )
      {
        if ( ((int)v18.Message.pNode & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&v18.Message);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v18.Message);
      }
      v15->Start(v15, (Scaleform::GFx::MovieImpl *)v16);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v15);
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eWrongArgumentCountError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v9);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
