bool __thiscall Scaleform::Render::PrimitiveFillData::RequiresBlend(Scaleform::Render::PrimitiveFillData *this)
{
  Scaleform::Render::PrimitiveFillType Type; // eax
  int v2; // edi
  Scaleform::Ptr<Scaleform::Render::Texture> *i; // esi
  int v4; // eax

  Type = this->Type;
  if ( this->Type >= PrimFill_None )
  {
    if ( Type <= PrimFill_Mask )
      return 0;
    if ( Type == PrimFill_SolidColor )
      return this->SolidColor.Channels.Alpha != 0xFF;
    if ( Type == PrimFill_Texture || Type == PrimFill_2Texture || Type == PrimFill_UVTexture )
    {
      v2 = 0;
      for ( i = this->Textures; ; ++i )
      {
        if ( i->pObject )
        {
          v4 = i->pObject->GetFormat(i->pObject);
          if ( v4 < 3 || v4 > 4 && v4 != 53 && v4 != 55 && v4 != 59 && v4 != 200 )
            break;
        }
        if ( ++v2 >= 2 )
          return 0;
      }
    }
  }
  return 1;
}
