void __thiscall Scaleform::GFx::AS3::VM::exec_newactivation(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASStringNode *cf)
{
  const Scaleform::GFx::AS3::CallFrame *v2; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ActivationInstanceTraits; // edi
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // edx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Instance *v8; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // ecx
  Scaleform::GFx::AS3::Value v12; // [esp+8h] [ebp-10h] BYREF

  v2 = (const Scaleform::GFx::AS3::CallFrame *)cf;
  cf = cf[2].pLower;
  ++cf->RefCount;
  ActivationInstanceTraits = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
                               v2->pFile,
                               v2->MBIIndex,
                               (Scaleform::GFx::AS3::InstanceTraits::Traits *)&cf);
  v5 = cf;
  --cf->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  pVM = ActivationInstanceTraits->pVM;
  MemSize = ActivationInstanceTraits->MemSize;
  v12.Flags = 337;
  v8 = (Scaleform::GFx::AS3::Instance *)pVM->MHeap->Alloc(pVM->MHeap, MemSize, (const Scaleform::AllocInfo *)&v12);
  if ( v8 )
    Scaleform::GFx::AS3::Instance::Instance(v8, ActivationInstanceTraits);
  else
    v9.VInt = 0;
  v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
  pCurrent = this->OpStack.pCurrent;
  v12.Bonus.pWeakProxy = 0;
  v12.Flags = 12;
  *(_QWORD *)&v12.value.VNumber = v9.VUInt;
  if ( !v10 )
  {
    pCurrent->Flags = 12;
    pCurrent->Bonus.pWeakProxy = 0;
    pCurrent->value.VS._1 = v9;
    pCurrent->value.VS._2.VObj = 0;
    Scaleform::GFx::AS3::Value::AddRefInternal(&v12);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
}
