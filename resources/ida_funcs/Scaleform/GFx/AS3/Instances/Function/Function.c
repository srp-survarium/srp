void __thiscall Scaleform::GFx::AS3::Instances::Function::Function(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::InstanceTraits::Function *tr,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss,
        Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_StoredScopeStack; // edi
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int Size; // ebx
  unsigned int v8; // esi
  Scaleform::GFx::AS3::VM *pVM; // edx
  unsigned int v10; // ecx
  unsigned int ScopeStackBaseInd; // eax
  int p_RefCount; // esi
  unsigned int v13; // eax
  Scaleform::Pair<double,unsigned long> *Data; // ebp
  Scaleform::GFx::AS3::Value *v15; // ebx
  unsigned int v16; // esi
  Scaleform::Pair<double,unsigned long> *v17; // ecx
  unsigned int *v18; // esi
  bool v19; // zf
  Scaleform::GFx::AS3::Value *tra; // [esp+18h] [ebp+4h]
  Scaleform::GFx::AS3::InstanceTraits::Function *trb; // [esp+18h] [ebp+4h]
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v22; // [esp+1Ch] [ebp+8h]
  Scaleform::GFx::AS3::VM *vm; // [esp+20h] [ebp+Ch]

  Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(this, tr);
  this->__vftable = (Scaleform::GFx::AS3::Instances::Function_vtbl *)&Scaleform::GFx::AS3::Instances::Function::`vftable';
  p_StoredScopeStack = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->StoredScopeStack;
  this->StoredScopeStack.Data.Data = 0;
  this->StoredScopeStack.Data.Size = 0;
  this->StoredScopeStack.Data.Policy.Capacity = 0;
  pHeap = ss->Data.pHeap;
  this->StoredScopeStack.Data.pHeap = pHeap;
  Size = ss->Data.Size;
  tra = ss->Data.Data;
  if ( Size )
  {
    v8 = this->StoredScopeStack.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->StoredScopeStack.Data,
      pHeap,
      v8 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
      (unsigned int *)&p_StoredScopeStack->Data[v8],
      Size,
      tra);
  }
  this->This = *_this;
  if ( (_this->Flags & 0x1F) > 9 )
  {
    if ( (_this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(_this);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(_this);
  }
  pVM = this->pTraits.pObject->pVM;
  v10 = pVM->ScopeStack.Data.Size;
  vm = pVM;
  if ( pVM->CallStack.Size )
    ScopeStackBaseInd = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(pVM->CallStack.Size - 1) & 0x3F].ScopeStackBaseInd;
  else
    ScopeStackBaseInd = 0;
  if ( ScopeStackBaseInd < v10 )
  {
    p_RefCount = 16 * ScopeStackBaseInd;
    trb = (Scaleform::GFx::AS3::InstanceTraits::Function *)(16 * ScopeStackBaseInd);
    v22 = (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)(v10
                                                                                                 - ScopeStackBaseInd);
    while ( 1 )
    {
      v13 = p_StoredScopeStack->Size;
      Data = p_StoredScopeStack[1].Data;
      v15 = (Scaleform::GFx::AS3::Value *)((char *)pVM->ScopeStack.Data.Data + p_RefCount);
      v16 = v13 + 1;
      if ( v13 + 1 >= v13 )
      {
        if ( v16 >= p_StoredScopeStack->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_StoredScopeStack,
            Data,
            v16 + (v16 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)&p_StoredScopeStack->Data[v13 + 1],
          0xFFFFFFFF);
        if ( v16 < p_StoredScopeStack->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_StoredScopeStack,
            Data,
            v16);
      }
      v17 = p_StoredScopeStack->Data;
      p_StoredScopeStack->Size = v16;
      v18 = (unsigned int *)&v17[v16 - 1];
      if ( v18 )
      {
        *v18 = v15->Flags;
        v18[1] = (unsigned int)v15->Bonus.pWeakProxy;
        v18[2] = v15->value.VS._1.VUInt;
        v18[3] = (unsigned int)v15->value.VS._2.VObj;
        if ( (v15->Flags & 0x1F) > 9 )
        {
          if ( (v15->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(v15);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(v15);
        }
      }
      p_RefCount = (int)&trb->RefCount;
      v19 = v22 == (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)1;
      v22 = (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)((char *)v22 - 1);
      trb = (Scaleform::GFx::AS3::InstanceTraits::Function *)((char *)trb + 16);
      if ( v19 )
        break;
      pVM = vm;
    }
  }
}
