void __thiscall Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl::Init(
        Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::StyleSheetObject *pTarget)
{
  unsigned __int8 *pFileData; // ecx
  signed int FileSize; // eax
  unsigned __int8 *v6; // edi
  signed int v7; // ecx
  unsigned __int8 *v8; // ecx
  signed int v9; // edx
  Scaleform::GFx::AS2::StyleSheetObject *v10; // edi
  Scaleform::GFx::Text::StyleManager *p_CSS; // ecx
  bool v12; // al
  const wchar_t *v13; // [esp-10h] [ebp-14h]

  pFileData = this->pFileData;
  if ( pFileData )
  {
    FileSize = this->FileSize;
    v6 = pFileData;
    if ( *(_WORD *)pFileData == 0xFEFF )
    {
      v6 = pFileData + 2;
      FileSize = FileSize / 2 - 1;
      v7 = 0;
      for ( this->Type = STREAM_UTF16; v7 < FileSize; ++v7 )
        ;
    }
    else if ( *(_WORD *)pFileData == 0xFFFE )
    {
      v8 = pFileData + 2;
      FileSize = FileSize / 2 - 1;
      v9 = 0;
      v6 = v8;
      for ( this->Type = STREAM_UTF16; v9 < FileSize; ++v9 )
        *(_WORD *)&v8[2 * v9] = __ROL2__(*(_WORD *)&v8[2 * v9], 8);
    }
    else if ( FileSize > 2 && *pFileData == 0xEF && pFileData[1] == 0xBB && pFileData[2] == 0xBF )
    {
      v6 = pFileData + 3;
      FileSize -= 3;
    }
    v13 = (const wchar_t *)v6;
    v10 = pTarget;
    p_CSS = &pTarget->CSS;
    if ( this->Type == STREAM_UTF16 )
      v12 = Scaleform::GFx::Text::StyleManager::ParseCSS(p_CSS, v13, FileSize);
    else
      v12 = Scaleform::GFx::Text::StyleManager::ParseCSS(p_CSS, (const char *)v13, FileSize);
    LOBYTE(pTarget) = v12;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pFileData);
    this->pFileData = 0;
    Scaleform::GFx::AS2::StyleSheetObject::NotifyOnLoad(v10, penv, (const Scaleform::GFx::ASString)pTarget);
  }
  else
  {
    Scaleform::GFx::AS2::StyleSheetObject::NotifyOnLoad(pTarget, penv, 0);
  }
}
