bool __thiscall Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::Rect<float> *bounds,
        bool boundsEmpty)
{
  bool result; // al
  unsigned int State; // eax
  int v5; // edi
  unsigned int i; // esi

  result = boundsEmpty;
  if ( !boundsEmpty )
  {
    State = Scaleform::Render::StateBag::GetState(&this->States, State_ActionControl);
    if ( State )
    {
      v5 = *(_DWORD *)(State + 4);
      if ( v5 )
      {
        for ( i = 0; i < *(_DWORD *)(v5 + 12); ++i )
          Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
            *(const Scaleform::Render::Filter **)(*(_DWORD *)(v5 + 8) + 4 * i),
            bounds);
      }
    }
    return 0;
  }
  return result;
}


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
  float v10; // [esp+8h] [ebp-Ch]
  float v11; // [esp+8h] [ebp-Ch]
  float v12; // [esp+8h] [ebp-Ch]
  float v13; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Filter_vtbl *v14; // [esp+8h] [ebp-Ch]
  float v15; // [esp+Ch] [ebp-8h]
  float v16; // [esp+10h] [ebp-4h]
  float v17; // [esp+10h] [ebp-4h]
  float v18; // [esp+10h] [ebp-4h]
  float v19; // [esp+10h] [ebp-4h]
  float v20; // [esp+10h] [ebp-4h]
  float v21; // [esp+10h] [ebp-4h]
  float v22; // [esp+10h] [ebp-4h]
  float v23; // [esp+10h] [ebp-4h]
  float v24; // [esp+10h] [ebp-4h]
  float v25; // [esp+18h] [ebp+4h]
  float v26; // [esp+18h] [ebp+4h]
  float v27; // [esp+18h] [ebp+4h]

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
      v25 = v4;
      v6 = (double)(int)filter[1].RefCount;
      if ( RefCount < 0 )
        v6 = v6 + 4294967300.0;
      v16 = v6;
      v10 = *(float *)&filter[1].Type * 0.05000000074505806;
      v11 = v10 + 1.0;
      v12 = v11 * 20.0;
      v13 = v12 * v16 * v25;
      v7 = v16;
      v17 = 0.05000000074505806 * *(float *)&filter[1].Frozen;
      v18 = v17 + 1.0;
      v19 = 20.0 * v18;
      v20 = v7 * v19 * v25;
      bounds->x1 = bounds->x1 - v13;
      bounds->x2 = v13 + bounds->x2;
      bounds->y1 = bounds->y1 - v20;
      bounds->y2 = v20 + bounds->y2;
      v8 = filter->Type;
      if ( v8 == Filter_Shadow || v8 == Filter_Bevel )
      {
        v14 = filter[2].__vftable;
        v15 = *(float *)&filter[2].RefCount;
        v21 = fabs(*(float *)&v14);
        v22 = v25 * v21;
        v23 = ceilf(v22);
        if ( *(float *)&v14 <= 0.0 )
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
        v24 = fabs(v15);
        v26 = v24 * v25;
        v27 = ceilf(v26);
        if ( v15 <= 0.0 )
        {
          bounds->y1 = bounds->y1 - v27;
          bounds->y2 = bounds->y2 + 0.0;
        }
        else
        {
          bounds->y1 = bounds->y1 - 0.0;
          bounds->y2 = bounds->y2 + v27;
        }
      }
      Scaleform::Render::SnapRectToPixels(bounds);
    }
  }
}
