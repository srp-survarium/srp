char __thiscall Scaleform::Render::D3D1x::HAL::shouldRenderFilters(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::FilterPrimitive *prim)
{
  Scaleform::Render::FilterSet *pObject; // ecx
  unsigned int Size; // edx
  int v5; // eax
  Scaleform::Ptr<Scaleform::Render::Filter> *i; // ecx

  if ( this->SManager.ShaderModel == ShaderVersion_D3D1xFL1x )
    return 1;
  pObject = prim->pFilters.pObject;
  Size = pObject->Filters.Data.Size;
  v5 = 0;
  if ( !Size )
    return 0;
  for ( i = pObject->Filters.Data.Data; i->pObject->Type != Filter_ColorMatrix; ++i )
  {
    if ( ++v5 >= Size )
      return 0;
  }
  return 1;
}
