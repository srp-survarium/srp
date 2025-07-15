void __thiscall Scaleform::Render::TreeNode::NodeData::contractByFilterBounds(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::Rect<float> *bounds)
{
  unsigned int State; // eax
  int v3; // ecx
  unsigned int v4; // eax
  unsigned int i; // ebx
  int v6; // edi
  double v7; // st7
  int v8; // eax
  double v9; // st7
  float v10; // [esp+30h] [ebp-18h]
  float v11; // [esp+34h] [ebp-14h]
  float v12; // [esp+34h] [ebp-14h]
  float v13; // [esp+34h] [ebp-14h]
  float v14; // [esp+34h] [ebp-14h]
  float v15; // [esp+34h] [ebp-14h]
  float v16; // [esp+38h] [ebp-10h]
  float v17; // [esp+38h] [ebp-10h]
  float v18; // [esp+38h] [ebp-10h]
  float v19; // [esp+38h] [ebp-10h]
  float v20; // [esp+38h] [ebp-10h]
  float v21; // [esp+38h] [ebp-10h]
  float v22; // [esp+38h] [ebp-10h]
  float v23; // [esp+38h] [ebp-10h]
  int v24; // [esp+3Ch] [ebp-Ch]
  float v25; // [esp+40h] [ebp-8h]
  float v26; // [esp+44h] [ebp-4h]

  State = Scaleform::Render::StateBag::GetState(&this->States, State_ActionControl);
  if ( State )
  {
    v3 = *(_DWORD *)(State + 4);
    v24 = v3;
    if ( v3 )
    {
      v4 = *(_DWORD *)(v3 + 12);
      for ( i = 0; i < v4; ++i )
      {
        v6 = *(_DWORD *)(*(_DWORD *)(v3 + 8) + 4 * (v4 - i) - 4);
        if ( *(_DWORD *)(v6 + 8) <= 3u )
        {
          v7 = *(char *)(v6 + 16) >= 0 ? 1.0 : 2.0;
          v10 = v7;
          v11 = *(float *)(v6 + 28) * (double)*(unsigned int *)(v6 + 20);
          v12 = ceil(v11);
          v16 = v12;
          v13 = *(float *)(v6 + 24) * (double)*(unsigned int *)(v6 + 20);
          v14 = ceil(v13);
          v15 = v14 * v10;
          v17 = v16 * v10;
          bounds->x1 = bounds->x1 + v15;
          bounds->x2 = bounds->x2 - v15;
          bounds->y1 = bounds->y1 + v17;
          bounds->y2 = bounds->y2 - v17;
          v8 = *(_DWORD *)(v6 + 8);
          if ( v8 == 1 || v8 == 3 )
          {
            v25 = *(float *)(v6 + 32);
            v26 = *(float *)(v6 + 36);
            v18 = fabs(v25);
            v19 = v10 * v18;
            v20 = ceil(v19);
            if ( v25 <= 0.0 )
            {
              bounds->x1 = bounds->x1 + v20;
              v9 = bounds->x2 - 0.0;
            }
            else
            {
              bounds->x1 = bounds->x1 + 0.0;
              v9 = bounds->x2 - v20;
            }
            bounds->x2 = v9;
            v21 = fabs(v26);
            v22 = v21 * v10;
            v23 = ceil(v22);
            if ( v26 <= 0.0 )
            {
              bounds->x1 = bounds->x1 + v23;
              bounds->x2 = bounds->x2 - 0.0;
            }
            else
            {
              bounds->x1 = bounds->x1 + 0.0;
              bounds->x2 = bounds->x2 - v23;
            }
          }
        }
        v3 = v24;
        v4 = *(_DWORD *)(v24 + 12);
      }
    }
  }
}
