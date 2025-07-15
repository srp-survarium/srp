void __thiscall Scaleform::Render::TreeText::SetFilters(
        Scaleform::Render::TreeText *this,
        const Scaleform::Render::TreeText::Filter *filters,
        unsigned int filtersCnt)
{
  int v4; // esi
  double v5; // st7
  double v6; // st6
  $A4C37A7477F7A8C6E9231F01C70999D4 *v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // eax
  unsigned int Flags; // edx
  double BlurY; // st4
  Scaleform::Render::Text::TextFilter *v12; // esi
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  unsigned int Color; // edi
  double v15; // st5
  int v16; // [esp+8h] [ebp-4Ch]
  Scaleform::Render::Text::TextFilter __that; // [esp+Ch] [ebp-48h] BYREF
  int v18; // [esp+5Ch] [ebp+8h]

  v4 = *(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                 + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                 + 20);
  v16 = v4;
  if ( !*(_DWORD *)(v4 + 144) )
    goto LABEL_14;
  Scaleform::Render::Text::TextFilter::TextFilter(&__that);
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
        __that.ShadowFlags = v7->Glow.Flags;
        __that.ShadowParams.BlurX = v15;
        __that.ShadowAlpha = HIBYTE(Color);
        __that.ShadowParams.BlurY = v7->Blur.BlurY * v5;
        __that.ShadowParams.Strength = v7->Blur.Strength / v6;
        __that.ShadowAngle = v7->DropShadow.Angle * 3.141592653589793 / 180.0;
        v18 = (__int16)(int)(v5 * v7->DropShadow.Distance);
        __that.ShadowParams.Colors[0].Raw = Color;
        __that.ShadowDistance = (float)v18;
        goto LABEL_8;
      case 2:
        __that.BlurX = v7->Blur.BlurX * v5;
        __that.BlurY = v7->Blur.BlurY * v5;
        __that.BlurStrength = v7->Blur.Strength / v6;
        break;
      case 3:
        v9 = v7->Glow.Color;
        Flags = v7->Glow.Flags;
        __that.ShadowParams.BlurX = v7->Blur.BlurX * v5;
        __that.ShadowFlags = Flags;
        BlurY = v7->Blur.BlurY;
        __that.ShadowAlpha = HIBYTE(v9);
        __that.ShadowParams.Colors[0].Raw = v9;
        __that.ShadowParams.BlurY = v5 * BlurY;
        __that.ShadowParams.Strength = v7->Blur.Strength / v6;
        __that.ShadowAngle = 0.0;
        __that.ShadowDistance = 0.0;
LABEL_8:
        Scaleform::Render::Text::TextFilter::UpdateShadowOffset(&__that);
        v6 = 100.0;
        v5 = 20.0;
        break;
    }
    v7 = ($A4C37A7477F7A8C6E9231F01C70999D4 *)((char *)v7 + 32);
    --v8;
  }
  while ( v8 );
  v4 = v16;
LABEL_11:
  v12 = (Scaleform::Render::Text::TextFilter *)(*(_DWORD *)(v4 + 144) + 168);
  if ( !Scaleform::Render::Text::TextFilter::operator==(v12, &__that) )
    Scaleform::Render::Text::TextFilter::operator=(v12, &__that);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&__that);
LABEL_14:
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
