void __cdecl Scaleform::Render::DrawableImage::CalcFilterRect(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Filter *filter)
{
  Scaleform::Render::Rect<float> v3; // [esp+20h] [ebp-20h] BYREF
  float x1; // [esp+30h] [ebp-10h]
  float y1; // [esp+34h] [ebp-Ch]
  float x2; // [esp+38h] [ebp-8h]
  float y2; // [esp+3Ch] [ebp-4h]

  x1 = (float)sourceRect->x1;
  y1 = (float)sourceRect->y1;
  x2 = (float)sourceRect->x2;
  y2 = (float)sourceRect->y2;
  v3.x1 = x1;
  v3.y1 = y1;
  v3.x2 = x2;
  v3.y2 = y2;
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(filter, &v3);
  if ( result )
    *result = v3;
}
