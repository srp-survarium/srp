void __cdecl Scaleform::GFx::AS2::StyleSheetProto::GetStyle(int fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // ebp
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
  char v15; // di
  char v16; // di
  char v17; // di
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
  Scaleform::String::DataDesc *v49; // eax
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
  int v79; // [esp+D0h] [ebp-28h]
  Scaleform::GFx::AS2::Object *obj; // [esp+D4h] [ebp-24h]
  Scaleform::String v81; // [esp+D8h] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *v82; // [esp+DCh] [ebp-1Ch] BYREF
  Scaleform::GFx::ASStringNode *v83; // [esp+E0h] [ebp-18h] BYREF
  Scaleform::GFx::ASString v84; // [esp+E4h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v85; // [esp+E8h] [ebp-10h] BYREF

  v1 = (Scaleform::GFx::AS2::FnCall *)fn;
  v77 = 0;
  if ( *(_DWORD *)(fn + 8) && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fn + 8) + 8))(*(_DWORD *)(fn + 8)) == 31 )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        if ( v1->NArgs >= 1 )
        {
          Env = v1->Env;
          v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
          Scaleform::GFx::AS2::Value::ToStringImpl(v5, &v84, Env, -1, 0);
          pNode = v84.pNode;
          Size = v84.pNode->Size;
          if ( Size && *v84.pNode->pData == 46 )
          {
            v8 = ((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, int, const char *, unsigned int))p_pProto[13].pObject->RootIndex)(
                   &p_pProto[13],
                   1,
                   v84.pNode->pData + 1,
                   Size - 1);
            v79 = v8;
          }
          else
          {
            v8 = ((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, _DWORD, const char *, unsigned int))p_pProto[13].pObject->RootIndex)(
                   &p_pProto[13],
                   0,
                   v84.pNode->pData,
                   v84.pNode->Size);
            v79 = v8;
          }
          if ( v8 )
          {
            pHeap = v1->Env->StringContext.pContext->pHeap;
            v12 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
            if ( v12 )
            {
              Scaleform::GFx::AS2::Object::Object(v12, v1->Env);
              obj = v13;
            }
            else
            {
              obj = 0;
            }
            p_StringContext = (int)&v1->Env->StringContext;
            if ( (*(_BYTE *)(v8 + 38) & 1) != 0 )
            {
              Scaleform::String::String(&v81);
              Scaleform::String::AppendChar(&v81, 0x23u);
              fn = *(int *)(v79 + 28);
              v15 = BYTE2(fn);
              Scaleform::String::AppendChar(&v81, a0123456789abcd_2[BYTE2(fn) >> 4]);
              Scaleform::String::AppendChar(&v81, a0123456789abcd_2[v15 & 0xF]);
              v16 = BYTE1(fn);
              Scaleform::String::AppendChar(&v81, a0123456789abcd_2[BYTE1(fn) >> 4]);
              Scaleform::String::AppendChar(&v81, a0123456789abcd_2[v16 & 0xF]);
              v17 = fn;
              Scaleform::String::AppendChar(&v81, a0123456789abcd_2[(unsigned __int8)fn >> 4]);
              Scaleform::String::AppendChar(&v81, a0123456789abcd_2[v17 & 0xF]);
              StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext
                                                                                         + 20)
                                                                             + 12)
                                                                 + 788),
                             (__m128i *)((v81.HeapTypeBits & 0xFFFFFFFC) + 8),
                             *(_DWORD *)(v81.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++StringNode->RefCount;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)StringNode;
              ++StringNode->RefCount;
              v19 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v19 + 20) + 12) + 788),
                      (__m128i *)"color");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
              Scaleform::String::~String(&v81);
              v8 = v79;
            }
            if ( (*(_BYTE *)(v8 + 38) & 4) != 0 )
            {
              FontList = Scaleform::Render::Text::TextFormat::GetFontList((Scaleform::Render::Text::TextFormat *)v79);
              v22 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                          + 788),
                      (__m128i *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                      *(_DWORD *)(FontList->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++v22->RefCount;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v22;
              ++v22->RefCount;
              v23 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v23 + 20) + 12) + 788),
                      (__m128i *)"fontFamily");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            if ( (*(_BYTE *)(v79 + 38) & 8) != 0 )
            {
              v25 = *(_DWORD *)p_StringContext;
              fn = *(unsigned __int16 *)(v79 + 34);
              v85.T.Type = 3;
              *(float *)&fn = (double)fn * 0.05000000074505806;
              v26 = *(float *)&fn;
              LOBYTE(fn) = 0;
              v85.NV.NumberValue = v26;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v25 + 20) + 12) + 788),
                      (__m128i *)"fontSize");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            if ( (*(_BYTE *)(v79 + 38) & 0x20) != 0 )
            {
              v28 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (*(_BYTE *)(v79 + 36) & 2) != 0 )
              {
                v77 = 1;
                v29 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v28,
                                                       (__m128i *)"italic");
              }
              else
              {
                v77 = 2;
                v29 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v28,
                                                       (__m128i *)"normal");
              }
              ++v29[1].Size;
              v81.pData = v29;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v29;
              ++v29[1].Size;
              v30 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v30 + 20) + 12) + 788),
                      (__m128i *)"fontStyle");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
                pData = v81.pData;
                v77 &= ~2u;
                v10 = v81.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pData);
              }
              if ( (v77 & 1) != 0 )
              {
                v34 = v81.pData;
                v77 &= ~1u;
                v10 = v81.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v34);
              }
            }
            if ( (*(_BYTE *)(v79 + 38) & 0x10) != 0 )
            {
              v35 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (*(_BYTE *)(v79 + 36) & 1) != 0 )
              {
                v77 |= 4u;
                v36 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v35,
                                                       (__m128i *)"bold");
              }
              else
              {
                v77 |= 8u;
                v36 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v35,
                                                       (__m128i *)"normal");
              }
              ++v36[1].Size;
              v81.pData = v36;
              v85.NV.Int32Value = (int)v36;
              v85.T.Type = 5;
              ++v36[1].Size;
              v37 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v37 + 20) + 12) + 788),
                      (__m128i *)"fontWeight");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
                v39 = v81.pData;
                v77 &= ~8u;
                v10 = v81.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v39);
              }
              if ( (v77 & 4) != 0 )
              {
                v40 = v81.pData;
                v77 &= ~4u;
                v10 = v81.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v40);
              }
            }
            if ( *(char *)(v79 + 38) < 0 )
            {
              v41 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (*(_BYTE *)(v79 + 36) & 8) != 0 )
              {
                v77 |= 0x10u;
                v42 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v41,
                                                       (__m128i *)"true");
              }
              else
              {
                v77 |= 0x20u;
                v42 = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       v41,
                                                       (__m128i *)"false");
              }
              ++v42[1].Size;
              v81.pData = v42;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v42;
              ++v42[1].Size;
              v43 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + 12) + 788),
                      (__m128i *)"kerning");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
                v45 = v81.pData;
                v77 &= ~0x20u;
                v10 = v81.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v45);
              }
              if ( (v77 & 0x10) != 0 )
              {
                v46 = v81.pData;
                v77 &= ~0x10u;
                v10 = v81.pData[1].Size-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v46);
              }
            }
            if ( (*(_BYTE *)(v79 + 38) & 2) != 0 )
            {
              v85.T.Type = 3;
              v85.NV.NumberValue = Scaleform::Render::Text::TextFormat::GetLetterSpacing((Scaleform::Render::Text::TextFormat *)v79);
              v47 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v47 + 20) + 12) + 788),
                      (__m128i *)"letterSpacing");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            v49 = (Scaleform::String::DataDesc *)(v79 + 40);
            v50 = *(_BYTE *)(v79 + 58) >> 4;
            v81.pData = (Scaleform::String::DataDesc *)(v79 + 40);
            if ( (v50 & 1) != 0 )
            {
              v51 = *(_DWORD *)p_StringContext;
              fn = *(unsigned __int16 *)(v79 + 54);
              v85.T.Type = 3;
              v52 = (double)fn;
              LOBYTE(fn) = 0;
              v85.NV.NumberValue = v52;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v51 + 20) + 12) + 788),
                      (__m128i *)"marginLeft");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
                (const Scaleform::GFx::ASString *)&v82,
                &v85,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v53 = v82;
              --v82->RefCount;
              if ( !v53->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v53);
              if ( v85.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v85);
              v49 = v81.pData;
            }
            if ( (v49[1].RefCount & 0x200000) != 0 )
            {
              v54 = *(_DWORD *)p_StringContext;
              fn = LOWORD(v81.pData[1].RefCount);
              v85.T.Type = 3;
              v55 = (double)fn;
              LOBYTE(fn) = 0;
              v85.NV.NumberValue = v55;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v54 + 20) + 12) + 788),
                      (__m128i *)"marginRight");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            v57 = v81.pData;
            if ( (v81.pData[1].RefCount & 0x10000) != 0 )
            {
              if ( (unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsLeftAlignment((Scaleform::Render::Text::ParagraphFormat *)v81.pData) )
              {
                v77 |= 0x40u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        (__m128i *)"left");
              }
              else if ( (unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsCenterAlignment((Scaleform::Render::Text::ParagraphFormat *)v57) )
              {
                v77 |= 0x80u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        (__m128i *)"center");
              }
              else if ( (unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsRightAlignment((Scaleform::Render::Text::ParagraphFormat *)v57) )
              {
                v77 |= 0x100u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        (__m128i *)"right");
              }
              else
              {
                v77 |= 0x200u;
                v58 = Scaleform::GFx::ASStringManager::CreateStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20)
                                                                        + 12)
                                                            + 788),
                        (__m128i *)"justify");
              }
              ++v58->RefCount;
              v83 = v58;
              v85.NV.Int32Value = (int)v58;
              v85.T.Type = 5;
              ++v58->RefCount;
              v59 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v82 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v59 + 20) + 12) + 788),
                      (__m128i *)"textAlign");
              ++v82->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            if ( (*(_BYTE *)(v79 + 38) & 0x40) != 0 )
            {
              v65 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_StringContext + 20) + 12)
                                                        + 788);
              if ( (*(_BYTE *)(v79 + 36) & 4) != 0 )
              {
                v78 = v77 | 0x400;
                v66 = Scaleform::GFx::ASStringManager::CreateStringNode(v65, (__m128i *)"underline");
              }
              else
              {
                v78 = v77 | 0x800;
                v66 = Scaleform::GFx::ASStringManager::CreateStringNode(v65, (__m128i *)"none");
              }
              ++v66->RefCount;
              v82 = v66;
              v85.T.Type = 5;
              v85.NV.Int32Value = (int)v66;
              ++v66->RefCount;
              v67 = *(_DWORD *)p_StringContext;
              LOBYTE(fn) = 0;
              v83 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v67 + 20) + 12) + 788),
                      (__m128i *)"textDecoration");
              ++v83->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            if ( (v81.pData[1].RefCount & 0x40000) != 0 )
            {
              v71 = *(_DWORD *)p_StringContext;
              fn = *(__int16 *)&v81.pData->Data[2];
              v85.T.Type = 3;
              v72 = (double)fn;
              LOBYTE(fn) = 0;
              v85.NV.NumberValue = v72;
              v83 = Scaleform::GFx::ASStringManager::CreateStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v71 + 20) + 12) + 788),
                      (__m128i *)"textIndent");
              ++v83->RefCount;
              obj->SetMember(
                &obj->Scaleform::GFx::AS2::ObjectInterface,
                v1->Env,
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
            Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, obj);
            if ( obj )
            {
              RefCount = obj->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                obj->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(obj);
              }
            }
            v75 = v84.pNode;
            v10 = v84.pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v75);
          }
          else
          {
            Result = v1->Result;
            Scaleform::GFx::AS2::Value::DropRefs(Result);
            Result->T.Type = 1;
            v10 = pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
        }
        else
        {
          v4 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v4);
          v4->T.Type = 1;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "StyleSheet");
  }
}
