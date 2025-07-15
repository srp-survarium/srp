void __thiscall Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // eax
  Scaleform::GFx::MovieDefRootNode *v3; // eax
  Scaleform::GFx::MovieDefRootNode *v4; // ecx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *DepthToIndexMap; // edi

  pRootNode = this->pRootNode;
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DisplayObjContainer_vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pRootNode )
  {
    --pRootNode->SpriteRefCount;
    v3 = this->pRootNode;
    if ( !v3->SpriteRefCount )
    {
      v3->pPrev->pNext = v3->pNext;
      v3->pNext->pPrev = v3->pPrev;
      v4 = this->pRootNode;
      if ( v4 )
        ((void (__thiscall *)(Scaleform::GFx::MovieDefRootNode *, int))v4->~Scaleform::GFx::MovieDefRootNode)(v4, 1);
    }
  }
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
  DepthToIndexMap = this->mDisplayList.DepthToIndexMap;
  if ( DepthToIndexMap )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, DepthToIndexMap->Array.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, DepthToIndexMap);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>(&this->mDisplayList.DisplayObjectArray.Data);
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
}
