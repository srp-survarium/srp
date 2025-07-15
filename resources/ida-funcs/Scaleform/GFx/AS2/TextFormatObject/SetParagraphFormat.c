void __thiscall Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(
        Scaleform::GFx::AS2::TextFormatObject *this,
        signed int psc,
        Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // edi
  char v5; // bl
  bool v6; // zf
  char *v7; // edx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::ObjectInterface *v9; // ecx
  Scaleform::GFx::AS2::ASStringContext *v10; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v11; // esi
  Scaleform::GFx::AS2::Value *p_nullVal; // eax
  Scaleform::GFx::AS2::Value *p_val; // eax
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::AS2::ArrayObject *v18; // esi
  unsigned int *TabStops; // ebx
  Scaleform::GFx::AS2::ArrayObject *v20; // eax
  Scaleform::GFx::AS2::ArrayObject *v21; // eax
  int i; // edi
  long double v23; // st7
  Scaleform::GFx::AS2::Value **Data; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  const Scaleform::GFx::AS2::Value *v26; // eax
  unsigned int RefCount; // eax
  int v28; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value nullVal; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+24h] [ebp-10h] BYREF

  v3 = paraFmt;
  v5 = 0;
  v28 = 0;
  Scaleform::Render::Text::ParagraphFormat::operator=(&this->mParagraphFormat, paraFmt);
  v6 = (v3->PresentMask & 1) == 0;
  nullVal.T.Type = 1;
  if ( v6 )
  {
    v11 = &this->Scaleform::GFx::AS2::ObjectInterface;
    paraFmt = (Scaleform::Render::Text::ParagraphFormat *)&this->Scaleform::GFx::AS2::ObjectInterface;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)psc,
      "align",
      &nullVal);
    v10 = (Scaleform::GFx::AS2::ASStringContext *)psc;
  }
  else
  {
    v7 = "left";
    switch ( (v3->PresentMask >> 9) & 3 )
    {
      case 1:
        v7 = "right";
        break;
      case 2:
        v7 = "justify";
        break;
      case 3:
        v7 = "center";
        break;
    }
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)psc + 20) + 12) + 788),
                   v7);
    ++StringNode->RefCount;
    v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
    v10 = (Scaleform::GFx::AS2::ASStringContext *)psc;
    val.T.Type = 5;
    val.NV.Int32Value = (int)StringNode;
    ++StringNode->RefCount;
    paraFmt = (Scaleform::Render::Text::ParagraphFormat *)v9;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v9, v10, "align", &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    v6 = StringNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v11 = (Scaleform::GFx::AS2::ObjectInterface *)paraFmt;
  }
  if ( (v3->PresentMask & 0x80u) == 0 )
  {
    p_nullVal = &nullVal;
  }
  else
  {
    v5 = 1;
    val.V.BooleanValue = (v3->PresentMask & 0x8000) != 0;
    val.T.Type = 2;
    p_nullVal = &val;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "bullet", p_nullVal);
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (v3->PresentMask & 2) != 0 )
  {
    psc = v3->BlockIndent;
    v5 |= 2u;
    val.T.Type = 3;
    p_val = &val;
    val.NV.NumberValue = (double)psc;
  }
  else
  {
    p_val = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "blockIndent", p_val);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (v3->PresentMask & 4) != 0 )
  {
    psc = v3->Indent;
    v5 |= 4u;
    val.T.Type = 3;
    v14 = &val;
    val.NV.NumberValue = (double)psc;
  }
  else
  {
    v14 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "indent", v14);
  if ( (v5 & 4) != 0 )
  {
    v5 &= ~4u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (v3->PresentMask & 8) != 0 )
  {
    psc = v3->Leading;
    v5 |= 8u;
    val.T.Type = 3;
    v15 = &val;
    val.NV.NumberValue = (double)psc;
  }
  else
  {
    v15 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "leading", v15);
  if ( (v5 & 8) != 0 )
  {
    v5 &= ~8u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (v3->PresentMask & 0x10) != 0 )
  {
    psc = v3->LeftMargin;
    v5 |= 0x10u;
    val.T.Type = 3;
    v16 = &val;
    val.NV.NumberValue = (double)psc;
  }
  else
  {
    v16 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "leftMargin", v16);
  if ( (v5 & 0x10) != 0 )
  {
    v5 &= ~0x10u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (v3->PresentMask & 0x20) != 0 )
  {
    psc = v3->RightMargin;
    v5 |= 0x20u;
    val.T.Type = 3;
    v17 = &val;
    val.NV.NumberValue = (double)psc;
  }
  else
  {
    v17 = &nullVal;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "rightMargin", v17);
  if ( (v5 & 0x20) != 0 && val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  if ( (v3->PresentMask & 0x40) != 0 )
  {
    v18 = 0;
    psc = 0;
    TabStops = Scaleform::Render::Text::ParagraphFormat::GetTabStops(v3, (unsigned int *)&psc);
    v20 = (Scaleform::GFx::AS2::ArrayObject *)v10->pContext->pHeap->Alloc(v10->pContext->pHeap, 80u, 0);
    if ( v20 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v20, v10);
      v18 = v21;
    }
    Scaleform::GFx::AS2::ArrayObject::Resize(v18, psc);
    for ( i = 0; i < (unsigned int)psc; ++i )
    {
      v23 = (double)TabStops[i];
      val.T.Type = 3;
      val.NV.NumberValue = v23;
      if ( i >= 0 && i < (signed int)v18->Elements.Data.Size )
      {
        Data = v18->Elements.Data.Data;
        v18->LengthValueOverriden = 0;
        if ( !Data[i] )
        {
          v28 = 323;
          v25 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                v18,
                                                16,
                                                &v28);
          if ( v25 )
            v25->T.Type = 0;
          else
            v25 = 0;
          v18->Elements.Data.Data[i] = v25;
        }
        Scaleform::GFx::AS2::Value::operator=(v18->Elements.Data.Data[i], &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
    }
    Scaleform::GFx::AS2::Value::Value(&val, v18);
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)paraFmt,
      v10,
      "tabStops",
      v26);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "tabStops", &nullVal);
  }
  if ( nullVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&nullVal);
}
