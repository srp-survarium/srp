Scaleform::GFx::FrameBindData *__thiscall Scaleform::GFx::LoadProcess::CreateFrameBindData(
        Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  Scaleform::GFx::FrameBindData *result; // eax

  pObject = this->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 0x24 )
  {
    result = (Scaleform::GFx::FrameBindData *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x24u);
  }
  else
  {
    result = (Scaleform::GFx::FrameBindData *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 36;
    p_TagMemAllocator->BytesLeft = BytesLeft - 36;
  }
  if ( !result )
    return 0;
  result->Frame = 0;
  result->BytesLoaded = 0;
  result->FontCount = 0;
  result->ImportCount = 0;
  result->ResourceCount = 0;
  result->pImportData = 0;
  result->pFontData = 0;
  result->pResourceData = 0;
  result->pNextFrame.Value = 0;
  result->ImportCount = this->ImportDataCount;
  result->pImportData = this->pImportData;
  result->FontCount = this->FontDataCount;
  result->pFontData = this->pFontData;
  result->ResourceCount = this->ResourceDataCount;
  result->pResourceData = this->pResourceData;
  this->ImportDataCount = 0;
  this->ResourceDataCount = 0;
  this->FontDataCount = 0;
  this->pImportData = 0;
  this->pResourceData = 0;
  this->pFontData = 0;
  return result;
}
