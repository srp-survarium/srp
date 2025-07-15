Scaleform::RefCountVImpl *__thiscall Scaleform::Render::Text::DocView::FindFont(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::DocView::FindFontInfo *pfontInfo,
        Scaleform::String quietMode)
{
  Scaleform::Render::Text::DocView::FindFontInfo *v3; // ebx
  Scaleform::RefCountVImpl **p_pCurrentFont; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > *pFontCache; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > v7; // ebp
  int v8; // eax
  unsigned int *v9; // ebp
  Scaleform::GFx::Resource **v10; // ebp
  Scaleform::RefCountVImpl *result; // eax
  Scaleform::Render::Text::TextFormat *pCurrentFormat; // ecx
  unsigned __int16 PresentMask; // ax
  Scaleform::GFx::Resource *FontHandle; // eax
  int v15; // edi
  Scaleform::Render::Text::FontManagerBase *pObject; // ebp
  bool v17; // bl
  Scaleform::StringDH *FontList; // eax
  Scaleform::Render::Text::FontHandle *v19; // ebx
  Scaleform::Render::Text::TextFormat *v20; // esi
  unsigned __int16 v21; // bx
  unsigned __int8 FormatFlags; // al
  Scaleform::StringDH *v23; // eax
  Scaleform::Render::Text::FontHandle *v24; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v25; // ecx
  Scaleform::RefCountVImpl *v26; // ebx
  const Scaleform::String *v27; // eax
  unsigned int v28; // esi
  Scaleform::StringDH *v29; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,78>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > *p_mHash; // ecx
  Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> *pTable; // [esp-Ch] [ebp-48h]
  bool v32; // [esp+Ch] [ebp-30h]
  char v33; // [esp+Ch] [ebp-30h]
  Scaleform::String v34; // [esp+10h] [ebp-2Ch] BYREF
  BOOL v35; // [esp+14h] [ebp-28h]
  Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeRef v36; // [esp+18h] [ebp-24h] BYREF
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo v37; // [esp+20h] [ebp-1Ch] BYREF

  v3 = pfontInfo;
  p_pCurrentFont = (Scaleform::RefCountVImpl **)&pfontInfo->pCurrentFont;
  if ( pfontInfo->pCurrentFont.pObject
    && pfontInfo->pPrevFormat
    && Scaleform::Render::Text::TextFormat::IsFontSame(
         (Scaleform::Render::Text::TextFormat *)pfontInfo->pCurrentFormat,
         pfontInfo->pPrevFormat) )
  {
LABEL_43:
    result = *p_pCurrentFont;
    v3->pPrevFormat = v3->pCurrentFormat;
    return result;
  }
  pFontCache = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > *)pfontInfo->pFontCache;
  if ( !pfontInfo->pFontCache
    || (v7.pTable = pFontCache->pTable) == 0
    || (v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS2::Object *>(
               pFontCache,
               (Scaleform::GFx::AS3::Instances::fl::Object *const *)&pfontInfo->pCurrentFormat,
               (int)pfontInfo->pCurrentFormat & v7.pTable->SizeMask),
        v8 < 0)
    || (v9 = &v7.pTable[1].SizeMask + 3 * v8) == 0
    || (v10 = (Scaleform::GFx::Resource **)(v9 + 1)) == 0 )
  {
    pCurrentFormat = (Scaleform::Render::Text::TextFormat *)pfontInfo->pCurrentFormat;
    v36.pFirst = &pfontInfo->pCurrentFormat;
    PresentMask = pCurrentFormat->PresentMask;
    if ( (PresentMask & 0x800) != 0 )
    {
      FontHandle = (Scaleform::GFx::Resource *)Scaleform::Render::Text::TextFormat::GetFontHandle(pCurrentFormat);
      v15 = (int)FontHandle;
      if ( FontHandle )
        Scaleform::RefCountImpl::AddRef(FontHandle);
    }
    else
    {
      pObject = this->pFontManager.pObject;
      if ( (PresentMask & 4) != 0 )
      {
        v17 = (PresentMask & 0x1000) != 0;
        LOBYTE(v34.pData) = (this->Flags & 0x20) != 0;
        v32 = (pCurrentFormat->FormatFlags & 2) != 0;
        LOBYTE(v35) = pCurrentFormat->FormatFlags & 1;
        FontList = Scaleform::Render::Text::TextFormat::GetFontList(pCurrentFormat);
        v19 = Scaleform::Render::Text::FontManagerBase::CreateFontHandle(
                pObject,
                (const char *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                v35,
                v32,
                (bool)v34.pData,
                !v17,
                0);
        if ( *p_pCurrentFont )
          Scaleform::RefCountImpl::Release(*p_pCurrentFont);
        *p_pCurrentFont = (Scaleform::RefCountVImpl *)v19;
        v3 = pfontInfo;
      }
      if ( *p_pCurrentFont )
        goto LABEL_41;
      if ( !LOBYTE(quietMode.pData) && (this->RTFlags & 0x10) == 0 && this->pLog.pObject )
      {
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo::FontSearchPathInfo(&v37, 1);
        v20 = (Scaleform::Render::Text::TextFormat *)*v36.pFirst;
        v21 = (*v36.pFirst)->PresentMask;
        LOBYTE(quietMode.pData) = (this->Flags & 0x20) != 0;
        FormatFlags = v20->FormatFlags;
        LOBYTE(v36.pFirst) = (FormatFlags & 2) != 0;
        LOBYTE(v35) = FormatFlags & 1;
        v23 = Scaleform::Render::Text::TextFormat::GetFontList(v20);
        v24 = Scaleform::Render::Text::FontManagerBase::CreateFontHandle(
                pObject,
                (const char *)((v23->HeapTypeBits & 0xFFFFFFFC) + 8),
                v35,
                (bool)v36.pFirst,
                (bool)quietMode.pData,
                (v21 & 0x1000) == 0,
                &v37);
        v25 = this->pDocumentListener.pObject;
        v26 = (Scaleform::RefCountVImpl *)v24;
        if ( v25 )
        {
          v33 = 1;
          v27 = v25->GetCharacterPath(v25, (Scaleform::String *)&v36);
        }
        else
        {
          v33 = 2;
          Scaleform::String::String(&quietMode);
        }
        Scaleform::String::String(&v34, v27);
        if ( (v33 & 2) != 0 )
        {
          v33 &= ~2u;
          Scaleform::String::~String(&quietMode);
        }
        if ( (v33 & 1) != 0 )
          Scaleform::String::~String((Scaleform::String *)&v36);
        quietMode.pData = (Scaleform::String::DataDesc *)v37.Info.pData;
        if ( !v37.Info.pData )
          quietMode.pData = (Scaleform::String::DataDesc *)uri;
        v28 = v34.HeapTypeBits & 0xFFFFFFFC;
        v29 = Scaleform::Render::Text::TextFormat::GetFontList((Scaleform::Render::Text::TextFormat *)pfontInfo->pCurrentFormat);
        Scaleform::Log::LogError(
          this->pLog.pObject,
          "Missing font \"%s\" in \"%s\". Search log:\n%s",
          (const char *)((v29->HeapTypeBits & 0xFFFFFFFC) + 8),
          (const char *)(v28 + 8),
          (const char *)quietMode.pData);
        this->RTFlags |= 0x10u;
        Scaleform::String::~String(&v34);
        if ( v26 )
          Scaleform::RefCountImpl::Release(v26);
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v37.Info);
        v3 = pfontInfo;
      }
      v15 = (int)pObject->GetEmptyFont(pObject);
      p_pCurrentFont = (Scaleform::RefCountVImpl **)&v3->pCurrentFont;
    }
    if ( *p_pCurrentFont )
      Scaleform::RefCountImpl::Release(*p_pCurrentFont);
    *p_pCurrentFont = (Scaleform::RefCountVImpl *)v15;
LABEL_41:
    p_mHash = &v3->pFontCache->mHash;
    if ( v3->pFontCache )
    {
      v36.pFirst = &v3->pCurrentFormat;
      pTable = (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> *)p_mHash[1].pTable;
      v36.pSecond = (const Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *)p_pCurrentFont;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,78>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeRef>(
        p_mHash,
        pTable,
        &v36);
    }
    goto LABEL_43;
  }
  if ( *v10 )
    Scaleform::RefCountImpl::AddRef(*v10);
  if ( *p_pCurrentFont )
    Scaleform::RefCountImpl::Release(*p_pCurrentFont);
  *p_pCurrentFont = (Scaleform::RefCountVImpl *)*v10;
  result = *p_pCurrentFont;
  pfontInfo->pPrevFormat = pfontInfo->pCurrentFormat;
  return result;
}
