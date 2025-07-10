void __thiscall Scaleform::Render::Text::StyledText::HTMLImageTagInfo::HTMLImageTagInfo(
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo *this,
        Scaleform::MemoryHeap *pheap)
{
  this->pTextImageDesc.pObject = 0;
  Scaleform::StringDH::StringDH(&this->Url, pheap);
  Scaleform::StringDH::StringDH(&this->Id, pheap);
  this->Width = 0;
  this->Height = 0;
  this->VSpace = 0;
  this->HSpace = 0;
  this->Alignment = 0;
  this->ParaId = -1;
}
