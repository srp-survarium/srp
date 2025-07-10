Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *__thiscall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::allocInsertCopy(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this,
        unsigned int index,
        Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *source,
        unsigned int size,
        unsigned int allocSize)
{
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *result; // eax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v6; // esi

  result = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                      Scaleform::Memory::pGlobalHeap,
                                                                      this,
                                                                      4 * allocSize,
                                                                      0);
  v6 = result;
  if ( result )
  {
    if ( index )
      memcpy((unsigned __int8 *)result, (unsigned __int8 *)source, 4 * index);
    if ( index < size )
      memcpy((unsigned __int8 *)&v6[index + 1], (unsigned __int8 *)&source[index], 4 * (size - index));
    return v6;
  }
  return result;
}
