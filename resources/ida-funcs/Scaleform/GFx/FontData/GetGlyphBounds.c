Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::FontData::GetGlyphBounds(
        Scaleform::GFx::FontData *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  Scaleform::Render::Rect<float> *result; // eax
  Scaleform::GFx::FontData::AdvanceEntry *v5; // ecx
  Scaleform::GFx::ShapeDataBase *pObject; // ecx
  bool v7; // zf
  double x1; // st7
  double y1; // st6
  float v10; // [esp+14h] [ebp-1Ch]
  float v11; // [esp+14h] [ebp-1Ch]
  float Advance; // [esp+14h] [ebp-1Ch]
  float v13; // [esp+1Ch] [ebp-14h]
  float v14; // [esp+1Ch] [ebp-14h]
  float v15; // [esp+1Ch] [ebp-14h]
  float v16; // [esp+1Ch] [ebp-14h]
  Scaleform::Render::Rect<float> r; // [esp+20h] [ebp-10h] BYREF

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    prect->y1 = 0.0;
    prect->x1 = 0.0;
    v10 = this->GetGlyphWidth(this, glyphIndex);
    prect->x2 = prect->x1 + v10;
    v11 = this->GetGlyphHeight(this, glyphIndex);
    result = prect;
    prect->y2 = prect->y1 + v11;
  }
  else if ( glyphIndex >= this->AdvanceTable.Data.Size )
  {
    prect->y1 = 0.0;
    prect->x1 = 0.0;
    v14 = 0.0 + 0.0;
    prect->x2 = v14;
    prect->y2 = v14;
    if ( glyphIndex < this->Glyphs.Data.Size && (pObject = this->Glyphs.Data.Data[glyphIndex].pObject) != 0 )
    {
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::ShapeDataBase::ComputeBound(pObject, &r);
      v7 = !Scaleform::Render::Rect<float>::IsNormal(&r);
      result = prect;
      if ( !v7 )
      {
        x1 = r.x1;
        prect->x1 = r.x1;
        y1 = r.y1;
        prect->y1 = r.y1;
        v15 = r.x2 - x1;
        prect->x2 = x1 + v15;
        v16 = r.y2 - y1;
        prect->y2 = y1 + v16;
      }
    }
    else
    {
      return prect;
    }
  }
  else
  {
    v5 = &this->AdvanceTable.Data.Data[glyphIndex];
    Advance = (double)v5->Width / 20.0;
    if ( 0.0 == Advance )
      Advance = v5->Advance;
    result = prect;
    v13 = (double)v5->Height / 20.0;
    prect->x1 = (double)v5->Left / 20.0;
    prect->y1 = (double)v5->Top / 20.0;
    prect->x2 = prect->x1 + Advance;
    prect->y2 = prect->y1 + v13;
  }
  return result;
}
