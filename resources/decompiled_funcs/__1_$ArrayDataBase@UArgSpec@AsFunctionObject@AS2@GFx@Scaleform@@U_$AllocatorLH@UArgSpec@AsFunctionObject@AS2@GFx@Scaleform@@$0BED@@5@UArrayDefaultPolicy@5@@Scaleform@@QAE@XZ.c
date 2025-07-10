void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v3; // ecx
  Scaleform::GFx::ASString *p_Name; // esi
  unsigned int v5; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    p_Name = &v3->Name;
    v5 = Size;
    do
    {
      pNode = p_Name->pNode;
      if ( p_Name->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      p_Name -= 2;
      --v5;
    }
    while ( v5 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
