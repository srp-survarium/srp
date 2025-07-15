void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toString(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  unsigned int Size; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  int v7; // eax
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v11; // zf
  Scaleform::MemoryHeap *MHeap; // [esp-10h] [ebp-34h]
  bool simple; // [esp+7h] [ebp-1Dh] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+8h] [ebp-1Ch]
  Scaleform::StringBuffer buf; // [esp+Ch] [ebp-18h] BYREF

  Scaleform::GFx::AS3::Instances::fl::XMLList::AS3hasSimpleContent(this, &simple);
  if ( simple )
  {
    pVM = this->pTraits.pObject->pVM;
    MHeap = pVM->MHeap;
    vm = pVM;
    Scaleform::StringBuffer::StringBuffer(&buf, MHeap);
    Size = this->List.Data.Size;
    v5 = 0;
    if ( Size )
    {
      do
      {
        pObject = this->List.Data.Data[v5].pObject;
        v7 = pObject->GetKind(pObject);
        if ( v7 != 4 && v7 != 3 )
          pObject->ToString(pObject, &buf, 0);
        ++v5;
      }
      while ( v5 < Size );
      pVM = vm;
    }
    pData = buf.pData;
    if ( !buf.pData )
      pData = (char *)&::buf;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   pVM->StringManagerRef->pStringManager,
                   pData,
                   buf.Size);
    StringNode->RefCount += 2;
    pNode = result->pNode;
    v11 = result->pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = StringNode;
    v11 = StringNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(this, result);
  }
}
