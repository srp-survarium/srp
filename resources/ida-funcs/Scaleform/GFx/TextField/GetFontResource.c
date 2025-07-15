Scaleform::GFx::FontResource *__thiscall Scaleform::GFx::TextField::GetFontResource(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextFieldDef *pObject; // eax
  Scaleform::GFx::Resource *v4; // eax
  Scaleform::Log *v5; // edi
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::GFx::Resource *v7; // esi
  Scaleform::GFx::ResourceBindData result; // [esp+4h] [ebp-8h] BYREF

  pObject = this->pDef.pObject;
  if ( !LOWORD(pObject->FontId.Id) )
    return 0;
  Scaleform::GFx::ResourceBinding::GetResourceData(this->pBinding, &result, &pObject->pFont);
  if ( !result.pResource.pObject )
  {
    v4 = (Scaleform::GFx::Resource *)this->GetLog(this);
    v5 = (Scaleform::Log *)v4;
    if ( v4 )
    {
      Scaleform::RefCountImpl::AddRef(v4);
      Scaleform::Log::LogError(
        v5,
        "Resource for font id = %d is not found in text field id = %d, def text = '%s'",
        LOWORD(this->pDef.pObject->FontId.Id),
        LOWORD(this->Id.Id),
        (this->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFC) + 8);
LABEL_9:
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
      goto LABEL_10;
    }
    goto LABEL_10;
  }
  if ( (result.pResource.pObject->GetResourceTypeCode(result.pResource.pObject) & 0xFF00) != 0x200 )
  {
    v6 = (Scaleform::GFx::Resource *)this->GetLog(this);
    v5 = (Scaleform::Log *)v6;
    if ( v6 )
    {
      Scaleform::RefCountImpl::AddRef(v6);
      Scaleform::Log::LogError(
        v5,
        "Font id = %d is referring to non-font resource in text field id = %d, def text = '%s'",
        LOWORD(this->pDef.pObject->FontId.Id),
        LOWORD(this->Id.Id),
        (this->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFC) + 8);
      goto LABEL_9;
    }
LABEL_10:
    if ( result.pResource.pObject )
      Scaleform::GFx::Resource::Release(result.pResource.pObject);
    return 0;
  }
  v7 = result.pResource.pObject;
  if ( result.pResource.pObject )
    Scaleform::GFx::Resource::Release(result.pResource.pObject);
  return (Scaleform::GFx::FontResource *)v7;
}
