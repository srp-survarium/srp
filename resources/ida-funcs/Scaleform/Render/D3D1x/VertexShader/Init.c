char __usercall Scaleform::Render::D3D1x::VertexShader::Init@<al>(
        Scaleform::Render::D3D1x::VertexShader *this@<edi>,
        ID3D11Device *pdevice@<eax>,
        const Scaleform::Render::D3D1x::VertexShaderDesc *pd@<esi>)
{
  unsigned int v4; // ecx
  int *UniformOffset; // eax

  this->pDesc = pd;
  if ( pdevice->CreateVertexShader(pdevice, pd->pBinary, pd->BinarySize, 0, (ID3D11VertexShader **)&this->pProg) < 0 )
    return 0;
  v4 = 0;
  UniformOffset = this->UniformOffset;
  do
    *UniformOffset++ = 16 * pd->Uniforms[v4++].Location;
  while ( v4 < 15 );
  return 1;
}
