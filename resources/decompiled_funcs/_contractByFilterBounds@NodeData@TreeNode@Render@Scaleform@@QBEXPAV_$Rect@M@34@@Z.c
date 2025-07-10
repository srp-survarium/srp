void __thiscall Scaleform::Render::TreeNode::NodeData::contractByFilterBounds(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::Rect<float> *bounds)
{
  unsigned int State; // eax
  const Scaleform::Render::FilterSet *v3; // ecx
  unsigned int Size; // eax
  unsigned int i; // ebx
  Scaleform::Render::Filter *pObject; // edi
  double v7; // st7
  Scaleform::Render::FilterType Type; // eax
  double v9; // st7
  float count; // [esp+30h] [ebp-18h]
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
  const Scaleform::Render::FilterSet *filters; // [esp+3Ch] [ebp-Ch]
  Scaleform::Render::Filter_vtbl *offset; // [esp+40h] [ebp-8h]
  float offset_4; // [esp+44h] [ebp-4h]

  State = Scaleform::Render::StateBag::GetState(&this->States, State_ActionControl);
  if ( State )
  {
    v3 = *(const Scaleform::Render::FilterSet **)(State + 4);
    filters = v3;
    if ( v3 )
    {
      Size = v3->Filters.Data.Size;
      for ( i = 0; i < Size; ++i )
      {
        pObject = v3->Filters.Data.Data[Size - i - 1].pObject;
        if ( pObject->Type <= (unsigned int)Filter_Bevel )
        {
          v7 = SLOBYTE(pObject[1].__vftable) >= 0 ? 1.0 : 2.0;
          count = v7;
          v11 = *(float *)&pObject[1].Frozen * (double)(unsigned int)pObject[1].RefCount;
          v12 = ceil(v11);
          v16 = v12;
          v13 = *(float *)&pObject[1].Type * (double)(unsigned int)pObject[1].RefCount;
          v14 = ceil(v13);
          v15 = v14 * count;
          v17 = v16 * count;
          bounds->x1 = bounds->x1 + v15;
          bounds->x2 = bounds->x2 - v15;
          bounds->y1 = bounds->y1 + v17;
          bounds->y2 = bounds->y2 - v17;
          Type = pObject->Type;
          if ( Type == Filter_Shadow || Type == Filter_Bevel )
          {
            offset = pObject[2].__vftable;
            offset_4 = *(float *)&pObject[2].RefCount;
            v18 = fabs(*(float *)&offset);
            v19 = count * v18;
            v20 = ceil(v19);
            if ( *(float *)&offset <= 0.0 )
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
            v21 = fabs(offset_4);
            v22 = v21 * count;
            v23 = ceil(v22);
            if ( offset_4 <= 0.0 )
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
        v3 = filters;
        Size = filters->Filters.Data.Size;
      }
    }
  }
}
