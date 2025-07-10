char __usercall Scaleform::Render::D3D1x::VertexShader::Init@<al>(
        Scaleform::Render::D3D1x::VertexShader *this@<edi>,
        ID3D11Device *pdevice@<eax>,
        const Scaleform::Render::D3D1x::VertexShaderDesc *pd@<esi>)
{
  unsigned int v4; // eax
  int *v5; // ecx

  this->pDesc = pd;
  if ( pdevice->CreateVertexShader(pdevice, pd->pBinary, pd->BinarySize, 0, (ID3D11VertexShader **)&this->pProg) < 0 )
    return 0;
  v4 = 3;
  v5 = &this->UniformOffset[1];
  do
  {
    *(v5 - 1) = 16 * pd->Uniforms[v4 - 3].Location;
    *v5 = 16 * pd->Uniforms[v4 - 2].Location;
    v5[1] = 16 * pd->Uniforms[v4 - 1].Location;
    v5[2] = 16 * pd->Uniforms[v4].Location;
    v5[3] = 16 * pd->Uniforms[v4 + 1].Location;
    v4 += 5;
    v5 += 5;
  }
  while ( v4 < 18 );
  return 1;
}
