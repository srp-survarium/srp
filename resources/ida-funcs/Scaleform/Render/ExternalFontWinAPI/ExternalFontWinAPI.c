void __thiscall Scaleform::Render::ExternalFontWinAPI::ExternalFontWinAPI(
        Scaleform::Render::ExternalFontWinAPI *this,
        Scaleform::GFx::Resource *pprovider,
        Scaleform::Render::FontSysDataWinAPI *sysData,
        const char *name,
        unsigned int fontFlags,
        Scaleform::Lock *fontLock)
{
  Scaleform::ArrayLH<wchar_t,2,Scaleform::ArrayDefaultPolicy> *p_NameW; // ebx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  int Length; // eax
  unsigned int v11; // edi
  wchar_t *lfFaceName; // eax
  int v13; // edx
  int v14; // edi
  wchar_t v15; // cx
  Scaleform::Render::FontSysDataWinAPI *pSysData; // edx
  HFONT__ *FontW; // eax
  HDC__ *WinHDC; // edi
  HGDIOBJ v19; // ebp
  bool found; // [esp+13h] [ebp-99h] BYREF
  tagTEXTMETRICW tm; // [esp+14h] [ebp-98h] BYREF
  tagLOGFONTW lf; // [esp+50h] [ebp-5Ch] BYREF

  this->Ascent = 0.0;
  this->__vftable = (Scaleform::Render::ExternalFontWinAPI_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Descent = 0.0;
  this->Leading = 0.0;
  this->__vftable = (Scaleform::Render::ExternalFontWinAPI_vtbl *)&Scaleform::Render::Font::`vftable';
  this->RefCount = 1;
  this->Flags = fontFlags;
  this->LowerCaseTop = 0;
  this->UpperCaseTop = 0;
  this->hRef.pManager.Value = 0;
  this->hRef.pFontHandle = 0;
  this->__vftable = (Scaleform::Render::ExternalFontWinAPI_vtbl *)&Scaleform::Render::ExternalFontWinAPI::`vftable';
  if ( pprovider )
    Scaleform::RefCountImpl::AddRef(pprovider);
  this->pFontProvider.pObject = (Scaleform::Render::FontProviderWinAPI *)pprovider;
  this->pSysData = sysData;
  this->Name.Data.Data = 0;
  this->Name.Data.Size = 0;
  this->Name.Data.Policy.Capacity = 0;
  this->NameW.Data.Data = 0;
  this->NameW.Data.Size = 0;
  this->NameW.Data.Policy.Capacity = 0;
  p_NameW = &this->NameW;
  this->MasterFont = 0;
  this->HintedFont = 0;
  this->LastHintedFontSize = 0;
  this->Glyphs.Data.Data = 0;
  this->Glyphs.Data.Size = 0;
  this->Glyphs.Data.Policy.Capacity = 0;
  this->CodeTable.mHash.pTable = 0;
  this->KerningPairs.mHash.pTable = 0;
  this->Scale1024 = 4.2666669;
  Scaleform::String::String(&this->Hinting.Typeface);
  this->pFontLock = fontLock;
  v8 = strlen(name);
  v9 = v8 + 1;
  if ( v8 + 1 >= this->Name.Data.Size )
  {
    if ( v9 >= this->Name.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Name,
        &this->Name,
        v9 + (v9 >> 2));
  }
  else if ( v9 < this->Name.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Name,
      &this->Name,
      v8 + 1);
  }
  this->Name.Data.Size = v9;
  strcpy_s(this->Name.Data.Data, strlen(name) + 1, name);
  Length = Scaleform::UTF8Util::GetLength(name, -1);
  v11 = Length + 1;
  if ( Length + 1 >= this->NameW.Data.Size )
  {
    if ( v11 >= this->NameW.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->NameW.Data,
        &this->NameW,
        v11 + (v11 >> 2));
  }
  else if ( v11 < this->NameW.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->NameW.Data,
      &this->NameW,
      Length + 1);
  }
  this->NameW.Data.Size = v11;
  Scaleform::UTF8Util::DecodeString(p_NameW->Data.Data, name, -1);
  lfFaceName = lf.lfFaceName;
  v13 = 32;
  v14 = (char *)p_NameW->Data.Data - (char *)lf.lfFaceName;
  while ( v13 != -2147483614 )
  {
    v15 = *(wchar_t *)((char *)lfFaceName + v14);
    if ( !v15 )
      break;
    *lfFaceName++ = v15;
    if ( !--v13 )
    {
      --lfFaceName;
      break;
    }
  }
  *lfFaceName = 0;
  found = 0;
  pSysData = this->pSysData;
  lf.lfCharSet = 1;
  EnumFontFamiliesExW(pSysData->WinHDC, &lf, (FONTENUMPROCW)Scaleform::Render::EnumFontFamExProc, (LPARAM)&found, 0);
  if ( found || !strcmp(name, "_sans") || !strcmp(name, "_typewriter") || !strcmp(name, "_serif") )
  {
    FontW = CreateFontW(
              -240,
              0,
              0,
              0,
              (this->Flags & 2) != 0 ? 700 : 400,
              this->Flags & 1,
              0,
              0,
              1u,
              0,
              0,
              4u,
              0,
              p_NameW->Data.Data);
    this->MasterFont = FontW;
    if ( FontW )
    {
      WinHDC = this->pSysData->WinHDC;
      v19 = SelectObject(WinHDC, FontW);
      if ( GetTextMetricsW(this->pSysData->WinHDC, &tm) )
      {
        this->Leading = (double)tm.tmExternalLeading * this->Scale1024;
        this->Ascent = (double)tm.tmAscent * this->Scale1024;
        this->Descent = (double)tm.tmDescent * this->Scale1024;
        Scaleform::Render::ExternalFontWinAPI::loadKerningPairs(this);
      }
      SelectObject(WinHDC, v19);
    }
  }
}
