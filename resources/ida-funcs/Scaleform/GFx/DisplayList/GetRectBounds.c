Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::DisplayList::GetRectBounds(
        Scaleform::GFx::DisplayList *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned int Size; // eax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // edi
  Scaleform::GFx::DisplayObjectBase *v5; // ecx
  const Scaleform::Render::Matrix2x4<float> *v6; // eax
  float *v7; // eax
  int v9; // [esp+2Ch] [ebp-4Ch]
  unsigned int v10; // [esp+30h] [ebp-48h]
  Scaleform::GFx::DisplayList *v11; // [esp+34h] [ebp-44h]
  Scaleform::Render::Rect<float> left; // [esp+38h] [ebp-40h]
  Scaleform::Render::Rect<float> v13; // [esp+48h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v14; // [esp+58h] [ebp-20h] BYREF

  Size = this->DisplayObjectArray.Data.Size;
  result->x1 = 0.0;
  result->y1 = 0.0;
  result->x2 = 0.0;
  v11 = this;
  result->y2 = 0.0;
  v14.M[0][0] = 1.0;
  v14.M[1][1] = 1.0;
  v14.M[0][1] = 0.0;
  v14.M[0][2] = 0.0;
  v14.M[0][3] = 0.0;
  v14.M[1][0] = 0.0;
  v14.M[1][2] = 0.0;
  v14.M[1][3] = 0.0;
  if ( Size )
  {
    v9 = 0;
    v10 = Size;
    while ( 1 )
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v9].pCharacter;
      if ( pCharacter )
      {
        v5 = this->DisplayObjectArray.Data.Data[v9].pCharacter;
        v14.M[0][0] = transform->M[0][0];
        v14.M[0][1] = transform->M[0][1];
        v14.M[0][2] = transform->M[0][2];
        v14.M[0][3] = transform->M[0][3];
        v14.M[1][0] = transform->M[1][0];
        v14.M[1][1] = transform->M[1][1];
        v14.M[1][2] = transform->M[1][2];
        v14.M[1][3] = transform->M[1][3];
        v6 = pCharacter->GetMatrix(v5);
        Scaleform::Render::Matrix2x4<float>::Prepend(&v14, v6);
        v7 = (float *)pCharacter->GetRectBounds(pCharacter, &v13, &v14);
        left.x1 = *v7;
        left.y1 = v7[1];
        left.x2 = v7[2];
        left.y2 = v7[3];
        if ( left.x2 > (double)left.x1 && left.y2 > (double)left.y1 )
        {
          if ( Scaleform::Render::Rect<float>::IsEmpty(result) )
            *result = left;
          else
            Scaleform::Render::Rect<float>::Union(result, left.x1, left.y1, left.x2, left.y2);
        }
      }
      ++v9;
      if ( !--v10 )
        break;
      this = v11;
    }
  }
  return result;
}
