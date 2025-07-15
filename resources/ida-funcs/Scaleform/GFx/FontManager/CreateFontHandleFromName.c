Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *__thiscall Scaleform::GFx::FontManager::CreateFontHandleFromName(
        Scaleform::GFx::FontManager *this,
        __m128i *pfontName,
        unsigned int matchFontFlags,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  unsigned int v5; // ebp
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v6; // edi
  Scaleform::String::DataDesc *v8; // ecx
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v9; // esi
  unsigned int v10; // ebp
  Scaleform::GFx::FontHandle *v11; // eax
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v12; // eax
  Scaleform::GFx::FontResource *v13; // ebp
  unsigned int v14; // eax
  int Indent; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::FontResource *v18; // [esp+18h] [ebp-8h] BYREF
  int v19; // [esp+1Ch] [ebp-4h]
  Scaleform::GFx::FontHandle *f; // [esp+24h] [ebp+4h]

  v5 = matchFontFlags;
  v6 = searchInfo;
  Indent = 0;
  if ( searchInfo )
  {
    Indent = searchInfo->Indent;
    Scaleform::GFx::AddSearchInfo_1(
      searchInfo,
      (const __m128i *)"Searching for font: \"",
      pfontName,
      (const __m128i *)"\" ",
      matchFontFlags,
      (const __m128i *)uri);
  }
  v18 = 0;
  v9 = (Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *)Scaleform::GFx::FontManager::FindOrCreateHandle(
                                                                         this,
                                                                         pfontName,
                                                                         v5,
                                                                         &v18,
                                                                         v6);
  if ( !v9 )
  {
    v19 = v5 & 3;
    if ( (v5 & 3) != 0 )
    {
      v10 = v5 & 0xFFFFFFFC;
      if ( v6 )
      {
        ++v6->Indent;
        Scaleform::GFx::AddSearchInfo_1(
          v6,
          (const __m128i *)"Searching for font: \"",
          pfontName,
          (const __m128i *)"\" ",
          v10,
          (const __m128i *)uri);
      }
      f = (Scaleform::GFx::FontHandle *)Scaleform::GFx::FontManager::FindOrCreateHandle(this, pfontName, v10, 0, v6);
      if ( f )
      {
        v11 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
        if ( v11 )
        {
          Scaleform::GFx::FontHandle::FontHandle(v11, f);
          v9 = v12;
        }
        else
        {
          v9 = 0;
        }
        v9->Info.BufferSize |= v19;
        searchInfo = v9;
        if ( v6 )
          Scaleform::GFx::AddSearchInfo_2(
            v6,
            (const __m128i *)"Font \"",
            pfontName,
            (const __m128i *)"\" ",
            matchFontFlags,
            (const __m128i *)" will be generated from \"",
            pfontName,
            (const __m128i *)"\"",
            v10);
        else
          Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
            &this->CreatedFonts,
            (Scaleform::GFx::FontHandle *const *)&searchInfo);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)f);
      }
    }
  }
  if ( v6 )
    v6->Indent = Indent;
  if ( !v9 )
  {
    v13 = v18;
    if ( !v18 )
      goto LABEL_25;
    Scaleform::GFx::AddSearchInfo_0(v6, (const __m128i *)"Empty font: \"", pfontName, (const __m128i *)"\" is created");
    v9 = (Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                           Scaleform::Memory::pGlobalHeap,
                                                                           32,
                                                                           0);
    if ( v9 )
    {
      Scaleform::Render::Text::FontHandle::FontHandle(
        (Scaleform::Render::Text::FontHandle *)v9,
        v6 == 0 ? this : 0,
        (Scaleform::GFx::Resource *)v13->pFont.pObject,
        pfontName,
        0);
      v9->Indent = (int)&Scaleform::GFx::FontHandle::`vftable';
      v9[1].Indent = 0;
    }
    else
    {
      v9 = 0;
    }
    searchInfo = v9;
    if ( !v6 )
    {
      v14 = Scaleform::GFx::FontManager::NodePtrHashOp::operator()(
              (Scaleform::GFx::FontManager::NodePtrHashOp *)&matchFontFlags,
              (const Scaleform::GFx::FontHandle *)v9);
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::add<Scaleform::GFx::FontHandle *>(
        &this->CreatedFonts,
        &this->CreatedFonts,
        (Scaleform::GFx::FontHandle *const *)&searchInfo,
        v14);
    }
    if ( !v9 )
LABEL_25:
      Scaleform::GFx::AddSearchInfo(v6, v8, (const __m128i *)"Font not found.");
  }
  return v9;
}
