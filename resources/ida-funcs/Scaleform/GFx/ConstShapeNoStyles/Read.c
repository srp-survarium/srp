bool __thiscall Scaleform::GFx::ConstShapeNoStyles::Read(
        Scaleform::GFx::ConstShapeNoStyles *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::Render::FillStyleType *tagType,
        unsigned int lenInBytes,
        bool withStyle)
{
  bool v5; // al
  Scaleform::Render::StrokeStyleType *Data; // edi
  bool v7; // bl
  Scaleform::GFx::ShapeSwfReader reader; // [esp+Ch] [ebp-20h] BYREF

  reader.Shape = this;
  reader.pAllocator = p->pLoadData.pObject->pPathAllocator;
  memset(&reader.FillStyles, 0, 24);
  v5 = Scaleform::GFx::ShapeSwfReader::Read(&reader, p, tagType, lenInBytes, withStyle);
  Data = reader.StrokeStyles.Data.Data;
  v7 = v5;
  Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
    reader.StrokeStyles.Data.Data,
    reader.StrokeStyles.Data.Size);
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(&reader.FillStyles.Data);
  return v7;
}
