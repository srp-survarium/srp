void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::Button::CharToRec>::DestructArray(
        Scaleform::GFx::Button::CharToRec *p,
        unsigned int count)
{
  Scaleform::GFx::Button::CharToRec *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->Char.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->Char.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::DocView::ImageSubstitutor::Element>::DestructArray(
        Scaleform::Render::Text::DocView::ImageSubstitutor::Element *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::Text::ImageDesc> *p_pImageDesc; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pImageDesc = &p[count - 1].pImageDesc;
    v3 = count;
    do
    {
      if ( p_pImageDesc->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pImageDesc->pObject);
      p_pImageDesc -= 12;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo>::DestructArray(
        Scaleform::GFx::AS3::SocketThreadMgr::EventInfo *p,
        unsigned int count)
{
  Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_EventParameters; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_EventParameters = &p[count - 1].EventParameters;
    v3 = count;
    do
    {
      if ( p_EventParameters->Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_EventParameters->Data.Data);
      p_EventParameters = (Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)((char *)p_EventParameters
                                                                                            - 16);
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::ComplexMesh::FillRecord>::DestructArray(
        Scaleform::Render::ComplexMesh::FillRecord *p,
        unsigned int count)
{
  Scaleform::Render::ComplexMesh::FillRecord *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pFill.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->pFill.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::FilterStackEntry>::DestructArray(
        Scaleform::Render::HAL::FilterStackEntry *p,
        unsigned int count)
{
  Scaleform::Render::HAL::FilterStackEntry *v2; // esi
  unsigned int v3; // edi
  Scaleform::Render::RenderTarget *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pRenderTarget.pObject;
      if ( pObject )
        pObject->Release(pObject);
      if ( v2->pPrimitive.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v2->pPrimitive.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::FontDesc>::DestructArray(
        Scaleform::GFx::MovieImpl::FontDesc *p,
        unsigned int count)
{
  Scaleform::GFx::MovieImpl::FontDesc *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::Resource *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pFont.pObject;
      if ( pObject )
        Scaleform::GFx::Resource::Release(pObject);
      if ( v2->pMovieDef.pObject )
        Scaleform::GFx::Resource::Release(v2->pMovieDef.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
        Scaleform::GFx::MovieDataDef::FrameLabelInfo *p,
        unsigned int count)
{
  Scaleform::GFx::MovieDataDef::FrameLabelInfo *v2; // edi
  unsigned int v3; // ebp
  volatile LONG *v4; // esi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      v4 = (volatile LONG *)(v2->Name.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo *p,
        unsigned int count)
{
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v2; // edi
  unsigned int v3; // ebp
  volatile LONG *v4; // esi
  volatile LONG *v5; // esi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      v4 = (volatile LONG *)(v2->Id.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      v5 = (volatile LONG *)(v2->Url.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
      if ( v2->pTextImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->pTextImageDesc.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::IndirectTransPair>::DestructArray(
        Scaleform::GFx::MovieImpl::IndirectTransPair *p,
        unsigned int count)
{
  Scaleform::GFx::MovieImpl::IndirectTransPair *v2; // esi
  unsigned int v3; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Render::ContextImpl::Entry *v6; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->OriginalParent.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      v5 = v2->Obj.pObject;
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      v6 = v2->TransformParent.pObject;
      if ( v2->TransformParent.pObject )
      {
        if ( v6->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry>::DestructArray(
        Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *p,
        unsigned int count)
{
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v2; // esi
  unsigned int v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = (Scaleform::RefCountVImpl *)v2->pMesh.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      if ( v2->M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v2->M.pHandle->pHeader);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener>::DestructArray(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Value *p_mFunction; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_mFunction = &p[count - 1].mFunction;
    v3 = count;
    do
    {
      if ( (p_mFunction->Flags & 0x1F) > 9 )
      {
        if ( (p_mFunction->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mFunction);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(p_mFunction);
      }
      p_mFunction = (Scaleform::GFx::AS3::Value *)((char *)p_mFunction - 24);
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::MaskStackEntry>::DestructArray(
        Scaleform::Render::HAL::MaskStackEntry *p,
        unsigned int count)
{
  Scaleform::RefCountVImpl **v2; // esi
  unsigned int v3; // edi

  v2 = (Scaleform::RefCountVImpl **)&p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( *v2 )
        Scaleform::RefCountImpl::Release(*v2);
      v2 -= 6;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::MDKillListEntry>::DestructArray(
        Scaleform::GFx::MovieImpl::MDKillListEntry *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *p_pMovieDef; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pMovieDef = &p[count - 1].pMovieDef;
    v3 = count;
    do
    {
      if ( p_pMovieDef->pObject )
        Scaleform::GFx::Resource::Release(p_pMovieDef->pObject);
      p_pMovieDef -= 4;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Font::NativeHintingType>::DestructArray(
        Scaleform::Render::Font::NativeHintingType *p,
        unsigned int count)
{
  Scaleform::Render::Font::NativeHintingType *v2; // edi
  unsigned int v3; // ebp
  volatile LONG *v4; // esi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      v4 = (volatile LONG *)(v2->Typeface.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Slots::Pair>::DestructArray(
        Scaleform::GFx::AS3::Slots::Pair *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Slots::Pair *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v2->Value);
      pObject = v2->Key.pObject;
      if ( v2->Key.pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership>::DestructArray(
        Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *p,
        unsigned int count)
{
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v2; // esi
  unsigned int v3; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->Owner.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      if ( v2->mPrefix.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->mPrefix.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::DestructArray(
        Scaleform::Render::HAL::RenderTargetEntry *p,
        unsigned int count)
{
  Scaleform::Render::HAL::RenderTargetEntry *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      Scaleform::RefCountImplCore::~RefCountImplCore(&v2->OldMatrixState);
      if ( v2->pRenderTarget.pObject )
        v2->pRenderTarget.pObject->Release(v2->pRenderTarget.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::SceneInfo>::DestructArray(
        Scaleform::GFx::MovieDataDef::SceneInfo *p,
        unsigned int count)
{
  Scaleform::GFx::MovieDataDef::SceneInfo *v2; // esi
  unsigned int v3; // ebp
  volatile LONG *v4; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
        v2->Labels.Data.Data,
        v2->Labels.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2->Labels.Data.Data);
      v4 = (volatile LONG *)(v2->Name.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
        Scaleform::Render::StrokeStyleType *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *p_pFill; // esi
  unsigned int v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( count )
  {
    p_pFill = &p[count - 1].pFill;
    v3 = count;
    do
    {
      pObject = (Scaleform::RefCountVImpl *)p_pFill[1].pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      if ( p_pFill->pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)p_pFill->pObject);
      p_pFill -= 7;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextMeshEntry>::DestructArray(
        Scaleform::Render::TextMeshEntry *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::PrimitiveFill> *p_pFill; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pFill = &p[count - 1].pFill;
    v3 = count;
    do
    {
      if ( p_pFill->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pFill->pObject);
      p_pFill -= 8;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextMeshLayer>::DestructArray(
        Scaleform::Render::TextMeshLayer *p,
        unsigned int count)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_M; // esi
  unsigned int v3; // edi
  Scaleform::RefCountNTSImpl *pHandle; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v5; // eax
  Scaleform::Render::MeshKey *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  if ( count )
  {
    p_M = &p[count - 1].M;
    v3 = count;
    do
    {
      pHandle = (Scaleform::RefCountNTSImpl *)p_M[1].pHandle;
      if ( pHandle )
        Scaleform::RefCountNTSImpl::Release(pHandle);
      if ( p_M->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(p_M->pHandle->pHeader);
      v5 = p_M[-1].pHandle;
      if ( v5 )
        (*(void (__thiscall **)(Scaleform::Render::MatrixPoolImpl::EntryHandle *))&v5[2].pHeader->DataPageOffset)(v5 + 2);
      v6 = (Scaleform::Render::MeshKey *)p_M[-2].pHandle;
      if ( v6 )
        Scaleform::Render::MeshKey::Release(v6);
      v7 = (Scaleform::RefCountVImpl *)p_M[-3].pHandle;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      p_M -= 9;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::DestructArray(
        Scaleform::Render::TextureGlyph *p,
        unsigned int count)
{
  Scaleform::Render::TextureGlyph *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      ((void (__thiscall *)(Scaleform::Render::TextureGlyph *, _DWORD))v2->~Scaleform::Render::TextureGlyph)(v2, 0);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>>::DestructArray(
        Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *p,
        unsigned int count)
{
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pNode = v2->First.pNode;
      if ( v2->First.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::DestructArray(
        Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *p,
        unsigned int count)
{
  unsigned int v2; // edi
  Scaleform::Render::Text::TextFormat *p_TextFmt; // esi

  v2 = count;
  if ( count )
  {
    p_TextFmt = &p[count - 1].TextFmt;
    do
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&p_TextFmt[1]);
      Scaleform::Render::Text::TextFormat::~TextFormat(p_TextFmt);
      p_TextFmt = (Scaleform::Render::Text::TextFormat *)((char *)p_TextFmt - 76);
      --v2;
    }
    while ( v2 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
        Scaleform::GFx::AS2::ArraySortFunctor *p,
        unsigned int count)
{
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  unsigned int RefCount; // eax
  bool v6; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  unsigned int v8; // eax

  if ( count )
  {
    p_pLocalFrame = &p[count - 1].Func.pLocalFrame;
    v3 = count;
    do
    {
      if ( ((_BYTE)p_pLocalFrame[1] & 2) == 0 )
      {
        v4 = *(p_pLocalFrame - 1);
        if ( v4 )
        {
          RefCount = v4->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
      }
      v6 = ((_BYTE)p_pLocalFrame[1] & 1) == 0;
      *(p_pLocalFrame - 1) = 0;
      if ( v6 )
      {
        v7 = *p_pLocalFrame;
        if ( *p_pLocalFrame )
        {
          v8 = v7->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v8) != 0 )
          {
            v7->RefCount = v8 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
          }
        }
      }
      *p_pLocalFrame = 0;
      p_pLocalFrame -= 7;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ASString>::DestructArray(
        Scaleform::GFx::ASString *p,
        unsigned int count)
{
  Scaleform::GFx::ASString *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pNode = v2->pNode;
      if ( v2->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::DestructArray(
        Scaleform::GFx::ButtonRecord *p,
        unsigned int count)
{
  Scaleform::RefCountVImpl **p_pFilters; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pFilters = (Scaleform::RefCountVImpl **)&p[count - 1].pFilters;
    v3 = count;
    do
    {
      if ( *p_pFilters )
        Scaleform::RefCountImpl::Release(*p_pFilters);
      p_pFilters -= 24;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::DisplayList::DisplayEntry>::DestructArray(
        Scaleform::GFx::DisplayList::DisplayEntry *p,
        unsigned int count)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pCharacter )
        Scaleform::RefCountNTSImpl::Release(v2->pCharacter);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception>::DestructArray(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *p,
        unsigned int count)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *i; // esi

  v2 = count;
  for ( i = &p[count - 1]; v2; --v2 )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, i->info.Data.Data);
    --i;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
        Scaleform::Render::MatrixPoolImpl::HMatrix *p,
        unsigned int count)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v2->pHandle->pHeader);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __usercall Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
        Scaleform::Render::Text::Paragraph *a1@<edi>,
        Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *p,
        unsigned int count)
{
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v3; // ebx
  unsigned int v4; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // esi
  Scaleform::Render::Text::ParagraphFormat *pObject; // edi

  v3 = &p[count - 1];
  if ( count )
  {
    v4 = count;
    do
    {
      pPara = v3->pPara;
      if ( v3->pPara )
      {
        Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
          pPara->FormatInfo.Ranges.Data.Data,
          pPara->FormatInfo.Ranges.Data.Size);
        ((void (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *, Scaleform::Render::Text::Paragraph *))Scaleform::Memory::pGlobalHeap->Free)(
          Scaleform::Memory::pGlobalHeap,
          pPara->FormatInfo.Ranges.Data.Data,
          a1);
        pObject = pPara->pFormat.pObject;
        if ( pObject )
        {
          if ( pObject->RefCount-- == 1 )
          {
            Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
          }
        }
        Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pPara);
        a1 = pPara;
        ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
      }
      --v3;
      --v4;
    }
    while ( v4 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::String>::DestructArray(Scaleform::String *p, unsigned int count)
{
  Scaleform::String *v2; // edi
  unsigned int v3; // ebp
  volatile LONG *v4; // esi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      v4 = (volatile LONG *)(v2->HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(
        Scaleform::GFx::AS2::Value *p,
        unsigned int count)
{
  Scaleform::GFx::AS2::Value *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v2);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        Scaleform::GFx::AS3::Value *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Value *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( (v2->Flags & 0x1F) > 9 )
      {
        if ( (v2->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *p,
        unsigned int count)
{
  Scaleform::RefCountVImpl **v2; // esi
  unsigned int v3; // edi

  v2 = (Scaleform::RefCountVImpl **)&p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( *v2 )
        Scaleform::RefCountImpl::Release(*v2);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Fence>>::DestructArray(
        Scaleform::Ptr<Scaleform::Render::Fence> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::Fence> *v2; // ebx
  unsigned int v3; // ebp
  Scaleform::Render::Fence *pObject; // esi
  Scaleform::Render::RenderSync *RSContext; // edi
  Scaleform::Render::FenceImpl *Data; // eax
  int p_APIHandle; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( !--pObject->RefCount )
        {
          if ( pObject->HasData )
          {
            RSContext = pObject->Data->RSContext;
            ((void (__stdcall *)(_DWORD, _DWORD))RSContext->FenceFrameAlloc.pHeapOrPtr)(
              pObject->Data->APIHandle,
              HIDWORD(pObject->Data->APIHandle));
            Data = pObject->Data;
            Data->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
            RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)Data;
            pObject->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
            RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)pObject;
          }
          else
          {
            p_APIHandle = (int)&pObject->Data[2].APIHandle;
            pObject->Data = (Scaleform::Render::FenceImpl *)HIDWORD(pObject->Data[2].FenceID);
            *(_DWORD *)(p_APIHandle + 12) = pObject;
          }
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Image>>::DestructArray(
        Scaleform::Ptr<Scaleform::Render::Image> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::Image> *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pObject )
        v2->pObject->Release(v2->pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pObject )
        Scaleform::GFx::Resource::Release(v2->pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AS2::Object>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
  unsigned int RefCount; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::Sprite>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pObject )
        Scaleform::RefCountNTSImpl::Release(v2->pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::DestructArray(
        Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *p,
        unsigned int count)
{
  Scaleform::GFx::TextField::CSSHolderBase::UrlZone *p_Data; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_Data = &p[count - 1].Data;
    v3 = count;
    do
    {
      if ( p_Data->SavedFmt.pObject )
        Scaleform::RefCountNTSImpl::Release(p_Data->SavedFmt.pObject);
      p_Data = (Scaleform::GFx::TextField::CSSHolderBase::UrlZone *)((char *)p_Data - 20);
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>>::DestructArray(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v2->pObject = (Scaleform::GFx::ASStringNode *)((char *)pObject - 1);
        }
        else if ( pObject->RefCount-- == 1 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ecx
  unsigned int RefCount; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v2->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>>::DestructArray(
        Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p,
        unsigned int count)
{
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v2; // esi
  unsigned int v3; // edi
  Scaleform::WeakPtrProxy *pObject; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pProxy.pObject;
      if ( v2->pProxy.pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
