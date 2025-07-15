void __cdecl Scaleform::Render::SnapRectToPixels(Scaleform::Render::Rect<float> *rect)
{
  float recta; // [esp+10h] [ebp+4h]
  float rectb; // [esp+10h] [ebp+4h]
  float rectc; // [esp+10h] [ebp+4h]
  float rectd; // [esp+10h] [ebp+4h]
  float recte; // [esp+10h] [ebp+4h]
  float rectf; // [esp+10h] [ebp+4h]
  float rectg; // [esp+10h] [ebp+4h]
  float recth; // [esp+10h] [ebp+4h]

  recta = rect->x1 - 10.0;
  rectb = floor(recta);
  rect->x1 = rectb;
  rectc = rect->y1 - 10.0;
  rectd = floor(rectc);
  rect->y1 = rectd;
  recte = rect->x2 + 10.0;
  rectf = ceil(recte);
  rect->x2 = rectf;
  rectg = rect->y2 + 10.0;
  recth = ceil(rectg);
  rect->y2 = recth;
}
