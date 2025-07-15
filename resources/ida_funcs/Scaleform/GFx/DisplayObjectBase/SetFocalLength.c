void __thiscall Scaleform::GFx::DisplayObjectBase::SetFocalLength(
        Scaleform::GFx::DisplayObjectBase *this,
        double focalLength)
{
  double v2; // st7
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v4; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v5; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // ecx
  long double v7; // [esp+0h] [ebp-8h] BYREF

  v2 = focalLength;
  v7 = focalLength;
  if ( (HIDWORD(v7) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(v7) | LODWORD(v7)) )
  {
    v7 = focalLength;
    if ( focalLength == -INFINITY || (v7 = focalLength, focalLength == INFINITY) )
    {
      v2 = 0.0;
      focalLength = 0.0;
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
      v2 = focalLength;
      this->pPerspectiveData = v5;
    }
    pPerspectiveData = this->pPerspectiveData;
    if ( v2 != pPerspectiveData->FocalLength )
    {
      pPerspectiveData->FocalLength = v2;
      Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
    }
  }
}
