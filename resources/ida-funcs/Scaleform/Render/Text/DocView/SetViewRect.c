void __thiscall Scaleform::Render::Text::DocView::SetViewRect(
        Scaleform::Render::Text::DocView *this,
        const Scaleform::Render::Rect<float> *rect,
        Scaleform::Render::Text::DocView::UseType ut)
{
  unsigned int v4; // edx
  unsigned __int8 AlignProps; // bl
  unsigned int v6; // ecx
  unsigned int MaxHScroll; // eax
  unsigned int MaxVScroll; // eax
  float v9; // [esp+18h] [ebp-28h]
  float x2; // [esp+18h] [ebp-28h]
  float v11; // [esp+1Ch] [ebp-24h]
  float y1; // [esp+1Ch] [ebp-24h]
  float y2; // [esp+20h] [ebp-20h]
  Scaleform::Render::Rect<float> v14; // [esp+20h] [ebp-20h]
  float v15; // [esp+20h] [ebp-20h]
  float v16; // [esp+20h] [ebp-20h]
  __int64 v17; // [esp+38h] [ebp-8h]

  if ( this->ViewRect.x1 != rect->x1
    || this->ViewRect.x2 != rect->x2
    || this->ViewRect.y1 != rect->y1
    || this->ViewRect.y2 != rect->y2 )
  {
    v9 = this->ViewRect.x2 - this->ViewRect.x1;
    v4 = (__int64)v9;
    v11 = this->ViewRect.y2 - this->ViewRect.y1;
    v17 = (__int64)v11;
    y1 = rect->y1;
    x2 = rect->x2;
    y2 = rect->y2;
    this->ViewRect.x1 = rect->x1;
    this->ViewRect.y1 = y1;
    this->ViewRect.x2 = x2;
    this->ViewRect.y2 = y2;
    v14.x1 = this->ViewRect.x1 + 40.0;
    v14.x2 = this->ViewRect.x2 - 40.0;
    v14.y1 = this->ViewRect.y1 + 40.0;
    v14.y2 = this->ViewRect.y2 - 40.0;
    this->mLineBuffer.Geom.VisibleRect = v14;
    if ( ut == UseExternally )
    {
      AlignProps = this->AlignProps;
      v15 = this->ViewRect.x2 - this->ViewRect.x1;
      v6 = (__int64)v15;
      v16 = this->ViewRect.y2 - this->ViewRect.y1;
      if ( (AlignProps & 0x30) != 0
        || v4 != v6
        && ((this->Flags & 8) != 0
         || v6 < v4 && (this->mLineBuffer.Geom.Flags & 0x20) != 0
         || (AlignProps & 3) != 0
         || Scaleform::Render::Text::DocView::ContainsNonLeftAlignment(this))
        || (unsigned int)(__int64)v16 < (unsigned int)v17 && (this->mLineBuffer.Geom.Flags & 0x20) != 0
        || ((AlignProps >> 2) & 3u) > 1 )
      {
        this->RTFlags |= 2u;
      }
      else
      {
        ++this->FormatCounter;
        MaxHScroll = Scaleform::Render::Text::DocView::GetMaxHScroll(this);
        if ( this->mLineBuffer.Geom.HScrollOffset > MaxHScroll )
          Scaleform::Render::Text::DocView::SetHScrollOffset(this, MaxHScroll);
        MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
        if ( this->mLineBuffer.Geom.FirstVisibleLinePos > MaxVScroll )
          Scaleform::Render::Text::DocView::SetVScrollOffset(this, MaxVScroll);
        this->mLineBuffer.Geom.Flags |= 1u;
      }
    }
  }
}
