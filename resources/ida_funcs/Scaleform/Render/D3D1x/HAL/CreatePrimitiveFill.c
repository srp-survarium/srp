Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::D3D1x::HAL::CreatePrimitiveFill(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::PrimitiveFillData *data)
{
  char *v2; // eax
  char *v3; // ebx

  v2 = (char *)this->pHeap->Alloc(this->pHeap, 36, 0);
  v3 = v2;
  if ( !v2 )
    return 0;
  *((_DWORD *)v2 + 1) = 1;
  *(_DWORD *)v2 = &Scaleform::Render::PrimitiveFill::`vftable';
  Scaleform::Render::PrimitiveFillData::PrimitiveFillData((Scaleform::Render::PrimitiveFillData *)(v2 + 8), data);
  *((_DWORD *)v3 + 8) = 0;
  return (Scaleform::Render::PrimitiveFill *)v3;
}
