unsigned __int8 __thiscall Scaleform::Render::PrimitiveFillData::GetTextureCount(
        Scaleform::Render::PrimitiveFillData *this)
{
  Scaleform::Render::PrimitiveFillType Type; // eax

  Type = this->Type;
  if ( this->Type < PrimFill_Texture || Type > PrimFill_2Texture_EAlpha )
    return 0;
  else
    return (Type >= PrimFill_2Texture) + 1;
}
