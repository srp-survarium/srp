void __userpurge Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(
        const Scaleform::Render::D3D1x::VertexShaderDesc *pvdesc@<eax>,
        Scaleform::Render::D3D1x::SysVertexFormat *this,
        ID3D11Device *pdevice,
        const Scaleform::Render::VertexFormat *vf)
{
  int NumAttribs; // eax
  unsigned int *p_SemanticIndex; // ecx
  int v8; // edi
  int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned int v11; // edi
  bool v12; // zf
  unsigned int v13; // edi
  ID3D11InputLayout *pObject; // eax
  unsigned __int8 src[224]; // [esp+Ch] [ebp-74h] BYREF
  unsigned __int16 v16; // [esp+ECh] [ebp+6Ch]
  int v17; // [esp+F8h] [ebp+78h]

  this->__vftable = (Scaleform::Render::D3D1x::SysVertexFormat_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::D3D1x::SysVertexFormat_vtbl *)&Scaleform::Render::D3D1x::SysVertexFormat::`vftable';
  this->pVDecl.pObject = 0;
  v16 = 0;
  NumAttribs = pvdesc->NumAttribs;
  if ( NumAttribs > 0 )
  {
    p_SemanticIndex = &pvdesc->Attributes[0].SemanticIndex;
    v17 = NumAttribs;
    do
    {
      v8 = *(p_SemanticIndex - 1);
      v9 = 28 * v16++;
      v10 = &src[v9];
      *((_DWORD *)v10 + 4) = -1;
      *(_DWORD *)v10 = v8;
      *((_DWORD *)v10 + 1) = *p_SemanticIndex;
      v11 = p_SemanticIndex[1];
      p_SemanticIndex += 5;
      v12 = v17-- == 1;
      *((_DWORD *)v10 + 2) = v11;
      *((_DWORD *)v10 + 3) = 0;
      *((_DWORD *)v10 + 5) = 0;
      *((_DWORD *)v10 + 6) = 0;
    }
    while ( !v12 );
  }
  v13 = v16;
  memcpy((unsigned __int8 *)this->VertexElements, src, 28 * v16);
  this->VertexElementCount = v13;
  if ( pdevice->CreateInputLayout(
         pdevice,
         (const D3D11_INPUT_ELEMENT_DESC *)src,
         v13,
         pvdesc->pBinary,
         pvdesc->BinarySize,
         (ID3D11InputLayout **)&this->pVDecl) < 0 )
  {
    pObject = this->pVDecl.pObject;
    if ( pObject )
      pObject->Release(this->pVDecl.pObject);
    this->pVDecl.pObject = 0;
  }
  qmemcpy((void *)this->VertexElements, src, sizeof(this->VertexElements));
}
