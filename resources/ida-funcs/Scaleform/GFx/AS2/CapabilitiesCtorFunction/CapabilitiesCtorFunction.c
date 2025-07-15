void __thiscall Scaleform::GFx::AS2::CapabilitiesCtorFunction::CapabilitiesCtorFunction(
        Scaleform::GFx::AS2::CapabilitiesCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // esi
  Scaleform::GFx::ASStringManager *pMovieImpl; // ecx
  Scaleform::GFx::AS2::ObjectInterface *v5; // edi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // ebx
  Scaleform::GFx::ASStringManager *v22; // ecx
  Scaleform::GFx::ASStringNode *v23; // eax
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // ebx
  Scaleform::GFx::ASStringManager *v27; // ecx
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // ebx
  Scaleform::GFx::ASStringManager *v31; // ecx
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::ASStringManager *v33; // ecx
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // ebx
  Scaleform::GFx::ASStringManager *v36; // ecx
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // ebx
  Scaleform::GFx::ASStringManager *v39; // ecx
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::ASStringManager *v41; // ecx
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::GFx::ASStringNode *v44; // ebx
  Scaleform::GFx::ASStringManager *v45; // ecx
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // eax
  Scaleform::GFx::ASStringManager *v48; // ecx
  Scaleform::GFx::ASStringNode *v49; // eax
  Scaleform::GFx::ASStringManager *v50; // ecx
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::GFx::ASStringManager *v52; // ecx
  Scaleform::GFx::ASStringNode *v53; // eax
  Scaleform::GFx::ASStringNode *v54[2]; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value v55; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v56; // [esp+28h] [ebp-10h] BYREF

  v2 = psc;
  v54[1] = (Scaleform::GFx::ASStringNode *)this;
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->pFunction = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::CapabilitiesCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::CapabilitiesCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pMovieImpl = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  LOBYTE(psc) = 6;
  v55.T.Type = 2;
  v55.V.BooleanValue = 0;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(pMovieImpl, "avHardwareDisable", 0x11u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v6 = v54[0];
  --v54[0]->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasAccessibility",
             0x10u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v7 = v54[0];
  --v54[0]->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasAudio",
             8u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v8 = v54[0];
  --v54[0]->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasAudioEncoder",
             0xFu,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v9 = v54[0];
  --v54[0]->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasEmbeddedVideo",
             0x10u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v10 = v54[0];
  --v54[0]->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasIME",
             6u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v11 = v54[0];
  --v54[0]->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasMP3",
             6u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v12 = v54[0];
  --v54[0]->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasPrinting",
             0xBu,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v13 = v54[0];
  --v54[0]->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasScreenBroadcast",
             0x12u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v14 = v54[0];
  --v54[0]->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasScreenPlayback",
             0x11u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v15 = v54[0];
  --v54[0]->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasStreamingAudio",
             0x11u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v16 = v54[0];
  --v54[0]->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasStreamingVideo",
             0x11u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v17 = v54[0];
  --v54[0]->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "hasVideoEncoder",
             0xFu,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v18 = v54[0];
  --v54[0]->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "isDebugger",
             0xAu,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v19 = v54[0];
  --v54[0]->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "localFileReadDisable",
             0x14u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v20 = v54[0];
  --v54[0]->RefCount;
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "en",
                      2u,
                      0);
  ++ConstStringNode->RefCount;
  ++ConstStringNode->RefCount;
  v22 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 5;
  v56.NV.Int32Value = (int)ConstStringNode;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v22, "language", 8u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v23 = v54[0];
  --v54[0]->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v24 = ConstStringNode->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  v25 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "Scaleform Windows",
          0x11u,
          0);
  v26 = v25;
  ++v25->RefCount;
  v24 = ++v25->RefCount == 1;
  --v25->RefCount;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  ++v26->RefCount;
  v27 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 5;
  v56.NV.Int32Value = (int)v26;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v27, "manufacturer", 0xCu, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v28 = v54[0];
  --v54[0]->RefCount;
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v24 = v26->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  v29 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "Windows",
          7u,
          0);
  v30 = v29;
  ++v29->RefCount;
  v24 = ++v29->RefCount == 1;
  --v29->RefCount;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  ++v30->RefCount;
  v31 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 5;
  v56.NV.Int32Value = (int)v30;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v31, "os", 2u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v32 = v54[0];
  --v54[0]->RefCount;
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v24 = v30->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  v33 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 4;
  v56.NV.Int32Value = 1;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v33, "pixelAspectRatio", 0x10u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v34 = v54[0];
  --v54[0]->RefCount;
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v35 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "External",
          8u,
          0);
  ++v35->RefCount;
  ++v35->RefCount;
  v36 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 5;
  v56.NV.Int32Value = (int)v35;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v36, "playerType", 0xAu, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v37 = v54[0];
  --v54[0]->RefCount;
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v24 = v35->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  v38 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "color",
          5u,
          0);
  ++v38->RefCount;
  ++v38->RefCount;
  v39 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 5;
  v56.NV.Int32Value = (int)v38;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v39, "screenColor", 0xBu, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v40 = v54[0];
  --v54[0]->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v24 = v38->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  v41 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 4;
  v56.NV.Int32Value = 72;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v41, "screenDPI", 9u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v42 = v54[0];
  --v54[0]->RefCount;
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v43 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "WIN 8,0,0,0",
          0xBu,
          0);
  v44 = v43;
  ++v43->RefCount;
  v24 = ++v43->RefCount == 1;
  --v43->RefCount;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  ++v44->RefCount;
  v45 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 5;
  v56.NV.Int32Value = (int)v44;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v45, "version", 7u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v46 = v54[0];
  --v54[0]->RefCount;
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v24 = v44->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             "windowlessDisable",
             0x11u,
             0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v55,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v47 = v54[0];
  --v54[0]->RefCount;
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 10;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v48, "screenResolutionX", 0x11u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v49 = v54[0];
  --v54[0]->RefCount;
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v50 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 10;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v50, "screenResolutionY", 0x11u, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v51 = v54[0];
  --v54[0]->RefCount;
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  v52 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v56.T.Type = 10;
  v54[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(v52, "serverString", 0xCu, 0);
  ++v54[0]->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    (const Scaleform::GFx::ASString *)v54,
    &v56,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v53 = v54[0];
  --v54[0]->RefCount;
  if ( !v53->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
  if ( v55.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v55);
}
