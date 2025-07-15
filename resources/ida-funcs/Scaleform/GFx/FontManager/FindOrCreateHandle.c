Scaleform::RefCountVImpl *__thiscall Scaleform::GFx::FontManager::FindOrCreateHandle(
        Scaleform::GFx::FontManager *this,
        __m128i *pfontName,
        unsigned int matchFontFlags,
        Scaleform::GFx::FontResource **ppfoundFont,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  __m128i *v5; // ebx
  Scaleform::GFx::FontManager *v6; // edi
  Scaleform::GFx::FontManagerStates *pState; // eax
  Scaleform::GFx::FontLib *pObject; // ecx
  Scaleform::GFx::FontProvider *v9; // edx
  Scaleform::GFx::FontMap *v10; // eax
  Scaleform::GFx::FontHandle *v11; // eax
  _DWORD *v12; // ecx
  char *v13; // eax
  Scaleform::GFx::FontHandle *v14; // edi
  void *v15; // esi
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // ebp
  unsigned int v18; // eax
  signed int v19; // eax
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v20; // esi
  Scaleform::GFx::FontResource *RegisteredFont; // esi
  Scaleform::GFx::MovieImpl *pMovie; // ecx
  Scaleform::Render::Text::FontHandle *v23; // ebp
  Scaleform::GFx::Resource *v24; // edi
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v25; // ebp
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v26; // ecx
  Scaleform::RefCountVImpl *v27; // esi
  _DWORD *v28; // eax
  char *v29; // eax
  void (__thiscall *Release)(Scaleform::RefCountVImpl *); // edi
  unsigned __int8 v31; // si
  unsigned int v32; // eax
  signed int v33; // eax
  Scaleform::RefCountVImpl *v34; // ebp
  unsigned int v35; // ebx
  Scaleform::Render::Text::FontManagerBase *v36; // edi
  Scaleform::Render::Text::FontManagerBase *p_FontMapEntry; // esi
  Scaleform::Render::Text::FontManagerBase_vtbl *v38; // eax
  __m128i *v39; // edx
  int v40; // eax
  int v41; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v42; // edi
  signed int v43; // eax
  Scaleform::GFx::FontHandle *v44; // eax
  Scaleform::RefCountVImpl *v45; // eax
  signed int v46; // eax
  Scaleform::GFx::Resource *EntryCount; // ecx
  Scaleform::GFx::FontHandle *v48; // eax
  Scaleform::RefCountVImpl *v49; // eax
  Scaleform::Render::Text::FontManagerBase_vtbl *v50; // eax
  Scaleform::Render::Text::FontHandle *(__thiscall **p_GetEmptyFont)(Scaleform::Render::Text::FontManagerBase *); // eax
  const __m128i *v52; // edi
  Scaleform::Render::Text::FontManagerBase *v53; // edi
  signed int v54; // eax
  Scaleform::GFx::Resource **v55; // esi
  Scaleform::GFx::FontHandle *v56; // eax
  Scaleform::RefCountVImpl *v57; // eax
  unsigned int v58; // edx
  Scaleform::Render::Text::FontHandle *v59; // esi
  Scaleform::GFx::MovieDef *pMovieDef; // edi
  double v61; // st7
  Scaleform::Render::Text::FontManagerBase_vtbl *pDefImpl; // eax
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // eax
  const __m128i *v64; // esi
  Scaleform::GFx::FontResource *FontResource; // edi
  Scaleform::Render::Text::FontHandle *v66; // esi
  Scaleform::Render::Text::FontManagerBase_vtbl *v67; // eax
  unsigned int v68; // ebp
  int v69; // eax
  const __m128i *v70; // esi
  Scaleform::Render::Text::FontHandle *v71; // esi
  Scaleform::GFx::MovieDef *v72; // edi
  const __m128i *v73; // edx
  unsigned int v74; // ebx
  const Scaleform::GFx::FontHandle **v75; // eax
  Scaleform::RefCountVImpl *v76; // ecx
  unsigned int v77; // esi
  Scaleform::GFx::Resource *v78; // esi
  const Scaleform::GFx::FontHandle **v79; // [esp+40h] [ebp-84h]
  char v80; // [esp+57h] [ebp-6Dh]
  Scaleform::RefCountVImpl *v81; // [esp+58h] [ebp-6Ch] BYREF
  Scaleform::GFx::FontManager *v82; // [esp+5Ch] [ebp-68h]
  float v83; // [esp+60h] [ebp-64h]
  char *pname; // [esp+64h] [ebp-60h]
  unsigned int v85; // [esp+68h] [ebp-5Ch]
  Scaleform::GFx::FontLib *v86; // [esp+6Ch] [ebp-58h]
  const Scaleform::GFx::FontHandle **v87; // [esp+70h] [ebp-54h]
  int v88; // [esp+74h] [ebp-50h]
  Scaleform::GFx::FontProvider *pprovider; // [esp+78h] [ebp-4Ch]
  Scaleform::GFx::MovieDefImpl::SearchInfo *v90; // [esp+7Ch] [ebp-48h]
  Scaleform::GFx::Resource *v91; // [esp+80h] [ebp-44h] BYREF
  Scaleform::GFx::FontMap *v92; // [esp+84h] [ebp-40h]
  Scaleform::GFx::FontLib::FontResult v93; // [esp+88h] [ebp-3Ch] BYREF
  Scaleform::GFx::FontLib::FontResult v94; // [esp+90h] [ebp-34h] BYREF
  Scaleform::GFx::FontManager::FontKey v95; // [esp+98h] [ebp-2Ch] BYREF
  Scaleform::GFx::FontManager::FontKey v96; // [esp+A0h] [ebp-24h] BYREF
  Scaleform::GFx::FontManager::FontKey v97; // [esp+A8h] [ebp-1Ch] BYREF
  Scaleform::GFx::FontManager::FontKey v98; // [esp+B0h] [ebp-14h] BYREF
  Scaleform::GFx::MovieDefImpl::SearchInfo v99; // [esp+B8h] [ebp-Ch] BYREF

  v5 = pfontName;
  v6 = this;
  v95.FontStyle = matchFontFlags;
  pState = this->pState;
  pObject = pState->pFontLib.pObject;
  v9 = pState->pFontProvider.pObject;
  v10 = pState->pFontMap.pObject;
  v86 = pObject;
  v82 = v6;
  v95.pFontName = (const char *)pfontName;
  v81 = 0;
  pprovider = v9;
  v92 = v10;
  v88 = 0;
  v87 = 0;
  v99.ImportSearchUrls.pTable = 0;
  Scaleform::String::String(&v99.ImportFoundUrl);
  v11 = v6->pIMECandidateFont.pObject;
  v90 = 0;
  v80 = 0;
  if ( v11 )
  {
    v12 = (_DWORD *)(v11->FontName.HeapTypeBits & 0xFFFFFFFC);
    v13 = (char *)((*v12 & 0x7FFFFFFF) != 0 ? v12 + 2 : v11->pFont.pObject->GetName(v11->pFont.pObject));
    if ( !Scaleform::String::CompareNoCase(v13, pfontName->m128i_i8) )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->pIMECandidateFont.pObject);
      v14 = v6->pIMECandidateFont.pObject;
      v15 = (void *)(v99.ImportFoundUrl.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v99.ImportFoundUrl.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
      Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Clear(&v99.ImportSearchUrls);
      return (Scaleform::RefCountVImpl *)v14;
    }
  }
  while ( 1 )
  {
    if ( searchInfo )
    {
      ++v88;
      ++searchInfo->Indent;
      v90 = &v99;
    }
    else
    {
      p_CreatedFonts = &v6->CreatedFonts;
      if ( v6->CreatedFonts.pTable )
      {
        v18 = Scaleform::String::BernsteinHashFunctionCIS(v5->m128i_i8, strlen(v5->m128i_i8), 0x1505u);
        v19 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
                &v6->CreatedFonts,
                &v95,
                p_CreatedFonts->pTable->SizeMask & (v18 ^ matchFontFlags & 3));
        if ( v19 >= 0 )
        {
          v20 = &p_CreatedFonts->pTable[2 * v19 + 2];
          if ( v20 )
          {
            if ( (matchFontFlags & 0x10) != 0
              || ((*(_BYTE *)(v20->EntryCount + 12) | *(_BYTE *)(*(_DWORD *)(v20->EntryCount + 24) + 20)) & 0x10) == 0 )
            {
              goto LABEL_134;
            }
            if ( LOBYTE(v20->SizeMask) )
            {
              EntryCount = (Scaleform::GFx::Resource *)v20->EntryCount;
              goto LABEL_136;
            }
            v87 = (const Scaleform::GFx::FontHandle **)&p_CreatedFonts->pTable[2 * v19 + 2];
          }
        }
      }
    }
    RegisteredFont = v6->pDefImpl ? v6->pDefImpl->GetFontResource(v6->pDefImpl, v5->m128i_i8, matchFontFlags, v90) : 0;
    Scaleform::GFx::AddSearchInfo_4(searchInfo, v5->m128i_i8, matchFontFlags, v6->pState->pFontLib.pObject != 0, &v99);
    v91 = 0;
    if ( RegisteredFont )
      goto LABEL_25;
    pMovie = v6->pMovie;
    if ( !pMovie )
      goto LABEL_33;
    RegisteredFont = Scaleform::GFx::MovieImpl::FindRegisteredFont(
                       pMovie,
                       v5->m128i_i8,
                       matchFontFlags,
                       (Scaleform::GFx::MovieDef **)&v91);
    if ( RegisteredFont )
    {
LABEL_25:
      pMovie = (Scaleform::GFx::MovieImpl *)RegisteredFont->pFont.pObject;
      if ( (pMovie->LastLoadQueueEntryCnt & 0x40) == 0 )
      {
        if ( (matchFontFlags & 3) != 0
          && !((unsigned __int8 (__thiscall *)(Scaleform::GFx::MovieImpl *))pMovie->SetSafeRect)(pMovie) )
        {
          if ( ppfoundFont )
            *ppfoundFont = RegisteredFont;
          v75 = v87;
          if ( v87 )
          {
            (*v87)->pFontManager = 0;
            Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
              &v82->CreatedFonts,
              v75);
            Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&v99);
            return 0;
          }
          goto LABEL_144;
        }
        v23 = (Scaleform::Render::Text::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       32,
                                                       0);
        if ( v23 )
        {
          v24 = v91;
          Scaleform::Render::Text::FontHandle::FontHandle(
            v23,
            searchInfo == 0 ? v82 : 0,
            (Scaleform::GFx::Resource *)RegisteredFont->pFont.pObject,
            v5,
            0);
          v23->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
          if ( v24 )
            Scaleform::RefCountImpl::AddRef(v24);
          v23[1].__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)v24;
          v81 = (Scaleform::RefCountVImpl *)v23;
        }
        else
        {
          v81 = 0;
        }
      }
    }
    else
    {
      Scaleform::GFx::AddSearchInfo_1(
        searchInfo,
        (const __m128i *)"Registered fonts: \"",
        v5,
        (const __m128i *)"\"",
        matchFontFlags,
        (const __m128i *)" not found.");
    }
LABEL_33:
    v20 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *)v87;
    if ( v87 )
    {
      if ( !v81 )
      {
        EntryCount = (Scaleform::GFx::Resource *)*v87;
        *((_BYTE *)v87 + 4) = 1;
        goto LABEL_136;
      }
      v25 = &v82->CreatedFonts;
      v79 = v87;
      v26 = &v82->CreatedFonts;
      (*v87)->pFontManager = 0;
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
        v26,
        v79);
      if ( v25->pTable
        && ((v27 = v81, v28 = (_DWORD *)((int)v81[2].__vftable & 0xFFFFFFFC), (*v28 & 0x7FFFFFFF) != 0)
          ? (v29 = (char *)(v28 + 2))
          : (v29 = (char *)(*((int (__thiscall **)(Scaleform::RefCountVImpl_vtbl *))v81[3].~Scaleform::RefCountVImpl + 1))(v81[3].__vftable)),
            Release = v27[3].__vftable[1].Release,
            v31 = ((unsigned __int8)Release | v27[1].RefCount) & 3,
            v32 = Scaleform::String::BernsteinHashFunctionCIS(v29, strlen(v29), 0x1505u),
            v33 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontHandle *>(
                    v25,
                    (Scaleform::GFx::FontHandle **)&v81,
                    v25->pTable->SizeMask & (v32 ^ ((unsigned __int8)Release | v31) & 3)),
            v33 >= 0) )
      {
        v20 = &v25->pTable[2 * v33 + 2];
        v87 = (const Scaleform::GFx::FontHandle **)v20;
        if ( v20 )
        {
          v76 = v81;
          v81[1].__vftable = 0;
          Scaleform::RefCountImpl::Release(v76);
LABEL_134:
          EntryCount = (Scaleform::GFx::Resource *)v20->EntryCount;
LABEL_136:
          Scaleform::RefCountImpl::AddRef(EntryCount);
          v77 = v20->EntryCount;
          Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&v99);
          return (Scaleform::RefCountVImpl *)v77;
        }
      }
      else
      {
        v87 = 0;
      }
    }
    v34 = v81;
    v83 = 1.0;
    v35 = matchFontFlags;
    pname = (char *)pfontName;
    v85 = 0;
    if ( !v81 )
    {
      pMovie = (Scaleform::GFx::MovieImpl *)v92;
      if ( v92 )
      {
        v36 = v82;
        p_FontMapEntry = (Scaleform::Render::Text::FontManagerBase *)&v82->FontMapEntry;
        if ( Scaleform::GFx::FontMap::GetFontMapping(v92, &v82->FontMapEntry, pfontName->m128i_i8) )
        {
          v38 = p_FontMapEntry[1].__vftable;
          v39 = (__m128i *)(((int)p_FontMapEntry->__vftable & 0xFFFFFFFC) + 8);
          pname = (char *)v39;
          if ( v38 != (Scaleform::Render::Text::FontManagerBase_vtbl *)16 )
            v35 = matchFontFlags & 0xFFFFFFFC | (unsigned int)v38 & 0xFFFFFFF3;
          v40 = (int)p_FontMapEntry[1].__vftable;
          v83 = *(float *)&v36[5].RefCount;
          if ( (v40 & 0xC) != 0 )
            v41 = v40 >> 2;
          else
            LOBYTE(v41) = 0;
          v85 = v41 & 3 | v40 & 0x20;
          if ( searchInfo )
          {
            Scaleform::GFx::AddSearchInfo_3(
              searchInfo,
              (const __m128i *)"Applying FontMap: \"",
              pfontName,
              (const __m128i *)"\"  mapped to \"",
              v39,
              (const __m128i *)"\"",
              v35);
          }
          else
          {
            v42 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v36[1];
            v96.pFontName = (const char *)v39;
            v96.FontStyle = v35;
            v43 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndex<Scaleform::GFx::FontManager::FontKey>(
                    v42,
                    &v96);
            if ( v43 >= 0 )
            {
              v20 = &v42->pTable[2 * v43 + 2];
              if ( v20 )
              {
                if ( v83 == *(float *)(v20->EntryCount + 20) )
                {
                  EntryCount = (Scaleform::GFx::Resource *)v20->EntryCount;
                  goto LABEL_136;
                }
                v44 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      32,
                                                      0);
                if ( v44 )
                {
                  Scaleform::GFx::FontHandle::FontHandle(
                    v44,
                    v82,
                    *(Scaleform::GFx::Resource **)(v20->EntryCount + 24),
                    pfontName,
                    matchFontFlags,
                    *(Scaleform::GFx::MovieDef **)(v20->EntryCount + 28));
                  v34 = v45;
                }
                else
                {
                  v34 = 0;
                }
                v81 = v34;
                *(float *)&v34[2].RefCount = v83;
              }
            }
            v97.pFontName = (const char *)pfontName;
            v97.FontStyle = v35;
            v46 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndex<Scaleform::GFx::FontManager::FontKey>(
                    v42,
                    &v97);
            if ( v46 >= 0 )
            {
              v20 = &v42->pTable[2 * v46 + 2];
              if ( v20 )
              {
                EntryCount = (Scaleform::GFx::Resource *)v20->EntryCount;
                if ( v83 == *(float *)(v20->EntryCount + 20) )
                  goto LABEL_136;
                v48 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      32,
                                                      0);
                if ( v48 )
                {
                  Scaleform::GFx::FontHandle::FontHandle(
                    v48,
                    v82,
                    *(Scaleform::GFx::Resource **)(v20->EntryCount + 24),
                    pfontName,
                    matchFontFlags,
                    *(Scaleform::GFx::MovieDef **)(v20->EntryCount + 28));
                  v34 = v49;
                }
                else
                {
                  v34 = 0;
                }
                v81 = v34;
                *(float *)&v34[2].RefCount = v83;
              }
            }
            if ( v34 )
              goto LABEL_87;
          }
        }
      }
      if ( v86 )
      {
        v50 = (Scaleform::Render::Text::FontManagerBase_vtbl *)v82->pState;
        v93.pMovieDef = 0;
        v93.pFontResource = 0;
        if ( v50 )
          p_GetEmptyFont = &v50->GetEmptyFont;
        else
          p_GetEmptyFont = 0;
        v52 = (const __m128i *)pname;
        if ( v86->FindFont(
               v86,
               &v93,
               pname,
               v35,
               v82->pDefImpl,
               (Scaleform::GFx::StateBag *)p_GetEmptyFont,
               v82->pWeakLib) )
        {
          if ( v85 )
          {
            v98.FontStyle = v85;
            v53 = (Scaleform::Render::Text::FontManagerBase *)&v82->CreatedFonts;
            v98.pFontName = (const char *)pfontName;
            v54 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndex<Scaleform::GFx::FontManager::FontKey>(
                    &v82->CreatedFonts,
                    &v98);
            if ( v54 >= 0 )
            {
              v55 = (Scaleform::GFx::Resource **)&v53->__vftable[v54 + 1];
              if ( v55 )
              {
                Scaleform::RefCountImpl::AddRef(*v55);
                v78 = *v55;
                Scaleform::GFx::FontLib::FontResult::~FontResult(&v93);
                Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&v99);
                return (Scaleform::RefCountVImpl *)v78;
              }
            }
            v56 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  32,
                                                  0);
            if ( v56 )
            {
              Scaleform::GFx::FontHandle::FontHandle(
                v56,
                searchInfo == 0 ? v82 : 0,
                (Scaleform::GFx::Resource *)v93.pFontResource->pFont.pObject,
                pfontName,
                v85,
                v93.pMovieDef);
              v34 = v57;
            }
            else
            {
              v34 = 0;
            }
            v58 = v85;
            *(float *)&v34[2].RefCount = v83;
            v81 = v34;
            Scaleform::GFx::AddSearchInfo_1(
              searchInfo,
              (const __m128i *)"Searching FontLib: \"",
              pfontName,
              (const __m128i *)"\" ",
              v58,
              (const __m128i *)" found.");
          }
          else
          {
            v59 = (Scaleform::Render::Text::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           32,
                                                           0);
            if ( v59 )
            {
              pMovieDef = v93.pMovieDef;
              Scaleform::Render::Text::FontHandle::FontHandle(
                v59,
                searchInfo == 0 ? v82 : 0,
                (Scaleform::GFx::Resource *)v93.pFontResource->pFont.pObject,
                pfontName,
                0);
              v59->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
              if ( pMovieDef )
                Scaleform::RefCountImpl::AddRef(pMovieDef);
              v61 = v83;
              v34 = (Scaleform::RefCountVImpl *)v59;
              v59[1].__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)pMovieDef;
              v59->FontScaleFactor = v61;
              v81 = (Scaleform::RefCountVImpl *)v59;
              Scaleform::GFx::AddSearchInfo_1(
                searchInfo,
                (const __m128i *)"Searching FontLib: \"",
                (const __m128i *)pname,
                (const __m128i *)"\" ",
                v35,
                (const __m128i *)" found.");
            }
            else
            {
              v34 = 0;
              MEMORY[0x14] = v83;
              v81 = 0;
              Scaleform::GFx::AddSearchInfo_1(
                searchInfo,
                (const __m128i *)"Searching FontLib: \"",
                v52,
                (const __m128i *)"\" ",
                v35,
                (const __m128i *)" found.");
            }
          }
        }
        else
        {
          Scaleform::GFx::AddSearchInfo_1(
            searchInfo,
            (const __m128i *)"Searching FontLib: \"",
            v52,
            (const __m128i *)"\" ",
            v35,
            (const __m128i *)" not found.");
        }
        Scaleform::GFx::FontLib::FontResult::~FontResult(&v93);
      }
    }
LABEL_87:
    if ( v80 || !searchInfo )
    {
      if ( v34 )
        goto LABEL_103;
      goto LABEL_94;
    }
    if ( !v34 )
    {
      if ( !v86 && v99.Status == NonStaticFunction )
        Scaleform::GFx::AddSearchInfo(
          searchInfo,
          (Scaleform::String::DataDesc *)pMovie,
          (const __m128i *)"FontLib not installed.");
LABEL_94:
      pMovie = (Scaleform::GFx::MovieImpl *)pprovider;
      if ( pprovider )
      {
        pDefImpl = (Scaleform::Render::Text::FontManagerBase_vtbl *)v82->pDefImpl;
        if ( pDefImpl )
          pWeakLib = (Scaleform::GFx::ResourceWeakLib *)*((_DWORD *)pDefImpl[1].CreateFontHandle + 5);
        else
          pWeakLib = v82->pWeakLib;
        v64 = (const __m128i *)pname;
        FontResource = Scaleform::GFx::FontResource::CreateFontResource(
                         pname,
                         v35,
                         (Scaleform::GFx::Resource *)pprovider,
                         pWeakLib);
        if ( FontResource )
        {
          Scaleform::GFx::AddSearchInfo_1(
            searchInfo,
            (const __m128i *)"Searching FontProvider: \"",
            v64,
            (const __m128i *)"\" ",
            v35,
            (const __m128i *)" found.");
          v66 = (Scaleform::Render::Text::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         32,
                                                         0);
          if ( v66 )
          {
            Scaleform::Render::Text::FontHandle::FontHandle(
              v66,
              searchInfo == 0 ? v82 : 0,
              (Scaleform::GFx::Resource *)FontResource->pFont.pObject,
              pfontName,
              0);
            v66->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
            v66[1].__vftable = 0;
            v34 = (Scaleform::RefCountVImpl *)v66;
          }
          else
          {
            v34 = 0;
          }
          *(float *)&v34[2].RefCount = v83;
          v81 = v34;
          Scaleform::GFx::Resource::Release(FontResource);
        }
        else
        {
          Scaleform::GFx::AddSearchInfo_1(
            searchInfo,
            (const __m128i *)"Searching FontProvider: \"",
            v64,
            (const __m128i *)"\" ",
            v35,
            (const __m128i *)" not found.");
        }
      }
LABEL_103:
      if ( v80 )
        goto LABEL_110;
    }
    if ( searchInfo )
    {
      if ( v34 )
        break;
      if ( !pprovider && v99.Status == NonStaticFunction )
        Scaleform::GFx::AddSearchInfo(
          searchInfo,
          (Scaleform::String::DataDesc *)pMovie,
          (const __m128i *)"FontProvider not installed.");
      goto LABEL_111;
    }
LABEL_110:
    if ( v34 )
      break;
LABEL_111:
    if ( v86 && (v35 & 0x10) != 0 )
    {
      v67 = (Scaleform::Render::Text::FontManagerBase_vtbl *)v82->pState;
      v68 = v35 & 0xFFFFFFEF;
      v94.pMovieDef = 0;
      v94.pFontResource = 0;
      v69 = v67 ? (int)&v67->GetEmptyFont : 0;
      v70 = (const __m128i *)pname;
      if ( v86->FindFont(v86, &v94, pname, v68, v82->pDefImpl, (Scaleform::GFx::StateBag *)v69, 0) )
      {
        v71 = (Scaleform::Render::Text::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       32,
                                                       0);
        if ( v71 )
        {
          v72 = v94.pMovieDef;
          Scaleform::Render::Text::FontHandle::FontHandle(
            v71,
            searchInfo == 0 ? v82 : 0,
            (Scaleform::GFx::Resource *)v94.pFontResource->pFont.pObject,
            pfontName,
            0x10u);
          v71->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
          if ( v72 )
            Scaleform::RefCountImpl::AddRef(v72);
          v71[1].__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)v72;
          v81 = (Scaleform::RefCountVImpl *)v71;
        }
        else
        {
          v81 = 0;
        }
        v73 = (const __m128i *)pname;
        *(float *)&v81[2].RefCount = v83;
        Scaleform::GFx::AddSearchInfo_1(
          searchInfo,
          (const __m128i *)"Searching FontLib without [Device] flag: \"",
          v73,
          (const __m128i *)"\" ",
          v68,
          (const __m128i *)" found.");
      }
      else
      {
        Scaleform::GFx::AddSearchInfo_1(
          searchInfo,
          (const __m128i *)"Searching FontLib without [Device] flag: \"",
          v70,
          (const __m128i *)"\" ",
          v68,
          (const __m128i *)" not found.");
      }
      Scaleform::GFx::FontLib::FontResult::~FontResult(&v94);
      if ( v81 )
        break;
    }
    v74 = matchFontFlags;
    if ( (matchFontFlags & 0x10) == 0 )
    {
      if ( searchInfo )
        searchInfo->Indent -= v88;
LABEL_144:
      Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&v99);
      return 0;
    }
    Scaleform::GFx::AddSearchInfo(
      searchInfo,
      (Scaleform::String::DataDesc *)pMovie,
      (const __m128i *)"Searching again without [Device] flag:");
    v6 = v82;
    matchFontFlags &= ~0x10u;
    v95.FontStyle = v74 & 0xFFFFFFEF;
    v5 = pfontName;
    pprovider = 0;
    v86 = 0;
    v80 = 1;
  }
  if ( searchInfo )
    searchInfo->Indent -= v88;
  else
    Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
      &v82->CreatedFonts,
      (Scaleform::GFx::FontHandle *const *)&v81);
  Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&v99);
  return v81;
}
