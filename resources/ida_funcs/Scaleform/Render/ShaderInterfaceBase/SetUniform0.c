void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        const Scaleform::Render::D3D1x::ShaderPair *sd@<edi>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        unsigned int var,
        float *v,
        unsigned int n,
        unsigned int index,
        unsigned int batch)
{
  const Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // eax
  unsigned int v8; // esi
  const Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // edx

  pVDesc = sd->pVDesc;
  v8 = var;
  if ( pVDesc->Uniforms[var].Size )
    memcpy(
      (unsigned __int8 *)&this->UniformData[pVDesc->Uniforms[v8].ShadowOffset + index * pVDesc->Uniforms[v8].ElementSize],
      (unsigned __int8 *)v,
      4 * n);
  pFDesc = sd->pFDesc;
  if ( pFDesc->Uniforms[v8].Size )
    memcpy(
      (unsigned __int8 *)&this->UniformData[pFDesc->Uniforms[v8].ShadowOffset + index * pFDesc->Uniforms[v8].ElementSize],
      (unsigned __int8 *)v,
      4 * n);
  this->UniformSet[var] = 1;
}
