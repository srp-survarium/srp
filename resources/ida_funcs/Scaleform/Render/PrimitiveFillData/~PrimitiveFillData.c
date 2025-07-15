void __thiscall Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(Scaleform::Render::PrimitiveFillData *this)
{
  const Scaleform::Render::VertexFormat **p_pFormat; // esi
  int i; // edi
  Scaleform::RefCountVImpl *v3; // ecx

  p_pFormat = &this->pFormat;
  for ( i = 1; i >= 0; --i )
  {
    v3 = (Scaleform::RefCountVImpl *)*--p_pFormat;
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
  }
}
