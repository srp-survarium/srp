char __thiscall Scaleform::GFx::AS2::CapabilitiesCtorFunction::GetMember(
        Scaleform::GFx::AS2::CapabilitiesCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::InteractiveObject *Target; // eax
  int v6; // eax
  Scaleform::RefCountVImpl *v7; // esi
  bool v8; // bl
  int v9; // ebp
  Scaleform::GFx::ASString *v10; // ebp
  Scaleform::GFx::InteractiveObject *v11; // ecx
  int BufferHeight; // ecx
  Scaleform::GFx::InteractiveObject *v14; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::RefCountVImpl *v16; // eax
  Scaleform::RefCountVImpl *v17; // esi
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS2::Value *v19; // ecx
  Scaleform::GFx::ASString *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v23; // esi
  bool v24; // zf
  Scaleform::GFx::InteractiveObject *v25; // edx
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // esi
  Scaleform::GFx::InteractiveObject *v28; // ecx
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // esi
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::ASStringNode *v32; // esi
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // esi
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // esi
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *v40; // eax
  Scaleform::GFx::MovieImpl *v41; // ecx
  unsigned int (__thiscall *GetControllerCount)(Scaleform::GFx::Movie *); // eax
  unsigned int cap_bits; // [esp+10h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS2::CapabilitiesCtorFunction *v44; // [esp+14h] [ebp-48h]
  Scaleform::GFx::AS2::Value v; // [esp+18h] [ebp-44h] BYREF
  Scaleform::GFx::Viewport vp; // [esp+28h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::Environment *penva; // [esp+60h] [ebp+4h]

  Target = penv->Target;
  v44 = this;
  v6 = (int)Target->pASRoot->pMovieImpl->GetStateAddRef(
              &Target->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
              State_Audio);
  v7 = (Scaleform::RefCountVImpl *)v6;
  v8 = 0;
  if ( v6 )
  {
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6);
    penva = (Scaleform::GFx::AS2::Environment *)v9;
    Scaleform::RefCountImpl::Release(v7);
  }
  else
  {
    v9 = 0;
    penva = 0;
  }
  cap_bits = 0;
  if ( v9 )
    (*(void (__thiscall **)(int, unsigned int *))(*(_DWORD *)v9 + 4))(v9, &cap_bits);
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        "screenResolutionX",
                        0x11u,
                        0);
    v23 = ConstStringNode;
    ++ConstStringNode->RefCount;
    if ( !ConstStringNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(ConstStringNode);
    v10 = name;
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    LOBYTE(name) = v23->pLower == v10->pNode->pLower;
    v24 = v23->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    if ( (_BYTE)name )
    {
      v25 = penv->Target;
      vp.AspectRatio = 1.0;
      vp.Height = 1;
      vp.Scale = 1.0;
      vp.Width = 1;
      memset(&vp, 0, 16);
      memset(&vp.ScissorLeft, 0, 20);
      v25->pASRoot->pMovieImpl->GetViewport(v25->pASRoot->pMovieImpl, &vp);
      v.T.Type = 4;
      v.NV.Int32Value = vp.BufferWidth;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_12;
    }
    v26 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "screenResolutionY",
            0x11u,
            0);
    v27 = v26;
    ++v26->RefCount;
    if ( !v26->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v26);
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    LOBYTE(name) = v27->pLower == v10->pNode->pLower;
    v24 = v27->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    if ( (_BYTE)name )
    {
      v28 = penv->Target;
      vp.AspectRatio = 1.0;
      vp.Height = 1;
      vp.Scale = 1.0;
      vp.Width = 1;
      memset(&vp, 0, 16);
      memset(&vp.ScissorLeft, 0, 20);
      v28->pASRoot->pMovieImpl->GetViewport(v28->pASRoot->pMovieImpl, &vp);
      BufferHeight = vp.BufferHeight;
      goto LABEL_10;
    }
    v29 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "hasIME",
            6u,
            0);
    v30 = v29;
    ++v29->RefCount;
    if ( !v29->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v29);
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    LOBYTE(name) = v30->pLower == v10->pNode->pLower;
    v24 = v30->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v30);
    if ( (_BYTE)name )
      goto LABEL_18;
    v31 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "hasAudio",
            8u,
            0);
    v32 = v31;
    ++v31->RefCount;
    if ( !v31->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v31);
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    LOBYTE(name) = v32->pLower == v10->pNode->pLower;
    v24 = v32->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v32);
    if ( (_BYTE)name )
    {
LABEL_22:
      v.T.Type = 2;
      v.V.BooleanValue = penva != 0;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_12;
    }
    v33 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "hasMP3",
            6u,
            0);
    v34 = v33;
    ++v33->RefCount;
    if ( !v33->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v33);
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    LOBYTE(name) = v34->pLower == v10->pNode->pLower;
    v24 = v34->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    if ( (_BYTE)name )
    {
      if ( !penva || (cap_bits & 1) != 0 )
      {
LABEL_32:
        v.T.Type = 2;
        v.V.BooleanValue = v8;
        Scaleform::GFx::AS2::Value::operator=(val, &v);
        goto LABEL_12;
      }
      v.T.Type = 2;
      v.V.BooleanValue = 1;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
LABEL_12:
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      return 1;
    }
    v35 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "hasStreamingAudio",
            0x11u,
            0);
    v36 = v35;
    ++v35->RefCount;
    if ( !v35->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v35);
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    LOBYTE(name) = v36->pLower == v10->pNode->pLower;
    v24 = v36->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v36);
    if ( (_BYTE)name )
    {
LABEL_29:
      if ( penva && (cap_bits & 4) == 0 )
        v8 = 1;
      goto LABEL_32;
    }
    v37 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "serverString",
            0xCu,
            0);
    v38 = v37;
    ++v37->RefCount;
    if ( !v37->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v37);
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    LOBYTE(name) = v38->pLower == v10->pNode->pLower;
    v24 = v38->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
    if ( (_BYTE)name )
    {
      pNode = Scaleform::GFx::AS2::GFxCapabilities_ServerString((Scaleform::GFx::ASString *)&name, penv)->pNode;
      ++pNode->RefCount;
      v.T.Type = 5;
      v.NV.Int32Value = (int)pNode;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v40 = name;
      --name[3].pNode;
      v21 = (Scaleform::GFx::ASStringNode *)v40;
      if ( v40[3].pNode )
        return 1;
LABEL_37:
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      return 1;
    }
  }
  else
  {
    v10 = name;
    if ( !strcmp(name->pNode->pData, "screenResolutionX") )
    {
      v11 = penv->Target;
      vp.AspectRatio = 1.0;
      vp.Height = 1;
      vp.Scale = 1.0;
      vp.Width = 1;
      memset(&vp, 0, 16);
      memset(&vp.ScissorLeft, 0, 20);
      v11->pASRoot->pMovieImpl->GetViewport(v11->pASRoot->pMovieImpl, &vp);
      BufferHeight = vp.BufferWidth;
LABEL_10:
      v.T.Type = 4;
      v.NV.Int32Value = BufferHeight;
LABEL_11:
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_12;
    }
    if ( !strcmp(name->pNode->pData, "screenResolutionY") )
    {
      vp.Height = 1;
      vp.AspectRatio = 1.0;
      vp.Width = 1;
      vp.Scale = 1.0;
      v14 = penv->Target;
      memset(&vp, 0, 16);
      memset(&vp.ScissorLeft, 0, 20);
      v14->pASRoot->pMovieImpl->GetViewport(v14->pASRoot->pMovieImpl, &vp);
      v.T.Type = 4;
      v.NV.Int32Value = vp.BufferHeight;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_12;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "hasIME") )
    {
LABEL_18:
      pMovieImpl = penv->Target->pASRoot->pMovieImpl;
      v16 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(
                                          &pMovieImpl->Scaleform::GFx::StateBag,
                                          State_IMEManager);
      v17 = v16;
      if ( v16 )
        Scaleform::RefCountImpl::Release(v16);
      v.T.Type = 2;
      v.V.BooleanValue = v17 != 0;
      goto LABEL_11;
    }
    if ( Scaleform::GFx::ASString::operator==(v10, "hasAudio") )
      goto LABEL_22;
    if ( Scaleform::GFx::ASString::operator==(v10, "hasMP3") )
    {
      if ( penva && (cap_bits & 1) == 0 )
        v8 = 1;
      v.T.Type = 2;
      v.V.BooleanValue = v8;
      goto LABEL_11;
    }
    if ( Scaleform::GFx::ASString::operator==(v10, "hasStreamingAudio") )
      goto LABEL_29;
    if ( Scaleform::GFx::ASString::operator==(v10, "serverString") )
    {
      v18 = Scaleform::GFx::AS2::GFxCapabilities_ServerString((Scaleform::GFx::ASString *)&name, penv)->pNode;
      v19 = val;
      ++v18->RefCount;
      v.T.Type = 5;
      v.NV.Int32Value = (int)v18;
      Scaleform::GFx::AS2::Value::operator=(v19, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v20 = name;
      --name[3].pNode;
      v21 = (Scaleform::GFx::ASStringNode *)v20;
      if ( v20[3].pNode )
        return 1;
      goto LABEL_37;
    }
  }
  if ( penv->StringContext.pContext->GFxExtensions.Value == 1
    && Scaleform::GFx::ASString::operator==(v10, "numControllers") )
  {
    v41 = penv->Target->pASRoot->pMovieImpl;
    GetControllerCount = v41->GetControllerCount;
    v.T.Type = 4;
    v.NV.Int32Value = GetControllerCount(v41);
    Scaleform::GFx::AS2::Value::operator=(val, &v);
    goto LABEL_12;
  }
  return ((int (__thiscall *)(Scaleform::GFx::AS2::CapabilitiesCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v44->IsNull)(
           v44,
           &penv->StringContext,
           v10,
           val);
}
