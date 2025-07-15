void __thiscall Scaleform::Render::D3D1x::FragShader::~FragShader(Scaleform::Render::D3D1x::VertexShader *this)
{
  ID3D11VertexShader *pObject; // eax

  pObject = this->pProg.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->pProg.pObject = 0;
}
