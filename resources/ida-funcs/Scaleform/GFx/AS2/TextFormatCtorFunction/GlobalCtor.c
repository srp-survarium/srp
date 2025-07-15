void __cdecl Scaleform::GFx::AS2::TextFormatCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::TextFormatObject *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // eax
  unsigned int FirstArgBottomIndex; // eax
  _DWORD *v8; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v9; // edi
  Scaleform::GFx::ASStringNode *v10; // eax
  int v11; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v12; // ebx
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  int v15; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v16; // ebx
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  int v19; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v20; // ebx
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  int v23; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v24; // ebx
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  int v27; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v28; // ebx
  Scaleform::GFx::AS2::Value *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  int v31; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v32; // ebx
  Scaleform::GFx::AS2::Value *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  int v35; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v36; // ebx
  Scaleform::GFx::AS2::Value *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  int v39; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v40; // ebx
  Scaleform::GFx::AS2::Value *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  int v43; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v44; // ebx
  Scaleform::GFx::AS2::Value *v45; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  int v47; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v48; // ebx
  Scaleform::GFx::AS2::Value *v49; // eax
  Scaleform::GFx::ASStringNode *v50; // eax
  int v51; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v52; // ebx
  Scaleform::GFx::AS2::Value *v53; // eax
  Scaleform::GFx::ASStringNode *v54; // eax
  int v55; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v56; // ebp
  Scaleform::GFx::AS2::Value *v57; // eax
  Scaleform::GFx::ASStringNode *v58; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v60; // [esp+D8h] [ebp-Ch]
  int v61; // [esp+DCh] [ebp-8h]
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+E0h] [ebp-4h] BYREF

  v1 = fn;
  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextFormat
    && !v1->ThisPtr->IsBuiltinPrototype(v1->ThisPtr) )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
      v60 = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    }
    else
    {
      p_pProto = 0;
      v60 = 0;
    }
  }
  else
  {
    pHeap = v1->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::TextFormatObject *)pHeap->Alloc(pHeap, 112u, 0);
    if ( v5 )
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v5, v1->Env);
    else
      v6 = 0;
    v60 = v6;
    p_pProto = v6;
  }
  if ( v1->NArgs >= 1 )
  {
    FirstArgBottomIndex = v1->FirstArgBottomIndex;
    v8 = &v1->Env->__vftable;
    LOBYTE(fn) = 0;
    v9 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
    v61 = 0;
    if ( FirstArgBottomIndex <= 32 * (v8[6] - 1) + ((v8[1] - v8[2]) >> 4) )
      v61 = *(_DWORD *)(v8[5] + 4 * (FirstArgBottomIndex >> 5)) + 16 * (FirstArgBottomIndex & 0x1F);
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v8[29] + 20) + 12) + 788),
                        "font",
                        4u,
                        0);
    ++ConstStringNode->RefCount;
    v9->SetMember(
      v9,
      v1->Env,
      (const Scaleform::GFx::ASString *)&ConstStringNode,
      (const Scaleform::GFx::AS2::Value *)v61,
      (const Scaleform::GFx::AS2::PropFlags *)&fn);
    v10 = ConstStringNode;
    --ConstStringNode->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    if ( v1->NArgs >= 2 )
    {
      v11 = v8[29];
      LOBYTE(fn) = 0;
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v11 + 20) + 12) + 788),
                          "size",
                          4u,
                          0);
      ++ConstStringNode->RefCount;
      v12 = v9->__vftable;
      v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v12->SetMember(
        v9,
        v1->Env,
        (const Scaleform::GFx::ASString *)&ConstStringNode,
        v13,
        (const Scaleform::GFx::AS2::PropFlags *)&fn);
      v14 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v14->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v1->NArgs >= 3 )
      {
        v15 = v8[29];
        LOBYTE(fn) = 0;
        ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                            *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v15 + 20) + 12) + 788),
                            "color",
                            5u,
                            0);
        ++ConstStringNode->RefCount;
        v16 = v9->__vftable;
        v17 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        v16->SetMember(
          v9,
          v1->Env,
          (const Scaleform::GFx::ASString *)&ConstStringNode,
          v17,
          (const Scaleform::GFx::AS2::PropFlags *)&fn);
        v18 = ConstStringNode;
        --ConstStringNode->RefCount;
        if ( !v18->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        if ( v1->NArgs >= 4 )
        {
          v19 = v8[29];
          LOBYTE(fn) = 0;
          ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                              *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v19 + 20) + 12) + 788),
                              "bold",
                              4u,
                              0);
          ++ConstStringNode->RefCount;
          v20 = v9->__vftable;
          v21 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          v20->SetMember(
            v9,
            v1->Env,
            (const Scaleform::GFx::ASString *)&ConstStringNode,
            v21,
            (const Scaleform::GFx::AS2::PropFlags *)&fn);
          v22 = ConstStringNode;
          --ConstStringNode->RefCount;
          if ( !v22->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          if ( v1->NArgs >= 5 )
          {
            v23 = v8[29];
            LOBYTE(fn) = 0;
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v23 + 20) + 12) + 788),
                                "italic",
                                6u,
                                0);
            ++ConstStringNode->RefCount;
            v24 = v9->__vftable;
            v25 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
            v24->SetMember(
              v9,
              v1->Env,
              (const Scaleform::GFx::ASString *)&ConstStringNode,
              v25,
              (const Scaleform::GFx::AS2::PropFlags *)&fn);
            v26 = ConstStringNode;
            --ConstStringNode->RefCount;
            if ( !v26->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            if ( v1->NArgs >= 6 )
            {
              v27 = v8[29];
              LOBYTE(fn) = 0;
              ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                  *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v27 + 20) + 12) + 788),
                                  "underline",
                                  9u,
                                  0);
              ++ConstStringNode->RefCount;
              v28 = v9->__vftable;
              v29 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
              v28->SetMember(
                v9,
                v1->Env,
                (const Scaleform::GFx::ASString *)&ConstStringNode,
                v29,
                (const Scaleform::GFx::AS2::PropFlags *)&fn);
              v30 = ConstStringNode;
              --ConstStringNode->RefCount;
              if ( !v30->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v30);
              if ( v1->NArgs >= 7 )
              {
                v31 = v8[29];
                LOBYTE(fn) = 0;
                ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                    *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v31 + 20) + 12) + 788),
                                    "url",
                                    3u,
                                    0);
                ++ConstStringNode->RefCount;
                v32 = v9->__vftable;
                v33 = Scaleform::GFx::AS2::FnCall::Arg(v1, 6);
                v32->SetMember(
                  v9,
                  v1->Env,
                  (const Scaleform::GFx::ASString *)&ConstStringNode,
                  v33,
                  (const Scaleform::GFx::AS2::PropFlags *)&fn);
                v34 = ConstStringNode;
                --ConstStringNode->RefCount;
                if ( !v34->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v34);
                if ( v1->NArgs >= 8 )
                {
                  v35 = v8[29];
                  LOBYTE(fn) = 0;
                  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v35 + 20) + 12) + 788),
                                      "target",
                                      6u,
                                      0);
                  ++ConstStringNode->RefCount;
                  v36 = v9->__vftable;
                  v37 = Scaleform::GFx::AS2::FnCall::Arg(v1, 7);
                  v36->SetMember(
                    v9,
                    v1->Env,
                    (const Scaleform::GFx::ASString *)&ConstStringNode,
                    v37,
                    (const Scaleform::GFx::AS2::PropFlags *)&fn);
                  v38 = ConstStringNode;
                  --ConstStringNode->RefCount;
                  if ( !v38->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
                  if ( v1->NArgs >= 9 )
                  {
                    v39 = v8[29];
                    LOBYTE(fn) = 0;
                    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                        *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v39 + 20) + 12)
                                                                            + 788),
                                        "align",
                                        5u,
                                        0);
                    ++ConstStringNode->RefCount;
                    v40 = v9->__vftable;
                    v41 = Scaleform::GFx::AS2::FnCall::Arg(v1, 8);
                    v40->SetMember(
                      v9,
                      v1->Env,
                      (const Scaleform::GFx::ASString *)&ConstStringNode,
                      v41,
                      (const Scaleform::GFx::AS2::PropFlags *)&fn);
                    v42 = ConstStringNode;
                    --ConstStringNode->RefCount;
                    if ( !v42->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v42);
                    if ( v1->NArgs >= 10 )
                    {
                      v43 = v8[29];
                      LOBYTE(fn) = 0;
                      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                          *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + 12)
                                                                              + 788),
                                          "leftMargin",
                                          0xAu,
                                          0);
                      ++ConstStringNode->RefCount;
                      v44 = v9->__vftable;
                      v45 = Scaleform::GFx::AS2::FnCall::Arg(v1, 9);
                      v44->SetMember(
                        v9,
                        v1->Env,
                        (const Scaleform::GFx::ASString *)&ConstStringNode,
                        v45,
                        (const Scaleform::GFx::AS2::PropFlags *)&fn);
                      v46 = ConstStringNode;
                      --ConstStringNode->RefCount;
                      if ( !v46->RefCount )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v46);
                      if ( v1->NArgs >= 11 )
                      {
                        v47 = v8[29];
                        LOBYTE(fn) = 0;
                        ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v47 + 20) + 12)
                                                                                + 788),
                                            "rightMargin",
                                            0xBu,
                                            0);
                        ++ConstStringNode->RefCount;
                        v48 = v9->__vftable;
                        v49 = Scaleform::GFx::AS2::FnCall::Arg(v1, 10);
                        v48->SetMember(
                          v9,
                          v1->Env,
                          (const Scaleform::GFx::ASString *)&ConstStringNode,
                          v49,
                          (const Scaleform::GFx::AS2::PropFlags *)&fn);
                        v50 = ConstStringNode;
                        --ConstStringNode->RefCount;
                        if ( !v50->RefCount )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v50);
                        if ( v1->NArgs >= 12 )
                        {
                          v51 = v8[29];
                          LOBYTE(fn) = 0;
                          ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                              *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v51 + 20)
                                                                                              + 12)
                                                                                  + 788),
                                              "indent",
                                              6u,
                                              0);
                          ++ConstStringNode->RefCount;
                          v52 = v9->__vftable;
                          v53 = Scaleform::GFx::AS2::FnCall::Arg(v1, 11);
                          v52->SetMember(
                            v9,
                            v1->Env,
                            (const Scaleform::GFx::ASString *)&ConstStringNode,
                            v53,
                            (const Scaleform::GFx::AS2::PropFlags *)&fn);
                          v54 = ConstStringNode;
                          --ConstStringNode->RefCount;
                          if ( !v54->RefCount )
                            Scaleform::GFx::ASStringNode::ReleaseNode(v54);
                          if ( v1->NArgs >= 13 )
                          {
                            v55 = v8[29];
                            LOBYTE(fn) = 0;
                            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v55 + 20)
                                                                                                + 12)
                                                                                    + 788),
                                                "leading",
                                                7u,
                                                0);
                            ++ConstStringNode->RefCount;
                            v56 = v9->__vftable;
                            v57 = Scaleform::GFx::AS2::FnCall::Arg(v1, 12);
                            v56->SetMember(
                              v9,
                              v1->Env,
                              (const Scaleform::GFx::ASString *)&ConstStringNode,
                              v57,
                              (const Scaleform::GFx::AS2::PropFlags *)&fn);
                            v58 = ConstStringNode;
                            --ConstStringNode->RefCount;
                            if ( !v58->RefCount )
                              Scaleform::GFx::ASStringNode::ReleaseNode(v58);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    p_pProto = v60;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, p_pProto);
  if ( p_pProto )
  {
    RefCount = p_pProto->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      p_pProto->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
    }
  }
}
