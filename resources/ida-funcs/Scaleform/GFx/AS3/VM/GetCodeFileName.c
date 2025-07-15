void __thiscall Scaleform::GFx::AS3::VM::GetCodeFileName(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 result->pNode->pManager,
                 (__m128i *)((this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F].pFile->File.pObject->Source.HeapTypeBits
                            & 0xFFFFFFFC)
                           + 8),
                 *(_DWORD *)(this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F].pFile->File.pObject->Source.HeapTypeBits
                           & 0xFFFFFFFC)
               & 0x7FFFFFFF);
  ++StringNode->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
}
