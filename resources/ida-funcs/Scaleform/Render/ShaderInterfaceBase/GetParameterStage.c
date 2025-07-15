unsigned int __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetParameterStage(
        int a1,
        const Scaleform::Render::D3D1x::ShaderPair *sd)
{
  const Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // ecx
  const Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // eax
  int Size; // eax
  const Scaleform::Render::D3D1x::UniformVar *Uniforms; // esi
  const Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // ecx
  const Scaleform::Render::D3D1x::BatchVar *v8; // eax
  int v9; // eax
  const Scaleform::Render::D3D1x::UniformVar *v10; // ecx
  int v11; // eax

  pVDesc = sd->pVDesc;
  BatchUniforms = pVDesc->BatchUniforms;
  if ( BatchUniforms[11].Offset >= 0 )
  {
    Size = BatchUniforms[11].Size;
    if ( Size )
      return (unsigned int)&_sbh_sizeHeaderList | Size;
  }
  Uniforms = pVDesc->Uniforms;
  if ( Uniforms[11].Location >= 0 && Uniforms[11].Size > 0 )
    return (unsigned int)&_sbh_sizeHeaderList | (pVDesc->Uniforms[11].Size / (int)pVDesc->Uniforms[11].ElementSize);
  pFDesc = sd->pFDesc;
  v8 = pFDesc->BatchUniforms;
  if ( v8[11].Offset >= 0 )
  {
    v9 = v8[11].Size;
    if ( v9 )
      return (unsigned int)&loc_20000 | v9;
  }
  v10 = pFDesc->Uniforms;
  if ( v10[11].Location >= 0 )
  {
    v11 = v10[11].Size;
    if ( v11 > 0 )
    {
      v9 = v11 / Uniforms[11].ElementSize;
      return (unsigned int)&loc_20000 | v9;
    }
  }
  return 0;
}
