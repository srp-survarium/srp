void __thiscall Scaleform::GFx::DisplayObjectBase::SetGeomData(
        Scaleform::GFx::DisplayObjectBase *this,
        const Scaleform::GFx::DisplayObjectBase::GeomDataType *gd)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // ecx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v5; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  pGeomData = this->pGeomData;
  if ( pGeomData )
  {
    Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(pGeomData, gd);
  }
  else
  {
    v6 = 322;
    v4 = (Scaleform::GFx::DisplayObjectBase::GeomDataType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              this,
                                                              96,
                                                              &v6);
    if ( v4 )
    {
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(v4, gd);
      this->pGeomData = v5;
    }
    else
    {
      this->pGeomData = 0;
    }
  }
}
