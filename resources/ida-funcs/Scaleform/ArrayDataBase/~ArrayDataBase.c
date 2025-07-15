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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::GFx::StaticTextSnapshotData::CharRef *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pChar.pObject )
        Scaleform::RefCountNTSImpl::Release(v3->pChar.pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Render::ComplexMesh::FillRecord *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pFill.pObject )
        Scaleform::RefCountNTSImpl::Release(v3->pFill.pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Render::FillStyleType *v3; // ecx
  Scaleform::RefCountVImpl **p_pFill; // esi
  unsigned int v5; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    p_pFill = (Scaleform::RefCountVImpl **)&v3->pFill;
    v5 = Size;
    do
    {
      if ( *p_pFill )
        Scaleform::RefCountImpl::Release(*p_pFill);
      p_pFill -= 2;
      --v5;
    }
    while ( v5 );
  }
  if ( this->Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Render::FillStyleType *v3; // ecx
  Scaleform::RefCountVImpl **p_pFill; // esi
  unsigned int v5; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    p_pFill = (Scaleform::RefCountVImpl **)&v3->pFill;
    v5 = Size;
    do
    {
      if ( *p_pFill )
        Scaleform::RefCountImpl::Release(*p_pFill);
      p_pFill -= 2;
      --v5;
    }
    while ( v5 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


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


void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pCharacter )
        Scaleform::RefCountNTSImpl::Release(v3->pCharacter);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pObject )
        Scaleform::RefCountNTSImpl::Release(v3->pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  if ( this->Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::RefCountVImpl **v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = (Scaleform::RefCountVImpl **)&this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( *v3 )
        Scaleform::RefCountImpl::Release(*v3);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pObject )
        Scaleform::RefCountNTSImpl::Release(v3->pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::RefCountVImpl **v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = (Scaleform::RefCountVImpl **)&this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( *v3 )
        Scaleform::RefCountImpl::Release(*v3);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  if ( this->Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::Render::Image> *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pObject )
        v3->pObject->Release(v3->pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pObject )
        Scaleform::GFx::Resource::Release(v3->pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  if ( this->Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}


void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pObject )
        Scaleform::GFx::Resource::Release(v3->pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
