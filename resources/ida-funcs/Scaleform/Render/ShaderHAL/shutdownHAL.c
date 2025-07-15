char __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::shutdownHAL(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  char result; // al
  Scaleform::Render::VertexFormat **MappedXY16iAlphaSolid; // esi
  int v4; // ebx
  int v5; // edi
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::Render::VertexFormat *v7; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  result = Scaleform::Render::HAL::shutdownHAL(this);
  if ( result )
  {
    MappedXY16iAlphaSolid = this->MappedXY16iAlphaSolid;
    v4 = 3;
    do
    {
      v5 = (int)*(MappedXY16iAlphaSolid - 3);
      if ( v5 )
      {
        v6 = *(Scaleform::RefCountVImpl **)(v5 + 8);
        if ( v6 )
          Scaleform::RefCountImpl::Release(v6);
        *(_DWORD *)(v5 + 8) = 0;
      }
      v7 = *MappedXY16iAlphaSolid;
      *(MappedXY16iAlphaSolid - 3) = 0;
      if ( v7 )
      {
        pObject = (Scaleform::RefCountVImpl *)v7->pSysFormat.pObject;
        if ( pObject )
          Scaleform::RefCountImpl::Release(pObject);
        v7->pSysFormat.pObject = 0;
      }
      *MappedXY16iAlphaSolid++ = 0;
      --v4;
    }
    while ( v4 );
    return 1;
  }
  return result;
}
