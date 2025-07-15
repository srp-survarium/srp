void __userpurge Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::appendHtml(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this@<ecx>,
        int a2@<esi>,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        const Scaleform::GFx::ASString *newHtml,
        const char ***a6)
{
  Scaleform::GFx::TextField *pObject; // esi
  void *v7; // eax
  const char **v8; // edx
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [esp+4h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+14h] [ebp+0h]

  if ( LOBYTE(this->pTraits.pObject->pVM[1].ExceptionObj.Bonus.pWeakProxy) )
  {
    pObject = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(pObject) )
    {
      v7 = (void *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, int))Scaleform::Memory::pGlobalHeap->GetAllocHeap)(
                     Scaleform::Memory::pGlobalHeap,
                     pObject,
                     a2);
      v8 = *a6;
      retaddr = v7;
      memset(&imageInfoArray.Data.Size, 0, 12);
      Scaleform::Render::Text::DocView::AppendHtml(
        pObject->pDocument.pObject,
        *v8,
        0xFFFFFFFF,
        0,
        (Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *)&imageInfoArray.Data.Size);
      pObject->Flags |= (unsigned int)&_sbh_sizeHeaderList;
      if ( imageInfoArray.Data.Policy.Capacity )
        Scaleform::GFx::TextField::ProcessImageTags(
          pObject,
          (Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *)&imageInfoArray.Data.Size);
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
      Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        (Scaleform::Render::Text::StyledText::HTMLImageTagInfo *)imageInfoArray.Data.Size,
        imageInfoArray.Data.Policy.Capacity);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)imageInfoArray.Data.Size);
    }
  }
}
