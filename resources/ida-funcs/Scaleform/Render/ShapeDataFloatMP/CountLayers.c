void __thiscall Scaleform::Render::ShapeDataFloatMP::CountLayers(Scaleform::Render::ShapeDataFloatMP *this)
{
  Scaleform::Render::ShapeDataFloat *pObject; // esi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus Status; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v4; // [esp+8h] [ebp-4h] BYREF

  pObject = this->pData.pObject;
  Status = pObject->Status;
  if ( Status != Status_EndShape && Status )
  {
    if ( Status != Status_EndPath )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this->pData.pObject);
    v4.Data = pObject->Data;
    Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteChar(
      &v4,
      7);
    pObject->Status = Status_EndShape;
  }
  Scaleform::Render::ShapeMeshProvider::AttachShape(this, (int)this->pData.pObject, 0);
}
