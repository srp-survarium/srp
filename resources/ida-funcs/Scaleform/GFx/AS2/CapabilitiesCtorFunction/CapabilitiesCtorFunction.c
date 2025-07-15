void __thiscall Scaleform::GFx::AS2::CapabilitiesCtorFunction::CapabilitiesCtorFunction(
        Scaleform::GFx::AS2::CapabilitiesCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // esi
  Scaleform::GFx::ASStringManager *pMovieImpl; // ecx
  Scaleform::GFx::AS2::ObjectInterface *v5; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
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
  Scaleform::GFx::ASString name; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::CapabilitiesCtorFunction *v55; // [esp+14h] [ebp-24h]
  Scaleform::GFx::AS2::Value falseVal; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+28h] [ebp-10h] BYREF

  v2 = psc;
  v55 = this;
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->pFunction = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::CapabilitiesCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::CapabilitiesCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pMovieImpl = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  LOBYTE(psc) = 6;
  falseVal.T.Type = 2;
  falseVal.V.BooleanValue = 0;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pMovieImpl, "avHardwareDisable", 0x11u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  pNode = name.pNode;
  --name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasAccessibility",
                 0x10u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v7 = name.pNode;
  --name.pNode->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasAudio",
                 8u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v8 = name.pNode;
  --name.pNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasAudioEncoder",
                 0xFu,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v9 = name.pNode;
  --name.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasEmbeddedVideo",
                 0x10u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v10 = name.pNode;
  --name.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasIME",
                 6u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v11 = name.pNode;
  --name.pNode->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasMP3",
                 6u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v12 = name.pNode;
  --name.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasPrinting",
                 0xBu,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v13 = name.pNode;
  --name.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasScreenBroadcast",
                 0x12u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v14 = name.pNode;
  --name.pNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasScreenPlayback",
                 0x11u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v15 = name.pNode;
  --name.pNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasStreamingAudio",
                 0x11u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v16 = name.pNode;
  --name.pNode->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasStreamingVideo",
                 0x11u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v17 = name.pNode;
  --name.pNode->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "hasVideoEncoder",
                 0xFu,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v18 = name.pNode;
  --name.pNode->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "isDebugger",
                 0xAu,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v19 = name.pNode;
  --name.pNode->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "localFileReadDisable",
                 0x14u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v20 = name.pNode;
  --name.pNode->RefCount;
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
  val.T.Type = 5;
  val.NV.Int32Value = (int)ConstStringNode;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v22, "language", 8u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v23 = name.pNode;
  --name.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
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
  val.T.Type = 5;
  val.NV.Int32Value = (int)v26;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v27, "manufacturer", 0xCu, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v28 = name.pNode;
  --name.pNode->RefCount;
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
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
  val.T.Type = 5;
  val.NV.Int32Value = (int)v30;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v31, "os", 2u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v32 = name.pNode;
  --name.pNode->RefCount;
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v24 = v30->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  v33 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 4;
  val.NV.Int32Value = 1;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v33, "pixelAspectRatio", 0x10u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v34 = name.pNode;
  --name.pNode->RefCount;
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v35 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "External",
          8u,
          0);
  ++v35->RefCount;
  ++v35->RefCount;
  v36 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 5;
  val.NV.Int32Value = (int)v35;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v36, "playerType", 0xAu, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v37 = name.pNode;
  --name.pNode->RefCount;
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v24 = v35->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  v38 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          (char *)&stru_9555EC,
          5u,
          0);
  ++v38->RefCount;
  ++v38->RefCount;
  v39 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 5;
  val.NV.Int32Value = (int)v38;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v39, "screenColor", 0xBu, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v40 = name.pNode;
  --name.pNode->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v24 = v38->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  v41 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 4;
  val.NV.Int32Value = 72;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v41, "screenDPI", 9u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v42 = name.pNode;
  --name.pNode->RefCount;
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
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
  val.T.Type = 5;
  val.NV.Int32Value = (int)v44;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v45, "version", 7u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v46 = name.pNode;
  --name.pNode->RefCount;
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v24 = v44->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 "windowlessDisable",
                 0x11u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &falseVal,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v47 = name.pNode;
  --name.pNode->RefCount;
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 10;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v48, "screenResolutionX", 0x11u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v49 = name.pNode;
  --name.pNode->RefCount;
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v50 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 10;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v50, "screenResolutionY", 0x11u, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v51 = name.pNode;
  --name.pNode->RefCount;
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v52 = (Scaleform::GFx::ASStringManager *)v2->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  val.T.Type = 10;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v52, "serverString", 0xCu, 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    v2,
    &name,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  v53 = name.pNode;
  --name.pNode->RefCount;
  if ( !v53->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  if ( falseVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&falseVal);
}
