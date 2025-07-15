void __thiscall Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::Render::Text::TextFormat *textFmt)
{
  __int16 v5; // bx
  char v6; // al
  bool v7; // cl
  Scaleform::GFx::AS2::Value *p_val; // eax
  Scaleform::GFx::AS2::ObjectInterface *StringNode; // esi
  Scaleform::GFx::AS2::Value *p_nullVal; // eax
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
  Scaleform::GFx::AS2::Value nullVal; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+24h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::ASStringContext *psca; // [esp+38h] [ebp+4h]
  float pscb; // [esp+38h] [ebp+4h]
  int pscc; // [esp+38h] [ebp+4h]
  Scaleform::GFx::AS2::ASStringContext *pscd; // [esp+38h] [ebp+4h]
  Scaleform::GFx::AS2::ObjectInterface *textFmta; // [esp+3Ch] [ebp+8h]

  v5 = 0;
  Scaleform::Render::Text::TextFormat::operator=(&this->mTextFormat, textFmt);
  v6 = LOBYTE(textFmt->PresentMask) >> 4;
  nullVal.T.Type = 1;
  if ( (v6 & 1) != 0 )
  {
    v5 = 1;
    v7 = textFmt->FormatFlags & 1;
    val.T.Type = 2;
    val.V.BooleanValue = v7;
    p_val = &val;
  }
  else
  {
    p_val = &nullVal;
  }
  StringNode = &this->Scaleform::GFx::AS2::ObjectInterface;
  textFmta = StringNode;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "bold", p_val);
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (textFmt->PresentMask & 0x20) != 0 )
  {
    v5 |= 2u;
    val.V.BooleanValue = (textFmt->FormatFlags & 2) != 0;
    val.T.Type = 2;
    p_nullVal = &val;
  }
  else
  {
    p_nullVal = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "italic", p_nullVal);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (textFmt->PresentMask & 0x40) != 0 )
  {
    v5 |= 4u;
    v12 = (textFmt->FormatFlags & 4) != 0;
    val.T.Type = 2;
    val.V.BooleanValue = v12;
    v13 = &val;
  }
  else
  {
    v13 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "underline", v13);
  if ( (v5 & 4) != 0 )
  {
    v5 &= ~4u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (textFmt->PresentMask & 8) != 0 )
  {
    psca = (Scaleform::GFx::AS2::ASStringContext *)textFmt->FontSize;
    v5 |= 8u;
    val.T.Type = 3;
    v14 = &val;
    pscb = (double)(int)psca * 0.05000000074505806;
    val.NV.NumberValue = pscb;
  }
  else
  {
    v14 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(StringNode, psc, "size", v14);
  if ( (v5 & 8) != 0 )
  {
    v5 &= ~8u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (textFmt->PresentMask & 4) != 0 )
  {
    v5 |= 0x30u;
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(textFmt);
    StringNode = (Scaleform::GFx::AS2::ObjectInterface *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                           (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                           (char *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                                                           *(_DWORD *)(FontList->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode[1].__vftable;
    val.T.Type = 5;
    val.NV.Int32Value = (int)StringNode;
    ++StringNode[1].__vftable;
    v16 = &val;
  }
  else
  {
    v16 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(textFmta, psc, "font", v16);
  if ( (v5 & 0x20) != 0 )
  {
    v5 &= ~0x20u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
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
    v18 = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & textFmt->ColorV);
    val.T.Type = 3;
    val.NV.NumberValue = v18;
    v19 = &val;
  }
  else
  {
    v19 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(textFmta, psc, (char *)&stru_9555EC, v19);
  if ( (v5 & 0x40) != 0 )
  {
    v5 &= ~0x40u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (textFmt->PresentMask & 2) != 0 )
  {
    v5 |= 0x80u;
    pscc = textFmt->LetterSpacing / 20;
    val.T.Type = 3;
    v20 = &val;
    val.NV.NumberValue = (double)pscc;
  }
  else
  {
    v20 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(textFmta, psc, "letterSpacing", v20);
  if ( (v5 & 0x80u) != 0 )
  {
    v5 &= ~0x80u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( SLOBYTE(textFmt->PresentMask) >= 0 )
  {
    v21 = &nullVal;
  }
  else
  {
    v5 |= 0x100u;
    val.V.BooleanValue = (textFmt->FormatFlags & 8) != 0;
    val.T.Type = 2;
    v21 = &val;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(textFmta, psc, "kerning", v21);
  if ( (v5 & 0x100) != 0 )
  {
    v5 &= ~0x100u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (textFmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&textFmt->Url) )
  {
    v5 |= 0x600u;
    v22 = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            (char *)((textFmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
            *(_DWORD *)(textFmt->Url.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++v22->RefCount;
    val.T.Type = 5;
    val.NV.Int32Value = (int)v22;
    ++v22->RefCount;
    v23 = &val;
  }
  else
  {
    v22 = (Scaleform::GFx::ASStringNode *)textFmta;
    v23 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(textFmta, psc, "url", v23);
  if ( (v5 & 0x400) != 0 )
  {
    v5 &= ~0x400u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (v5 & 0x200) != 0 )
  {
    v5 &= ~0x200u;
    v17 = v22->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  if ( psc->pContext->GFxExtensions.Value == 1 )
  {
    if ( (textFmt->PresentMask & 1) != 0 )
    {
      pscd = (Scaleform::GFx::AS2::ASStringContext *)HIBYTE(textFmt->ColorV);
      v5 |= 0x800u;
      val.T.Type = 3;
      v24 = &val;
      val.NV.NumberValue = (double)(int)pscd * 100.0 / 255.0;
    }
    else
    {
      v24 = &nullVal;
    }
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(textFmta, psc, "alpha", v24);
    if ( (v5 & 0x800) != 0 && val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( nullVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&nullVal);
}
