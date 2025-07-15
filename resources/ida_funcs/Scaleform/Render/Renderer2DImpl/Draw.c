void __thiscall Scaleform::Render::Renderer2DImpl::Draw(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::Render::TreeCacheRoot *pRenderer; // esi
  _DWORD *v4; // eax
  bool v5; // zf
  Scaleform::Render::Viewport *v6; // ecx
  int v7; // eax
  int v8; // edx
  int p_ViewRectOriginal; // eax
  int v10; // edx
  int Left; // edx
  char CullRectF; // al
  int v13; // esi
  Scaleform::Render::TreeCacheRoot *v14; // eax
  Scaleform::Render::TreeCacheRoot *v15; // eax
  double x1; // st7
  char v17; // [esp+9Dh] [ebp-25h]
  Scaleform::Render::Viewport *p_VP; // [esp+9Eh] [ebp-24h]
  int v19; // [esp+A2h] [ebp-20h]
  int Top; // [esp+A2h] [ebp-20h]
  Scaleform::Render::HAL *pObject; // [esp+AAh] [ebp-18h]
  int v22; // [esp+AAh] [ebp-18h]
  int v23; // [esp+AEh] [ebp-14h] BYREF
  Scaleform::Render::Rect<float> prect; // [esp+B2h] [ebp-10h] BYREF

  pRenderer = (Scaleform::Render::TreeCacheRoot *)pnode->pRenderer;
  v4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pnode & 0xFFFFF000) + 0x14)
                            + 4 * ((int)((int)&pnode[-1] - ((unsigned int)pnode & 0xFFFFF000)) / 28)
                            + 20)
                & 0xFFFFFFFE);
  v5 = v4[40] == 0;
  v6 = (Scaleform::Render::Viewport *)(v4 + 40);
  v23 = (int)v4;
  if ( v5 || !v4[41] )
  {
    p_VP = &this->VP;
    v6 = &this->VP;
  }
  else
  {
    v7 = v4[50] & 0x30;
    p_VP = v6;
    if ( v7 == 16 || v7 == 48 )
    {
      Left = v6->Left;
      Top = v6->Top;
      LODWORD(prect.x2) = Left + v6->Height;
      LODWORD(prect.y2) = Top + v6->Width;
      pObject = this->pHal.pObject;
      p_ViewRectOriginal = (int)&pObject->Matrices.pObject->ViewRectOriginal;
      *(_DWORD *)p_ViewRectOriginal = Left;
      v10 = Top;
    }
    else
    {
      v8 = v6->Left;
      v19 = v6->Top;
      LODWORD(prect.x2) = v8 + v6->Width;
      LODWORD(prect.y2) = v19 + v6->Height;
      pObject = this->pHal.pObject;
      p_ViewRectOriginal = (int)&pObject->Matrices.pObject->ViewRectOriginal;
      *(_DWORD *)p_ViewRectOriginal = v8;
      v10 = v19;
    }
    *(_DWORD *)(p_ViewRectOriginal + 4) = v10;
    *(float *)(p_ViewRectOriginal + 8) = prect.x2;
    *(float *)(p_ViewRectOriginal + 12) = prect.y2;
    pObject->Matrices.pObject->UVPOChanged = 1;
  }
  prect.x1 = 0.0;
  prect.y1 = 0.0;
  prect.x2 = 0.0;
  prect.y2 = 0.0;
  CullRectF = Scaleform::Render::Viewport::GetCullRectF(v6, &prect, 1);
  v17 = CullRectF;
  if ( p_VP->BufferWidth && p_VP->BufferHeight )
  {
    if ( pRenderer )
    {
      if ( CullRectF == pRenderer->ViewValid )
      {
        if ( !Scaleform::Render::Rect<float>::operator!=(&prect, &pRenderer->ViewCullRect) )
          goto LABEL_22;
        CullRectF = v17;
      }
      x1 = prect.x1;
      pRenderer->ViewValid = CullRectF;
      pRenderer->ViewCullRect.x1 = x1;
      pRenderer->ViewCullRect.y1 = prect.y1;
      pRenderer->ViewCullRect.x2 = prect.x2;
      pRenderer->ViewCullRect.y2 = prect.y2;
      Scaleform::Render::TreeCacheRoot::AddToUpdate(pRenderer, pRenderer, 1u);
LABEL_21:
      Scaleform::Render::TreeCacheRoot::UpdateTreeData(pRenderer);
LABEL_22:
      if ( v17 )
        Scaleform::Render::TreeCacheRoot::Draw(pRenderer);
      return;
    }
    v13 = *(_WORD *)(v23 + 6) & 0xC;
    v22 = *(_BYTE *)(v23 + 6) & 1;
    if ( !v13 )
      v13 = 4;
    v23 = 74;
    v14 = (Scaleform::Render::TreeCacheRoot *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                304,
                                                &v23);
    if ( v14 )
    {
      Scaleform::Render::TreeCacheRoot::TreeCacheRoot(v14, this, this->pHal.pObject, v22 | v13, pnode);
      pRenderer = v15;
      if ( v15 )
      {
        pnode->pRenderer = v15;
        v15->pPrev = this->RenderRoots.Root.pPrev;
        v15->pNext = (Scaleform::Render::TreeCacheNode *)&this->VP.ScissorTop;
        this->RenderRoots.Root.pPrev->pNext = v15;
        this->RenderRoots.Root.pPrev = v15;
        v15->ViewValid = v17;
        Scaleform::Render::Rect<float>::operator=(&v15->ViewCullRect, &prect);
        pRenderer->UpdateChildSubtree(
          pRenderer,
          (const Scaleform::Render::TreeNode::NodeData *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pnode & 0xFFFFF000)
                                                                                + 0x14)
                                                                    + 4
                                                                    * ((int)((int)&pnode[-1]
                                                                           - ((unsigned int)pnode & 0xFFFFF000))
                                                                     / 28)
                                                                    + 20)
                                                        & 0xFFFFFFFE),
          1u);
        Scaleform::Render::TreeCacheRoot::AddToUpdate(
          pRenderer,
          pRenderer,
          (unsigned int)&vostok::memory::s_CRT_arena[5574203]);
        Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(pRenderer);
        goto LABEL_21;
      }
    }
  }
}
