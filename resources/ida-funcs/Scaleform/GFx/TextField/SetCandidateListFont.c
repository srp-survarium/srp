void __thiscall Scaleform::GFx::TextField::SetCandidateListFont(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::Sprite *psprite)
{
  char v2; // bl
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  Scaleform::RefCountVImpl *v5; // ebp
  unsigned int CursorPos; // eax
  Scaleform::StringDH *FontList; // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  int v9; // esi
  Scaleform::GFx::FontManager *v10; // edi
  int v11; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::FontHandle *v13; // ebp
  Scaleform::GFx::Resource **v14; // eax
  Scaleform::GFx::Resource *pDefImpl; // edi
  Scaleform::GFx::Resource *v16; // eax
  Scaleform::GFx::Resource *v17; // edi
  void *v18; // esi
  Scaleform::Render::Text::TextFormat *v19; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::Resource *v20; // [esp+18h] [ebp-Ch] BYREF
  Scaleform::String v21; // [esp+1Ch] [ebp-8h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v22; // [esp+20h] [ebp-4h] BYREF

  v2 = 0;
  v21.pData = 0;
  pObject = this->pDocument.pObject->pEditorKit.pObject;
  v5 = 0;
  if ( pObject )
    CursorPos = (unsigned int)Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)pObject);
  else
    CursorPos = -1;
  Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
    this->pDocument.pObject->pDocument.pObject,
    &v19,
    &v22,
    CursorPos);
  FontList = Scaleform::Render::Text::TextFormat::GetFontList(v19);
  Scaleform::String::String(&v21, FontList);
  pParent = this->pParent;
  v9 = (2 * (v19->FormatFlags & 1)) | (v19->FormatFlags >> 1) & 1;
  if ( pParent )
  {
    v10 = pParent->GetFontManager(pParent);
    v11 = (int)v10->CreateFontHandle(v10, (const char *)((v21.HeapTypeBits & 0xFFFFFFFC) + 8), v9, 1, 0);
    if ( v11 )
    {
      pHeap = psprite->pASRoot->pMovieImpl->pHeap;
      v13 = (Scaleform::GFx::FontHandle *)pHeap->Alloc(pHeap, 32u, 0);
      if ( v13 )
      {
        v14 = (Scaleform::GFx::Resource **)(v11 + 28);
        if ( !*(_DWORD *)(v11 + 28) )
        {
          pDefImpl = v10->pDefImpl;
          v2 = 1;
          if ( pDefImpl )
            Scaleform::RefCountImpl::AddRef(pDefImpl);
          v20 = pDefImpl;
          v14 = &v20;
        }
        Scaleform::GFx::FontHandle::FontHandle(
          v13,
          0,
          *(Scaleform::GFx::Resource **)(v11 + 24),
          (__m128i *)"$IMECandidateListFont",
          0,
          (Scaleform::GFx::MovieDef *)*v14);
        v17 = v16;
      }
      else
      {
        v17 = 0;
      }
      v5 = (Scaleform::RefCountVImpl *)v17;
      if ( (v2 & 1) != 0 && v20 )
        Scaleform::GFx::Resource::Release(v20);
      Scaleform::GFx::Sprite::SetIMECandidateListFont(psprite, v17);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11);
    }
  }
  v18 = (void *)(v21.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v21.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
}
