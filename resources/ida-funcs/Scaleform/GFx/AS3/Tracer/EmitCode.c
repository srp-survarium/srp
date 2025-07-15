void __thiscall Scaleform::GFx::AS3::Tracer::EmitCode(Scaleform::GFx::AS3::Tracer *this)
{
  const Scaleform::GFx::AS3::CallFrame *CF; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *p_exception; // ebx
  unsigned int *v4; // edi
  Scaleform::GFx::AS3::TR::Block *v5; // eax
  Scaleform::GFx::AS3::TR::Block *v6; // eax
  unsigned int v7; // ecx
  Scaleform::GFx::AS3::TR::State *v8; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // edi
  int v10; // ebp
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v11; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // esi
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  unsigned int j; // ebx
  Scaleform::GFx::AS3::Tracer::Recalculate *Data; // ecx
  unsigned int *v19; // eax
  unsigned int pos; // edx
  unsigned int v21; // edi
  Scaleform::GFx::AS3::Tracer::Recalculate *v22; // ecx
  unsigned int *v23; // ebp
  unsigned int v24; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v25; // eax
  _DWORD *v26; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *WException; // ebx
  unsigned int *v28; // eax
  unsigned int v29; // edi
  unsigned int *v30; // ebp
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v31; // edx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v32; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // [esp-10h] [ebp-4Ch]
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *e; // [esp+4h] [ebp-38h]
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *ea; // [esp+4h] [ebp-38h]
  Scaleform::GFx::AS3::VM *vm; // [esp+8h] [ebp-34h]
  Scaleform::GFx::AS3::VM *vma; // [esp+8h] [ebp-34h]
  unsigned int i; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::ASStringNode *v39; // [esp+10h] [ebp-2Ch]
  Scaleform::GFx::AS3::TR::State *state; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v41; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo val; // [esp+28h] [ebp-14h] BYREF

  if ( this->Done )
    return;
  CF = this->CF;
  vm = CF->pFile->VMRef;
  p_exception = &CF->pFile->File.pObject->MethodBodies.Info.Data.Data[CF->MBIIndex.Ind]->exception;
  i = 0;
  if ( p_exception->info.Data.Size )
  {
    e = 0;
    do
    {
      v4 = (unsigned int *)((char *)e + (unsigned int)p_exception->info.Data.Data);
      v5 = Scaleform::GFx::AS3::Tracer::AddBlock(this, this->Blocks.Root.pNext->State, *v4, tUnknown, 0);
      if ( v5 )
      {
        *((_DWORD *)v5 + 2) &= ~1u;
        v5->Type |= 2u;
      }
      v6 = Scaleform::GFx::AS3::Tracer::AddBlock(this, this->Blocks.Root.pNext->State, v4[2], tUnknown, 0);
      if ( v6 )
      {
        v7 = v4[3];
        v6->Type |= 4u;
        v8 = v6->State;
        state = v8;
        if ( v7 )
        {
          pFile = this->CF->pFile;
          v10 = (int)&pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v7];
          v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, pFile, (Scaleform::GFx::AS3::Abc::Multiname *)v10);
          if ( !v11 )
          {
            InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                               pFile,
                               (Scaleform::GFx::ASString *)&state,
                               *(Scaleform::GFx::ASStringNode **)(v10 + 8));
            Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&val, InternedString);
            Scaleform::GFx::AS3::VM::Error::Error(
              (Scaleform::GFx::AS3::VM::Error *)&i,
              (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
              (Scaleform::GFx::ASStringNode *)vm,
              (Scaleform::GFx::AS3::Value *)&val);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              vm,
              v14,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
            v15 = v39;
            --v39->RefCount;
            if ( !v15->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v15);
            Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&val);
            v16 = (Scaleform::GFx::ASStringNode *)state;
            --state->Registers.Data.Data;
            if ( !v16->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v16);
            return;
          }
          pObject = v11->ITraits.pObject;
          v41.Bonus.pWeakProxy = 0;
          v41.value.VS._1.VInt = (int)pObject;
          v41.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, pObject) & 0xFFFFFFF7)) | 8;
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &state->OpStack.Data,
            &v41);
          Scaleform::GFx::AS3::Value::~Value(&v41);
        }
        else
        {
          val.target = (unsigned int)this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
          val.to = 0;
          val.from = 72;
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &v8->OpStack.Data,
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
  for ( j = 0; j < this->PosToRecalculate.Data.Size; *v23 = v24 )
  {
    Data = this->PosToRecalculate.Data.Data;
    v19 = this->WCode->Data.Data;
    pos = Data[j].pos;
    v21 = v19[pos];
    v22 = &Data[j];
    v23 = &v19[pos];
    v24 = 0;
    if ( v21 < this->Orig2newPosMap.Data.Size )
      v24 = v22->base + this->Orig2newPosMap.Data.Data[v21] - pos;
    ++j;
  }
  v25 = &this->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->CF->MBIIndex.Ind]->exception;
  ea = v25;
  i = 0;
  if ( v25->info.Data.Size )
  {
    vma = 0;
    while ( 1 )
    {
      v26 = (Scaleform::GFx::AS3::VM_vtbl **)((char *)&vma->__vftable + (unsigned int)v25->info.Data.Data);
      Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo::ExceptionInfo(
        &val,
        this->Orig2newPosMap.Data.Data[*v26],
        this->Orig2newPosMap.Data.Data[v26[1]],
        this->Orig2newPosMap.Data.Data[v26[2]],
        v26[3],
        v26[4]);
      WException = this->WException;
      v29 = WException->info.Data.Size + 1;
      v30 = v28;
      if ( v29 >= WException->info.Data.Size )
      {
        if ( v29 >= WException->info.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &WException->info.Data,
            WException,
            v29 + (v29 >> 2));
      }
      else if ( v29 < WException->info.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &WException->info.Data,
          WException,
          WException->info.Data.Size + 1);
      }
      v31 = WException->info.Data.Data;
      vma = (Scaleform::GFx::AS3::VM *)((char *)vma + 20);
      WException->info.Data.Size = v29;
      v32 = &v31[v29 - 1];
      v32->from = *v30;
      v32->to = v30[1];
      v32->target = v30[2];
      v32->exc_type_ind = v30[3];
      v32->var_name_ind = v30[4];
      if ( ++i >= ea->info.Data.Size )
        break;
      v25 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)ea;
    }
  }
  this->Done = 1;
}
