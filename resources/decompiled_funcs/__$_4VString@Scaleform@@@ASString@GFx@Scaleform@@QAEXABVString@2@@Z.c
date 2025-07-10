void __thiscall Scaleform::GFx::ASString::operator=<Scaleform::String>(
        Scaleform::GFx::ASString *this,
        const Scaleform::String *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(str->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->pNode = StringNode;
}
