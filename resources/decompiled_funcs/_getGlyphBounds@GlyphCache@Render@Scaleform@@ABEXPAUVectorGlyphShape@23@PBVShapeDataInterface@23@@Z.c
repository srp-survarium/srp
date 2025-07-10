void __thiscall Scaleform::Render::GlyphCache::getGlyphBounds(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::VectorGlyphShape *glyphShape,
        const Scaleform::Render::ShapeDataInterface *shapeData)
{
  Scaleform::Render::Rect<float> *v3; // eax
  float y1; // [esp+14h] [ebp-3Ch]
  float x2; // [esp+18h] [ebp-38h]
  float y2; // [esp+1Ch] [ebp-34h]
  Scaleform::Render::Rect<float> result; // [esp+20h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [esp+30h] [ebp-20h] BYREF

  if ( glyphShape->Key.HintedVector )
  {
    if ( shapeData->IsEmpty(shapeData) )
    {
      glyphShape->Key.pFont->pFont->GetGlyphBounds(
        glyphShape->Key.pFont->pFont,
        glyphShape->Key.GlyphIndex,
        &glyphShape->Bounds);
    }
    else
    {
      trans.M[0][0] = 1.0;
      trans.M[0][1] = 0.0;
      trans.M[0][2] = 0.0;
      trans.M[0][3] = 0.0;
      trans.M[1][0] = 0.0;
      trans.M[1][2] = 0.0;
      trans.M[1][3] = 0.0;
      trans.M[1][1] = 1.0;
      result.x1 = 1.0e30;
      result.y1 = 1.0e30;
      result.x2 = -1.0e30;
      result.y2 = -1.0e30;
      Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(
        shapeData,
        &trans,
        &result,
        Bound_AllEdges);
      glyphShape->Bounds = result;
    }
  }
  else
  {
    glyphShape->Key.pFont->pFont->GetGlyphBounds(
      glyphShape->Key.pFont->pFont,
      glyphShape->Key.GlyphIndex,
      &glyphShape->Bounds);
    if ( (glyphShape->Bounds.x2 <= (double)glyphShape->Bounds.x1
       || glyphShape->Bounds.y2 <= (double)glyphShape->Bounds.y1)
      && !shapeData->IsEmpty(shapeData) )
    {
      trans.M[0][0] = 1.0;
      trans.M[0][1] = 0.0;
      trans.M[0][2] = 0.0;
      trans.M[0][3] = 0.0;
      trans.M[1][0] = 0.0;
      trans.M[1][2] = 0.0;
      trans.M[1][3] = 0.0;
      trans.M[1][1] = 1.0;
      v3 = Scaleform::Render::ComputeBoundsFill<Scaleform::Render::Matrix2x4<float>>(
             &result,
             shapeData,
             &trans,
             Bound_AllEdges);
      y1 = v3->y1;
      x2 = v3->x2;
      y2 = v3->y2;
      glyphShape->Bounds.x1 = v3->x1;
      glyphShape->Bounds.y1 = y1;
      glyphShape->Bounds.x2 = x2;
      glyphShape->Bounds.y2 = y2;
    }
  }
}
