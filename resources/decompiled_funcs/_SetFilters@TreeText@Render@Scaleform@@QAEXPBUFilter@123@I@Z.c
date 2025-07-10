void __thiscall Scaleform::Render::TreeText::SetFilters(
        Scaleform::Render::TreeText *this,
        const Scaleform::Render::TreeText::Filter *filters,
        unsigned int filtersCnt)
{
  const Scaleform::Render::TreeText::NodeData *v4; // esi
  double v5; // st7
  double v6; // st6
  $57F196AB27F8D57F4328C335D7E3132A *v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // eax
  unsigned int Flags; // edx
  double BlurY; // st4
  Scaleform::Render::Text::TextFilter *p_Filter; // esi
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  unsigned int Color; // edi
  double v15; // st5
  const Scaleform::Render::TreeText::NodeData *data; // [esp+8h] [ebp-4Ch]
  Scaleform::Render::Text::TextFilter f; // [esp+Ch] [ebp-48h] BYREF
  signed int filtersCnta; // [esp+5Ch] [ebp+8h]

  v4 = *(const Scaleform::Render::TreeText::NodeData **)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                       + 4
                                                       * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                        / 28)
                                                       + 20);
  data = v4;
  if ( !v4->pDocView.pObject )
    goto LABEL_14;
  Scaleform::Render::Text::TextFilter::TextFilter(&f);
  if ( !filtersCnt )
    goto LABEL_11;
  v5 = 20.0;
  v6 = 100.0;
  v7 = &filters->4;
  v8 = filtersCnt;
  do
  {
    switch ( LODWORD(v7[-1].DropShadow.Distance) )
    {
      case 1:
        Color = v7->Glow.Color;
        v15 = v7->Blur.BlurX * v5;
        f.ShadowFlags = v7->Glow.Flags;
        f.ShadowParams.BlurX = v15;
        f.ShadowAlpha = HIBYTE(Color);
        f.ShadowParams.BlurY = v7->Blur.BlurY * v5;
        f.ShadowParams.Strength = v7->Blur.Strength / v6;
        f.ShadowAngle = v7->DropShadow.Angle * 3.141592653589793 / 180.0;
        filtersCnta = (__int16)(int)(v5 * v7->DropShadow.Distance);
        f.ShadowParams.Colors[0].Raw = Color;
        f.ShadowDistance = (float)filtersCnta;
        goto LABEL_8;
      case 2:
        f.BlurX = v7->Blur.BlurX * v5;
        f.BlurY = v7->Blur.BlurY * v5;
        f.BlurStrength = v7->Blur.Strength / v6;
        break;
      case 3:
        v9 = v7->Glow.Color;
        Flags = v7->Glow.Flags;
        f.ShadowParams.BlurX = v7->Blur.BlurX * v5;
        f.ShadowFlags = Flags;
        BlurY = v7->Blur.BlurY;
        f.ShadowAlpha = HIBYTE(v9);
        f.ShadowParams.Colors[0].Raw = v9;
        f.ShadowParams.BlurY = v5 * BlurY;
        f.ShadowParams.Strength = v7->Blur.Strength / v6;
        f.ShadowAngle = 0.0;
        f.ShadowDistance = 0.0;
LABEL_8:
        Scaleform::Render::Text::TextFilter::UpdateShadowOffset(&f);
        v6 = 100.0;
        v5 = 20.0;
        break;
    }
    v7 = ($57F196AB27F8D57F4328C335D7E3132A *)((char *)v7 + 32);
    --v8;
  }
  while ( v8 );
  v4 = data;
LABEL_11:
  p_Filter = &v4->pDocView.pObject->Filter;
  if ( !Scaleform::Render::Text::TextFilter::operator==(p_Filter, &f) )
    Scaleform::Render::Text::TextFilter::operator=(p_Filter, &f);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&f);
LABEL_14:
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
