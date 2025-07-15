const Scaleform::Render::FilterSet *__thiscall Scaleform::GFx::TextField::GetFilters(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::TreeText *RenderNode; // esi
  unsigned int v3; // edi
  Scaleform::Render::FilterSet *v4; // eax
  Scaleform::Render::FilterSet *v5; // eax
  Scaleform::Render::FilterSet *v6; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  $57F196AB27F8D57F4328C335D7E3132A *v8; // esi
  unsigned int v9; // ebp
  Scaleform::Render::GlowFilter *v10; // eax
  int v11; // eax
  int v12; // edi
  Scaleform::Render::BlurFilter *v13; // eax
  int v14; // eax
  Scaleform::Render::ShadowFilter *v15; // eax
  int v16; // eax
  char Flags; // al
  int v18; // ecx
  Scaleform::RefCountVImpl *v20; // ecx
  float angle; // [esp+34h] [ebp-64h]
  Scaleform::Render::TreeText::Filter filters[3]; // [esp+38h] [ebp-60h] BYREF

  if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) || this->pFilters.pObject )
    return this->pFilters.pObject;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  `vector constructor iterator'(
    (char *)filters,
    0x20u,
    3,
    (void *(__thiscall *)(void *))Scaleform::Render::TreeText::Filter::Filter);
  v3 = Scaleform::Render::TreeText::GetFilters(RenderNode, filters, 3u);
  if ( v3 )
  {
    v4 = (Scaleform::Render::FilterSet *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 24, 0);
    if ( v4 )
    {
      Scaleform::Render::FilterSet::FilterSet(v4, 0);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFilters.pObject = v6;
    v8 = &filters[0].4;
    v9 = v3;
    while ( LODWORD(v8[-1].DropShadow.Distance) != 1 )
    {
      if ( LODWORD(v8[-1].DropShadow.Distance) == 2 )
      {
        v13 = (Scaleform::Render::BlurFilter *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 60,
                                                 0);
        if ( v13 )
        {
          Scaleform::Render::BlurFilter::BlurFilter(v13, v8->Blur.BlurX, v8->Blur.BlurY, 1u);
          v12 = v14;
          *(float *)(v14 + 40) = v8->Blur.Strength / 100.0;
        }
        else
        {
          v12 = 0;
          MEMORY[0x28] = v8->Blur.Strength / 100.0;
        }
        goto LABEL_28;
      }
      if ( LODWORD(v8[-1].DropShadow.Distance) == 3 )
      {
        v10 = (Scaleform::Render::GlowFilter *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 60,
                                                 0);
        if ( v10 )
        {
          Scaleform::Render::GlowFilter::GlowFilter(v10, v8->Blur.BlurX, v8->Blur.BlurY, 1u);
          v12 = v11;
          goto LABEL_21;
        }
LABEL_20:
        v12 = 0;
        goto LABEL_21;
      }
LABEL_29:
      v8 = ($57F196AB27F8D57F4328C335D7E3132A *)((char *)v8 + 32);
      if ( !--v9 )
        return this->pFilters.pObject;
    }
    v15 = (Scaleform::Render::ShadowFilter *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               60,
                                               0);
    if ( !v15 )
      goto LABEL_20;
    angle = v8->DropShadow.Angle * 3.141592653589793 / 180.0;
    Scaleform::Render::ShadowFilter::ShadowFilter(
      v15,
      angle,
      v8->DropShadow.Distance,
      v8->Blur.BlurX,
      v8->Blur.BlurY,
      1u);
    v12 = v16;
LABEL_21:
    *(float *)(v12 + 40) = v8->Blur.Strength / 100.0;
    *(_DWORD *)(v12 + 44) = v8->Glow.Color;
    Flags = v8->Glow.Flags;
    v18 = 0;
    if ( (Flags & 0x20) != 0 )
      v18 = 16;
    if ( (Flags & 0x40) != 0 )
      v18 |= 0x40u;
    if ( Flags < 0 )
      v18 |= 0x80u;
    *(_DWORD *)(v12 + 16) = v18;
LABEL_28:
    Scaleform::Render::FilterSet::AddFilter(this->pFilters.pObject, (Scaleform::GFx::Resource *)v12);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
    goto LABEL_29;
  }
  v20 = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  this->pFilters.pObject = 0;
  return this->pFilters.pObject;
}
