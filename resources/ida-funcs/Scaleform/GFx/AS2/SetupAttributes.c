void __cdecl Scaleform::GFx::AS2::SetupAttributes(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *preal)
{
  Scaleform::GFx::AS2::Environment *v2; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::XML::ElementNode *v5; // esi
  Scaleform::GFx::AS3::Object::UserDataHolder *pShadow; // edi
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::Movie *v8; // eax
  Scaleform::GFx::Movie *v9; // ebx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pMovieView; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::Attribute *FirstAttribute; // ebx
  __m128i *pData; // esi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  __m128i **pNode; // edx
  Scaleform::GFx::Movie *v17; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v22; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Object::UserDataHolder *v23; // [esp+1Ch] [ebp-18h]
  __m128i *v24; // [esp+20h] [ebp-14h]
  Scaleform::GFx::AS2::Value v25; // [esp+24h] [ebp-10h] BYREF

  v2 = penv;
  pHeap = penv->StringContext.pContext->pHeap;
  Alloc = pHeap->Alloc;
  v5 = preal;
  pShadow = (Scaleform::GFx::AS3::Object::UserDataHolder *)preal->pShadow;
  v23 = pShadow;
  v7 = (Scaleform::GFx::AS2::Object *)Alloc(pHeap, 52u, 0);
  if ( v7 )
  {
    Scaleform::GFx::AS2::Object::Object(v7, v2);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pMovieView = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pShadow[1].pMovieView;
  if ( pMovieView )
  {
    RefCount = pMovieView->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pMovieView->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pMovieView);
    }
  }
  pShadow[1].pMovieView = v9;
  if ( Scaleform::GFx::XML::ElementNode::HasAttributes((Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v5) )
  {
    FirstAttribute = v5->FirstAttribute;
    if ( FirstAttribute )
    {
      while ( 1 )
      {
        pData = (__m128i *)FirstAttribute->Value.pNode->pData;
        StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v2->StringContext.pContext);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, pData);
        ++StringNode->RefCount;
        v25.T.Type = 5;
        v25.NV.Int32Value = (int)StringNode;
        ++StringNode->RefCount;
        pNode = (__m128i **)FirstAttribute->Name.pNode;
        v17 = pShadow[1].pMovieView;
        pContext = v2->StringContext.pContext;
        LOBYTE(penv) = 0;
        v24 = *pNode;
        v19 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
        v22 = Scaleform::GFx::ASStringManager::CreateStringNode(v19->pStringManager, v24);
        ++v22->RefCount;
        ((void (__thiscall *)(Scaleform::GFx::Movie *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment **))v17[1].HasLooped)(
          &v17[1],
          v2,
          &v22,
          &v25,
          &penv);
        v20 = v22;
        --v22->RefCount;
        if ( !v20->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        Scaleform::GFx::AS2::Value::~Value(&v25);
        if ( StringNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        FirstAttribute = FirstAttribute->Next;
        if ( !FirstAttribute )
          break;
        pShadow = v23;
      }
      v5 = preal;
    }
    Scaleform::GFx::XML::ElementNode::ClearAttributes(v5);
  }
}
