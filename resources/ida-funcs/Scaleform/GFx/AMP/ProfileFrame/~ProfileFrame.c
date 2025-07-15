void __thiscall Scaleform::GFx::AMP::ProfileFrame::~ProfileFrame(Scaleform::GFx::AMP::ProfileFrame *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ImageList);
  pObject = (Scaleform::RefCountVImpl *)this->Fonts.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->Images.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->MemoryByStatId.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FileHandles.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->SwdHandles.Data.Data);
  v5 = (Scaleform::RefCountVImpl *)this->DisplayFunctionStats.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->DisplayStats.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->MovieStats);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
