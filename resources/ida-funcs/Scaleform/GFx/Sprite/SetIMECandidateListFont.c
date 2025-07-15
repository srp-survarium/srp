void __thiscall Scaleform::GFx::Sprite::SetIMECandidateListFont(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::Resource *pfontHandle)
{
  if ( pfontHandle )
    Scaleform::GFx::FontManager::SetIMECandidateFont(this->pRootNode->pFontManager.pObject, pfontHandle);
}


void __thiscall Scaleform::GFx::Sprite::SetIMECandidateListFont(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::FontResource *pfont)
{
  int v3; // eax
  Scaleform::GFx::MovieDefRootNode *pRootNode; // eax
  Scaleform::GFx::FontManager *pObject; // esi
  Scaleform::Render::Font *v6; // ecx
  Scaleform::GFx::ResourceBinding *pBinding; // eax
  Scaleform::GFx::MovieDef *pOwnerDefImpl; // esi
  Scaleform::MemoryHeap *v9; // ecx
  Scaleform::GFx::FontHandle *v10; // eax
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::Resource *v12; // edi
  unsigned int Flags; // edi
  int v14; // eax
  int v15; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::FontHandle *v17; // eax
  Scaleform::GFx::Resource *v18; // eax

  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + this->AvmObjOffset)
                                     + 8))(
         (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * this->AvmObjOffset);
  if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v3 + 136))(v3, 9999) )
  {
    pRootNode = this->pRootNode;
    if ( pRootNode )
    {
      pObject = pRootNode->pFontManager.pObject;
      if ( pObject )
      {
        v6 = pfont->pFont.pObject;
        pBinding = pfont->pBinding;
        if ( (v6->Flags & 0x40) != 0 )
        {
          Flags = v6->Flags;
          v14 = ((int (*)(void))v6->GetName)();
          v15 = (int)pObject->CreateFontHandle(pObject, (const char *)v14, Flags, 0, 0);
          if ( !v15 )
            return;
          pHeap = this->pASRoot->pMovieImpl->pHeap;
          v17 = (Scaleform::GFx::FontHandle *)pHeap->Alloc(pHeap, 32u, 0);
          if ( v17 )
            Scaleform::GFx::FontHandle::FontHandle(
              v17,
              0,
              *(Scaleform::GFx::Resource **)(v15 + 24),
              "$IMECandidateListFont",
              0,
              *(Scaleform::GFx::MovieDef **)(v15 + 28));
          else
            v18 = 0;
          v12 = v18;
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v15);
        }
        else
        {
          if ( pBinding )
            pOwnerDefImpl = pBinding->pOwnerDefImpl;
          else
            pOwnerDefImpl = 0;
          v9 = this->pASRoot->pMovieImpl->pHeap;
          v10 = (Scaleform::GFx::FontHandle *)v9->Alloc(v9, 32u, 0);
          if ( v10 )
          {
            Scaleform::GFx::FontHandle::FontHandle(
              v10,
              0,
              (Scaleform::GFx::Resource *)pfont->pFont.pObject,
              "$IMECandidateListFont",
              0,
              pOwnerDefImpl);
            v12 = v11;
          }
          else
          {
            v12 = 0;
          }
        }
        if ( v12 )
        {
          Scaleform::GFx::FontManager::SetIMECandidateFont(this->pRootNode->pFontManager.pObject, v12);
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
        }
      }
    }
  }
}
