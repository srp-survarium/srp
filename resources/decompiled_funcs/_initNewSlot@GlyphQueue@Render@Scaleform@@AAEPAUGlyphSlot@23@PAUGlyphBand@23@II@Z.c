Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *__thiscall Scaleform::Render::GlyphQueue::initNewSlot(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphBand *band,
        unsigned __int16 x,
        unsigned __int16 w)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *v5; // esi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v6; // eax
  Scaleform::Render::GlyphRect v8; // [esp+8h] [ebp-8h]

  v5 = Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79>>::allocate(&this->Slots);
  v6 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::allocate(&this->Glyphs);
  v5->Data[0].pBand = band;
  v5->Data[0].pRoot = (Scaleform::Render::GlyphNode *)v6;
  v5->Data[0].TextureId = band->TextureId;
  v5->Data[0].x = x;
  v5->Data[0].w = w;
  v5->Data[0].Failures = 0;
  v5->Data[0].PinCount = 0;
  v5->Data[0].TextFields.Root.pPrev = (Scaleform::Render::TextNotifier *)&v5->Data[0].TextFields;
  v5->Data[0].TextFields.Root.pNext = (Scaleform::Render::TextNotifier *)&v5->Data[0].TextFields;
  v5->Data[0].SlotFence.pObject = 0;
  v6->Data[0].Param.GlyphIndex = 0;
  v6->Data[0].Param.FontSize = 0;
  v6->Data[0].Param.Flags = 0;
  v6->Data[0].Param.BlurX = 0;
  v6->Data[0].Param.BlurY = 0;
  v6->Data[0].Param.pFont = 0;
  v6->Data[0].pSlot = (Scaleform::Render::GlyphSlot *)v5;
  v6->Data[0].pNext = 0;
  v6->Data[0].pNex2 = 0;
  v6->Data[0].Param.BlurStrength = 16;
  v8.x = v5->Data[0].x;
  v8.y = band->y;
  v8.w = v5->Data[0].w;
  v8.h = band->h;
  v6->Data[0].mRect = v8;
  v6->Data[0].Origin.x = 0;
  v6->Data[0].Origin.y = 0;
  return v5;
}
