void __thiscall Scaleform::Render::DrawableImage::Draw(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Image *source,
        const Scaleform::Render::Matrix2x4<float> *matrix,
        const Scaleform::Render::Cxform *cform,
        Scaleform::Render::BlendMode blendMode,
        Scaleform::Render::Rect<int> *clipRect,
        bool smoothing)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *RContext; // esi
  Scaleform::Render::TreeRoot::NodeData *v10; // eax
  Scaleform::Render::ContextImpl::EntryData *v11; // edi
  Scaleform::Render::TreeRoot *EntryHelper; // ebp
  Scaleform::Render::ComplexFill *v13; // esi
  unsigned int Size; // eax
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::ComplexFill *v16; // eax
  Scaleform::Render::ComplexFill *v17; // eax
  Scaleform::Render::Image *v18; // ecx
  Scaleform::Render::ShapeDataFloatMP *v19; // eax
  Scaleform::Render::ShapeDataFloatMP *v20; // eax
  Scaleform::Render::ShapeDataFloatMP *v21; // esi
  Scaleform::Render::Rect<int> *v22; // eax
  Scaleform::Render::Size<unsigned long> *v23; // eax
  unsigned int v24; // ecx
  Scaleform::Render::Size<int> *v25; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_Draw *v27; // eax
  bool v28; // zf
  Scaleform::Render::Rect<int> v29; // [esp+1Ch] [ebp-B4h]
  float x2; // [esp+28h] [ebp-A8h]
  float y2; // [esp+2Ch] [ebp-A4h]
  Scaleform::Render::Size<unsigned long> *v32; // [esp+40h] [ebp-90h]
  Scaleform::Render::ShapeDataFloatMP *v33; // [esp+44h] [ebp-8Ch]
  Scaleform::Render::TreeShape *childSubtree; // [esp+48h] [ebp-88h]
  Scaleform::Render::FillStyleType fill; // [esp+4Ch] [ebp-84h] BYREF
  unsigned int Height; // [esp+54h] [ebp-7Ch] BYREF
  _DWORD v37[4]; // [esp+5Ch] [ebp-74h] BYREF
  char v38[8]; // [esp+6Ch] [ebp-64h] BYREF
  char v39[8]; // [esp+74h] [ebp-5Ch] BYREF
  char v40[8]; // [esp+7Ch] [ebp-54h] BYREF
  Scaleform::Render::DICommand_Draw v41; // [esp+84h] [ebp-4Ch] BYREF
  Scaleform::Render::Viewport vp; // [esp+A4h] [ebp-2Ch] BYREF

  pObject = this->pContext.pObject;
  if ( pObject && pObject->RContext )
  {
    RContext = pObject->RContext;
    v10 = (Scaleform::Render::TreeRoot::NodeData *)RContext->pHeap->Alloc(RContext->pHeap, 208u, 0);
    v11 = v10;
    if ( v10 )
      Scaleform::Render::TreeRoot::NodeData::NodeData(v10);
    EntryHelper = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                   RContext,
                                                   v11);
    v13 = 0;
    if ( EntryHelper )
    {
      childSubtree = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(this->pContext.pObject->RContext);
      Size = Scaleform::Render::TreeContainer::GetSize(EntryHelper);
      Scaleform::Render::TreeContainer::Insert(EntryHelper, Size, childSubtree);
      Alloc = Scaleform::Memory::pGlobalHeap->Alloc;
      fill.Color = 0;
      v16 = (Scaleform::Render::ComplexFill *)Alloc(Scaleform::Memory::pGlobalHeap, 64u, 0);
      if ( v16 )
      {
        Scaleform::Render::ComplexFill::ComplexFill(v16);
        v13 = v17;
      }
      fill.pFill.pObject = v13;
      if ( source )
        source->AddRef(source);
      v18 = v13->pImage.pObject;
      if ( v18 )
        v18->Release(v18);
      v13->pImage.pObject = source;
      v19 = (Scaleform::Render::ShapeDataFloatMP *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     112,
                                                     0);
      if ( v19 )
      {
        Scaleform::Render::ShapeDataFloatMP::ShapeDataFloatMP(v19);
        v21 = v20;
        v33 = v20;
      }
      else
      {
        v33 = 0;
        v21 = 0;
      }
      Scaleform::Render::ShapeDataFloatMP::AddFillStyle(v21, &fill);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(v21->pData.pObject);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        v21->pData.pObject,
        1u,
        0,
        0);
      v32 = source->GetSize(source, v38);
      Height = source->GetSize(source, v39)->Height;
      x2 = (float)v32->Width;
      y2 = (float)Height;
      Scaleform::Render::ShapeDataFloatMP::RectanglePath(v21, 0.0, 0.0, x2, y2);
      Scaleform::Render::ShapeDataFloatMP::CountLayers(v21);
      Scaleform::Render::TreeShape::SetShape(childSubtree, (Scaleform::Render::ContextImpl::EntryData_vtbl *)v21);
      v22 = clipRect;
      if ( !clipRect )
      {
        v23 = this->GetSize(this, &Height);
        v24 = v23->Height;
        v37[2] = v23->Width;
        v37[0] = 0;
        v37[1] = 0;
        v37[3] = v24;
        v22 = (Scaleform::Render::Rect<int> *)v37;
      }
      v29 = *v22;
      v25 = (Scaleform::Render::Size<int> *)this->GetSize(this, v40);
      Scaleform::Render::Viewport::Viewport(&vp, *v25, v29, 0);
      Scaleform::Render::TreeRoot::SetViewport(EntryHelper, &vp);
      Scaleform::Render::TreeNode::SetMatrix(EntryHelper, matrix);
      Scaleform::Render::TreeNode::SetMatrix(childSubtree, &Scaleform::Render::Matrix2x4<float>::Identity);
      qmemcpy(&Scaleform::Render::ContextImpl::Entry::getWritableData(childSubtree, 2u)[10], cform, 0x20u);
      Scaleform::Render::TreeNode::SetBlendMode(childSubtree, blendMode);
      ++EntryHelper->RefCount;
      pControlContext = this->pContext.pObject->pControlContext;
      if ( pControlContext )
        pControlContext->DIChangesRequired = 1;
      this->pContext.pObject->OnCapture(&this->pContext.pObject->Scaleform::Render::ContextImpl::ContextCaptureNotify);
      Scaleform::Render::DICommand_Draw::DICommand_Draw(
        &v41,
        this,
        EntryHelper,
        (const Scaleform::Render::Rect<long> *)clipRect);
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(this, v27);
      v41.__vftable = (Scaleform::Render::DICommand_Draw_vtbl *)&Scaleform::Render::DICommand::`vftable';
      if ( v41.pImage.pObject )
        v41.pImage.pObject->Release(v41.pImage.pObject);
      v33->Release(&v33->Scaleform::Render::MeshProvider);
      if ( fill.pFill.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)fill.pFill.pObject);
      if ( childSubtree )
      {
        v28 = childSubtree->RefCount-- == 1;
        if ( v28 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(childSubtree);
      }
      v28 = EntryHelper->RefCount-- == 1;
      if ( v28 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
    }
  }
}
