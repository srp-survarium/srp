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
  unsigned __int8 *WorldMatrix3D; // eax
  double v14; // st6
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::ShapeDataFloat *v16; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v17; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v18; // esi
  Scaleform::Render::ShapeMeshProvider *v19; // eax
  float v20; // eax
  Scaleform::Render::ShapeMeshProvider *v21; // eax
  Scaleform::Render::ShapeMeshProvider *v22; // eax
  Scaleform::Render::TreeShape *v23; // edi
  unsigned int v24; // eax
  Scaleform::Render::ContextImpl::Entry *v25; // ecx
  Scaleform::Render::TreeContainer *y; // [esp+268h] [ebp-C4h]
  Scaleform::Render::ShapeMeshProvider *pshape; // [esp+284h] [ebp-A8h] BYREF
  int v28; // [esp+288h] [ebp-A4h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+28Ch] [ebp-A0h] BYREF
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v30; // [esp+2A4h] [ebp-88h]
  unsigned int v31; // [esp+2A8h] [ebp-84h]
  int v32; // [esp+2ACh] [ebp-80h]
  Scaleform::GFx::DisplayObjectBase *v33; // [esp+2B0h] [ebp-7Ch]
  Scaleform::Render::FillStyleType v34; // [esp+2B4h] [ebp-78h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+2BCh] [ebp-70h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+2CCh] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+2FCh] [ebp-30h] BYREF

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
      Scaleform::Render::TreeContainer::Insert(v7, v8, y);
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
                WorldMatrix3D = (unsigned __int8 *)Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v12, &result);
                memcpy((unsigned __int8 *)&dst, WorldMatrix3D, sizeof(dst));
                Scaleform::Render::Matrix3x4<float>::EncloseTransform(&dst, &pr, &r);
                *(float *)&v28 = (double)v31 * 20.0;
                pshape = (Scaleform::Render::ShapeMeshProvider *)v28;
                v14 = *(float *)&v28;
                v28 = 2;
                AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
                pr.x1 = pr.x1 - v14;
                pr.x2 = v14 + pr.x2;
                pr.y1 = pr.y1 - *(float *)&pshape;
                pr.y2 = *(float *)&pshape + pr.y2;
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
                v34.pFill.pObject = 0;
                v34.Color = v32 ^ 0xFFFFFF00 | 0xFF000000;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
                  v18,
                  &v34);
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
                *(float *)&pshape = pr.y1 + 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x2,
                  *(float *)&pshape);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x1,
                  *(float *)&pshape);
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
                *(float *)&pshape = pr.x2 - 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  *(float *)&pshape,
                  pr.y2);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  *(float *)&pshape,
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
                *(float *)&pshape = pr.y2 - 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x1,
                  *(float *)&pshape);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  pr.x2,
                  *(float *)&pshape);
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
                *(float *)&pshape = pr.x1 + 20.0;
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  *(float *)&pshape,
                  pr.y1);
                Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                  v18,
                  *(float *)&pshape,
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
                  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v19, v18, 0);
                  *(float *)&v28 = v20;
                }
                else
                {
                  *(float *)&v28 = 0.0;
                }
                pshape = (Scaleform::Render::ShapeMeshProvider *)2;
                v21 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this,
                                                                96,
                                                                &pshape);
                if ( v21 )
                {
                  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v21, v18, 0);
                  pshape = v22;
                }
                else
                {
                  *(float *)&pshape = 0.0;
                }
                v23 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(&this->RenderContext);
                Scaleform::Render::TreeShape::SetShape(v23, (Scaleform::Render::ContextImpl::EntryData_vtbl *)pshape);
                v24 = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
                Scaleform::Render::TreeContainer::Insert(this->FocusRectContainerNode.pObject, v24, v23);
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
                if ( *(float *)&pshape != 0.0 )
                  pshape->Release(&pshape->Scaleform::Render::MeshProvider);
                if ( *(float *)&v28 != 0.0 )
                  (*(void (__thiscall **)(int))(*(_DWORD *)(v28 + 8) + 8))(v28 + 8);
                if ( v34.pFill.pObject )
                  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v34.pFill.pObject);
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
        v32 += (int)vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase;
        p_LastFocused += 16;
        ++v31;
        v30 = p_LastFocused;
      }
      while ( v31 < this->FocusGroupsCnt );
    }
    this->FocusRectChanged = 0;
  }
}
