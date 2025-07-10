void __thiscall Scaleform::Render::ShapeDataFloatMP::ShapeDataFloatMP(Scaleform::Render::ShapeDataFloatMP *this)
{
  Scaleform::Render::ShapeDataFloat *v2; // eax
  Scaleform::Render::ShapeDataFloat *v3; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  int v5; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(this);
  this->Scaleform::Render::ShapeMeshProvider::Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeDataFloatMP_vtbl *)&Scaleform::Render::ShapeDataFloatMP::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::ShapeMeshProvider::Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::ShapeDataFloatMP::`vftable'{for `Scaleform::Render::MeshProvider'};
  this->pData.pObject = 0;
  v5 = 2;
  v2 = (Scaleform::Render::ShapeDataFloat *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              72,
                                              &v5);
  if ( v2 )
  {
    v2->__vftable = (Scaleform::Render::ShapeDataFloat_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v2->RefCount = 1;
    v2->Status = Status_Clean;
    v2->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0;
    v2->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0;
    v2->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0;
    v2->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0;
    v2->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0;
    v2->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0;
    v2->StartX = 0.0;
    v2->StartY = 0.0;
    v2->LastX = 0.0;
    v2->Data = &v2->Container;
    v2->LastY = 0.0;
    v2->StartingPos = 0;
    v2->__vftable = (Scaleform::Render::ShapeDataFloat_vtbl *)&Scaleform::Render::ShapeDataFloat::`vftable';
    v2->Container.Data.Data = 0;
    v2->Container.Data.Size = 0;
    v2->Container.Data.Policy.Capacity = 0;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pData.pObject = v3;
}
