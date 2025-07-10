void __cdecl Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
        const Scaleform::Render::Filter *filter,
        Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::FilterType Type; // ecx
  double v4; // st7
  volatile int RefCount; // ecx
  double v6; // st7
  double v7; // st7
  Scaleform::Render::FilterType v8; // ecx
  double v9; // st7
  float offset; // [esp+8h] [ebp-Ch]
  float offseta; // [esp+8h] [ebp-Ch]
  float offsetb; // [esp+8h] [ebp-Ch]
  float offsetc; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Filter_vtbl *offsetd; // [esp+8h] [ebp-Ch]
  float offset_4; // [esp+Ch] [ebp-8h]
  float v16; // [esp+10h] [ebp-4h]
  float v17; // [esp+10h] [ebp-4h]
  float v18; // [esp+10h] [ebp-4h]
  float v19; // [esp+10h] [ebp-4h]
  float v20; // [esp+10h] [ebp-4h]
  float v21; // [esp+10h] [ebp-4h]
  float _X; // [esp+10h] [ebp-4h]
  float v23; // [esp+10h] [ebp-4h]
  float v24; // [esp+10h] [ebp-4h]
  float count; // [esp+18h] [ebp+4h]
  float countb; // [esp+18h] [ebp+4h]
  float counta; // [esp+18h] [ebp+4h]

  if ( filter )
  {
    Type = filter->Type;
    if ( (unsigned int)Type <= Filter_Bevel )
    {
      if ( Type == Filter_Bevel )
        v4 = 2.0;
      else
        v4 = 1.0;
      RefCount = filter[1].RefCount;
      count = v4;
      v6 = (double)(int)filter[1].RefCount;
      if ( RefCount < 0 )
        v6 = v6 + 4294967300.0;
      v16 = v6;
      offset = *(float *)&filter[1].Type * 0.05000000074505806;
      offseta = offset + 1.0;
      offsetb = offseta * 20.0;
      offsetc = offsetb * v16 * count;
      v7 = v16;
      v17 = 0.05000000074505806 * *(float *)&filter[1].Frozen;
      v18 = v17 + 1.0;
      v19 = 20.0 * v18;
      v20 = v7 * v19 * count;
      bounds->x1 = bounds->x1 - offsetc;
      bounds->x2 = offsetc + bounds->x2;
      bounds->y1 = bounds->y1 - v20;
      bounds->y2 = v20 + bounds->y2;
      v8 = filter->Type;
      if ( v8 == Filter_Shadow || v8 == Filter_Bevel )
      {
        offsetd = filter[2].__vftable;
        offset_4 = *(float *)&filter[2].RefCount;
        v21 = fabs(*(float *)&offsetd);
        _X = count * v21;
        v23 = ceilf(_X);
        if ( *(float *)&offsetd <= 0.0 )
        {
          bounds->x1 = bounds->x1 - v23;
          v9 = bounds->x2 + 0.0;
        }
        else
        {
          bounds->x1 = bounds->x1 - 0.0;
          v9 = bounds->x2 + v23;
        }
        bounds->x2 = v9;
        v24 = fabs(offset_4);
        countb = v24 * count;
        counta = ceilf(countb);
        if ( offset_4 <= 0.0 )
        {
          bounds->y1 = bounds->y1 - counta;
          bounds->y2 = bounds->y2 + 0.0;
        }
        else
        {
          bounds->y1 = bounds->y1 - 0.0;
          bounds->y2 = bounds->y2 + counta;
        }
      }
      Scaleform::Render::SnapRectToPixels(bounds);
    }
  }
}
