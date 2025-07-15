bool __userpurge Scaleform::GFx::TextField::SetRestrict@<al>(
        Scaleform::GFx::TextField *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::GFx::ASString *restrStr)
{
  Scaleform::GFx::Text::EditorKit *pObject; // esi
  const Scaleform::String *v5; // eax
  bool v6; // al
  void *v7; // esi
  bool v8; // bl
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [esp+8h] [ebp-4h] BYREF

  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, a2, (int)&result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  }
  pObject = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
  Scaleform::String::String((Scaleform::String *)&restrStr, (char *)restrStr->pNode->pData);
  v6 = Scaleform::GFx::Text::EditorKit::SetRestrict(pObject, v5);
  v7 = (void *)((unsigned int)restrStr & 0xFFFFFFFC);
  v8 = v6;
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)restrStr & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  return v8;
}
