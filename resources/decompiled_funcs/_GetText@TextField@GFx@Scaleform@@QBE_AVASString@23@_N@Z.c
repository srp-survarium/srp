Scaleform::GFx::ASString *__thiscall Scaleform::GFx::TextField::GetText(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String reqHtml)
{
  Scaleform::GFx::ASStringManager *StringManager; // edi
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::Render::Text::DocView *pObject; // ecx
  const Scaleform::String *Html; // eax
  void *v11; // esi
  Scaleform::String *Text; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  void *v14; // esi

  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(this);
  if ( LOBYTE(reqHtml.pData) )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset
      && (v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                               + AvmObjOffset)
                                             + 16))(
                 (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
               + 4 * AvmObjOffset),
          (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 96))(v6)) )
    {
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     StringManager,
                     (char *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC) + 8),
                     *(_DWORD *)(this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      result->pNode = StringNode;
      ++StringNode->RefCount;
      return result;
    }
    else
    {
      pObject = this->pDocument.pObject;
      if ( (this->Flags & 2) != 0 )
        Html = Scaleform::Render::Text::DocView::GetHtml(pObject, &reqHtml);
      else
        Html = Scaleform::Render::Text::DocView::GetText(pObject, &reqHtml);
      Scaleform::GFx::ASStringManager::CreateString(StringManager, result, Html);
      v11 = (void *)(reqHtml.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((reqHtml.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      return result;
    }
  }
  else
  {
    Text = Scaleform::Render::Text::DocView::GetText(this->pDocument.pObject, &reqHtml);
    v13 = Scaleform::GFx::ASStringManager::CreateStringNode(
            StringManager,
            (char *)((Text->HeapTypeBits & 0xFFFFFFFC) + 8),
            *(_DWORD *)(Text->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    result->pNode = v13;
    ++v13->RefCount;
    v14 = (void *)(reqHtml.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((reqHtml.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
    return result;
  }
}
