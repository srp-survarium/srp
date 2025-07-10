Scaleform::GFx::Resource *__thiscall Scaleform::GFx::FontManager::FindOrCreateHandle(
        Scaleform::GFx::FontManager *this,
        char *pfontName,
        unsigned int matchFontFlags,
        Scaleform::GFx::FontResource **ppfoundFont,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  char *v5; // ebx
  Scaleform::GFx::FontManager *v6; // edi
  Scaleform::GFx::FontManagerStates *pState; // eax
  Scaleform::GFx::FontLib *pObject; // ecx
  Scaleform::GFx::FontProvider *v9; // edx
  Scaleform::GFx::FontMap *v10; // eax
  Scaleform::GFx::FontHandle *v11; // eax
  _DWORD *v12; // ecx
  const char *v13; // eax
  Scaleform::GFx::FontHandle *v14; // edi
  void *v15; // esi
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // ebp
  unsigned int v18; // eax
  signed int v19; // eax
  const Scaleform::GFx::FontManager::NodePtr *v20; // esi
  Scaleform::GFx::FontResource *RegisteredFont; // esi
  Scaleform::GFx::MovieImpl *pMovie; // ecx
  Scaleform::GFx::FontHandle *v23; // ebp
  Scaleform::GFx::MovieDef *v24; // edi
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v25; // ebp
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v26; // ecx
  Scaleform::GFx::FontHandle *v27; // esi
  _DWORD *v28; // eax
  char *v29; // eax
  unsigned int Flags; // edi
  unsigned __int8 v31; // si
  unsigned int v32; // eax
  signed int v33; // eax
  Scaleform::GFx::FontHandle *v34; // ebp
  unsigned int v35; // ebx
  Scaleform::Render::Text::FontManagerBase *v36; // edi
  Scaleform::Render::Text::FontManagerBase *v37; // esi
  Scaleform::Render::Text::FontManagerBase_vtbl *v38; // eax
  char *v39; // edx
  int v40; // eax
  int v41; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v42; // edi
  signed int v43; // eax
  Scaleform::GFx::FontHandle *v44; // eax
  Scaleform::GFx::FontHandle *v45; // eax
  signed int v46; // eax
  Scaleform::GFx::Resource *pNode; // ecx
  Scaleform::GFx::FontHandle *v48; // eax
  Scaleform::GFx::FontHandle *v49; // eax
  Scaleform::Render::Text::FontManagerBase_vtbl *v50; // eax
  Scaleform::GFx::StateBag *p_GetEmptyFont; // eax
  char *v52; // edi
  Scaleform::Render::Text::FontManagerBase *v53; // edi
  signed int v54; // eax
  Scaleform::GFx::Resource **v55; // esi
  Scaleform::GFx::FontHandle *v56; // eax
  Scaleform::GFx::FontHandle *v57; // eax
  unsigned int v58; // edx
  Scaleform::GFx::FontHandle *v59; // esi
  Scaleform::GFx::MovieDef *pMovieDef; // edi
  double v61; // st7
  Scaleform::Render::Text::FontManagerBase_vtbl *v62; // eax
  Scaleform::GFx::ResourceWeakLib *RefCount; // eax
  char *v64; // esi
  Scaleform::GFx::FontResource *FontResource; // edi
  Scaleform::Render::Text::FontHandle *v66; // esi
  Scaleform::Render::Text::FontManagerBase_vtbl *v67; // eax
  unsigned int v68; // ebp
  Scaleform::GFx::StateBag *v69; // eax
  char *v70; // esi
  Scaleform::GFx::FontHandle *v71; // esi
  Scaleform::GFx::MovieDef *v72; // edi
  char *v73; // edx
  unsigned int v74; // ebx
  Scaleform::GFx::FontManager::NodePtr *v75; // eax
  Scaleform::RefCountVImpl *v76; // ecx
  Scaleform::GFx::FontHandle *v77; // esi
  Scaleform::GFx::Resource *v78; // esi
  Scaleform::GFx::FontManager::NodePtr *v79; // [esp+40h] [ebp-84h]
  bool secondLoop; // [esp+57h] [ebp-6Dh]
  Scaleform::GFx::FontHandle *phandle; // [esp+58h] [ebp-6Ch] BYREF
  Scaleform::Render::Text::FontManagerBase *pmanager; // [esp+5Ch] [ebp-68h]
  float scaleFactor; // [esp+60h] [ebp-64h]
  const char *plookupFontName; // [esp+64h] [ebp-60h]
  unsigned int overridenFlags; // [esp+68h] [ebp-5Ch]
  Scaleform::GFx::FontLib *pfontLib; // [esp+6Ch] [ebp-58h]
  const Scaleform::GFx::FontManager::NodePtr *pfoundNode; // [esp+70h] [ebp-54h]
  int indentDif; // [esp+74h] [ebp-50h]
  Scaleform::GFx::FontProvider *pfontProvider; // [esp+78h] [ebp-4Ch]
  Scaleform::GFx::MovieDefImpl::SearchInfo *presSearchInfo; // [esp+7Ch] [ebp-48h]
  Scaleform::GFx::MovieDef *psrcMovieDef; // [esp+80h] [ebp-44h] BYREF
  Scaleform::GFx::FontMap *pfontMap; // [esp+84h] [ebp-40h]
  Scaleform::GFx::FontLib::FontResult fr; // [esp+88h] [ebp-3Ch] BYREF
  Scaleform::GFx::FontLib::FontResult v94; // [esp+90h] [ebp-34h] BYREF
  Scaleform::GFx::FontManager::FontKey key; // [esp+98h] [ebp-2Ch] BYREF
  Scaleform::GFx::FontManager::FontKey lookupKey; // [esp+A0h] [ebp-24h] BYREF
  Scaleform::GFx::FontManager::FontKey lookupKey2; // [esp+A8h] [ebp-1Ch] BYREF
  Scaleform::GFx::FontManager::FontKey v98; // [esp+B0h] [ebp-14h] BYREF
  Scaleform::GFx::MovieDefImpl::SearchInfo resSearchInfo; // [esp+B8h] [ebp-Ch] BYREF

  v5 = pfontName;
  v6 = this;
  key.FontStyle = matchFontFlags;
  pState = this->pState;
  pObject = pState->pFontLib.pObject;
  v9 = pState->pFontProvider.pObject;
  v10 = pState->pFontMap.pObject;
  pfontLib = pObject;
  pmanager = v6;
  key.pFontName = pfontName;
  phandle = 0;
  pfontProvider = v9;
  pfontMap = v10;
  indentDif = 0;
  pfoundNode = 0;
  resSearchInfo.ImportSearchUrls.pTable = 0;
  Scaleform::String::String(&resSearchInfo.ImportFoundUrl);
  v11 = v6->pIMECandidateFont.pObject;
  presSearchInfo = 0;
  secondLoop = 0;
  if ( v11 )
  {
    v12 = (_DWORD *)(v11->FontName.HeapTypeBits & 0xFFFFFFFC);
    v13 = (*v12 & 0x7FFFFFFF) != 0 ? (const char *)(v12 + 2) : v11->pFont.pObject->GetName(v11->pFont.pObject);
    if ( !Scaleform::String::CompareNoCase(v13, pfontName) )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->pIMECandidateFont.pObject);
      v14 = v6->pIMECandidateFont.pObject;
      v15 = (void *)(resSearchInfo.ImportFoundUrl.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((resSearchInfo.ImportFoundUrl.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
      Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Clear(&resSearchInfo.ImportSearchUrls);
      return (Scaleform::GFx::Resource *)v14;
    }
  }
  while ( 1 )
  {
    if ( searchInfo )
    {
      ++indentDif;
      ++searchInfo->Indent;
      presSearchInfo = &resSearchInfo;
    }
    else
    {
      p_CreatedFonts = &v6->CreatedFonts;
      if ( v6->CreatedFonts.pTable )
      {
        v18 = Scaleform::String::BernsteinHashFunctionCIS(v5, strlen(v5), 0x1505u);
        v19 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
                &v6->CreatedFonts,
                &key,
                p_CreatedFonts->pTable->SizeMask & (v18 ^ matchFontFlags & 3));
        if ( v19 >= 0 )
        {
          v20 = (const Scaleform::GFx::FontManager::NodePtr *)&p_CreatedFonts->pTable[2 * v19 + 2];
          if ( v20 )
          {
            if ( (matchFontFlags & 0x10) != 0
              || ((LOBYTE(v20->pNode->OverridenFontFlags) | LOBYTE(v20->pNode->pFont.pObject->Flags)) & 0x10) == 0 )
            {
              goto LABEL_134;
            }
            if ( v20->SearchedForNonDeviceFont )
            {
              pNode = (Scaleform::GFx::Resource *)v20->pNode;
              goto LABEL_136;
            }
            pfoundNode = (const Scaleform::GFx::FontManager::NodePtr *)&p_CreatedFonts->pTable[2 * v19 + 2];
          }
        }
      }
    }
    RegisteredFont = v6->pDefImpl ? v6->pDefImpl->GetFontResource(v6->pDefImpl, v5, matchFontFlags, presSearchInfo) : 0;
    Scaleform::GFx::AddSearchInfo_4(searchInfo, v5, matchFontFlags, v6->pState->pFontLib.pObject != 0, &resSearchInfo);
    psrcMovieDef = 0;
    if ( RegisteredFont )
      goto LABEL_25;
    pMovie = v6->pMovie;
    if ( !pMovie )
      goto LABEL_33;
    RegisteredFont = Scaleform::GFx::MovieImpl::FindRegisteredFont(pMovie, v5, matchFontFlags, &psrcMovieDef);
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
          v75 = (Scaleform::GFx::FontManager::NodePtr *)pfoundNode;
          if ( pfoundNode )
          {
            pfoundNode->pNode->pFontManager = 0;
            Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
              (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager[1],
              (const Scaleform::GFx::FontHandle **)&v75->pNode);
            Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&resSearchInfo);
            return 0;
          }
          goto LABEL_144;
        }
        v23 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
        if ( v23 )
        {
          v24 = psrcMovieDef;
          Scaleform::Render::Text::FontHandle::FontHandle(
            v23,
            searchInfo == 0 ? pmanager : 0,
            (Scaleform::GFx::Resource *)RegisteredFont->pFont.pObject,
            v5,
            0);
          v23->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
          if ( v24 )
            Scaleform::RefCountImpl::AddRef(v24);
          v23->pSourceMovieDef.pObject = v24;
          phandle = v23;
        }
        else
        {
          phandle = 0;
        }
      }
    }
    else
    {
      Scaleform::GFx::AddSearchInfo_1(searchInfo, "Registered fonts: \"", v5, "\"", matchFontFlags, " not found.");
    }
LABEL_33:
    v20 = pfoundNode;
    if ( pfoundNode )
    {
      if ( !phandle )
      {
        pNode = (Scaleform::GFx::Resource *)pfoundNode->pNode;
        pfoundNode->SearchedForNonDeviceFont = 1;
        goto LABEL_136;
      }
      v25 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager[1];
      v79 = (Scaleform::GFx::FontManager::NodePtr *)pfoundNode;
      v26 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager[1];
      pfoundNode->pNode->pFontManager = 0;
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
        v26,
        (const Scaleform::GFx::FontHandle **)&v79->pNode);
      if ( v25->pTable
        && ((v27 = phandle, v28 = (_DWORD *)(phandle->FontName.HeapTypeBits & 0xFFFFFFFC), (*v28 & 0x7FFFFFFF) != 0)
          ? (v29 = (char *)(v28 + 2))
          : (v29 = (char *)phandle->pFont.pObject->GetName(phandle->pFont.pObject)),
            Flags = v27->pFont.pObject->Flags,
            v31 = (Flags | v27->OverridenFontFlags) & 3,
            v32 = Scaleform::String::BernsteinHashFunctionCIS(v29, strlen(v29), 0x1505u),
            v33 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontHandle *>(
                    v25,
                    &phandle,
                    v25->pTable->SizeMask & (v32 ^ ((unsigned __int8)Flags | v31) & 3)),
            v33 >= 0) )
      {
        v20 = (const Scaleform::GFx::FontManager::NodePtr *)&v25->pTable[2 * v33 + 2];
        pfoundNode = v20;
        if ( v20 )
        {
          v76 = (Scaleform::RefCountVImpl *)phandle;
          phandle->pFontManager = 0;
          Scaleform::RefCountImpl::Release(v76);
LABEL_134:
          pNode = (Scaleform::GFx::Resource *)v20->pNode;
LABEL_136:
          Scaleform::RefCountImpl::AddRef(pNode);
          v77 = v20->pNode;
          Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&resSearchInfo);
          return (Scaleform::GFx::Resource *)v77;
        }
      }
      else
      {
        pfoundNode = 0;
      }
    }
    v34 = phandle;
    scaleFactor = 1.0;
    v35 = matchFontFlags;
    plookupFontName = pfontName;
    overridenFlags = 0;
    if ( !phandle )
    {
      pMovie = (Scaleform::GFx::MovieImpl *)pfontMap;
      if ( pfontMap )
      {
        v36 = pmanager;
        v37 = pmanager + 5;
        if ( Scaleform::GFx::FontMap::GetFontMapping(
               pfontMap,
               (Scaleform::GFx::FontMap::MapEntry *)&pmanager[5],
               pfontName) )
        {
          v38 = v37[1].__vftable;
          v39 = (char *)(((int)v37->__vftable & 0xFFFFFFFC) + 8);
          plookupFontName = v39;
          if ( v38 != (Scaleform::Render::Text::FontManagerBase_vtbl *)16 )
            v35 = matchFontFlags & 0xFFFFFFFC | (unsigned int)v38 & 0xFFFFFFF3;
          v40 = (int)v37[1].__vftable;
          scaleFactor = *(float *)&v36[5].RefCount;
          if ( (v40 & 0xC) != 0 )
            v41 = v40 >> 2;
          else
            LOBYTE(v41) = 0;
          overridenFlags = v41 & 3 | v40 & 0x20;
          if ( searchInfo )
          {
            Scaleform::GFx::AddSearchInfo_3(
              searchInfo,
              "Applying FontMap: \"",
              pfontName,
              "\"  mapped to \"",
              v39,
              "\"",
              v35);
          }
          else
          {
            v42 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v36[1];
            lookupKey.pFontName = v39;
            lookupKey.FontStyle = v35;
            v43 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndex<Scaleform::GFx::FontManager::FontKey>(
                    v42,
                    &lookupKey);
            if ( v43 >= 0 )
            {
              v20 = (const Scaleform::GFx::FontManager::NodePtr *)&v42->pTable[2 * v43 + 2];
              if ( v20 )
              {
                if ( scaleFactor == v20->pNode->FontScaleFactor )
                {
                  pNode = (Scaleform::GFx::Resource *)v20->pNode;
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
                    pmanager,
                    (Scaleform::GFx::Resource *)v20->pNode->pFont.pObject,
                    pfontName,
                    matchFontFlags,
                    v20->pNode->pSourceMovieDef.pObject);
                  v34 = v45;
                }
                else
                {
                  v34 = 0;
                }
                phandle = v34;
                v34->FontScaleFactor = scaleFactor;
              }
            }
            lookupKey2.pFontName = pfontName;
            lookupKey2.FontStyle = v35;
            v46 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndex<Scaleform::GFx::FontManager::FontKey>(
                    v42,
                    &lookupKey2);
            if ( v46 >= 0 )
            {
              v20 = (const Scaleform::GFx::FontManager::NodePtr *)&v42->pTable[2 * v46 + 2];
              if ( v20 )
              {
                pNode = (Scaleform::GFx::Resource *)v20->pNode;
                if ( scaleFactor == v20->pNode->FontScaleFactor )
                  goto LABEL_136;
                v48 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      32,
                                                      0);
                if ( v48 )
                {
                  Scaleform::GFx::FontHandle::FontHandle(
                    v48,
                    pmanager,
                    (Scaleform::GFx::Resource *)v20->pNode->pFont.pObject,
                    pfontName,
                    matchFontFlags,
                    v20->pNode->pSourceMovieDef.pObject);
                  v34 = v49;
                }
                else
                {
                  v34 = 0;
                }
                phandle = v34;
                v34->FontScaleFactor = scaleFactor;
              }
            }
            if ( v34 )
              goto LABEL_87;
          }
        }
      }
      if ( pfontLib )
      {
        v50 = pmanager[4].__vftable;
        fr.pMovieDef = 0;
        fr.pFontResource = 0;
        if ( v50 )
          p_GetEmptyFont = (Scaleform::GFx::StateBag *)&v50->GetEmptyFont;
        else
          p_GetEmptyFont = 0;
        v52 = (char *)plookupFontName;
        if ( pfontLib->FindFont(
               pfontLib,
               &fr,
               plookupFontName,
               v35,
               (Scaleform::GFx::MovieDef *)pmanager[3].__vftable,
               p_GetEmptyFont,
               (Scaleform::GFx::ResourceWeakLib *)pmanager[3].RefCount) )
        {
          if ( overridenFlags )
          {
            v98.FontStyle = overridenFlags;
            v53 = pmanager + 1;
            v98.pFontName = pfontName;
            v54 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndex<Scaleform::GFx::FontManager::FontKey>(
                    (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager[1],
                    &v98);
            if ( v54 >= 0 )
            {
              v55 = (Scaleform::GFx::Resource **)&v53->__vftable[v54 + 1];
              if ( v55 )
              {
                Scaleform::RefCountImpl::AddRef(*v55);
                v78 = *v55;
                Scaleform::GFx::FontLib::FontResult::~FontResult(&fr);
                Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&resSearchInfo);
                return v78;
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
                searchInfo == 0 ? pmanager : 0,
                (Scaleform::GFx::Resource *)fr.pFontResource->pFont.pObject,
                pfontName,
                overridenFlags,
                fr.pMovieDef);
              v34 = v57;
            }
            else
            {
              v34 = 0;
            }
            v58 = overridenFlags;
            v34->FontScaleFactor = scaleFactor;
            phandle = v34;
            Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontLib: \"", pfontName, "\" ", v58, " found.");
          }
          else
          {
            v59 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  32,
                                                  0);
            if ( v59 )
            {
              pMovieDef = fr.pMovieDef;
              Scaleform::Render::Text::FontHandle::FontHandle(
                v59,
                searchInfo == 0 ? pmanager : 0,
                (Scaleform::GFx::Resource *)fr.pFontResource->pFont.pObject,
                pfontName,
                0);
              v59->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
              if ( pMovieDef )
                Scaleform::RefCountImpl::AddRef(pMovieDef);
              v61 = scaleFactor;
              v34 = v59;
              v59->pSourceMovieDef.pObject = pMovieDef;
              v59->FontScaleFactor = v61;
              phandle = v59;
              Scaleform::GFx::AddSearchInfo_1(
                searchInfo,
                "Searching FontLib: \"",
                (char *)plookupFontName,
                "\" ",
                v35,
                " found.");
            }
            else
            {
              v34 = 0;
              MEMORY[0x14] = scaleFactor;
              phandle = 0;
              Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontLib: \"", v52, "\" ", v35, " found.");
            }
          }
        }
        else
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontLib: \"", v52, "\" ", v35, " not found.");
        }
        Scaleform::GFx::FontLib::FontResult::~FontResult(&fr);
      }
    }
LABEL_87:
    if ( secondLoop || !searchInfo )
    {
      if ( v34 )
        goto LABEL_103;
      goto LABEL_94;
    }
    if ( !v34 )
    {
      if ( !pfontLib && resSearchInfo.Status == FoundInResourcesNoGlyphs )
        Scaleform::GFx::AddSearchInfo(searchInfo, (Scaleform::String::DataDesc *)pMovie, "FontLib not installed.");
LABEL_94:
      pMovie = (Scaleform::GFx::MovieImpl *)pfontProvider;
      if ( pfontProvider )
      {
        v62 = pmanager[3].__vftable;
        if ( v62 )
          RefCount = (Scaleform::GFx::ResourceWeakLib *)*((_DWORD *)v62[1].CreateFontHandle + 5);
        else
          RefCount = (Scaleform::GFx::ResourceWeakLib *)pmanager[3].RefCount;
        v64 = (char *)plookupFontName;
        FontResource = Scaleform::GFx::FontResource::CreateFontResource(plookupFontName, v35, pfontProvider, RefCount);
        if ( FontResource )
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontProvider: \"", v64, "\" ", v35, " found.");
          v66 = (Scaleform::Render::Text::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         32,
                                                         0);
          if ( v66 )
          {
            Scaleform::Render::Text::FontHandle::FontHandle(
              v66,
              searchInfo == 0 ? pmanager : 0,
              (Scaleform::GFx::Resource *)FontResource->pFont.pObject,
              pfontName,
              0);
            v66->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
            v66[1].__vftable = 0;
            v34 = (Scaleform::GFx::FontHandle *)v66;
          }
          else
          {
            v34 = 0;
          }
          v34->FontScaleFactor = scaleFactor;
          phandle = v34;
          Scaleform::GFx::Resource::Release(FontResource);
        }
        else
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontProvider: \"", v64, "\" ", v35, " not found.");
        }
      }
LABEL_103:
      if ( secondLoop )
        goto LABEL_110;
    }
    if ( searchInfo )
    {
      if ( v34 )
        break;
      if ( !pfontProvider && resSearchInfo.Status == FoundInResourcesNoGlyphs )
        Scaleform::GFx::AddSearchInfo(searchInfo, (Scaleform::String::DataDesc *)pMovie, "FontProvider not installed.");
      goto LABEL_111;
    }
LABEL_110:
    if ( v34 )
      break;
LABEL_111:
    if ( pfontLib && (v35 & 0x10) != 0 )
    {
      v67 = pmanager[4].__vftable;
      v68 = v35 & 0xFFFFFFEF;
      v94.pMovieDef = 0;
      v94.pFontResource = 0;
      v69 = v67 ? (Scaleform::GFx::StateBag *)&v67->GetEmptyFont : 0;
      v70 = (char *)plookupFontName;
      if ( pfontLib->FindFont(
             pfontLib,
             &v94,
             plookupFontName,
             v68,
             (Scaleform::GFx::MovieDef *)pmanager[3].__vftable,
             v69,
             0) )
      {
        v71 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
        if ( v71 )
        {
          v72 = v94.pMovieDef;
          Scaleform::Render::Text::FontHandle::FontHandle(
            v71,
            searchInfo == 0 ? pmanager : 0,
            (Scaleform::GFx::Resource *)v94.pFontResource->pFont.pObject,
            pfontName,
            0x10u);
          v71->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
          if ( v72 )
            Scaleform::RefCountImpl::AddRef(v72);
          v71->pSourceMovieDef.pObject = v72;
          phandle = v71;
        }
        else
        {
          phandle = 0;
        }
        v73 = (char *)plookupFontName;
        phandle->FontScaleFactor = scaleFactor;
        Scaleform::GFx::AddSearchInfo_1(
          searchInfo,
          "Searching FontLib without [Device] flag: \"",
          v73,
          "\" ",
          v68,
          " found.");
      }
      else
      {
        Scaleform::GFx::AddSearchInfo_1(
          searchInfo,
          "Searching FontLib without [Device] flag: \"",
          v70,
          "\" ",
          v68,
          " not found.");
      }
      Scaleform::GFx::FontLib::FontResult::~FontResult(&v94);
      if ( phandle )
        break;
    }
    v74 = matchFontFlags;
    if ( (matchFontFlags & 0x10) == 0 )
    {
      if ( searchInfo )
        searchInfo->Indent -= indentDif;
LABEL_144:
      Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&resSearchInfo);
      return 0;
    }
    Scaleform::GFx::AddSearchInfo(
      searchInfo,
      (Scaleform::String::DataDesc *)pMovie,
      "Searching again without [Device] flag:");
    v6 = (Scaleform::GFx::FontManager *)pmanager;
    matchFontFlags &= ~0x10u;
    key.FontStyle = v74 & 0xFFFFFFEF;
    v5 = pfontName;
    pfontProvider = 0;
    pfontLib = 0;
    secondLoop = 1;
  }
  if ( searchInfo )
    searchInfo->Indent -= indentDif;
  else
    Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
      (Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager[1],
      (const Scaleform::GFx::FontHandle **)&phandle);
  Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(&resSearchInfo);
  return (Scaleform::GFx::Resource *)phandle;
}
