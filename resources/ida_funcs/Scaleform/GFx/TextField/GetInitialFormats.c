void __thiscall Scaleform::GFx::TextField::GetInitialFormats(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Text::TextFormat *ptextFmt,
        Scaleform::Render::Text::ParagraphFormat *pparaFmt)
{
  Scaleform::GFx::TextFieldDef *pObject; // eax
  Scaleform::GFx::Resource *v6; // ecx
  Scaleform::GFx::ResourceBindData *ResourceData; // ebx
  Scaleform::GFx::MovieDefImpl *v8; // eax
  Scaleform::GFx::MovieDefImpl *v9; // ebx
  Scaleform::GFx::TextFieldDef *v10; // eax
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::Log *v12; // ebx
  Scaleform::GFx::TextFieldDef *v13; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::GFx::Resource *v15; // ebx
  char *v16; // eax
  Scaleform::GFx::TextFieldDef *v17; // eax
  Scaleform::GFx::FontHandle *v18; // eax
  Scaleform::Log *v19; // eax
  unsigned __int16 v20; // ax
  unsigned int Raw; // edx
  Scaleform::GFx::TextFieldDef *v22; // eax
  unsigned __int16 v23; // cx
  Scaleform::GFx::TextFieldDef *v24; // ecx
  double LeftMargin; // st7
  unsigned __int16 v26; // di
  double RightMargin; // st6
  int Id_low; // [esp-8h] [ebp-3Ch]
  const char *v29; // [esp-4h] [ebp-38h]
  Scaleform::GFx::ResourceBindData fontData; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::ResourceBindData result; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [esp+20h] [ebp-14h] BYREF
  char lookForResource; // [esp+38h] [ebp+4h]

  Scaleform::Render::Text::TextFormat::InitByDefaultValues(ptextFmt);
  Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(pparaFmt);
  pObject = this->pDef.pObject;
  v6 = 0;
  fontData.pResource.pObject = 0;
  fontData.pBinding = 0;
  lookForResource = 1;
  if ( LOWORD(pObject->FontId.Id) )
  {
    ResourceData = Scaleform::GFx::ResourceBinding::GetResourceData(this->pBinding, &result, &pObject->pFont);
    if ( ResourceData->pResource.pObject )
      Scaleform::RefCountImpl::AddRef(ResourceData->pResource.pObject);
    v6 = ResourceData->pResource.pObject;
    fontData = *ResourceData;
    if ( result.pResource.pObject )
    {
      Scaleform::GFx::Resource::Release(result.pResource.pObject);
LABEL_14:
      v6 = fontData.pResource.pObject;
    }
  }
  else if ( (*(_DWORD *)(pObject->FontClass.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
  {
    v8 = this->GetResourceMovieDef(this);
    v9 = v8;
    if ( v8 )
      Scaleform::RefCountImpl::AddRef(v8);
    if ( !Scaleform::GFx::MovieImpl::FindExportedResource(
            this->pASRoot->pMovieImpl,
            v9,
            &fontData,
            &this->pDef.pObject->FontClass) )
    {
      Scaleform::Render::Text::TextFormat::SetFontName(ptextFmt, &this->pDef.pObject->FontClass);
      lookForResource = 0;
    }
    if ( v9 )
      Scaleform::GFx::Resource::Release(v9);
    if ( !lookForResource )
      goto LABEL_35;
    goto LABEL_14;
  }
  v10 = this->pDef.pObject;
  if ( LOWORD(v10->FontId.Id) || (*(_DWORD *)(v10->FontClass.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
  {
    if ( !v6 )
    {
      v11 = (Scaleform::GFx::Resource *)this->GetLog(this);
      v12 = (Scaleform::Log *)v11;
      if ( !v11 )
        goto LABEL_35;
      Scaleform::RefCountImpl::AddRef(v11);
      v13 = this->pDef.pObject;
      v29 = (const char *)((v13->DefaultText.HeapTypeBits & 0xFFFFFFFC) + 8);
      Id_low = LOWORD(this->Id.Id);
      if ( LOWORD(v13->FontId.Id) )
        Scaleform::Log::LogError(
          v12,
          "Resource for font id = %d is not found in text field id = %d, def text = '%s'",
          LOWORD(v13->FontId.Id),
          Id_low,
          v29);
      else
        Scaleform::Log::LogError(
          v12,
          "Resource for font class = '%s' is not found in text field id = %d, def text = '%s'",
          (const char *)((v13->FontClass.HeapTypeBits & 0xFFFFFFFC) + 8),
          Id_low,
          v29);
      goto LABEL_34;
    }
    if ( (v6->GetResourceTypeCode(v6) & 0xFF00) != 0x200 )
    {
      v14 = (Scaleform::GFx::Resource *)this->GetLog(this);
      v12 = (Scaleform::Log *)v14;
      if ( !v14 )
        goto LABEL_35;
      Scaleform::RefCountImpl::AddRef(v14);
      Scaleform::Log::LogError(
        v12,
        "Font id = %d is referring to non-font resource in text field id = %d, def text = '%s'",
        LOWORD(this->pDef.pObject->FontId.Id),
        LOWORD(this->Id.Id),
        (const char *)((this->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFC) + 8));
      goto LABEL_34;
    }
    if ( fontData.pResource.pObject )
    {
      v15 = (Scaleform::GFx::Resource *)fontData.pResource.pObject[1].__vftable;
      v16 = (char *)((int (__thiscall *)(Scaleform::GFx::Resource *))v15->GetKey)(v15);
      Scaleform::Render::Text::TextFormat::SetFontName(ptextFmt, v16, 0xFFFFFFFF);
      v17 = this->pDef.pObject;
      if ( SLOBYTE(v17->Flags) >= 0 || (*(_DWORD *)(v17->FontClass.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
      {
        Scaleform::Render::Text::TextFormat::SetBold(ptextFmt, ((int)v15[1].pLib & 2) != 0);
        Scaleform::Render::Text::TextFormat::SetItalic(ptextFmt, (int)v15[1].pLib & 1);
        if ( (this->pDef.pObject->Flags & 0x100) == 0 && ((int)v15[1].pLib & 0x40) == 0 )
        {
          v18 = (Scaleform::GFx::FontHandle *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x20u);
          if ( v18 )
          {
            Scaleform::GFx::FontHandle::FontHandle(v18, 0, v15, 0, 0, fontData.pBinding->pOwnerDefImpl);
            v12 = v19;
          }
          else
          {
            v12 = 0;
          }
          Scaleform::Render::Text::TextFormat::SetFontHandle(ptextFmt, (Scaleform::GFx::Resource *)v12);
          if ( v12 )
LABEL_34:
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
        }
      }
    }
  }
LABEL_35:
  result = (Scaleform::GFx::ResourceBindData)(__int64)this->pDef.pObject->TextHeight;
  v20 = (unsigned __int16)result.pResource.pObject;
  if ( result.pResource.pObject > (Scaleform::GFx::Resource *)&_sbh_sizeHeaderList )
    v20 = -1;
  ptextFmt->PresentMask |= 8u;
  ptextFmt->FontSize = v20;
  Raw = this->pDef.pObject->ColorV.Raw;
  ptextFmt->PresentMask |= 1u;
  ptextFmt->ColorV = Raw;
  v22 = this->pDef.pObject;
  defaultParagraphFmt.RefCount = 1;
  memset(&defaultParagraphFmt.pTabStops, 0, 16);
  switch ( v22->Alignment )
  {
    case ALIGN_LEFT:
      v23 = pparaFmt->PresentMask & 0xF9FE | 1;
      goto LABEL_42;
    case ALIGN_RIGHT:
      pparaFmt->PresentMask = pparaFmt->PresentMask & 0xF9FE | 0x201;
      break;
    case ALIGN_CENTER:
      pparaFmt->PresentMask |= 0x601u;
      break;
    case ALIGN_JUSTIFY:
      v23 = pparaFmt->PresentMask & 0xF9FE | 0x401;
LABEL_42:
      pparaFmt->PresentMask = v23;
      break;
    default:
      break;
  }
  v24 = this->pDef.pObject;
  if ( (v24->Flags & 0x200) != 0 )
  {
    LeftMargin = v24->LeftMargin;
    pparaFmt->PresentMask |= 0x10u;
    v26 = pparaFmt->PresentMask | 0x20;
    pparaFmt->LeftMargin = (int)(LeftMargin * 0.05000000074505806);
    RightMargin = this->pDef.pObject->RightMargin;
    pparaFmt->PresentMask = v26;
    pparaFmt->RightMargin = (int)(RightMargin * 0.05000000074505806);
    pparaFmt->Indent = (int)(this->pDef.pObject->Indent * 0.05000000074505806);
    v26 |= 4u;
    pparaFmt->PresentMask = v26;
    pparaFmt->Leading = (int)(0.05000000074505806 * this->pDef.pObject->Leading);
    pparaFmt->PresentMask = v26 | 8;
  }
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&defaultParagraphFmt);
  if ( fontData.pResource.pObject )
    Scaleform::GFx::Resource::Release(fontData.pResource.pObject);
}
