void __cdecl Scaleform::GFx::AS2::StyleSheetProto::GetStyle(Scaleform::Render::Color fn)
{
  const Scaleform::GFx::AS2::FnCall *Raw; // ebp
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // ebp
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  unsigned int Size; // eax
  int v8; // edi
  Scaleform::GFx::AS2::Value *Result; // ebp
  bool v10; // zf
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::Object *v13; // eax
  int p_StringContext; // esi
  unsigned __int8 Red; // di
  unsigned __int8 Green; // di
  unsigned __int8 Blue; // di
  Scaleform::GFx::ASStringNode *StringNode; // edi
  int v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::StringDH *FontList; // eax
  Scaleform::GFx::ASStringNode *v22; // edi
  int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  int v25; // edx
  long double v26; // st7
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringManager *v28; // ecx
  Scaleform::String::DataDesc *v29; // eax
  int v30; // edx
  Scaleform::GFx::ASStringNode *v31; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::String::DataDesc *pData; // ecx
  Scaleform::String::DataDesc *v34; // eax
  Scaleform::GFx::ASStringManager *v35; // ecx
  Scaleform::String::DataDesc *v36; // eax
  int v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::String::DataDesc *v39; // ecx
  Scaleform::String::DataDesc *v40; // ecx
  Scaleform::GFx::ASStringManager *v41; // ecx
  Scaleform::String::DataDesc *v42; // eax
  int v43; // ecx
  Scaleform::GFx::ASStringNode *v44; // eax
  Scaleform::String::DataDesc *v45; // ecx
  Scaleform::String::DataDesc *v46; // ecx
  int v47; // ecx
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::String::DataDesc *p_mParagraphFormat; // eax
  char v50; // cl
  int v51; // eax
  long double v52; // st7
  Scaleform::GFx::ASStringNode *v53; // eax
  int v54; // ecx
  long double v55; // st7
  Scaleform::GFx::ASStringNode *v56; // eax
  Scaleform::String::DataDesc *v57; // edi
  Scaleform::GFx::ASStringNode *v58; // eax
  int v59; // eax
  Scaleform::GFx::ASStringNode *v60; // eax
  Scaleform::GFx::ASStringNode *v61; // ecx
  Scaleform::GFx::ASStringNode *v62; // ecx
  Scaleform::GFx::ASStringNode *v63; // ecx
  Scaleform::GFx::ASStringNode *v64; // ecx
  Scaleform::GFx::ASStringManager *v65; // ecx
  Scaleform::GFx::ASStringNode *v66; // eax
  int v67; // edx
  Scaleform::GFx::ASStringNode *v68; // eax
  Scaleform::GFx::ASStringNode *v69; // ecx
  Scaleform::GFx::ASStringNode *v70; // ecx
  int v71; // eax
  long double v72; // st7
  Scaleform::GFx::ASStringNode *v73; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v75; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp+B0h] [ebp-48h]
  __int16 v77; // [esp+CCh] [ebp-2Ch]
  __int16 v78; // [esp+CCh] [ebp-2Ch]
  const Scaleform::Render::Text::Style *pstyle; // [esp+D0h] [ebp-28h]
  Scaleform::GFx::AS2::Object *obj; // [esp+D4h] [ebp-24h]
  Scaleform::String colorStr; // [esp+D8h] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *v82; // [esp+DCh] [ebp-1Ch] BYREF
  Scaleform::GFx::ASStringNode *v83; // [esp+E0h] [ebp-18h] BYREF
  Scaleform::GFx::ASString stylename; // [esp+E4h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v85; // [esp+E8h] [ebp-10h] BYREF

  Raw = (const Scaleform::GFx::AS2::FnCall *)fn.Raw;
  v77 = 0;
  if ( *(_DWORD *)(*(_DWORD *)&fn + 8)
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&fn + 8) + 8))(*(_DWORD *)(*(_DWORD *)&fn + 8)) == 31 )
  {
    ThisPtr = Raw->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        if ( Raw->NArgs >= 1 )
        {
          Env = Raw->Env;
          v5 = Scaleform::GFx::AS2::FnCall::Arg(Raw, 0);
          Scaleform::GFx::AS2::Value::ToStringImpl(v5, &stylename, Env, -1, 0);
          pNode = stylename.pNode;
          Size = stylename.pNode->Size;
          if ( Size && *stylename.pNode->pData == 46 )
          {
            v8 = ((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, int, const char *, unsigned int))p_pProto[13].pObject->RootIndex)(
                   &p_pProto[13],
                   1,
                   stylename.pNode->pData + 1,
                   Size - 1);
            pstyle = (const Scaleform::Render::Text::Style *)v8;
          }
          else
          {
            v8 = ((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, _DWORD, const char *, unsigned int))p_pProto[13].pObject->RootIndex)(
                   &p_pProto[13],
                   0,
                   stylename.pNode->pData,
                   stylename.pNode->Size);
            pstyle = (const Scaleform::Render::Text::Style *)v8;
          }
          if ( v8 )
          {
            pHeap = Raw->Env->StringContext.pContext->pHeap;
            v12 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
            if ( v12 )
            {
              Scaleform::GFx::AS2::Object::Object(v12, Raw->Env);
              obj = v13;
            }
            else
            {
              obj = 0;
            }
            p_StringContext = (int)&Raw->Env->StringContext;
            if ( (*(_BYTE *)(v8 + 38) & 1) != 0 )
            {
              Scaleform::String::String(&colorStr);
              Scaleform::String::AppendChar(&colorStr, 0x23u);
              fn = (Scaleform::Render::Color)pstyle->mTextFormat.ColorV;
              Red = fn.Channels.Red;
              Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[fn.Channels.Red >> 4]);
              Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[Red & 0xF]);
              Green = fn.Channels.Green;
              Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[fn.Channels.Green >> 4]);
              Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[Green & 0xF]);
              Blue = fn.Channels.Blue;
              Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[fn.Channels.Blue >> 4]);
              Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[Blue & 0xF]);
              StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext
                                                                                         + 20)
                                                                             + 12)
                                                                 + 788),
                             (char *)((colorStr.HeapTypeBits & 0xFFFFFFFC) + 8),
                             *(_DWORD *)(colorStr.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++StringNode->RefCount;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)StringNode;
              ++StringNode->RefCount;
              v19 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v19 + 20) + 12) + 788),
                      (char *)&stru_9555EC);
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v20 = v82;
              --v82->RefCount;
              if ( !v20->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v20);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              v10 = StringNode->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
              Scaleform::String::~String(&colorStr);
              v8 = (int)pstyle;
            }
            if ( (*(_BYTE *)(v8 + 38) & 4) != 0 )
            {
              FontList = Scaleform::Render::Text::TextFormat::GetFontList(&pstyle->mTextFormat);
              v22 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                          + 788),
                      (char *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                      *(_DWORD *)(FontList->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++v22->RefCount;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v22;
              ++v22->RefCount;
              v23 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v23 + 20) + 12) + 788),
                      "fontFamily");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v24 = v82;
              --v82->RefCount;
              if ( !v24->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v24);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              v10 = v22->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            }
            if ( (pstyle->mTextFormat.PresentMask & 8) != 0 )
            {
              v25 = *(_DWORD *)p_StringContext;
              fn = (Scaleform::Render::Color)pstyle->mTextFormat.FontSize;
              v85.T.Type = 3;
              *(float *)&fn.Raw = (double)(int)fn.Raw * 0.05000000074505806;
              v26 = *(float *)&fn.Raw;
              fn.Channels.Blue = 0;
              v85.NV.NumberValue = v26;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v25 + 20) + 12) + 788),
                      "fontSize");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v27 = v82;
              --v82->RefCount;
              if ( !v27->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v27);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
            }
            if ( (pstyle->mTextFormat.PresentMask & 0x20) != 0 )
            {
              v28 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (pstyle->mTextFormat.FormatFlags & 2) != 0 )
              {
                v77 = 1;
                v29 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(v28, "italic");
              }
              else
              {
                v77 = 2;
                v29 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(v28, "normal");
              }
              ++v29[1].Size;
              colorStr.pData = v29;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v29;
              ++v29[1].Size;
              v30 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v30 + 20) + 12) + 788),
                      "fontStyle");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v31 = v82;
              p_RefCount = &v82->RefCount;
              --v82->RefCount;
              if ( !*p_RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v31);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              if ( (v77 & 2) != 0 )
              {
                pData = colorStr.pData;
                v77 &= ~2u;
                v10 = colorStr.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pData);
              }
              if ( (v77 & 1) != 0 )
              {
                v34 = colorStr.pData;
                v77 &= ~1u;
                v10 = colorStr.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v34);
              }
            }
            if ( (pstyle->mTextFormat.PresentMask & 0x10) != 0 )
            {
              v35 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (pstyle->mTextFormat.FormatFlags & 1) != 0 )
              {
                v77 |= 4u;
                v36 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(v35, "bold");
              }
              else
              {
                v77 |= 8u;
                v36 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(v35, "normal");
              }
              ++v36[1].Size;
              colorStr.pData = v36;
              v85.NV.Int32Value = (int)v36;
              v85.T.Type = 5;
              ++v36[1].Size;
              v37 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v37 + 20) + 12) + 788),
                      "fontWeight");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v38 = v82;
              --v82->RefCount;
              if ( !v38->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v38);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              if ( (v77 & 8) != 0 )
              {
                v39 = colorStr.pData;
                v77 &= ~8u;
                v10 = colorStr.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v39);
              }
              if ( (v77 & 4) != 0 )
              {
                v40 = colorStr.pData;
                v77 &= ~4u;
                v10 = colorStr.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v40);
              }
            }
            if ( SLOBYTE(pstyle->mTextFormat.PresentMask) < 0 )
            {
              v41 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (pstyle->mTextFormat.FormatFlags & 8) != 0 )
              {
                v77 |= 0x10u;
                v42 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v41,
                                                       (char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1]);
              }
              else
              {
                v77 |= 0x20u;
                v42 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v41,
                                                       (char *)&stru_95AF78.m_key_bindings[6]);
              }
              ++v42[1].Size;
              colorStr.pData = v42;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v42;
              ++v42[1].Size;
              v43 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + 12) + 788),
                      "kerning");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v44 = v82;
              --v82->RefCount;
              if ( !v44->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v44);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              if ( (v77 & 0x20) != 0 )
              {
                v45 = colorStr.pData;
                v77 &= ~0x20u;
                v10 = colorStr.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v45);
              }
              if ( (v77 & 0x10) != 0 )
              {
                v46 = colorStr.pData;
                v77 &= ~0x10u;
                v10 = colorStr.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v46);
              }
            }
            if ( (pstyle->mTextFormat.PresentMask & 2) != 0 )
            {
              v85.T.Type = 3;
              v85.NV.NumberValue = Scaleform::Render::Text::TextFormat::GetLetterSpacing(&pstyle->mTextFormat);
              v47 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v47 + 20) + 12) + 788),
                      "letterSpacing");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v48 = v82;
              --v82->RefCount;
              if ( !v48->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v48);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
            }
            p_mParagraphFormat = (Scaleform::String::DataDesc *)&pstyle->mParagraphFormat;
            v50 = LOBYTE(pstyle->mParagraphFormat.PresentMask) >> 4;
            colorStr.pData = (Scaleform::String::DataDesc *)&pstyle->mParagraphFormat;
            if ( (v50 & 1) != 0 )
            {
              v51 = *(_DWORD *)p_StringContext;
              fn = (Scaleform::Render::Color)pstyle->mParagraphFormat.LeftMargin;
              v85.T.Type = 3;
              v52 = (double)(int)fn.Raw;
              fn.Channels.Blue = 0;
              v85.NV.NumberValue = v52;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v51 + 20) + 12) + 788),
                      "marginLeft");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v53 = v82;
              --v82->RefCount;
              if ( !v53->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v53);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              p_mParagraphFormat = colorStr.pData;
            }
            if ( (p_mParagraphFormat[1].RefCount & 0x200000) != 0 )
            {
              v54 = *(_DWORD *)p_StringContext;
              fn = (Scaleform::Render::Color)LOWORD(colorStr.pData[1].RefCount);
              v85.T.Type = 3;
              v55 = (double)(int)fn.Raw;
              fn.Channels.Blue = 0;
              v85.NV.NumberValue = v55;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v54 + 20) + 12) + 788),
                      "marginRight");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v56 = v82;
              --v82->RefCount;
              if ( !v56->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v56);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
            }
            v57 = colorStr.pData;
            if ( (colorStr.pData[1].RefCount & 0x10000) != 0 )
            {
              if ( (unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsLeftAlignment((Scaleform::Render::Text::ParagraphFormat *)colorStr.pData) )
              {
                v77 |= 0x40u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        "left");
              }
              else if ( (unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsCenterAlignment((Scaleform::Render::Text::ParagraphFormat *)v57) )
              {
                v77 |= 0x80u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        "center");
              }
              else if ( (unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsRightAlignment((Scaleform::Render::Text::ParagraphFormat *)v57) )
              {
                v77 |= 0x100u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        "right");
              }
              else
              {
                v77 |= 0x200u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        "justify");
              }
              ++v58->RefCount;
              v83 = v58;
              v85.NV.Int32Value = (int)v58;
              v85.T.Type = 5;
              ++v58->RefCount;
              v59 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v59 + 20) + 12) + 788),
                      "textAlign");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v60 = v82;
              --v82->RefCount;
              if ( !v60->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v60);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              if ( (v77 & 0x200) != 0 )
              {
                v61 = v83;
                v77 &= ~0x200u;
                v10 = v83->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v61);
              }
              if ( (v77 & 0x100) != 0 )
              {
                v62 = v83;
                v77 &= ~0x100u;
                v10 = v83->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v62);
              }
              if ( (v77 & 0x80u) != 0 )
              {
                v63 = v83;
                v77 &= ~0x80u;
                v10 = v83->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v63);
              }
              if ( (v77 & 0x40) != 0 )
              {
                v64 = v83;
                v77 &= ~0x40u;
                v10 = v83->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v64);
              }
            }
            if ( (pstyle->mTextFormat.PresentMask & 0x40) != 0 )
            {
              v65 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (pstyle->mTextFormat.FormatFlags & 4) != 0 )
              {
                v78 = v77 | 0x400;
                v66 = Scaleform::GFx::ASStringManager::CreateStringNode(v65, "underline");
              }
              else
              {
                v78 = v77 | 0x800;
                v66 = Scaleform::GFx::ASStringManager::CreateStringNode(v65, "none");
              }
              ++v66->RefCount;
              v82 = v66;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v66;
              ++v66->RefCount;
              v67 = *(_DWORD *)p_StringContext;
              fn.Channels.Blue = 0;
              v83 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v67 + 20) + 12) + 788),
                      "textDecoration");
              ++v83->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v83,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v68 = v83;
              --v83->RefCount;
              if ( !v68->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v68);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              if ( (v78 & 0x800) != 0 )
              {
                v69 = v82;
                v78 &= ~0x800u;
                v10 = v82->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v69);
              }
              if ( (v78 & 0x400) != 0 )
              {
                v70 = v82;
                v10 = v82->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v70);
              }
            }
            if ( (colorStr.pData[1].RefCount & 0x40000) != 0 )
            {
              v71 = *(_DWORD *)p_StringContext;
              fn = (Scaleform::Render::Color)*(__int16 *)&colorStr.pData->Data[2];
              v85.T.Type = 3;
              v72 = (double)(int)fn.Raw;
              fn.Channels.Blue = 0;
              v85.NV.NumberValue = v72;
              v83 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v71 + 20) + 12) + 788),
                      "textIndent");
              ++v83->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                Raw->Env,
                (const Scaleform::GFx::ASString *)&v83,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v73 = v83;
              --v83->RefCount;
              if ( !v73->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v73);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
            }
            Scaleform::GFx::AS2::Value::SetAsObject(Raw->Result, obj);
            if ( obj )
            {
              RefCount = obj->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
              {
                obj->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(obj);
              }
            }
            v75 = stylename.pNode;
            v10 = stylename.pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v75);
          }
          else
          {
            Result = Raw->Result;
            Scaleform::GFx::AS2::Value::DropRefs(Result);
            Result->T.Type = 1;
            v10 = pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
        }
        else
        {
          v4 = Raw->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v4);
          v4->T.Type = 1;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      Raw->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "StyleSheet");
  }
}
