void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        const Scaleform::Render::D3D1x::ShaderPair *sd@<eax>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        unsigned int var,
        float *v,
        unsigned int n,
        unsigned int index,
        unsigned int batch)
{
  _DWORD *pVDesc; // ecx
  unsigned int v8; // [esp+0h] [ebp-8h]

  if ( sd->pVDesc->BatchUniforms[var].Offset >= 0 )
  {
    pVDesc = sd->pVDesc;
LABEL_3:
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
      sd,
      this,
      *(char *)(pVDesc[6] + 3 * var),
      v,
      n,
      index
    + batch * *(unsigned __int8 *)(10 * *(char *)(pVDesc[6] + 3 * var) + pVDesc[5] + 9)
    + *(char *)(pVDesc[6] + 3 * var + 1),
      v8);
    return;
  }
  if ( sd->pFDesc->BatchUniforms[var].Offset >= 0 )
  {
    pVDesc = sd->pFDesc;
    goto LABEL_3;
  }
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
    sd,
    this,
    var,
    v,
    n,
    index,
    v8);
}
