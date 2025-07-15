void __thiscall Scaleform::GFx::AS3::TR::State::exec_dxns(Scaleform::GFx::AS3::TR::State *this, unsigned int index)
{
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ebx
  unsigned int v5; // edi
  int *Data; // edx
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v9; // [esp-8h] [ebp-1Ch]
  Scaleform::StringDataPtr v10; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v11; // [esp+Ch] [ebp-8h] BYREF

  if ( !this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    v9.pStr = "dxns";
    v9.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v11,
      eNotImplementedError,
      (Scaleform::String)this->pTracer->CF->pFile->VMRef,
      v9);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v3,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    goto LABEL_10;
  }
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v5 = WCode->Size + 1;
  if ( v5 >= WCode->Size )
  {
    if ( v5 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v5 + (v5 >> 2));
  }
  else if ( v5 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v5;
  Data[v5 - 1] = index;
  if ( (this->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[this->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags
      & 0x40) == 0 )
  {
    v10.pStr = "does not have the SETS_DXNS flag set";
    v10.Size = 36;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v11,
      eNotImplementedError,
      (Scaleform::String)this->pTracer->CF->pFile->VMRef,
      v10);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v7,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
LABEL_10:
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
