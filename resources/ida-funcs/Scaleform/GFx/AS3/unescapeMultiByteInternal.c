void __cdecl Scaleform::GFx::AS3::unescapeMultiByteInternal(
        Scaleform::String vm,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::VM *pData; // esi
  char v4; // bl
  const Scaleform::GFx::AS3::ClassTraits::Traits *v5; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASString *v7; // edi
  Scaleform::GFx::ASStringNode *v8; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v10; // zf
  void *v11; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  Scaleform::StringDataPtr qname; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+10h] [ebp-18h] BYREF

  pData = (Scaleform::GFx::AS3::VM *)vm.pData;
  v4 = 0;
  qname.pStr = "flash.utils.System";
  qname.Size = 18;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, (const Scaleform::GFx::AS3::VM *)vm.pData, &qname);
  v5 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(pData, &mn, pData->CurrentDomain);
  if ( v5 && v5->ITraits.pObject )
    v4 = (char)Scaleform::GFx::AS3::Traits::GetConstructor(&v5->Scaleform::GFx::AS3::Traits)[1].__vftable;
  Scaleform::String::String(&vm);
  if ( v4 )
  {
    Scaleform::GFx::ASUtils::Unescape(value->pNode->pData, value->pNode->Size, &vm);
  }
  else if ( !Scaleform::GFx::ASUtils::AS3::Unescape(value->pNode->pData, (const char *)value->pNode->Size, &vm, 0) )
  {
    goto LABEL_11;
  }
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pData->StringManagerRef->pStringManager,
                 (char *)((vm.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(vm.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  v7 = result;
  v8 = StringNode;
  StringNode->RefCount += 2;
  pNode = v7->pNode;
  v10 = v7->pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v7->pNode = v8;
  v10 = v8->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
LABEL_11:
  v11 = (void *)(vm.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vm.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  if ( mn.Obj.pObject && ((int)mn.Obj.pObject & 1) == 0 )
  {
    RefCount = mn.Obj.pObject->RefCount;
    pObject = mn.Obj.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      mn.Obj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
