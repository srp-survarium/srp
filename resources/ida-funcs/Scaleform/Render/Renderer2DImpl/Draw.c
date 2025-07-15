void __thiscall Scaleform::Render::Renderer2DImpl::Draw(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  Scaleform::Render::TreeCacheRoot *pRenderer; // esi
  _DWORD *v6; // eax
  bool v7; // zf
  Scaleform::Render::Viewport *v8; // ecx
  int v9; // eax
  int v10; // edx
  int p_ViewRectOriginal; // eax
  int v12; // edx
  int Left; // edx
  char CullRectF; // al
  __int16 v15; // si
  Scaleform::Render::TreeCacheRoot *v16; // eax
  Scaleform::Render::TreeCacheRoot *v17; // eax
  double x1; // st7
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v20; // edi
  unsigned __int64 ProfileTicks; // rax
  char v22; // [esp+1Bh] [ebp-35h]
  Scaleform::Render::Viewport *p_VP; // [esp+1Ch] [ebp-34h]
  int v24; // [esp+20h] [ebp-30h]
  int Top; // [esp+20h] [ebp-30h]
  Scaleform::Render::HAL *pObject; // [esp+28h] [ebp-28h]
  __int16 v27; // [esp+28h] [ebp-28h]
  int v28; // [esp+2Ch] [ebp-24h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+30h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v30; // [esp+40h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v4 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v30,
    v4,
    "Renderer2DImpl::Draw",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Draw);
  pRenderer = (Scaleform::Render::TreeCacheRoot *)pnode->pRenderer;
  v6 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pnode & 0xFFFFF000) + 0x14)
                            + 4 * ((int)((int)&pnode[-1] - ((unsigned int)pnode & 0xFFFFF000)) / 28)
                            + 20)
                & 0xFFFFFFFE);
  v7 = v6[40] == 0;
  v8 = (Scaleform::Render::Viewport *)(v6 + 40);
  v28 = (int)v6;
  if ( v7 || !v6[41] )
  {
    p_VP = &this->VP;
    v8 = &this->VP;
  }
  else
  {
    v9 = v6[50] & 0x30;
    p_VP = v8;
    if ( v9 == 16 || v9 == 48 )
    {
      Left = v8->Left;
      Top = v8->Top;
      LODWORD(r.x2) = Left + v8->Height;
      LODWORD(r.y2) = Top + v8->Width;
      pObject = this->pHal.pObject;
      p_ViewRectOriginal = (int)&pObject->Matrices.pObject->ViewRectOriginal;
      *(_DWORD *)p_ViewRectOriginal = Left;
      v12 = Top;
    }
    else
    {
      v10 = v8->Left;
      v24 = v8->Top;
      LODWORD(r.x2) = v10 + v8->Width;
      LODWORD(r.y2) = v24 + v8->Height;
      pObject = this->pHal.pObject;
      p_ViewRectOriginal = (int)&pObject->Matrices.pObject->ViewRectOriginal;
      *(_DWORD *)p_ViewRectOriginal = v10;
      v12 = v24;
    }
    *(_DWORD *)(p_ViewRectOriginal + 4) = v12;
    *(float *)(p_ViewRectOriginal + 8) = r.x2;
    *(float *)(p_ViewRectOriginal + 12) = r.y2;
    pObject->Matrices.pObject->UVPOChanged = 1;
  }
  r.x1 = 0.0;
  r.y1 = 0.0;
  r.x2 = 0.0;
  r.y2 = 0.0;
  CullRectF = Scaleform::Render::Viewport::GetCullRectF(v8, &r, 1);
  v22 = CullRectF;
  if ( p_VP->BufferWidth && p_VP->BufferHeight )
  {
    if ( pRenderer )
    {
      if ( CullRectF == pRenderer->ViewValid )
      {
        if ( !Scaleform::Render::Rect<float>::operator!=(&r, &pRenderer->ViewCullRect) )
          goto LABEL_22;
        CullRectF = v22;
      }
      x1 = r.x1;
      pRenderer->ViewValid = CullRectF;
      pRenderer->ViewCullRect.x1 = x1;
      pRenderer->ViewCullRect.y1 = r.y1;
      pRenderer->ViewCullRect.x2 = r.x2;
      pRenderer->ViewCullRect.y2 = r.y2;
      Scaleform::Render::TreeCacheRoot::AddToUpdate(pRenderer, pRenderer, 1u);
LABEL_21:
      Scaleform::Render::TreeCacheRoot::UpdateTreeData(pRenderer);
LABEL_22:
      if ( v22 )
        Scaleform::Render::TreeCacheRoot::Draw(pRenderer);
      goto LABEL_24;
    }
    v15 = *(_WORD *)(v28 + 6) & 0xC;
    v27 = *(_BYTE *)(v28 + 6) & 1;
    if ( (*(_WORD *)(v28 + 6) & 0xC) == 0 )
      v15 = 4;
    v28 = 74;
    v16 = (Scaleform::Render::TreeCacheRoot *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                304,
                                                &v28);
    if ( v16 )
    {
      Scaleform::Render::TreeCacheRoot::TreeCacheRoot(v16, this, this->pHal.pObject, v27 | v15, pnode);
      pRenderer = v17;
      if ( v17 )
      {
        pnode->pRenderer = v17;
        v17->pPrev = this->RenderRoots.Root.pPrev;
        v17->pNext = (Scaleform::Render::TreeCacheNode *)&this->VP.ScissorTop;
        this->RenderRoots.Root.pPrev->pNext = v17;
        this->RenderRoots.Root.pPrev = v17;
        v17->ViewValid = v22;
        Scaleform::Render::Rect<float>::operator=(&v17->ViewCullRect, &r);
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
        Scaleform::Render::TreeCacheRoot::AddToUpdate(pRenderer, pRenderer, 0x1000003u);
        Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(pRenderer);
        goto LABEL_21;
      }
    }
  }
LABEL_24:
  Stats = v30.Stats;
  if ( v30.Stats )
  {
    v20 = v30.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v20->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v30.StartTicks),
      (ProfileTicks - v30.StartTicks) >> 32);
  }
}
