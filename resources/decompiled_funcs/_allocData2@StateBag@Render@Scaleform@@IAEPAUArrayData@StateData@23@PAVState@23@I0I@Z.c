Scaleform::Render::StateData::ArrayData *__thiscall Scaleform::Render::StateBag::allocData2(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::State *source1,
        unsigned int count1,
        Scaleform::Render::State *source2,
        unsigned int count2)
{
  char *v5; // eax
  char *v6; // esi

  v5 = (char *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 this,
                 8 * (count1 + count2) + 4,
                 0);
  v6 = v5;
  if ( !v5 )
    return 0;
  *(_DWORD *)v5 = 1;
  Scaleform::Render::StateBag::copyArrayAddRef((Scaleform::Render::State *)(v5 + 4), source1, count1);
  Scaleform::Render::StateBag::copyArrayAddRef((Scaleform::Render::State *)&v6[8 * count1 + 4], source2, count2);
  return (Scaleform::Render::StateData::ArrayData *)v6;
}
