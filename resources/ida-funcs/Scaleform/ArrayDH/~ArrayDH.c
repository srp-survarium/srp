void __thiscall Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>::~ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *this)
{
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    this->Data.Data,
    this->Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data);
}
