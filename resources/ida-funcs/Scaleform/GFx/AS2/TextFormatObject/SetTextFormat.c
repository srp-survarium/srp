void __thiscall Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::ASStringNode *psc,
        Scaleform::Render::Text::TextFormat *textFmt)
{
  __int16 v5; // bx
  char v6; // al
  bool v7; // cl
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::ObjectInterface *StringNode; // esi
  Scaleform::GFx::AS2::Value *v11; // eax
  bool v12; // dl
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::StringDH *FontList; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  bool v17; // zf
  long double v18; // st7
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // esi
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value v25; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v26; // [esp+24h] [ebp-10h] BYREF
  int FontSize; // [esp+38h] [ebp+4h]
  float v28; // [esp+38h] [ebp+4h]
  int v29; // [esp+38h] [ebp+4h]
  int ColorV_high; // [esp+38h] [ebp+4h]
  Scaleform::GFx::AS2::ObjectInterface *__that; // [esp+3Ch] [ebp+8h]

  v5 = 0;
  Scaleform::Render::Text::TextFormat::operator=(&this->mTextFormat, textFmt);
  v6 = LOBYTE(textFmt->PresentMask) >> 4;
  v25.T.Type = 1;
  if ( (v6 & 1) != 0 )
  {
    v5 = 1;
    v7 = textFmt->FormatFlags & 1;
    v26.T.Type = 2;
    v26.V.BooleanValue = v7;
    v8 = &v26;
  }
  else
  {
    v8 = &v25;
  }
  StringNode = &this->Scaleform::GFx::AS2::ObjectInterface;
  __that = StringNode;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "bold", v8);
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (textFmt->PresentMask & 0x20) != 0 )
  {
    v5 |= 2u;
    v26.V.BooleanValue = (textFmt->FormatFlags & 2) != 0;
    v26.T.Type = 2;
    v11 = &v26;
  }
  else
  {
    v11 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "italic", v11);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (textFmt->PresentMask & 0x40) != 0 )
  {
    v5 |= 4u;
    v12 = (textFmt->FormatFlags & 4) != 0;
    v26.T.Type = 2;
    v26.V.BooleanValue = v12;
    v13 = &v26;
  }
  else
  {
    v13 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "underline", v13);
  if ( (v5 & 4) != 0 )
  {
    v5 &= ~4u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (textFmt->PresentMask & 8) != 0 )
  {
    FontSize = textFmt->FontSize;
    v5 |= 8u;
    v26.T.Type = 3;
    v14 = &v26;
    v28 = (double)FontSize * 0.05000000074505806;
    v26.NV.NumberValue = v28;
  }
  else
  {
    v14 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "size", v14);
  if ( (v5 & 8) != 0 )
  {
    v5 &= ~8u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (textFmt->PresentMask & 4) != 0 )
  {
    v5 |= 0x30u;
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(textFmt);
    StringNode = (Scaleform::GFx::AS2::ObjectInterface *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                           *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*((_DWORD *)psc->pData + 5) + 12)
                                                                                               + 788),
                                                           (__m128i *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                                                           *(_DWORD *)(FontList->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode[1].__vftable;
    v26.T.Type = 5;
    v26.NV.Int32Value = (int)StringNode;
    ++StringNode[1].__vftable;
    v16 = &v26;
  }
  else
  {
    v16 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(__that, psc, "font", v16);
  if ( (v5 & 0x20) != 0 )
  {
    v5 &= ~0x20u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (v5 & 0x10) != 0 )
  {
    v5 &= ~0x10u;
    v17 = StringNode[1].__vftable-- == (Scaleform::GFx::AS2::ObjectInterface_vtbl *)1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)StringNode);
  }
  if ( (textFmt->PresentMask & 1) != 0 )
  {
    v5 |= 0x40u;
    v18 = (double)(textFmt->ColorV & 0xFFFFFF);
    v26.T.Type = 3;
    v26.NV.NumberValue = v18;
    v19 = &v26;
  }
  else
  {
    v19 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(__that, psc, "color", v19);
  if ( (v5 & 0x40) != 0 )
  {
    v5 &= ~0x40u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (textFmt->PresentMask & 2) != 0 )
  {
    v5 |= 0x80u;
    v29 = textFmt->LetterSpacing / 20;
    v26.T.Type = 3;
    v20 = &v26;
    v26.NV.NumberValue = (double)v29;
  }
  else
  {
    v20 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(__that, psc, "letterSpacing", v20);
  if ( (v5 & 0x80u) != 0 )
  {
    v5 &= ~0x80u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( SLOBYTE(textFmt->PresentMask) >= 0 )
  {
    v21 = &v25;
  }
  else
  {
    v5 |= 0x100u;
    v26.V.BooleanValue = (textFmt->FormatFlags & 8) != 0;
    v26.T.Type = 2;
    v21 = &v26;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(__that, psc, "kerning", v21);
  if ( (v5 & 0x100) != 0 )
  {
    v5 &= ~0x100u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (textFmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&textFmt->Url) )
  {
    v5 |= 0x600u;
    v22 = Scaleform::GFx::ASStringManager::CreateStringNode(
            *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*((_DWORD *)psc->pData + 5) + 12) + 788),
            (__m128i *)((textFmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
            *(_DWORD *)(textFmt->Url.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++v22->RefCount;
    v26.T.Type = 5;
    v26.NV.Int32Value = (int)v22;
    ++v22->RefCount;
    v23 = &v26;
  }
  else
  {
    v22 = (Scaleform::GFx::ASStringNode *)__that;
    v23 = &v25;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(__that, psc, "url", v23);
  if ( (v5 & 0x400) != 0 )
  {
    v5 &= ~0x400u;
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( (v5 & 0x200) != 0 )
  {
    v5 &= ~0x200u;
    v17 = v22->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  if ( *((_BYTE *)psc->pData + 52) == 1 )
  {
    if ( (textFmt->PresentMask & 1) != 0 )
    {
      ColorV_high = HIBYTE(textFmt->ColorV);
      v5 |= 0x800u;
      v26.T.Type = 3;
      v24 = &v26;
      v26.NV.NumberValue = (double)ColorV_high * 100.0 / 255.0;
    }
    else
    {
      v24 = &v25;
    }
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(__that, psc, "alpha", v24);
    if ( (v5 & 0x800) != 0 && v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  if ( v25.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v25);
}
