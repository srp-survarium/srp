Scaleform::Render::StateData::ArrayData *__thiscall Scaleform::Render::StateBag::allocData(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::State *source,
        unsigned int count,
        unsigned int extra)
{
  Scaleform::Render::StateData::ArrayData *result; // eax
  Scaleform::Render::StateData::ArrayData *v5; // esi

  result = (Scaleform::Render::StateData::ArrayData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        8 * (count + extra) + 4,
                                                        0);
  v5 = result;
  if ( result )
  {
    result->RefCount = 1;
    Scaleform::Render::StateBag::copyArrayAddRef((Scaleform::Render::State *)&result[1], source, count);
    return v5;
  }
  return result;
}
