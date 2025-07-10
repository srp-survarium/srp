void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::GFx::ASString *v3; // esi
  unsigned int v4; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      pNode = v3->pNode;
      if ( v3->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
