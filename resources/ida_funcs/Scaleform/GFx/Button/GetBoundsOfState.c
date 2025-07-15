Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::Button::GetBoundsOfState(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *transform,
        Scaleform::GFx::Button::ButtonState state)
{
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *p_Characters; // ebx
  int v5; // esi
  Scaleform::Render::Rect<float> *BoundsOfRecord; // eax
  Scaleform::GFx::Button *v8; // [esp+2Ch] [ebp-24h]
  Scaleform::Render::Rect<float> left; // [esp+30h] [ebp-20h]
  Scaleform::Render::Rect<float> v10; // [esp+40h] [ebp-10h] BYREF

  result->x1 = 0.0;
  result->y1 = 0.0;
  p_Characters = &this->States[state].Characters;
  result->x2 = 0.0;
  v5 = 0;
  result->y2 = 0.0;
  v8 = this;
  if ( this->States[state].Characters.Data.Size )
  {
    while ( 1 )
    {
      BoundsOfRecord = Scaleform::GFx::Button::GetBoundsOfRecord(
                         this,
                         &v10,
                         transform,
                         p_Characters->Data.Data[v5].Char.pObject);
      left.x1 = BoundsOfRecord->x1;
      left.y1 = BoundsOfRecord->y1;
      left.x2 = BoundsOfRecord->x2;
      left.y2 = BoundsOfRecord->y2;
      if ( left.x1 != left.x2 || left.y1 != left.y2 )
      {
        if ( Scaleform::Render::Rect<float>::IsNull(result) )
          *result = left;
        else
          Scaleform::Render::Rect<float>::Union(result, left.x1, left.y1, left.x2, left.y2);
      }
      if ( ++v5 >= p_Characters->Data.Size )
        break;
      this = v8;
    }
  }
  return result;
}
