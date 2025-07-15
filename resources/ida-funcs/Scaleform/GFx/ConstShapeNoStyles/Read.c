bool __thiscall Scaleform::GFx::ConstShapeNoStyles::Read(
        Scaleform::GFx::ConstShapeNoStyles *this,
        __int64 p,
        unsigned int lenInBytes,
        bool withStyle)
{
  bool v4; // al
  Scaleform::Render::StrokeStyleType *Data; // edi
  bool v6; // bl
  Scaleform::GFx::ShapeSwfReader v8; // [esp+Ch] [ebp-20h] BYREF

  v8.Shape = this;
  v8.pAllocator = *(Scaleform::GFx::PathAllocator **)(*(_DWORD *)(p + 32) + 24);
  memset(&v8.FillStyles, 0, 24);
  v4 = Scaleform::GFx::ShapeSwfReader::Read(&v8, p, lenInBytes, withStyle);
  Data = v8.StrokeStyles.Data.Data;
  v6 = v4;
  Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
    v8.StrokeStyles.Data.Data,
    v8.StrokeStyles.Data.Size);
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(&v8.FillStyles.Data);
  return v6;
}
