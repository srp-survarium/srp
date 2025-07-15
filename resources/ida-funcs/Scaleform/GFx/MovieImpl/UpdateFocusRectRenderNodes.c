void __thiscall Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::TreeContainer *pObject; // esi
  Scaleform::Render::TreeContainer *v3; // eax
  Scaleform::Render::TreeContainer *v4; // ecx
  Scaleform::Render::TreeContainer *v5; // esi
  bool v6; // zf
  Scaleform::Render::TreeRoot *v7; // esi
  unsigned int v8; // eax
  unsigned int Size; // eax
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_LastFocused; // edi
  Scaleform::WeakPtrProxy *v11; // eax
  Scaleform::GFx::DisplayObjectBase *v12; // esi
  const __m128i *WorldMatrix3D; // eax
  double v14; // st6
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::ShapeDataFloat *v16; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v17; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v18; // esi
  Scaleform::Render::ShapeMeshProvider *v19; // eax
  float v20; // eax
  Scaleform::Render::ShapeMeshProvider *v21; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v22; // eax
  Scaleform::Render::TreeShape *v23; // edi
  unsigned int v24; // eax
  Scaleform::Render::ContextImpl::Entry *v25; // ecx
  Scaleform::Render::TreeContainer *y; // [esp+14h] [ebp-C4h]
  float x; // [esp+30h] [ebp-A8h] BYREF
  int v28; // [esp+34h] [ebp-A4h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+38h] [ebp-A0h] BYREF
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v30; // [esp+50h] [ebp-88h]
  unsigned int v31; // [esp+54h] [ebp-84h]
  int v32; // [esp+58h] [ebp-80h]
  Scaleform::GFx::DisplayObjectBase *v33; // [esp+5Ch] [ebp-7Ch]
  Scaleform::Render::FillStyleType fill; // [esp+60h] [ebp-78h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+68h] [ebp-70h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+78h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+A8h] [ebp-30h] BYREF

  if ( this->pMainMovie )
  {
    pObject = this->FocusRectContainerNode.pObject;
    if ( pObject )
    {
      Size = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
      Scaleform::Render::TreeContainer::Remove(pObject, 0, Size);
    }
    else
    {
      v3 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->RenderContext);
      v4 = this->FocusRectContainerNode.pObject;
      v5 = v3;
      if ( v4 )
      {
        v6 = v4->RefCount-- == 1;
        if ( v6 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
      }
      this->FocusRectContainerNode.pObject = v5;
      v7 = this->pRenderRoot.pObject;
      y = this->FocusRectContainerNode.pObject;
      v8 = Scaleform::Render::TreeContainer::GetSize(v7);
      Scaleform::Render::TreeContainer::Insert(v7, v8, (Scaleform::Render::TreeNodeArray *)y);
    }
    v31 = 0;
    if ( this->FocusGroupsCnt )
    {
      v32 = 0;
      p_LastFocused = &this->FocusGroups[0].LastFocused;
      v30 = &this->FocusGroups[0].LastFocused;
      do
      {
        v11 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          if ( v11->pObject )
          {
            v12 = (Scaleform::GFx::DisplayObjectBase *)v11->pObject;
            v6 = v12->RefCount == 0;
            v33 = v12;
            if ( !v6 )
            {
              ++v12->RefCount;
              ++v12->RefCount;
              Scaleform::RefCountNTSImpl::Release(v12);
              if ( LOBYTE(p_LastFocused[7].pProxy.pObject)
                && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObjectBase *))v12->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetProjectionMatrix3D)(v12) )
              {
                ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *))v12->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].UpdateTransform3D)(
                  v12,
                  &r);
                if ( r.x1 == r.x2 && r.y1 == r.y2 )
                {
                  Scaleform::RefCountNTSImpl::Release(v12);
                  return;
                }
                WorldMatrix3D = (const __m128i *)Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v12, &result);
                memcpy((int)&dst, WorldMatrix3D, sizeof(dst));
                Scaleform::Render::Matrix3x4<float>::EncloseTransform(&dst, &pr, &r);
                *(float *)&v28 = (double)v31 * 20.0;
                x = *(float *)&v28;
                v14 = *(float *)&v28;
                v28 = 2;
                AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
                pr.x1 = pr.x1 - v14;
                pr.x2 = v14 + pr.x2;
                pr.y1 = pr.y1 - x;
                pr.y2 = x + pr.y2;
                v16 = (Scaleform::Render::ShapeDataFloat *)AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this,
                                                             72u,
                                                             (const Scaleform::AllocInfo *)&v28);
                if ( v16 )
                {
                  Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v16);
                  v18 = v17;
                }
                else
                {
                  v18 = 0;
                }
                fill.pFill.pObject = 0;
                fill.Color = v32 ^ 0xFFFFFF00 | 0xFF000000;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
                  v18,
                  &fill);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
                  v18,
                  1u,
                  0,
                  0);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
                  v18,
                  pr.x1,
                  pr.y1);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x2,
                  pr.y1);
                x = pr.y1 + 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x2,
                  x);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x1,
                  x);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
                  v18,
                  1u,
                  0,
                  0);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
                  v18,
                  pr.x2,
                  pr.y1);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x2,
                  pr.y2);
                x = pr.x2 - 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  x,
                  pr.y2);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  x,
                  pr.y1);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
                  v18,
                  1u,
                  0,
                  0);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
                  v18,
                  pr.x2,
                  pr.y2);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x1,
                  pr.y2);
                x = pr.y2 - 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x1,
                  x);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x2,
                  x);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
                  v18,
                  1u,
                  0,
                  0);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
                  v18,
                  pr.x1,
                  pr.y2);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x1,
                  pr.y1);
                x = pr.x1 + 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  x,
                  pr.y1);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  x,
                  pr.y2);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v18);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v18);
                v28 = 2;
                v19 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this,
                                                                96,
                                                                &v28);
                if ( v19 )
                {
                  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v19, (Scaleform::GFx::Resource *)v18, 0);
                  *(float *)&v28 = v20;
                }
                else
                {
                  *(float *)&v28 = 0.0;
                }
                LODWORD(x) = 2;
                v21 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this,
                                                                96,
                                                                &x);
                if ( v21 )
                {
                  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v21, (Scaleform::GFx::Resource *)v18, 0);
                  x = *(float *)&v22;
                }
                else
                {
                  x = 0.0;
                }
                v23 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(&this->RenderContext);
                Scaleform::Render::TreeShape::SetShape(
                  v23,
                  (Scaleform::Render::ContextImpl::EntryData_vtbl *)LODWORD(x));
                v24 = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
                Scaleform::Render::TreeContainer::Insert(
                  this->FocusRectContainerNode.pObject,
                  v24,
                  (Scaleform::Render::TreeNodeArray *)v23);
                if ( v23 )
                  ++v23->RefCount;
                v25 = (Scaleform::Render::ContextImpl::Entry *)v30[-5].pProxy.pObject;
                if ( v25 )
                {
                  v6 = v25->RefCount-- == 1;
                  if ( v6 )
                    Scaleform::Render::ContextImpl::Entry::destroyHelper(v25);
                }
                v30[-5].pProxy.pObject = (Scaleform::WeakPtrProxy *)v23;
                if ( v23 )
                {
                  v6 = v23->RefCount-- == 1;
                  if ( v6 )
                    Scaleform::Render::ContextImpl::Entry::destroyHelper(v23);
                }
                if ( x != 0.0 )
                  (*(void (__thiscall **)(int))(*(_DWORD *)(LODWORD(x) + 8) + 8))(LODWORD(x) + 8);
                if ( *(float *)&v28 != 0.0 )
                  (*(void (__thiscall **)(int))(*(_DWORD *)(v28 + 8) + 8))(v28 + 8);
                if ( fill.pFill.pObject )
                  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)fill.pFill.pObject);
                if ( v18 )
                  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18);
                v12 = v33;
                p_LastFocused = v30;
              }
              Scaleform::RefCountNTSImpl::Release(v12);
            }
          }
          else
          {
            v6 = v11->RefCount-- == 1;
            if ( v6 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
            p_LastFocused->pProxy.pObject = 0;
          }
        }
        v32 += 1081552;
        p_LastFocused += 16;
        ++v31;
        v30 = p_LastFocused;
      }
      while ( v31 < this->FocusGroupsCnt );
    }
    this->FocusRectChanged = 0;
  }
}
