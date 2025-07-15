void __thiscall Scaleform::GFx::ConstShapeWithStyles::Clone(Scaleform::GFx::ConstShapeWithStyles *this)
{
  Scaleform::GFx::ConstShapeWithStyles *v2; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  v3 = 2;
  v2 = (Scaleform::GFx::ConstShapeWithStyles *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 64,
                                                 &v3);
  if ( v2 )
    Scaleform::GFx::ConstShapeWithStyles::ConstShapeWithStyles(v2, this);
}
