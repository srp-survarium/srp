void __thiscall Scaleform::Render::DrawableImage::Draw(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::TreeNode *subtree,
        const Scaleform::Render::Matrix2x4<float> *matrix,
        const Scaleform::Render::Cxform *cform,
        Scaleform::Render::BlendMode blendMode,
        Scaleform::Render::Rect<int> *clipRect)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *RContext; // ebp
  Scaleform::Render::TreeRoot::NodeData *v9; // eax
  Scaleform::Render::ContextImpl::EntryData *v10; // edi
  Scaleform::Render::TreeRoot *EntryHelper; // ebp
  Scaleform::Render::TreeNode *v12; // edi
  unsigned int Size; // eax
  Scaleform::Render::Rect<int> *v14; // eax
  Scaleform::Render::Size<unsigned long> *v15; // eax
  unsigned int Height; // ecx
  Scaleform::Render::Size<int> *v17; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_Draw *v19; // eax
  bool v20; // zf
  Scaleform::Render::Rect<int> v21; // [esp-14h] [ebp-98h]
  _BYTE v22[8]; // [esp+18h] [ebp-6Ch] BYREF
  int v23; // [esp+20h] [ebp-64h] BYREF
  _DWORD v24[4]; // [esp+28h] [ebp-5Ch] BYREF
  Scaleform::Render::DICommand_Draw v25; // [esp+38h] [ebp-4Ch] BYREF
  Scaleform::Render::Viewport vp; // [esp+58h] [ebp-2Ch] BYREF

  pObject = this->pContext.pObject;
  if ( pObject && pObject->RContext )
  {
    RContext = pObject->RContext;
    v9 = (Scaleform::Render::TreeRoot::NodeData *)RContext->pHeap->Alloc(RContext->pHeap, 208u, 0);
    v10 = v9;
    if ( v9 )
      Scaleform::Render::TreeRoot::NodeData::NodeData(v9);
    EntryHelper = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                   RContext,
                                                   v10);
    if ( EntryHelper )
    {
      v12 = Scaleform::Render::TreeNode::Clone(subtree, this->pContext.pObject->RContext);
      Size = Scaleform::Render::TreeContainer::GetSize(EntryHelper);
      Scaleform::Render::TreeContainer::Insert(EntryHelper, Size, v12);
      v14 = clipRect;
      if ( !clipRect )
      {
        v15 = this->GetSize(this, v22);
        Height = v15->Height;
        v24[2] = v15->Width;
        v24[0] = 0;
        v24[1] = 0;
        v24[3] = Height;
        v14 = (Scaleform::Render::Rect<int> *)v24;
      }
      v21 = *v14;
      v17 = (Scaleform::Render::Size<int> *)this->GetSize(this, &v23);
      Scaleform::Render::Viewport::Viewport(&vp, *v17, v21, 1u);
      Scaleform::Render::TreeRoot::SetViewport(EntryHelper, &vp);
      Scaleform::Render::TreeNode::SetMatrix(EntryHelper, matrix);
      Scaleform::Render::TreeNode::SetMatrix(v12, &Scaleform::Render::Matrix2x4<float>::Identity);
      qmemcpy(&Scaleform::Render::ContextImpl::Entry::getWritableData(v12, 2u)[10], cform, 0x20u);
      Scaleform::Render::TreeNode::SetBlendMode(v12, blendMode);
      ++EntryHelper->RefCount;
      pControlContext = this->pContext.pObject->pControlContext;
      if ( pControlContext )
        pControlContext->DIChangesRequired = 1;
      this->pContext.pObject->OnCapture(&this->pContext.pObject->Scaleform::Render::ContextImpl::ContextCaptureNotify);
      Scaleform::Render::DICommand_Draw::DICommand_Draw(
        &v25,
        this,
        EntryHelper,
        (const Scaleform::Render::Rect<long> *)clipRect);
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(this, v19);
      v25.__vftable = (Scaleform::Render::DICommand_Draw_vtbl *)&Scaleform::Render::DICommand::`vftable';
      if ( v25.pImage.pObject )
        v25.pImage.pObject->Release(v25.pImage.pObject);
      if ( v12 )
      {
        v20 = v12->RefCount-- == 1;
        if ( v20 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
      }
      v20 = EntryHelper->RefCount-- == 1;
      if ( v20 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
    }
  }
}
