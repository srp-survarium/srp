char __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::initHAL(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        const Scaleform::Render::HALInitParams *params)
{
  char result; // al

  result = Scaleform::Render::HAL::initHAL(this, params);
  if ( result )
  {
    this->MapVertexFormat(
      this,
      PrimFill_Texture,
      &Scaleform::Render::VertexXY16iAlpha::Format,
      this->MappedXY16iAlphaTexture,
      &this->MappedXY16iAlphaTexture[1],
      &this->MappedXY16iAlphaTexture[2],
      0);
    this->MapVertexFormat(
      this,
      PrimFill_SolidColor,
      &Scaleform::Render::VertexXY16iAlpha::Format,
      this->MappedXY16iAlphaSolid,
      &this->MappedXY16iAlphaSolid[1],
      &this->MappedXY16iAlphaSolid[2],
      0);
    return 1;
  }
  return result;
}
