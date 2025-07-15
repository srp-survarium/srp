Scaleform::Render::D3D1x::SysVertexFormat *__thiscall Scaleform::Render::D3D1x::SysVertexFormat::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::SysVertexFormat *this,
        char a2)
{
  ID3D11InputLayout *pObject; // eax

  pObject = this->pVDecl.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::Render::SystemVertexFormat::~SystemVertexFormat(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
