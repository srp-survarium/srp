char __userpurge Scaleform::GFx::TextField::SetRestrict@<al>(
        Scaleform::GFx::TextField *this@<ecx>,
        int a2@<ebx>,
        const __m128i ***restrStr)
{
  Scaleform::GFx::Text::EditorKit *pObject; // esi
  const Scaleform::String *v5; // eax
  char v6; // al
  void *v7; // esi
  char v8; // bl
  Scaleform::RefCountVImpl *v10; // [esp+8h] [ebp-4h] BYREF

  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, a2, (int)&v10);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
  }
  pObject = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
  Scaleform::String::String((Scaleform::String *)&restrStr, **restrStr);
  v6 = Scaleform::GFx::Text::EditorKit::SetRestrict(pObject, v5);
  v7 = (void *)((unsigned int)restrStr & 0xFFFFFFFC);
  v8 = v6;
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)restrStr & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  return v8;
}
