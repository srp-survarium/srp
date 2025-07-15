void __userpurge Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(
        const Scaleform::Render::VertexFormat *vf@<eax>,
        Scaleform::Render::D3D1x::SysVertexFormat *this,
        ID3D11Device *pdevice,
        const Scaleform::Render::D3D1x::VertexShaderDesc *pvdesc)
{
  $B996288B4BA8DC1872D28A6FA0F1BFD9 *v4; // ecx
  unsigned int i; // eax
  int NumAttribs; // edx
  unsigned int *p_SemanticIndex; // ecx
  int v8; // eax
  D3D11_INPUT_ELEMENT_DESC *v9; // eax
  unsigned int v10; // edi
  unsigned int Count; // esi
  ID3D11InputLayout *pObject; // eax
  Scaleform::Render::D3D1x::D3D1xVertexDeclBuilder builder; // [esp+1Ch] [ebp-E4h] BYREF

  this->__vftable = (Scaleform::Render::D3D1x::SysVertexFormat_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::D3D1x::SysVertexFormat_vtbl *)&Scaleform::Render::D3D1x::SysVertexFormat::`vftable';
  this->pVDecl.pObject = 0;
  v4 = &vf->pElements->4;
  for ( i = v4->Attribute; i; v4 += 2 )
  {
    if ( (i & 0xF00) == 0x100 )
      break;
    i = v4[2].Attribute;
  }
  builder.Count = 0;
  NumAttribs = pvdesc->NumAttribs;
  if ( NumAttribs > 0 )
  {
    p_SemanticIndex = &pvdesc->Attributes[0].SemanticIndex;
    do
    {
      v8 = builder.Count++;
      v9 = &builder.Elements[v8];
      v9->SemanticName = (const char *)*(p_SemanticIndex - 1);
      v9->SemanticIndex = *p_SemanticIndex;
      v10 = p_SemanticIndex[1];
      p_SemanticIndex += 5;
      --NumAttribs;
      v9->Format = v10;
      v9->InputSlot = 0;
      v9->AlignedByteOffset = -1;
      v9->InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
      v9->InstanceDataStepRate = 0;
    }
    while ( NumAttribs );
  }
  Count = builder.Count;
  memcpy((unsigned __int8 *)this->VertexElements, (unsigned __int8 *)&builder, 28 * builder.Count);
  this->VertexElementCount = Count;
  if ( pdevice->CreateInputLayout(
         pdevice,
         (const D3D11_INPUT_ELEMENT_DESC *)&builder,
         Count,
         pvdesc->pBinary,
         pvdesc->BinarySize,
         (ID3D11InputLayout **)&this->pVDecl) < 0 )
  {
    pObject = this->pVDecl.pObject;
    if ( pObject )
      pObject->Release(this->pVDecl.pObject);
    this->pVDecl.pObject = 0;
  }
  qmemcpy((void *)this->VertexElements, &builder, sizeof(this->VertexElements));
}
