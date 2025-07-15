void __thiscall Scaleform::GFx::MovieImpl::SetViewport(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::Viewport *viewDesc)
{
  Scaleform::GFx::Viewport *p_mViewport; // eax
  unsigned int v4; // ecx
  char *v5; // edx
  int Width; // edx
  int Height; // eax
  Scaleform::GFx::Movie::ScaleModeType ViewScaleMode; // ecx
  double v9; // st7
  int v10; // [esp+18h] [ebp-28h]
  int v11; // [esp+1Ch] [ebp-24h]
  float AspectRatio; // [esp+20h] [ebp-20h]
  int Left; // [esp+24h] [ebp-1Ch]
  int Top; // [esp+28h] [ebp-18h]
  float Scale; // [esp+2Ch] [ebp-14h]
  float x1; // [esp+30h] [ebp-10h]
  float y1; // [esp+34h] [ebp-Ch]
  float x2; // [esp+38h] [ebp-8h]
  float y2; // [esp+3Ch] [ebp-4h]

  p_mViewport = &this->mViewport;
  v4 = 52;
  v5 = (char *)((char *)viewDesc - (char *)p_mViewport);
  while ( *(int *)((char *)&p_mViewport->BufferWidth + (_DWORD)v5) == p_mViewport->BufferWidth )
  {
    v4 -= 4;
    p_mViewport = (Scaleform::GFx::Viewport *)((char *)p_mViewport + 4);
    if ( v4 < 4 )
      return;
  }
  Scale = this->mViewport.Scale;
  Width = this->mViewport.Width;
  AspectRatio = this->mViewport.AspectRatio;
  Top = this->mViewport.Top;
  Left = this->mViewport.Left;
  Height = this->mViewport.Height;
  this->Flags |= 1u;
  qmemcpy(&this->mViewport, viewDesc, sizeof(this->mViewport));
  x1 = this->VisibleFrameRect.x1;
  y1 = this->VisibleFrameRect.y1;
  x2 = this->VisibleFrameRect.x2;
  y2 = this->VisibleFrameRect.y2;
  v10 = Width;
  v11 = Height;
  Scaleform::GFx::MovieImpl::UpdateViewport(this);
  if ( this->VisibleFrameRect.x1 != x1
    || this->VisibleFrameRect.x2 != x2
    || this->VisibleFrameRect.y1 != y1
    || this->VisibleFrameRect.y2 != y2
    || (ViewScaleMode = this->ViewScaleMode, v9 = AspectRatio, ViewScaleMode == SM_NoScale)
    && (v10 != this->mViewport.Width
     || v11 != this->mViewport.Height
     || Left != this->mViewport.Left
     || Top != this->mViewport.Top
     || this->mViewport.Scale != Scale
     || this->mViewport.AspectRatio != v9)
    || ViewScaleMode != SM_ExactFit
    && (v10 != this->mViewport.Width || v11 != this->mViewport.Height || this->mViewport.AspectRatio != v9) )
  {
    this->pASMovieRoot.pObject->NotifyOnResize(this->pASMovieRoot.pObject);
  }
  Scaleform::Render::TreeRoot::SetViewport(this->pRenderRoot.pObject, &this->mViewport);
  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((int)this->pRenderRoot.pObject & 0xFFFFF000) + 0x10)
                             + 4
                             * ((int)((int)&this->pRenderRoot.pObject[-1] - ((int)this->pRenderRoot.pObject & 0xFFFFF000))
                              / 28)
                             + 20)
                 + 204) != this->BackgroundColor.Raw )
    *(_DWORD *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this->pRenderRoot.pObject, 0x1000u)[25].Type = this->BackgroundColor.Raw;
  Scaleform::Render::TreeNode::SetMatrix(this->pRenderRoot.pObject, &this->ViewportMatrix);
}
