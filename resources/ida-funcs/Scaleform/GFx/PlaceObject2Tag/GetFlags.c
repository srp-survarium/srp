Scaleform::GFx::CharPosInfoFlags *__thiscall Scaleform::GFx::PlaceObject2Tag::GetFlags(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  Scaleform::GFx::CharPosInfoFlags *v2; // eax

  v2 = result;
  result->Flags = this->pData[0] & 0x5F;
  return v2;
}
