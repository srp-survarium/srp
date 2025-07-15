void __thiscall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::styleNamesGet(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebx
  const Scaleform::Render::GlyphCacheParams *Styles; // eax
  unsigned int TextureWidth; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  _DWORD *v8; // ecx
  const Scaleform::Render::GlyphCacheParams *v9; // ebp
  signed int v10; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v12; // eax
  _DWORD *v13; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int RefCount; // eax
  void *v17; // esi
  Scaleform::String temp; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::ASString v; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> array; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Render::GlyphCache *p_CSS; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value v22; // [esp+20h] [ebp-10h] BYREF

  Scaleform::GFx::AS3::VM::MakeArray(this->pTraits.pObject->pVM, &array);
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  Scaleform::String::String(&temp);
  p_CSS = (Scaleform::Render::GlyphCache *)&this->CSS;
  Styles = Scaleform::GFx::Text::StyleManager::GetStyles((Scaleform::Render::GlyphCache *)&this->CSS);
  TextureWidth = Styles->TextureWidth;
  if ( Styles->TextureWidth )
  {
    v7 = *(_DWORD *)(TextureWidth + 4);
    v6 = 0;
    v8 = (_DWORD *)(TextureWidth + 8);
    do
    {
      if ( *v8 != -2 )
        break;
      ++v6;
      v8 += 5;
    }
    while ( v6 <= v7 );
  }
  else
  {
    Styles = 0;
    v6 = 0;
  }
  v9 = Styles;
  v10 = v6;
  while ( 1 )
  {
    Scaleform::GFx::Text::StyleManager::GetStyles(p_CSS);
    if ( !v9 || !v9->TextureWidth || v10 > *(_DWORD *)(v9->TextureWidth + 4) )
      break;
    Scaleform::String::Clear(&temp);
    if ( *(_DWORD *)(20 * v10 + v9->TextureWidth + 12) == 1 )
      Scaleform::String::AppendChar(&temp, 0x2Eu);
    Scaleform::String::operator+=(&temp, (const Scaleform::String *)(20 * v10 + v9->TextureWidth + 16));
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                StringManagerRef->pStringManager,
                (char *)((temp.HeapTypeBits & 0xFFFFFFFC) + 8),
                *(_DWORD *)(temp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&v22, &v);
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&array.pV->SA, &v22);
    if ( (v22.Flags & 0x1F) > 9 )
    {
      if ( (v22.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v22);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
    }
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = *(_DWORD *)(v9->TextureWidth + 4);
    if ( v10 <= (int)v12 && ++v10 <= v12 )
    {
      v13 = (_DWORD *)(v9->TextureWidth + 20 * v10 + 8);
      do
      {
        if ( *v13 != -2 )
          break;
        ++v10;
        v13 += 5;
      }
      while ( v10 <= v12 );
    }
  }
  pObject = result->pObject;
  pV = array.pV;
  if ( array.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  v17 = (void *)(temp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((temp.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
}
