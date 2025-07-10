void __thiscall Scaleform::GFx::AS3::VM::exec_newactivation(Scaleform::GFx::AS3::VM *this, int cf)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ActivationInstanceTraits; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Instance *v6; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // eax
  Scaleform::GFx::AS3::Value *v8; // ecx
  Scaleform::GFx::AS3::Value v9; // [esp+Ch] [ebp-10h] BYREF

  ActivationInstanceTraits = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
                               *(Scaleform::GFx::AS3::VMFile **)(cf + 20),
                               *(const Scaleform::GFx::AS3::Abc::MbiInd *)(cf + 24));
  pVM = ActivationInstanceTraits->pVM;
  MemSize = ActivationInstanceTraits->MemSize;
  cf = 337;
  v6 = (Scaleform::GFx::AS3::Instance *)pVM->MHeap->Alloc(pVM->MHeap, MemSize, (const Scaleform::AllocInfo *)&cf);
  if ( v6 )
    Scaleform::GFx::AS3::Instance::Instance(v6, ActivationInstanceTraits);
  else
    v7.VInt = 0;
  v8 = ++this->OpStack.pCurrent;
  v9.Bonus.pWeakProxy = 0;
  v9.Flags = 12;
  *(_QWORD *)&v9.value.VNumber = v7.VUInt;
  if ( v8 )
  {
    v8->Flags = 12;
    v8->Bonus.pWeakProxy = 0;
    v8->value.VS._1 = v7;
    v8->value.VS._2.VObj = 0;
    Scaleform::GFx::AS3::Value::AddRefInternal(&v9);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
}
