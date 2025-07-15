void __thiscall Scaleform::GFx::DisplayObjectBase::SetProjectionCenter(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> projCenter)
{
  double v3; // st5
  double v4; // st7
  double y; // st6
  double v6; // st6
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v8; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // ecx
  double x; // [esp+Ch] [ebp-8h] BYREF

  x = projCenter.x;
  if ( (HIDWORD(x) & 0x7FF00000) == 0x7FF00000 && HIDWORD(x) & 0xFFFFF | LODWORD(x) )
    return;
  x = projCenter.y;
  if ( (HIDWORD(x) & 0x7FF00000) == 0x7FF00000 )
  {
    if ( HIDWORD(x) & 0xFFFFF | LODWORD(x) )
      return;
  }
  if ( COERCE__INT64(projCenter.x) == 0xFFF0000000000000uLL )
  {
    v6 = 0.0;
  }
  else
  {
    v3 = projCenter.x;
    v6 = 0.0;
    if ( COERCE__INT64(projCenter.x) != 0x7FF0000000000000LL )
      goto LABEL_9;
  }
  projCenter.x = v6;
  v3 = projCenter.x;
LABEL_9:
  v4 = v3;
  x = projCenter.y;
  if ( COERCE__INT64(projCenter.y) == 0xFFF0000000000000uLL
    || (x = projCenter.y, COERCE__INT64(projCenter.y) == 0x7FF0000000000000LL) )
  {
    projCenter.y = v6;
    y = projCenter.y;
  }
  else
  {
    y = projCenter.y;
  }
  if ( !this->pPerspectiveData )
  {
    LODWORD(x) = 322;
    v7 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                     Scaleform::Memory::pGlobalHeap,
                                                                     this,
                                                                     80,
                                                                     &x);
    if ( v7 )
      Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v7);
    else
      v8 = 0;
    v4 = projCenter.x;
    this->pPerspectiveData = v8;
    y = projCenter.y;
  }
  pPerspectiveData = this->pPerspectiveData;
  if ( v4 != pPerspectiveData->ProjectionCenter.x || y != pPerspectiveData->ProjectionCenter.y )
  {
    *(float *)&x = y;
    pPerspectiveData->ProjectionCenter.x = v4;
    pPerspectiveData->ProjectionCenter.y = *(float *)&x;
    Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
  }
}
