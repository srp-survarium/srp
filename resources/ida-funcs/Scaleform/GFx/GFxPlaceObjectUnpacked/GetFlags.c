Scaleform::GFx::CharPosInfoFlags *__thiscall Scaleform::GFx::GFxPlaceObjectUnpacked::GetFlags(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  Scaleform::GFx::CharPosInfoFlags *v2; // eax

  v2 = result;
  result->Flags = (unsigned __int16)this->Pos.Flags;
  return v2;
}
