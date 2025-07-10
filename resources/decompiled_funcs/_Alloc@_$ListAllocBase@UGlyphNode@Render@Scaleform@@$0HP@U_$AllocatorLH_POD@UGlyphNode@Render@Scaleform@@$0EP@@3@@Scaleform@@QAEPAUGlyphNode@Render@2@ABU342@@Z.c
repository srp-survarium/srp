Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::Alloc(
        Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> > *this,
        const Scaleform::Render::GlyphNode *v)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *result; // eax
  __int16 y; // dx

  result = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::allocate(this);
  result->Data[0].Param.pFont = v->Param.pFont;
  *(_DWORD *)&result->Data[0].Param.GlyphIndex = *(_DWORD *)&v->Param.GlyphIndex;
  *(_DWORD *)&result->Data[0].Param.Flags = *(_DWORD *)&v->Param.Flags;
  *(_DWORD *)&result->Data[0].Param.BlurY = *(_DWORD *)&v->Param.BlurY;
  result->Data[0].pSlot = v->pSlot;
  result->Data[0].pNext = v->pNext;
  result->Data[0].pNex2 = v->pNex2;
  result->Data[0].mRect = v->mRect;
  y = v->Origin.y;
  result->Data[0].Origin.x = v->Origin.x;
  result->Data[0].Origin.y = y;
  result->Data[0].Scale = v->Scale;
  return result;
}
