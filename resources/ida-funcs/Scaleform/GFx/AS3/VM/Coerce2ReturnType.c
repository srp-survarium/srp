void __thiscall Scaleform::GFx::AS3::VM::Coerce2ReturnType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::CallFrame *v4; // esi
  Scaleform::GFx::AS3::VMFile *pFile; // eax
  Scaleform::GFx::AS3::Abc::Multiname *v6; // edi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v7; // ebp
  const char *pData; // eax
  unsigned int v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  unsigned int v13; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-28h]
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-28h]
  Scaleform::GFx::AS3::VM::Error v17; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [esp+18h] [ebp-8h] BYREF

  v4 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F];
  pFile = v4->pFile;
  v6 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)pFile[1].__vftable[2].ForEachChild_GC
                                             + 16
                                             * *(_DWORD *)(*((_DWORD *)pFile[1].__vftable[2].GetMultiname
                                                           + *(_DWORD *)(*((_DWORD *)pFile[1].__vftable[3].MakeInternedNamespaceSet
                                                                         + v4->MBIIndex.Ind)
                                                                       + 12))
                                                         + 4));
  v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, pFile, v6);
  if ( v7 )
  {
    if ( v7->Coerce(v7, value, result) )
      return;
    pData = v7->GetName(v7, (Scaleform::GFx::ASString *)&result)->pNode->pData;
    v15.pStr = pData;
    if ( pData )
      v9 = strlen(pData);
    else
      v9 = 0;
    v15.Size = v9;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v17,
      (Scaleform::GFx::AS3::VM_vtbl *)0x40A,
      (Scaleform::GFx::ASStringNode *)this,
      value,
      v15);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v10,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = (Scaleform::GFx::ASStringNode *)result;
  }
  else
  {
    Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
      &v4->pFile->File.pObject->Const_Pool.ConstStr.Data.Data[v6->NameIndex],
      (Scaleform::StringDataPtr *)&v17);
    v16.pStr = (const char *)v17.ID;
    if ( v17.ID )
      v13 = strlen((const char *)v17.ID);
    else
      v13 = 0;
    v16.Size = v13;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eClassNotFoundError, (Scaleform::String)this, v16);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v14,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = v18.Message.pNode;
  }
  if ( !--v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
