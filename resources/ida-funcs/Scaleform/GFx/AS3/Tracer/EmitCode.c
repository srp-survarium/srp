void __thiscall Scaleform::GFx::AS3::Tracer::EmitCode(Scaleform::GFx::AS3::Tracer *this)
{
  const Scaleform::GFx::AS3::CallFrame *CF; // eax
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *p_exception; // ebp
  unsigned int *v5; // edi
  Scaleform::GFx::AS3::TR::Block *v6; // eax
  Scaleform::GFx::AS3::TR::Block *v7; // eax
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::TR::State *State; // edi
  const Scaleform::GFx::AS3::CallFrame *v10; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v11; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::Tracer::Recalculate *Data; // ecx
  unsigned int *v16; // eax
  unsigned int pos; // edx
  unsigned int v18; // edi
  Scaleform::GFx::AS3::Tracer::Recalculate *v19; // ecx
  unsigned int *v20; // ebp
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v22; // eax
  _DWORD *v23; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *WException; // ebx
  unsigned int *v25; // eax
  unsigned int v26; // edi
  unsigned int *v27; // ebp
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v28; // edx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v29; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // [esp-10h] [ebp-48h]
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *e; // [esp+4h] [ebp-34h]
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *ea; // [esp+4h] [ebp-34h]
  Scaleform::GFx::AS3::VM *vm; // [esp+8h] [ebp-30h]
  Scaleform::GFx::AS3::VM *vma; // [esp+8h] [ebp-30h]
  unsigned int i; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::ASStringNode *v36; // [esp+10h] [ebp-28h]
  Scaleform::GFx::AS3::Value v37; // [esp+14h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo val; // [esp+24h] [ebp-14h] BYREF

  if ( this->Done )
    return;
  CF = this->CF;
  vm = CF->pFile->VMRef;
  v3 = 0;
  p_exception = &CF->pFile->File.pObject->MethodBodies.Info.Data.Data[CF->MBIIndex.Ind]->exception;
  i = 0;
  if ( p_exception->info.Data.Size )
  {
    e = 0;
    do
    {
      v5 = (unsigned int *)((char *)e + (unsigned int)p_exception->info.Data.Data);
      v6 = Scaleform::GFx::AS3::Tracer::AddBlock(this, this->Blocks.Root.pNext->State, *v5, tUnknown, 0);
      if ( v6 )
      {
        *((_DWORD *)v6 + 2) &= ~1u;
        v6->Type |= 2u;
      }
      v7 = Scaleform::GFx::AS3::Tracer::AddBlock(this, this->Blocks.Root.pNext->State, v5[2], tUnknown, 0);
      if ( v7 )
      {
        v8 = v5[3];
        v7->Type |= 4u;
        State = v7->State;
        v10 = this->CF;
        if ( v8 )
        {
          v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                  vm,
                  v10->pFile,
                  &v10->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v8]);
          if ( !v11 )
          {
            Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&i, eClassNotFoundError, vm);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              vm,
              v13,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
            v14 = v36;
            --v36->RefCount;
            if ( !v14->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v14);
            return;
          }
          pObject = v11->ITraits.pObject;
          v37.Bonus.pWeakProxy = 0;
          v37.value.VS._1.VInt = (int)pObject;
          v37.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, pObject) & 0xFFFFFFF7)) | 8;
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &State->OpStack.Data,
            &v37);
          Scaleform::GFx::AS3::Value::~Value(&v37);
        }
        else
        {
          val.target = (unsigned int)v10->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
          val.to = 0;
          val.from = 72;
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &State->OpStack.Data,
            (Scaleform::GFx::AS3::Value *)&val);
        }
      }
      e = (const Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)((char *)e + 20);
      ++i;
    }
    while ( i < p_exception->info.Data.Size );
  }
  Scaleform::GFx::AS3::Tracer::TraceBlock(this, 0, this->Blocks.Root.pNext);
  if ( vm->HandleException )
  {
    WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
    if ( WCode->Size )
    {
      if ( (WCode->Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( WCode->Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, WCode->Data);
          WCode->Data = 0;
        }
        WCode->Policy.Capacity = 0;
        WCode->Size = 0;
        return;
      }
    }
    else if ( !WCode->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        0);
    }
    WCode->Size = 0;
    return;
  }
  if ( this->PosToRecalculate.Data.Size )
  {
    do
    {
      Data = this->PosToRecalculate.Data.Data;
      v16 = this->WCode->Data.Data;
      pos = Data[v3].pos;
      v18 = v16[pos];
      v19 = &Data[v3];
      v20 = &v16[pos];
      v21 = 0;
      if ( v18 < this->Orig2newPosMap.Data.Size )
        v21 = v19->base + this->Orig2newPosMap.Data.Data[v18] - pos;
      ++v3;
      *v20 = v21;
    }
    while ( v3 < this->PosToRecalculate.Data.Size );
  }
  v22 = &this->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->CF->MBIIndex.Ind]->exception;
  ea = v22;
  i = 0;
  if ( v22->info.Data.Size )
  {
    vma = 0;
    while ( 1 )
    {
      v23 = (Scaleform::GFx::AS3::VM_vtbl **)((char *)&vma->__vftable + (unsigned int)v22->info.Data.Data);
      Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo::ExceptionInfo(
        &val,
        this->Orig2newPosMap.Data.Data[*v23],
        this->Orig2newPosMap.Data.Data[v23[1]],
        this->Orig2newPosMap.Data.Data[v23[2]],
        v23[3],
        v23[4]);
      WException = this->WException;
      v26 = WException->info.Data.Size + 1;
      v27 = v25;
      if ( v26 >= WException->info.Data.Size )
      {
        if ( v26 >= WException->info.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &WException->info.Data,
            WException,
            v26 + (v26 >> 2));
      }
      else if ( v26 < WException->info.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &WException->info.Data,
          WException,
          WException->info.Data.Size + 1);
      }
      v28 = WException->info.Data.Data;
      vma = (Scaleform::GFx::AS3::VM *)((char *)vma + 20);
      WException->info.Data.Size = v26;
      v29 = &v28[v26 - 1];
      v29->from = *v27;
      v29->to = v27[1];
      v29->target = v27[2];
      v29->exc_type_ind = v27[3];
      v29->var_name_ind = v27[4];
      if ( ++i >= ea->info.Data.Size )
        break;
      v22 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)ea;
    }
  }
  this->Done = 1;
}
