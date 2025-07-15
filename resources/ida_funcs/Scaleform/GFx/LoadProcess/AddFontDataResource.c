Scaleform::GFx::ResourceHandle *__thiscall Scaleform::GFx::LoadProcess::AddFontDataResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::ResourceId rid,
        Scaleform::GFx::Resource *pfontData)
{
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int BytesLeft; // eax
  Scaleform::GFx::FontDataUseNode *pCurrent; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ebp
  Scaleform::RefCountVImpl *v9; // ecx
  volatile LONG *p_pFonts; // eax
  Scaleform::GFx::ResourceData resData; // [esp+10h] [ebp-8h] BYREF

  static_inst.AddRef(&static_inst, pfontData);
  resData.pInterface = &static_inst;
  resData.hData = pfontData;
  Scaleform::GFx::LoadProcess::AddDataResource(this, result, rid, &resData);
  p_TagMemAllocator = &this->pLoadData.pObject->TagMemAllocator;
  BytesLeft = this->pLoadData.pObject->TagMemAllocator.BytesLeft;
  if ( BytesLeft < 0x10 )
  {
    pCurrent = (Scaleform::GFx::FontDataUseNode *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x10u);
  }
  else
  {
    pCurrent = (Scaleform::GFx::FontDataUseNode *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 16;
    p_TagMemAllocator->BytesLeft = BytesLeft - 16;
  }
  if ( pCurrent )
  {
    pCurrent->Id.Id = 0x40000;
    pCurrent->pFontData.pObject = 0;
    pCurrent->BindIndex = 0;
    pCurrent->pNext.Value = 0;
    pObject = this->pLoadData.pObject;
    pCurrent->Id = rid;
    if ( pfontData )
      Scaleform::RefCountImpl::AddRef(pfontData);
    v9 = (Scaleform::RefCountVImpl *)pCurrent->pFontData.pObject;
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    pCurrent->pFontData.pObject = (Scaleform::Render::Font *)pfontData;
    pCurrent->BindIndex = result->BindIndex;
    if ( !this->pFontData )
      this->pFontData = pCurrent;
    p_pFonts = (volatile LONG *)&pObject->BindData.pFonts;
    if ( pObject->BindData.pFonts.Value )
      p_pFonts = (volatile LONG *)&pObject->BindData.pFontsLast->pNext;
    InterlockedExchange(p_pFonts, (LONG)pCurrent);
    pObject->BindData.pFontsLast = pCurrent;
    ++this->FontDataCount;
  }
  static_inst.Release(&static_inst, pfontData);
  return result;
}
