char __thiscall Scaleform::GFx::TextField::SetShadowStyle(Scaleform::GFx::TextField *this, __m128i *pstr)
{
  Scaleform::GFx::TextField *v2; // ebp
  Scaleform::ArrayData<Scaleform::Render::Point<float>,Scaleform::AllocatorLH<Scaleform::Render::Point<float>,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // ebx
  Scaleform::GFx::TextField::ShadowParams *v4; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  int v7; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_ShadowOffsets; // esi
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_TextOffsets; // esi
  __m128i *v10; // edi
  char v11; // al
  char v12; // al
  const __m128i *v13; // edi
  const __m128i *v14; // esi
  long double v15; // st7
  char v16; // al
  char *v17; // esi
  const __m128i *v18; // ecx
  int v19; // edi
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  int p_ShadowStyleStr; // edi
  Scaleform::GFx::ASStringNode *v23; // ecx
  bool v24; // zf
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::Point<float> val; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::TextField *v27; // [esp+14h] [ebp-20h]
  float v28; // [esp+18h] [ebp-1Ch] BYREF
  char dst[24]; // [esp+1Ch] [ebp-18h] BYREF

  v2 = this;
  p_Data = 0;
  v27 = this;
  if ( !this->pShadow )
  {
    LODWORD(v28) = 323;
    v4 = (Scaleform::GFx::TextField::ShadowParams *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      32,
                                                      &v28);
    if ( v4 )
    {
      p_EmptyStringNode = &Scaleform::GFx::InteractiveObject::GetStringManager(v2)->EmptyStringNode;
      v4->ShadowStyleStr.pNode = p_EmptyStringNode;
      ++p_EmptyStringNode->RefCount;
      v4->ShadowOffsets.Data.Data = 0;
      v4->ShadowOffsets.Data.Size = 0;
      v4->ShadowOffsets.Data.Policy.Capacity = 0;
      v4->TextOffsets.Data.Data = 0;
      v4->TextOffsets.Data.Size = 0;
      val.x = -1.7014118e38;
      v4->TextOffsets.Data.Policy.Capacity = 0;
      *(float *)&v4->ShadowColor.Raw = -1.7014118e38;
    }
    else
    {
      v4 = 0;
    }
    v2->pShadow = v4;
    if ( !v4 )
      return 0;
  }
  v7 = v2->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF;
  v2->pShadow->ShadowColor.Channels.Blue = v2->pDocument.pObject->Filter.ShadowParams.Colors[0].Channels.Blue;
  v2->pShadow->ShadowColor.Channels.Green = BYTE1(v7);
  v2->pShadow->ShadowColor.Channels.Red = BYTE2(v7);
  v2->pDocument.pObject->Filter.ShadowFlags |= 1u;
reset:
  p_ShadowOffsets = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&v2->pShadow->ShadowOffsets;
  if ( v2->pShadow->ShadowOffsets.Data.Size )
  {
    if ( (v2->pShadow->ShadowOffsets.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_ShadowOffsets->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_ShadowOffsets->Data);
        p_ShadowOffsets->Data = 0;
      }
      p_ShadowOffsets->Policy.Capacity = 0;
    }
  }
  else if ( !v2->pShadow->ShadowOffsets.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ShadowOffsets,
      p_ShadowOffsets,
      0);
  }
  p_ShadowOffsets->Size = 0;
  p_TextOffsets = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&v2->pShadow->TextOffsets;
  if ( v2->pShadow->TextOffsets.Data.Size )
  {
    if ( (v2->pShadow->TextOffsets.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_TextOffsets->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TextOffsets->Data);
        p_TextOffsets->Data = 0;
      }
      p_TextOffsets->Policy.Capacity = 0;
    }
  }
  else if ( !v2->pShadow->TextOffsets.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_TextOffsets,
      p_TextOffsets,
      0);
  }
  v10 = pstr;
  p_TextOffsets->Size = 0;
  while ( 1 )
  {
    v11 = v10->m128i_i8[0];
    if ( !v10->m128i_i8[0] )
      break;
    if ( v11 == 115 || v11 == 83 )
    {
      p_Data = &v2->pShadow->ShadowOffsets.Data;
      v10 = (__m128i *)((char *)v10 + 1);
    }
    else if ( v11 == 116 || v11 == 84 )
    {
      p_Data = &v2->pShadow->TextOffsets.Data;
      v10 = (__m128i *)((char *)v10 + 1);
    }
    else
    {
      if ( v11 != 123 || !p_Data )
        goto LABEL_46;
      v12 = v10->m128i_i8[1];
      v13 = (const __m128i *)&v10->m128i_i8[1];
      v14 = v13;
      if ( v12 )
      {
        while ( v12 != 44 )
        {
          v12 = v14->m128i_i8[1];
          v14 = (const __m128i *)((char *)v14 + 1);
          if ( !v12 )
            goto LABEL_46;
        }
      }
      if ( !v14->m128i_i8[0] )
        goto LABEL_46;
      if ( (char *)v14 - (char *)v13 > 23 )
      {
        v2 = v27;
LABEL_46:
        pstr = (__m128i *)v2->pShadow->ShadowStyleStr.pNode->pData;
        p_Data = 0;
        goto reset;
      }
      memcpy((int)dst, v13, (char *)v14 - (char *)v13);
      dst[(char *)v14 - (char *)v13] = 0;
      v15 = Scaleform::SFstrtod((int)v13, dst, 0);
      v16 = v14->m128i_i8[1];
      v17 = &v14->m128i_i8[1];
      v28 = v15 * 20.0;
      v18 = (const __m128i *)v17;
      if ( !v16 )
        goto LABEL_39;
      while ( v16 != 125 )
      {
        v16 = *++v17;
        if ( !v16 )
          goto LABEL_39;
      }
      if ( !*v17 || (v19 = v17 - (char *)v18, v17 - (char *)v18 > 23) )
      {
LABEL_39:
        v2 = v27;
        pstr = (__m128i *)v27->pShadow->ShadowStyleStr.pNode->pData;
        p_Data = 0;
        goto reset;
      }
      memcpy((int)dst, v18, v17 - (char *)v18);
      val.x = v28;
      dst[v19] = 0;
      v10 = (__m128i *)(v17 + 1);
      val.y = Scaleform::SFstrtod((int)(v17 + 1), dst, 0) * 20.0;
      Scaleform::ArrayData<Scaleform::Render::Point<float>,Scaleform::AllocatorLH<Scaleform::Render::Point<float>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        p_Data,
        &val);
      v2 = v27;
    }
  }
  if ( pstr->m128i_i8[0] )
  {
    StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(v2);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager, pstr);
    ++StringNode->RefCount;
    p_ShadowStyleStr = (int)&v2->pShadow->ShadowStyleStr;
    ++StringNode->RefCount;
    v23 = *(Scaleform::GFx::ASStringNode **)p_ShadowStyleStr;
    v24 = (*(_DWORD *)(*(_DWORD *)p_ShadowStyleStr + 12))-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    *(_DWORD *)p_ShadowStyleStr = StringNode;
    v24 = StringNode->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  return 1;
}
