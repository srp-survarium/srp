void __thiscall Scaleform::Render::Renderer2DImpl::Renderer2DImpl(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::GFx::Resource *hal)
{
  Scaleform::Render::ThreadCommandQueue *v4; // ecx
  Scaleform::Render::HALNotify *v5; // edi
  Scaleform::MemoryHeap *v6; // eax
  Scaleform::MemoryHeap *v7; // eax
  Scaleform::MemoryHeap *v8; // eax
  int *p_ScissorTop; // ecx
  Scaleform::MemoryHeap *v10; // edi
  Scaleform::Render::MeshKeyManager *v11; // eax
  Scaleform::Render::HAL *v12; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::GlyphCache *v14; // eax
  Scaleform::Render::GlyphCache *v15; // eax
  Scaleform::Render::GlyphCache *v16; // edi
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::Render::HAL *hala; // [esp+18h] [ebp+4h]

  v4 = (Scaleform::Render::ThreadCommandQueue *)hal[6].__vftable;
  this->Scaleform::Render::ContextImpl::RenderNotify::__vftable = (Scaleform::Render::Renderer2DImpl_vtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable';
  this->ActiveContextSet.Root.Scaleform::Render::ContextImpl::RenderNotify::pPrev = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet;
  this->ActiveContextSet.Root.pNext = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet;
  this->pRTCommandQueue = v4;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::__vftable = (Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->ServiceCommandInstance.RefCount = 1;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::__vftable = (Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand_vtbl *)&Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand::`vftable';
  this->ServiceCommandInstance.pNotify = this;
  v5 = &this->Scaleform::Render::HALNotify;
  this->Scaleform::Render::HALNotify::__vftable = (Scaleform::Render::HALNotify_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  this->pNext = 0;
  this->pPrev = 0;
  this->Scaleform::Render::ContextImpl::RenderNotify::__vftable = (Scaleform::Render::Renderer2DImpl_vtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::ContextImpl::RenderNotify'};
  this->Scaleform::Render::HALNotify::__vftable = (Scaleform::Render::HALNotify_vtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::HALNotify'};
  Scaleform::RefCountImpl::AddRef(hal);
  this->pHal.pObject = (Scaleform::Render::HAL *)hal;
  v6 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::MeshGenerator::MeshGenerator(&this->MeshGen, v6);
  v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::StrokeGenerator::StrokeGenerator(&this->StrokeGen, v7);
  Scaleform::Render::ToleranceParams::ToleranceParams(&this->Tolerances);
  this->FillManager.__vftable = (Scaleform::Render::PrimitiveFillManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->FillManager.RefCount = 1;
  this->FillManager.__vftable = (Scaleform::Render::PrimitiveFillManager_vtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable';
  this->FillManager.pHAL = (Scaleform::Render::HAL *)hal;
  this->FillManager.FillSet.pTable = 0;
  this->FillManager.Gradients.pTable = 0;
  v8 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::MatrixPool(&this->MPool, v8);
  this->pMeshKeyManager.pObject = 0;
  this->pGlyphCache.pObject = 0;
  Scaleform::Render::GlyphCacheParams::GlyphCacheParams(&this->mGlyphCacheParam, 1u, 0x400u, 0x400u, 0x30u);
  this->mComplexMeshUpdateList.Root.pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)&this->mComplexMeshUpdateList;
  this->mComplexMeshUpdateList.Root.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)&this->mComplexMeshUpdateList;
  this->VP.BufferWidth = 0;
  this->VP.BufferHeight = 0;
  this->VP.Top = 0;
  this->VP.Left = 0;
  this->VP.Height = 1;
  this->VP.Width = 1;
  this->VP.ScissorHeight = 0;
  this->VP.ScissorWidth = 0;
  this->VP.ScissorTop = 0;
  this->VP.ScissorLeft = 0;
  this->VP.Flags = 0;
  if ( this == (Scaleform::Render::Renderer2DImpl *)-2032 )
    p_ScissorTop = 0;
  else
    p_ScissorTop = &this->VP.ScissorTop;
  this->RenderRoots.Root.pPrev = (Scaleform::Render::TreeCacheNode *)p_ScissorTop;
  this->RenderRoots.Root.pNext = (Scaleform::Render::TreeCacheNode *)p_ScissorTop;
  this->pPrev = (Scaleform::Render::HALNotify *)hal[1].RefCount.Value;
  this->pNext = (Scaleform::Render::HALNotify *)&hal[1];
  *(_DWORD *)(hal[1].RefCount.Value + 8) = v5;
  hal[1].RefCount.Value = (volatile int)v5;
  v10 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v11 = (Scaleform::Render::MeshKeyManager *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               52,
                                               0);
  if ( v11 )
  {
    Scaleform::Render::MeshKeyManager::MeshKeyManager(v11, v10);
    hala = v12;
  }
  else
  {
    hala = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pMeshKeyManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pMeshKeyManager.pObject = (Scaleform::Render::MeshKeyManager *)hala;
  v14 = (Scaleform::Render::GlyphCache *)v10->Alloc(v10, 5088u, 0);
  if ( v14 )
  {
    Scaleform::Render::GlyphCache::GlyphCache(v14, v10);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  v17 = (Scaleform::RefCountVImpl *)this->pGlyphCache.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  this->pGlyphCache.pObject = v16;
  Scaleform::Render::GlyphCache::Initialize(v16, (Scaleform::Render::HAL *)hal, &this->FillManager);
}
