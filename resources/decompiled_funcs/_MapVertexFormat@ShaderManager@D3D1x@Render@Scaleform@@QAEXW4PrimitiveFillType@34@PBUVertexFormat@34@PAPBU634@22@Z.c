void __thiscall Scaleform::Render::D3D1x::ShaderManager::MapVertexFormat(
        const Scaleform::Render::VertexFormat *sourceFormat,
        Scaleform::Render::D3D1x::ShaderManager *this,
        Scaleform::Render::PrimitiveFillType fill,
        const Scaleform::Render::VertexFormat **single,
        const Scaleform::Render::VertexFormat **batch,
        const Scaleform::Render::VertexFormat **instanced)
{
  Scaleform::Render::VertexElement *pElements; // esi
  unsigned int *p_Attribute; // eax
  int v8; // edi
  int v9; // ecx
  unsigned int v10; // eax
  $B996288B4BA8DC1872D28A6FA0F1BFD9 *v11; // edx
  bool v12; // zf
  unsigned int offset; // [esp+Ch] [ebp-54h]
  Scaleform::Render::VertexElement *v14; // [esp+10h] [ebp-50h]
  Scaleform::Render::VertexFormat floatPositionFormat; // [esp+14h] [ebp-4Ch] BYREF
  Scaleform::Render::VertexElement floatPositionElements[8]; // [esp+20h] [ebp-40h] BYREF

  pElements = sourceFormat->pElements;
  floatPositionFormat.pElements = floatPositionElements;
  p_Attribute = &pElements->Attribute;
  floatPositionFormat.pSysFormat.pObject = 0;
  v8 = 0;
  offset = 0;
  v14 = pElements;
  if ( pElements->Attribute )
  {
    v9 = 0;
    do
    {
      v10 = *p_Attribute;
      v11 = &floatPositionElements[v9].4;
      floatPositionElements[v9].Attribute = v10;
      if ( (v10 & 0xF00) == 0x100 )
      {
        v11->Attribute = v10 & 0xFFFFFF0F | 0x60;
        floatPositionElements[v9].Offset = offset + pElements->Offset;
        if ( (v11->Attribute & 0xF0) == 0x30 )
          offset += 4;
      }
      else
      {
        floatPositionElements[v9].Offset = offset + pElements->Offset;
      }
      v9 = ++v8;
      pElements = &v14[v8];
      p_Attribute = &pElements->Attribute;
    }
    while ( pElements->Attribute );
  }
  v12 = this->ShaderModel == ShaderVersion_D3D1xFL1x;
  floatPositionElements[v8].Attribute = 0;
  floatPositionElements[v8].Offset = 0;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::MapVertexFormat(
    fill,
    this,
    &floatPositionFormat,
    single,
    batch,
    instanced,
    (!v12 ? 0 : 8) | 3);
  if ( floatPositionFormat.pSysFormat.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)floatPositionFormat.pSysFormat.pObject);
}
