Scaleform::GFx::CharPosInfoFlags *__thiscall Scaleform::GFx::PlaceObject3Tag::GetFlags(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  char v2; // dl
  int v3; // eax
  char v4; // cl
  Scaleform::GFx::CharPosInfoFlags *v5; // eax

  v2 = this->pData[0];
  v3 = 1;
  if ( v2 < 0 )
    v3 = 5;
  v4 = this->pData[v3] & 1 | (2 * (this->pData[v3] & 0xFE));
  v5 = result;
  result->Flags = v2 & 0x5F | (unsigned __int8)(32 * v4);
  return v5;
}
