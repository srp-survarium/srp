void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        const Scaleform::Render::D3D1x::ShaderPair *sd@<edi>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        unsigned int var,
        float *v,
        unsigned int n,
        unsigned int index,
        unsigned int batch)
{
  unsigned int v7; // esi
  const Scaleform::Render::D3D1x::UniformVar *v8; // eax
  const Scaleform::Render::D3D1x::UniformVar *v9; // eax

  v7 = var;
  if ( sd->pVDesc->Uniforms[var].Size )
  {
    v8 = &sd->pVDesc->Uniforms[v7];
    memcpy(
      (unsigned __int8 *)&this->UniformData[v8->ShadowOffset + index * v8->ElementSize],
      (unsigned __int8 *)v,
      4 * n);
  }
  if ( sd->pFDesc->Uniforms[v7].Size )
  {
    v9 = &sd->pFDesc->Uniforms[v7];
    memcpy(
      (unsigned __int8 *)&this->UniformData[v9->ShadowOffset + index * v9->ElementSize],
      (unsigned __int8 *)v,
      4 * n);
  }
  this->UniformSet[var] = 1;
}
