void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        const Scaleform::Render::D3D1x::ShaderPair *sd@<eax>,
        unsigned int var@<ecx>,
        unsigned int index@<esi>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        const float *v,
        unsigned int n,
        unsigned int batch)
{
  const Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // edx
  unsigned int v9; // eax
  _DWORD *pVDesc; // ecx
  unsigned int v11; // [esp+0h] [ebp-Ch]

  BatchUniforms = sd->pVDesc->BatchUniforms;
  v9 = 3 * var;
  if ( BatchUniforms[var].Offset >= 0 )
  {
    pVDesc = sd->pVDesc;
LABEL_3:
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
      this,
      sd,
      *(char *)(v9 + pVDesc[6]),
      v,
      n,
      index
    + batch * *(unsigned __int8 *)(pVDesc[5] + 10 * *(char *)(v9 + pVDesc[6]) + 9)
    + *(char *)(v9 + pVDesc[6] + 1),
      v11);
    return;
  }
  if ( sd->pFDesc->BatchUniforms[v9 / 3].Offset >= 0 )
  {
    pVDesc = sd->pFDesc;
    goto LABEL_3;
  }
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
    this,
    sd,
    var,
    v,
    n,
    index,
    v11);
}
