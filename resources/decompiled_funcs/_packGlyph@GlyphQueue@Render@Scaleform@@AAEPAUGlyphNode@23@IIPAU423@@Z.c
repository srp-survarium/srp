Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::packGlyph(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h,
        Scaleform::Render::GlyphNode *glyph)
{
  Scaleform::Render::GlyphNode *result; // eax
  Scaleform::Render::GlyphNode *pNex2; // esi
  unsigned int v8; // ebx
  unsigned int v9; // ebp
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v12; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v13; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v14; // eax
  Scaleform::ListAllocLH_POD<Scaleform::Render::GlyphNode,127,79> *glypha; // [esp+1Ch] [ebp+Ch]

  if ( glyph->Param.pFont )
  {
    result = 0;
    if ( !glyph->pNext || (result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, glyph->pNext)) == 0 )
    {
      pNex2 = glyph->pNex2;
      if ( pNex2 )
        return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, pNex2);
    }
  }
  else
  {
    v8 = glyph->mRect.w;
    if ( w > v8 )
      return 0;
    v9 = glyph->mRect.h;
    if ( h > v9 )
    {
      return 0;
    }
    else
    {
      v10 = v9 - h;
      v11 = v8 - w;
      if ( v11 >= this->MinSlotSpace || v10 >= this->MinSlotSpace )
      {
        glypha = &this->Glyphs;
        v12 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::Alloc(
                &this->Glyphs,
                glyph);
        glyph->pNext = (Scaleform::Render::GlyphNode *)v12;
        if ( v11 <= v10 )
        {
          v12->Data[0].mRect.y = h + glyph->mRect.y;
          glyph->pNext->mRect.h = v10;
          if ( v11 >= this->MinSlotSpace )
          {
            v14 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::Alloc(
                    glypha,
                    glyph);
            glyph->pNex2 = (Scaleform::Render::GlyphNode *)v14;
            v14->Data[0].pNext = 0;
            glyph->pNex2->mRect.x = w + glyph->mRect.x;
            glyph->pNex2->mRect.w = v11;
            glyph->pNex2->mRect.h = h;
          }
        }
        else
        {
          v12->Data[0].mRect.x = w + glyph->mRect.x;
          glyph->pNext->mRect.w = v11;
          if ( v10 >= this->MinSlotSpace )
          {
            v13 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::Alloc(
                    glypha,
                    glyph);
            glyph->pNex2 = (Scaleform::Render::GlyphNode *)v13;
            v13->Data[0].pNext = 0;
            glyph->pNex2->mRect.y = h + glyph->mRect.y;
            glyph->pNex2->mRect.h = v10;
            glyph->pNex2->mRect.w = w;
          }
        }
      }
      glyph->mRect.w = w;
      glyph->mRect.h = h;
      return glyph;
    }
  }
  return result;
}
