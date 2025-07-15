void __userpurge Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::setStyle(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this@<ecx>,
        Scaleform::GFx::ASString a2@<ebx>,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::String styleName,
        const Scaleform::GFx::AS3::Value *styleObject)
{
  const __m128i ***pData; // ebp
  Scaleform::GFx::ASStringNode *Size; // edx
  unsigned int v8; // ecx
  Scaleform::GFx::Text::StyleManager *p_CSS; // ecx
  Scaleform::String *VInt; // esi
  void *v11; // esi
  const char *v12; // [esp-Ch] [ebp-18h]

  pData = (const __m128i ***)styleName.pData;
  Size = (Scaleform::GFx::ASStringNode *)styleName.pData->Size;
  if ( *(_DWORD *)(*(_DWORD *)styleName.HeapTypeBits + 20) )
  {
    v8 = styleObject->Flags & 0x1F;
    if ( v8 - 12 > 3 || styleObject->value.VS._1.VInt )
    {
      if ( v8 - 12 <= 3 )
      {
        VInt = (Scaleform::String *)styleObject->value.VS._1.VInt;
        Scaleform::String::String(&styleName);
        Scaleform::String::AppendString(&styleName, **pData, 0xFFFFFFFF);
        Scaleform::String::AppendChar(&styleName, 0x7Bu);
        Scaleform::GFx::AS3::CSSStringBuilder::Process((int)pData, &styleName, VInt, a2);
        Scaleform::String::AppendChar(&styleName, 0x7Du);
        Scaleform::GFx::Text::StyleManager::ParseCSS(
          &this->CSS,
          (const char *)((styleName.HeapTypeBits & 0xFFFFFFFC) + 8),
          *(_DWORD *)(styleName.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        v11 = (void *)(styleName.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((styleName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      }
    }
    else
    {
      p_CSS = &this->CSS;
      v12 = Size->pData;
      if ( *Size->pData == 46 )
        Scaleform::GFx::Text::StyleManager::ClearStyle(p_CSS, CSS_Class, v12, 0xFFFFFFFF);
      else
        Scaleform::GFx::Text::StyleManager::ClearStyle(p_CSS, CSS_Tag, v12, 0xFFFFFFFF);
    }
  }
}
