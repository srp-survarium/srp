void __thiscall Scaleform::Render::Text::StyledText::HTMLImageTagInfo::HTMLImageTagInfo(
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo *this,
        const Scaleform::Render::Text::StyledText::HTMLImageTagInfo *__that)
{
  if ( __that->pTextImageDesc.pObject )
    ++__that->pTextImageDesc.pObject->RefCount;
  this->pTextImageDesc.pObject = __that->pTextImageDesc.pObject;
  Scaleform::StringDH::CopyConstructHelper(&this->Url, &__that->Url, __that->Url.pHeap);
  Scaleform::StringDH::CopyConstructHelper(&this->Id, &__that->Id, __that->Id.pHeap);
  this->Width = __that->Width;
  this->Height = __that->Height;
  this->VSpace = __that->VSpace;
  this->HSpace = __that->HSpace;
  this->ParaId = __that->ParaId;
  this->Alignment = __that->Alignment;
}


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
