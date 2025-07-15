int __usercall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetUniformSize@<eax>(
        const Scaleform::Render::D3D1x::ShaderPair *sd@<eax>,
        unsigned int i@<edx>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this)
{
  const Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // edi
  unsigned int v5; // ecx
  int result; // eax
  unsigned int v7; // edx
  __int16 *p_Location; // edi
  const Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // edi
  __int16 *v10; // ecx

  pVDesc = sd->pVDesc;
  v5 = i;
  result = 0;
  if ( pVDesc->BatchUniforms[i].Array <= 14 )
    return pVDesc->BatchUniforms[i].Size * pVDesc->Uniforms[pVDesc->BatchUniforms[i].Array].ElementSize;
  v7 = i;
  p_Location = &pVDesc->Uniforms[v7].Location;
  if ( *p_Location >= 0 )
    return p_Location[3];
  pFDesc = sd->pFDesc;
  if ( pFDesc->BatchUniforms[v5].Array <= 14 )
    return pFDesc->BatchUniforms[v5].Size * pFDesc->Uniforms[pFDesc->BatchUniforms[v5].Array].ElementSize;
  v10 = &pFDesc->Uniforms[v7].Location;
  if ( *v10 >= 0 )
    return v10[3];
  return result;
}
