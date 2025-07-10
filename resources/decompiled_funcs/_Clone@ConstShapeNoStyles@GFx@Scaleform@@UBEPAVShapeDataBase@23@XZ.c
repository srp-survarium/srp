Scaleform::GFx::ShapeDataBase *__thiscall Scaleform::GFx::ConstShapeNoStyles::Clone(
        Scaleform::GFx::ConstShapeNoStyles *this)
{
  Scaleform::GFx::ShapeDataBase *result; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  v3 = 2;
  result = (Scaleform::GFx::ShapeDataBase *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              16,
                                              &v3);
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::ShapeDataBase_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  result->__vftable = (Scaleform::GFx::ShapeDataBase_vtbl *)&Scaleform::GFx::ShapeDataBase::`vftable';
  result->RefCount = 1;
  result->Paths = this->Paths;
  result->Flags = this->Flags;
  result->__vftable = (Scaleform::GFx::ShapeDataBase_vtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable';
  return result;
}
