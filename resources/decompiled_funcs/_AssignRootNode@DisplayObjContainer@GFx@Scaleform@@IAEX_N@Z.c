void __userpurge Scaleform::GFx::DisplayObjContainer::AssignRootNode(
        Scaleform::GFx::DisplayObjContainer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int importFlag)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::MovieDefRootNode *pNext; // eax
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // edx
  int v8; // ecx
  Scaleform::GFx::ASMovieRootBase *pASRoot; // ecx
  Scaleform::MemoryHeap *pHeap; // edi
  Scaleform::GFx::MovieDefRootNode *v11; // eax
  Scaleform::GFx::MovieDefImpl *pObject; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::FontManager *v14; // eax
  Scaleform::GFx::FontManager *v15; // eax
  Scaleform::GFx::FontManager *v16; // ebx
  Scaleform::GFx::MovieDefRootNode *pRootNode; // edi
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::Ptr<Scaleform::GFx::FontManager> *p_pFontManager; // edi
  Scaleform::GFx::MovieImpl *v20; // eax
  Scaleform::GFx::MovieDefRootNode *v21; // edx
  Scaleform::GFx::MovieDefRootNode *v22; // ecx

  if ( !this->pRootNode )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    pNext = pMovieImpl->RootMovieDefNodes.Root.pNext;
    p_RootMovieDefNodes = &pMovieImpl->RootMovieDefNodes;
    while ( 1 )
    {
      v8 = p_RootMovieDefNodes ? (int)&p_RootMovieDefNodes[-1].Root.4 : 0;
      if ( pNext == (Scaleform::GFx::MovieDefRootNode *)v8 )
        break;
      if ( pNext->pDefImpl == this->pDefImpl.pObject && pNext->ImportFlag == (_BYTE)importFlag )
      {
        ++pNext->SpriteRefCount;
        this->pRootNode = pNext;
        break;
      }
      pNext = pNext->pNext;
    }
    if ( !this->pRootNode )
    {
      pASRoot = this->pASRoot;
      pHeap = pASRoot->pMovieImpl->pHeap;
      v11 = (Scaleform::GFx::MovieDefRootNode *)((int (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::MemoryHeap *, Scaleform::GFx::MovieDefImpl *, int, int, int))pASRoot->CreateMovieDefRootNode)(
                                                  pASRoot,
                                                  pHeap,
                                                  this->pDefImpl.pObject,
                                                  importFlag,
                                                  a3,
                                                  a2);
      pObject = this->pDefImpl.pObject;
      this->pRootNode = v11;
      this->pRootNode->BytesLoaded = pObject->pBindData.pObject->BytesLoaded;
      if ( (_BYTE)importFlag )
        v13 = 0;
      else
        v13 = this->pDefImpl.pObject->GetLoadingFrame(this->pDefImpl.pObject);
      this->pRootNode->LoadingFrame = v13;
      v14 = (Scaleform::GFx::FontManager *)pHeap->Alloc(pHeap, 60u, 0);
      if ( v14 )
      {
        Scaleform::GFx::FontManager::FontManager(
          v14,
          this->pASRoot->pMovieImpl,
          this->pDefImpl.pObject,
          this->pASRoot->pMovieImpl->pFontManagerStates.pObject);
        v16 = v15;
      }
      else
      {
        v16 = 0;
      }
      pRootNode = this->pRootNode;
      v18 = (Scaleform::RefCountVImpl *)pRootNode->pFontManager.pObject;
      p_pFontManager = &pRootNode->pFontManager;
      if ( v18 )
        Scaleform::RefCountImpl::Release(v18);
      p_pFontManager->pObject = v16;
      v20 = this->pASRoot->pMovieImpl;
      v21 = v20->RootMovieDefNodes.Root.pNext;
      v22 = this->pRootNode;
      v20 = (Scaleform::GFx::MovieImpl *)((char *)v20 + 56);
      v22->pNext = v21;
      v22->pPrev = (Scaleform::GFx::MovieDefRootNode *)&v20[-1].IndirectTransformPairs.Data.Policy;
      *(_DWORD *)(v20->RefCount + 4) = v22;
      v20->RefCount = (volatile int)v22;
    }
  }
}
