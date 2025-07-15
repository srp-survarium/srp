void __thiscall Scaleform::GFx::AS3::Classes::fl_text::Font::registerFont(
        Scaleform::GFx::AS3::Classes::fl_text::Font *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::String font)
{
  Scaleform::GFx::AS3::Class *pData; // esi
  Scaleform::GFx::AS3::VM *pVM; // ebp
  int v6; // eax
  Scaleform::GFx::MovieDefImpl *v7; // edi
  char ExportedResource; // al
  void *v9; // esi
  char v10; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v12; // eax
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pBinding; // eax
  void *v16; // esi
  Scaleform::GFx::ASString className; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceBindData resBindData; // [esp+10h] [ebp-8h] BYREF

  pData = (Scaleform::GFx::AS3::Class *)font.pData;
  if ( font.pData
    && Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)this->pTraits.pObject,
         *(const Scaleform::GFx::AS3::ClassTraits::Traits **)font.pData[1].Data) )
  {
    pVM = this->pTraits.pObject->pVM;
    (*((void (__thiscall **)(Scaleform::GFx::AS3::Traits_vtbl *, Scaleform::GFx::ASString *, int))pData->pTraits.pObject[1].ForEachChild_GC
     + 5))(
      pData->pTraits.pObject[1].__vftable,
      &className,
      1);
    v6 = (int)pData->pTraits.pObject->GetFilePtr(pData->pTraits.pObject);
    if ( v6 )
    {
      v7 = *(Scaleform::GFx::MovieDefImpl **)(*(_DWORD *)(v6 + 60) + 184);
      resBindData.pResource.pObject = 0;
      resBindData.pBinding = 0;
      Scaleform::String::String(&font, (char *)className.pNode->pData);
      ExportedResource = Scaleform::GFx::MovieImpl::FindExportedResource(
                           (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
                           v7,
                           &resBindData,
                           &font);
      v9 = (void *)(font.HeapTypeBits & 0xFFFFFFFC);
      v10 = ExportedResource;
      if ( InterlockedExchangeAdd((volatile LONG *)((font.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
      if ( !v10 )
        goto LABEL_10;
      if ( resBindData.pResource.pObject )
      {
        if ( (resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject) & 0x200) != 0 )
          Scaleform::GFx::MovieImpl::RegisterFont(
            (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
            v7,
            (Scaleform::GFx::FontResource *)resBindData.pResource.pObject);
LABEL_10:
        if ( resBindData.pResource.pObject )
          Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
      }
    }
    pNode = className.pNode;
    --className.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  Scaleform::String::String(&font, "unknown");
  if ( pData )
  {
    v12 = (int)pData->pTraits.pObject->GetFilePtr(pData->pTraits.pObject);
    if ( v12 )
      Scaleform::String::operator=(&font, (const Scaleform::String *)(*(_DWORD *)(v12 + 60) + 12));
  }
  v13 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&resBindData, eSWFHasInvalidData, v13);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v13, v14);
  pBinding = (Scaleform::GFx::ASStringNode *)resBindData.pBinding;
  --resBindData.pBinding->ResourceLock.cs.DebugInfo;
  if ( !pBinding->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pBinding);
  v16 = (void *)(font.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((font.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
}
