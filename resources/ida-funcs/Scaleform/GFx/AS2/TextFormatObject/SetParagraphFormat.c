void __thiscall Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(
        Scaleform::GFx::AS2::TextFormatObject *this,
        unsigned int psc,
        Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // edi
  char v5; // bl
  bool v6; // zf
  __m128i *v7; // edx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::ObjectInterface *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v11; // esi
  Scaleform::GFx::AS2::Value *p_v; // eax
  Scaleform::GFx::AS2::Value *v13; // eax
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
  Scaleform::GFx::AS2::Value v29; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+24h] [ebp-10h] BYREF

  v3 = paraFmt;
  v5 = 0;
  v28 = 0;
  Scaleform::Render::Text::ParagraphFormat::operator=(&this->mParagraphFormat, paraFmt);
  v6 = (v3->PresentMask & 1) == 0;
  v29.T.Type = 1;
  if ( v6 )
  {
    v11 = &this->Scaleform::GFx::AS2::ObjectInterface;
    paraFmt = (Scaleform::Render::Text::ParagraphFormat *)&this->Scaleform::GFx::AS2::ObjectInterface;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)psc,
      "align",
      &v29);
    v10 = (Scaleform::GFx::ASStringNode *)psc;
  }
  else
  {
    v7 = (__m128i *)"left";
    switch ( (v3->PresentMask >> 9) & 3 )
    {
      case 1:
        v7 = (__m128i *)"right";
        break;
      case 2:
        v7 = (__m128i *)"justify";
        break;
      case 3:
        v7 = (__m128i *)"center";
        break;
    }
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)psc + 20) + 12) + 788),
                   v7);
    ++StringNode->RefCount;
    v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
    v10 = (Scaleform::GFx::ASStringNode *)psc;
    v.T.Type = 5;
    v.NV.Int32Value = (int)StringNode;
    ++StringNode->RefCount;
    paraFmt = (Scaleform::Render::Text::ParagraphFormat *)v9;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v9, v10, "align", &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v6 = StringNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v11 = (Scaleform::GFx::AS2::ObjectInterface *)paraFmt;
  }
  if ( (v3->PresentMask & 0x80u) == 0 )
  {
    p_v = &v29;
  }
  else
  {
    v5 = 1;
    v.V.BooleanValue = (v3->PresentMask & 0x8000) != 0;
    v.T.Type = 2;
    p_v = &v;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "bullet", p_v);
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (v3->PresentMask & 2) != 0 )
  {
    psc = v3->BlockIndent;
    v5 |= 2u;
    v.T.Type = 3;
    v13 = &v;
    v.NV.NumberValue = (double)(int)psc;
  }
  else
  {
    v13 = &v29;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "blockIndent", v13);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (v3->PresentMask & 4) != 0 )
  {
    psc = v3->Indent;
    v5 |= 4u;
    v.T.Type = 3;
    v14 = &v;
    v.NV.NumberValue = (double)(int)psc;
  }
  else
  {
    v14 = &v29;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "indent", v14);
  if ( (v5 & 4) != 0 )
  {
    v5 &= ~4u;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (v3->PresentMask & 8) != 0 )
  {
    psc = v3->Leading;
    v5 |= 8u;
    v.T.Type = 3;
    v15 = &v;
    v.NV.NumberValue = (double)(int)psc;
  }
  else
  {
    v15 = &v29;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "leading", v15);
  if ( (v5 & 8) != 0 )
  {
    v5 &= ~8u;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (v3->PresentMask & 0x10) != 0 )
  {
    psc = v3->LeftMargin;
    v5 |= 0x10u;
    v.T.Type = 3;
    v16 = &v;
    v.NV.NumberValue = (double)(int)psc;
  }
  else
  {
    v16 = &v29;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "leftMargin", v16);
  if ( (v5 & 0x10) != 0 )
  {
    v5 &= ~0x10u;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (v3->PresentMask & 0x20) != 0 )
  {
    psc = v3->RightMargin;
    v5 |= 0x20u;
    v.T.Type = 3;
    v17 = &v;
    v.NV.NumberValue = (double)(int)psc;
  }
  else
  {
    v17 = &v29;
  }
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "rightMargin", v17);
  if ( (v5 & 0x20) != 0 && v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( (v3->PresentMask & 0x40) != 0 )
  {
    v18 = 0;
    psc = 0;
    TabStops = Scaleform::Render::Text::ParagraphFormat::GetTabStops(v3, &psc);
    v20 = (Scaleform::GFx::AS2::ArrayObject *)(*(int (__thiscall **)(_DWORD, int, _DWORD))(**((_DWORD **)v10->pData + 6)
                                                                                         + 40))(
                                                *((_DWORD *)v10->pData + 6),
                                                80,
                                                0);
    if ( v20 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v20, (Scaleform::GFx::AS2::ASStringContext *)v10);
      v18 = v21;
    }
    Scaleform::GFx::AS2::ArrayObject::Resize(v18, psc);
    for ( i = 0; i < psc; ++i )
    {
      v23 = (double)TabStops[i];
      v.T.Type = 3;
      v.NV.NumberValue = v23;
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
        Scaleform::GFx::AS2::Value::operator=(v18->Elements.Data.Data[i], &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
      }
    }
    Scaleform::GFx::AS2::Value::Value(&v, v18);
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)paraFmt,
      v10,
      "tabStops",
      v26);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, v10, "tabStops", &v29);
  }
  if ( v29.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v29);
}
