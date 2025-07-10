bool __thiscall Scaleform::GFx::AS2::AvmSprite::GetMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::ASStringNode *v6; // eax
  bool v7; // zf
  Scaleform::GFx::AS2::AvmCharacter::StandardMember StandardMemberConstant; // ebx
  Scaleform::GFx::AS2::Environment *v9; // edx
  bool v10; // al
  Scaleform::GFx::AS2::Environment *v11; // eax
  Scaleform::GFx::AS2::TransformObject *v12; // edi
  Scaleform::GFx::AS2::Environment *v13; // eax
  Scaleform::GFx::AS2::Object *v14; // eax
  Scaleform::GFx::AS2::Object *v15; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v17; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  long double v19; // st7
  unsigned __int8 *v20; // eax
  Scaleform::GFx::AS2::ArrayObject *v21; // edi
  Scaleform::GFx::AS2::Environment *v22; // eax
  Scaleform::GFx::AS2::ArrayObject *v23; // eax
  Scaleform::GFx::AS2::ArrayObject *v24; // edi
  int i; // esi
  unsigned int v26; // eax
  Scaleform::GFx::AS2::MovieClipObject *pObject; // ebx
  Scaleform::GFx::AS2::Object *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // ecx
  unsigned int v31; // eax
  char v32; // bl
  Scaleform::GFx::AS2::Object *v33; // ecx
  unsigned int v34; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  Scaleform::GFx::DisplayObject *DisplayObjectByName; // eax
  Scaleform::GFx::AS2::Object *v39; // ebx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v40; // edx
  Scaleform::GFx::AS2::ObjectInterface *v41; // ecx
  Scaleform::GFx::InteractiveObject *mat4_60; // [esp+20Eh] [ebp-94h]
  Scaleform::GFx::Bool3W v43; // [esp+229h] [ebp-79h] BYREF
  Scaleform::GFx::ASString str; // [esp+22Ah] [ebp-78h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> result; // [esp+22Eh] [ebp-74h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+232h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> v47; // [esp+262h] [ebp-40h] BYREF

  if ( (name->pNode->HashFlags & 0x20000000) != 0 )
  {
LABEL_7:
    StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(this, name);
    if ( !this->GetStandardMember(this, StandardMemberConstant, pval, 0) )
    {
      switch ( StandardMemberConstant )
      {
        case M_transform:
          v11 = this->GetASEnvironment(this);
          v12 = (Scaleform::GFx::AS2::TransformObject *)v11->StringContext.pContext->pHeap->Alloc(
                                                          v11->StringContext.pContext->pHeap,
                                                          72u,
                                                          0);
          if ( v12 )
          {
            mat4_60 = this->pDispObj;
            v13 = this->GetASEnvironment(this);
            Scaleform::GFx::AS2::TransformObject::TransformObject(v12, v13, mat4_60);
            v15 = v14;
          }
          else
          {
            v15 = 0;
          }
          Scaleform::GFx::AS2::Value::SetAsObject(pval, v15);
          if ( v15 )
          {
            RefCount = v15->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
            {
              v15->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
            }
          }
          return 1;
        case M_z:
          v19 = this->pDispObj->GetZ(this->pDispObj);
          goto LABEL_28;
        case M_zscale:
          v19 = this->pDispObj->GetZScale(this->pDispObj);
          goto LABEL_28;
        case M_xrotation:
          v19 = this->pDispObj->GetXRotation(this->pDispObj);
          goto LABEL_28;
        case M_yrotation:
          v19 = this->pDispObj->GetYRotation(this->pDispObj);
          goto LABEL_28;
        case M_matrix3d:
          v20 = (unsigned __int8 *)this->pDispObj->GetMatrix3D(this->pDispObj);
          memcpy((unsigned __int8 *)&dst, v20, sizeof(dst));
          Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v47, &dst);
          Scaleform::Render::Matrix4x4<float>::Transpose(&v47);
          v21 = (Scaleform::GFx::AS2::ArrayObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                      penv->StringContext.pContext->pHeap,
                                                      80,
                                                      0);
          if ( v21 )
          {
            v22 = this->GetASEnvironment(this);
            Scaleform::GFx::AS2::ArrayObject::ArrayObject(v21, v22);
            v24 = v23;
          }
          else
          {
            v24 = 0;
          }
          Scaleform::GFx::AS2::ArrayObject::Resize(v24, 16);
          for ( i = 0; i < 16; ++i )
          {
            *(double *)&dst.M[0][1] = v47.M[0][i];
            LOBYTE(dst.M[0][0]) = 3;
            Scaleform::GFx::AS2::ArrayObject::SetElement(v24, i, (const Scaleform::GFx::AS2::Value *)&dst);
            if ( LOBYTE(dst.M[0][0]) >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&dst);
          }
          Scaleform::GFx::AS2::Value::SetAsObject(pval, v24);
          if ( !v24 )
            return 1;
          v26 = v24->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v26) == 0 )
            return 1;
          v24->RefCount = v26 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          return 1;
        case M_fov:
          v19 = this->pDispObj->GetFOV(this->pDispObj);
LABEL_28:
          Scaleform::GFx::AS2::Value::SetNumber(pval, v19);
          return 1;
        case M__version:
          if ( !this->IsLevelMovie(&this->Scaleform::GFx::AvmSpriteBase) )
            goto LABEL_11;
          v17 = this->GetASEnvironment(this);
          ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                              (Scaleform::GFx::ASStringManager *)v17->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                              "WIN 8,0,0,0",
                              0xBu,
                              0);
          ++ConstStringNode->RefCount;
          str.pNode = ConstStringNode;
          Scaleform::GFx::AS2::Value::SetString(pval, &str);
          v7 = ConstStringNode->RefCount-- == 1;
          if ( v7 )
            Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
          return 1;
        default:
          goto LABEL_11;
      }
    }
    return 1;
  }
  if ( Scaleform::GFx::ASConstString::GetLength(name) && Scaleform::GFx::ASConstString::GetCharAt(name, 0) == 95 )
  {
    v6 = Scaleform::GFx::ASConstString::ToLowerNode(name);
    ++v6->RefCount;
    if ( (v6->HashFlags & 0x10000000) != 0 )
    {
      v7 = v6->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      goto LABEL_7;
    }
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
LABEL_11:
  v9 = penv;
  if ( penv
    && name->pNode == *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion
    || psc
    && name->pNode == *(Scaleform::GFx::ASStringNode **)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(pval, this->pProto.pObject);
    return 1;
  }
  pObject = this->ASMovieClipObj.pObject;
  if ( pObject )
  {
    v28 = pObject->pProto.pObject;
    if ( v28 )
      v28->RefCount = (v28->RefCount + 1) & 0x8FFFFFFF;
    v29 = (Scaleform::GFx::ASStringNode *)pObject->pProto.pObject;
    v30 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v29;
    str.pNode = v29;
    if ( v29 )
    {
      v31 = v29->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v31) != 0 )
      {
        v30->RefCount = v31 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
        v9 = penv;
      }
    }
    pObject->pProto.pObject = 0;
    v32 = 0;
    if ( v9
      && this->ASMovieClipObj.pObject->GetMember(
           &this->ASMovieClipObj.pObject->Scaleform::GFx::AS2::ObjectInterface,
           v9,
           name,
           pval)
      || psc
      && this->ASMovieClipObj.pObject->GetMemberRaw(
           &this->ASMovieClipObj.pObject->Scaleform::GFx::AS2::ObjectInterface,
           psc,
           name,
           pval) )
    {
      v32 = 1;
    }
    Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
      this->ASMovieClipObj.pObject,
      &result,
      (Scaleform::GFx::AS2::Object *)str.pNode);
    v33 = result.pObject;
    if ( result.pObject )
    {
      v34 = result.pObject->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v34) != 0 )
      {
        result.pObject->RefCount = v34 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v33);
      }
    }
    pNode = str.pNode;
    if ( v32 )
    {
      if ( !str.pNode )
        return 1;
      v36 = str.pNode->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v36) == 0 )
        return 1;
      str.pNode->RefCount = v36 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pNode);
      return 1;
    }
    if ( str.pNode )
    {
      v37 = str.pNode->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v37) != 0 )
      {
        str.pNode->RefCount = v37 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pNode);
      }
    }
  }
  LOBYTE(result.pObject) = this->ASEnvironment.StringContext.SWFVersion > 6u;
  DisplayObjectByName = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                          (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
                          name,
                          (bool)result.pObject);
  if ( DisplayObjectByName && SLOBYTE(DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
  {
    Scaleform::GFx::AS2::Value::SetAsCharacter(pval, (Scaleform::GFx::InteractiveObject *)DisplayObjectByName);
    return 1;
  }
  else
  {
    v39 = this->pProto.pObject;
    if ( v39 )
    {
      if ( penv && v39->GetMember(&v39->Scaleform::GFx::AS2::ObjectInterface, penv, name, pval) )
        return 1;
      if ( psc )
      {
        v40 = v39->Scaleform::GFx::AS2::ObjectInterface::__vftable;
        v41 = &v39->Scaleform::GFx::AS2::ObjectInterface;
        v39 = (Scaleform::GFx::AS2::Object *)pval;
        if ( v40->GetMemberRaw(v41, psc, name, pval) )
          return 1;
      }
    }
    v10 = Scaleform::GFx::ASConstString::GetLength(name)
       && *name->pNode->pData == 95
       && (*(_QWORD *)&dst.M[0][1] = (unsigned int)pval,
           LODWORD(dst.M[0][0]) = name,
           memset(&dst.M[0][3], 0, 12),
           Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(
             &this->ASEnvironment,
             (Scaleform::GFx::ASMovieRootBase *)v39,
             &v43,
             (const Scaleform::GFx::AS2::Environment::GetVarParams *)&dst),
           v43.Value)
       && v43.Value == 1;
  }
  return v10;
}
