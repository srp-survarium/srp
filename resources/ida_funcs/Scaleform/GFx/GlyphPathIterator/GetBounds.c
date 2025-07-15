Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetBounds(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Rect<float> *result; // eax
  Scaleform::Render::Rect<float> v3; // [esp+10h] [ebp-10h]

  v3.x1 = (float)this->XMin;
  result = r;
  v3.y1 = (float)this->YMin;
  v3.x2 = (float)this->XMax;
  v3.y2 = (float)this->YMax;
  *r = v3;
  return result;
}
