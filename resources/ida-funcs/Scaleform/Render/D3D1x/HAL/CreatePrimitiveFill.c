Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::D3D1x::HAL::CreatePrimitiveFill(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::PrimitiveFillData *data)
{
  char *v2; // edi

  v2 = (char *)this->pHeap->Alloc(this->pHeap, 36, 0);
  if ( !v2 )
    return 0;
  *((_DWORD *)v2 + 1) = 1;
  *(_DWORD *)v2 = &Scaleform::Render::PrimitiveFill::`vftable';
  Scaleform::Render::PrimitiveFillData::PrimitiveFillData(data, (Scaleform::Render::PrimitiveFillData *)(v2 + 8));
  *((_DWORD *)v2 + 8) = 0;
  return (Scaleform::Render::PrimitiveFill *)v2;
}
