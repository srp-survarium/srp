void __cdecl Scaleform::Render::DrawableImage::CalcFilterRect(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Filter *filter)
{
  Scaleform::Render::Rect<float> bounds; // [esp+0h] [ebp-20h] BYREF
  float x1; // [esp+10h] [ebp-10h]
  float y1; // [esp+14h] [ebp-Ch]
  float x2; // [esp+18h] [ebp-8h]
  float y2; // [esp+1Ch] [ebp-4h]

  x1 = (float)sourceRect->x1;
  y1 = (float)sourceRect->y1;
  x2 = (float)sourceRect->x2;
  y2 = (float)sourceRect->y2;
  bounds.x1 = x1;
  bounds.y1 = y1;
  bounds.x2 = x2;
  bounds.y2 = y2;
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(filter, &bounds);
  if ( result )
    *result = bounds;
}
