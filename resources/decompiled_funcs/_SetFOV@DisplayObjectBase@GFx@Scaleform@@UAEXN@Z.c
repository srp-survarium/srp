void __thiscall Scaleform::GFx::DisplayObjectBase::SetFOV(Scaleform::GFx::DisplayObjectBase *this, double fovdeg)
{
  double v2; // st7
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v4; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v5; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // ecx
  long double v7; // [esp+0h] [ebp-8h] BYREF

  v2 = fovdeg;
  v7 = fovdeg;
  if ( (HIDWORD(v7) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(v7) | LODWORD(v7)) )
  {
    v7 = fovdeg;
    if ( fovdeg == -INFINITY || (v7 = fovdeg, fovdeg == INFINITY) )
    {
      v2 = 0.0;
      fovdeg = 0.0;
    }
    if ( !this->pPerspectiveData )
    {
      LODWORD(v7) = 322;
      v4 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       80,
                                                                       &v7);
      if ( v4 )
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v4);
      else
        v5 = 0;
      v2 = fovdeg;
      this->pPerspectiveData = v5;
    }
    pPerspectiveData = this->pPerspectiveData;
    if ( v2 != pPerspectiveData->FieldOfView )
    {
      pPerspectiveData->FieldOfView = v2;
      Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
    }
  }
}
