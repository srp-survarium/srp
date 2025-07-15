void __thiscall Scaleform::GFx::DisplayObject::SetScrollRect(
        Scaleform::GFx::DisplayObject *this,
        const Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v4; // edi
  const __m128i *pScrollRect; // eax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v6; // edi
  Scaleform::RefCountNTSImpl *v7; // ecx
  unsigned int v8; // edi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v9; // eax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v10; // eax
  long double y1; // st7
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v12; // eax
  long double x2; // st6
  long double y2; // st5
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v15; // eax
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::Ptr<Scaleform::GFx::DrawingContext> *p_Mask; // eax
  Scaleform::GFx::DrawingContext *v18; // ecx
  int v19; // ecx
  Scaleform::Render::TreeNode *v20; // [esp+28h] [ebp-2Ch]
  Scaleform::GFx::DrawingContext *DrawingContext; // [esp+2Ch] [ebp-28h]
  float x; // [esp+2Ch] [ebp-28h]
  int y; // [esp+30h] [ebp-24h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+34h] [ebp-20h] BYREF

  if ( this->pMaskCharacter && !this->IsUsedAsMask(this) && this->pMaskCharacter )
    Scaleform::GFx::DisplayObject::SetMask(this, 0);
  if ( (this->Scaleform::GFx::DisplayObjectBase::Flags & 0x8000u) == 0 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    v4 = RenderNode;
    v20 = RenderNode;
    if ( this->pScrollRect )
    {
      Scaleform::Render::TreeNode::SetMaskNode(RenderNode, 0);
      pScrollRect = (const __m128i *)this->pScrollRect;
      if ( pScrollRect[6].m128i_i8[0] )
      {
        Scaleform::Render::TreeNode::SetMatrix3D(v4, pScrollRect + 3);
      }
      else
      {
        Scaleform::Render::Matrix2x4<float>::operator=(&m, (const Scaleform::Render::Matrix2x4<float> *)&pScrollRect[3]);
        Scaleform::Render::TreeNode::SetMatrix(v4, &m);
      }
    }
    if ( r )
    {
      v8 = (unsigned int)v4 & 0xFFFFF000;
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v8 + 16) + 4 * ((int)((int)&v20[-1] - v8) / 28) + 20) + 6) & 0x10) != 0 )
        Scaleform::Render::TreeNode::SetMaskNode(v20, 0);
      if ( !this->pScrollRect )
      {
        y = 322;
        v9 = (Scaleform::GFx::DisplayObject::ScrollRectInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this,
                                                                112,
                                                                &y);
        if ( v9 )
          Scaleform::GFx::DisplayObject::ScrollRectInfo::ScrollRectInfo(v9);
        else
          v10 = 0;
        this->pScrollRect = v10;
      }
      y1 = r->y1;
      v12 = this->pScrollRect;
      x2 = r->x2;
      y2 = r->y2;
      v12->Rectangle.x1 = r->x1;
      v12->Rectangle.y1 = y1;
      v12->Rectangle.x2 = x2;
      v12->Rectangle.y2 = y2;
      memcpy(
        (int)&this->pScrollRect->OrigTransformMatrix,
        (const __m128i *)(*(_DWORD *)(*(_DWORD *)(v8 + 16) + 4 * ((int)((int)&v20[-1] - v8) / 28) + 20) + 16),
        sizeof(this->pScrollRect->OrigTransformMatrix));
      this->pScrollRect->IsOrig3D = (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 16)
                                                          + 4 * ((int)((int)&v20[-1] - v8) / 28)
                                                          + 20)
                                              + 6)
                                   & 0x200) != 0;
      DrawingContext = Scaleform::GFx::MovieImpl::CreateDrawingContext(this->pASRoot->pMovieImpl);
      v15 = this->pScrollRect;
      pObject = v15->Mask.pObject;
      p_Mask = &v15->Mask;
      y = (int)p_Mask;
      if ( pObject )
      {
        Scaleform::RefCountNTSImpl::Release(pObject);
        p_Mask = (Scaleform::Ptr<Scaleform::GFx::DrawingContext> *)y;
      }
      p_Mask->pObject = DrawingContext;
      Scaleform::GFx::DrawingContext::BeginSolidFill(this->pScrollRect->Mask.pObject, 0xFFFFFFFF);
      v18 = this->pScrollRect->Mask.pObject;
      x = r->x2 - r->x1;
      *(float *)&y = r->y2 - r->y1;
      Scaleform::GFx::DrawingContext::MoveTo(v18, 0.0, 0.0);
      Scaleform::GFx::DrawingContext::LineTo(this->pScrollRect->Mask.pObject, x, 0.0);
      Scaleform::GFx::DrawingContext::LineTo(this->pScrollRect->Mask.pObject, x, *(float *)&y);
      Scaleform::GFx::DrawingContext::LineTo(this->pScrollRect->Mask.pObject, 0.0, *(float *)&y);
      Scaleform::GFx::DrawingContext::EndFill(this->pScrollRect->Mask.pObject);
      Scaleform::GFx::DrawingContext::UpdateRenderNode(this->pScrollRect->Mask.pObject, (int)r);
      v19 = (int)&v20[-1] - v8;
      if ( this->pScrollRect->IsOrig3D )
        this->SetMatrix3D(
          this,
          (const Scaleform::Render::Matrix3x4<float> *)(*(_DWORD *)(*(_DWORD *)(v8 + 16) + 4 * (v19 / 28) + 20) + 16));
      else
        this->SetMatrix(
          this,
          (const Scaleform::Render::Matrix2x4<float> *)(*(_DWORD *)(*(_DWORD *)(v8 + 16) + 4 * (v19 / 28) + 20) + 16));
      Scaleform::Render::TreeNode::SetMaskNode(v20, this->pScrollRect->Mask.pObject->pTreeContainer.pObject);
    }
    else
    {
      v6 = this->pScrollRect;
      if ( v6 )
      {
        v7 = v6->Mask.pObject;
        if ( v7 )
          Scaleform::RefCountNTSImpl::Release(v7);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
      }
      this->pScrollRect = 0;
    }
  }
}
