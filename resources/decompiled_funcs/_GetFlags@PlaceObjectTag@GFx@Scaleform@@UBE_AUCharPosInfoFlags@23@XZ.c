Scaleform::GFx::CharPosInfoFlags *__thiscall Scaleform::GFx::PlaceObjectTag::GetFlags(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  Scaleform::GFx::CharPosInfoFlags *v2; // eax

  v2 = result;
  result->Flags = (this->HasCxForm ? 8 : 0) | 7;
  return v2;
}
