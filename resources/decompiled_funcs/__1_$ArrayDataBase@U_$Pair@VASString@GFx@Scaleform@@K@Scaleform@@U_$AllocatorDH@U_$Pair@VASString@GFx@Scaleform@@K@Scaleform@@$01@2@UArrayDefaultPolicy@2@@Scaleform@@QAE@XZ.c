void __thiscall Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v3; // esi
  unsigned int v4; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      pNode = v3->First.pNode;
      if ( v3->First.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
