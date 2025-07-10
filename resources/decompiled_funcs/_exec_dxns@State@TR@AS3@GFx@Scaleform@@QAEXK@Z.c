void __thiscall Scaleform::GFx::AS3::TR::State::exec_dxns(Scaleform::GFx::AS3::TR::State *this, unsigned int index)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // eax
  const Scaleform::GFx::AS3::CallFrame *CF; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v6; // esi
  int *Data; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-8h] BYREF

  pTracer = this->pTracer;
  if ( !this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    CF = pTracer->CF;
    goto LABEL_10;
  }
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)pTracer->WCode;
  v6 = WCode->Size + 1;
  if ( v6 >= WCode->Size )
  {
    if ( v6 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v6 + (v6 >> 2));
  }
  else if ( v6 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v6;
  Data[v6 - 1] = index;
  if ( (this->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[this->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags
      & 0x40) == 0 )
  {
    CF = this->pTracer->CF;
LABEL_10:
    VMRef = CF->pFile->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eNotImplementedError, VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      VMRef,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
