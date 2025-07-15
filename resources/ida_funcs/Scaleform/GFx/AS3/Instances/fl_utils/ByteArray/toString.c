void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::toString(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::ASString *result)
{
  unsigned int Size; // ebx
  unsigned __int8 *Data; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // zf
  Scaleform::GFx::ASString v11; // [esp+Ch] [ebp-4h] BYREF

  Size = this->Data.Data.Size;
  Data = this->Data.Data.Data;
  if ( Size <= 1 )
  {
LABEL_11:
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                   (char *)Data,
                   Size);
    goto LABEL_12;
  }
  if ( (*Data != 0xFE || Data[1] != 0xFF) && (*Data != 0xFF || Data[1] != 0xFE) )
  {
    if ( Size > 2 && Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::IsUTF8BOM((const char *)this->Data.Data.Data) )
    {
      v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v11,
             (char *)Data + 3,
             Size - 3);
      Scaleform::GFx::ASString::operator=(result, v6);
      pNode = v11.pNode;
      --v11.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    goto LABEL_11;
  }
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (const wchar_t *)Data + 1,
                 (Size - 2) >> 1);
LABEL_12:
  v8 = StringNode;
  StringNode->RefCount += 2;
  v9 = result->pNode;
  v10 = result->pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  result->pNode = v8;
  v10 = v8->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
