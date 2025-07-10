char __thiscall Scaleform::GFx::AS2::AvmButton::SetStandardMember(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        const Scaleform::GFx::AS2::Value *origVal,
        Scaleform::String opcodeFlag)
{
  Scaleform::GFx::AS2::Environment *v5; // eax
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v6; // ebx
  Scaleform::GFx::AS2::Environment *v7; // edi
  Scaleform::GFx::ASStringManager *pMovieImpl; // ecx
  char *pName; // edx
  char v10; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::InteractiveObject *v12; // edi
  const Scaleform::GFx::AS2::Environment *v13; // eax
  Scaleform::GFx::AS2::Environment *v15; // ebx
  Scaleform::GFx::AS2::Object *v16; // eax
  Scaleform::GFx::AS2::RectangleObject *v17; // edi
  Scaleform::GFx::InteractiveObject *pDispObj; // esi
  Scaleform::GFx::InteractiveObject *v19; // esi
  Scaleform::GFx::ASString prop; // [esp+FCh] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+100h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value resultVal; // [esp+110h] [ebp-40h] BYREF
  float v23[4]; // [esp+120h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+130h] [ebp-20h] BYREF

  Scaleform::GFx::AS2::Value::Value(&v21, origVal);
  v5 = this->GetASEnvironment(this);
  v6 = member;
  v7 = v5;
  if ( member > M_ymouse
    && v5
    && Scaleform::GFx::AS2::AvmButton::GetButtonASObject(this)
    && this->ASButtonObj.pObject->pWatchpoints )
  {
    pMovieImpl = (Scaleform::GFx::ASStringManager *)v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
    pName = (char *)Scaleform::GFx::AS2::AvmCharacter::MemberTable[member].pName;
    resultVal.T.Type = 0;
    *(float *)&prop.pNode = COERCE_FLOAT(
                              Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                pMovieImpl,
                                pName,
                                strlen(pName),
                                0));
    ++prop.pNode->RefCount;
    v10 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(this->ASButtonObj.pObject, v7, &prop, &v21, &resultVal);
    pNode = prop.pNode;
    --prop.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v10 )
      Scaleform::GFx::AS2::Value::operator=(&v21, &resultVal);
    if ( resultVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&resultVal);
    v6 = member;
  }
  if ( Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(this, v6, &v21, opcodeFlag) )
    goto LABEL_26;
  if ( v6 == M_scale9Grid )
  {
    if ( this->GetASEnvironment(this)->StringContext.SWFVersion < 8u )
      goto LABEL_29;
    v15 = this->GetASEnvironment(this);
    v16 = Scaleform::GFx::AS2::Value::ToObject(&v21, v15);
    v17 = (Scaleform::GFx::AS2::RectangleObject *)v16;
    if ( v16 && v16->GetObjectType(&v16->Scaleform::GFx::AS2::ObjectInterface) == Object_Rectangle )
    {
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(v17, v15, &r);
      *(float *)&prop.pNode = r.x1;
      pDispObj = this->pDispObj;
      *(float *)&resultVal.T.Type = *(float *)&prop.pNode * 20.0;
      *(float *)&prop.pNode = r.y1;
      *(float *)&resultVal.V.pStringNode = *(float *)&prop.pNode * 20.0;
      *(float *)&prop.pNode = r.x2 - r.x1;
      *(float *)&prop.pNode = *(float *)&prop.pNode * 20.0;
      *(float *)&resultVal.V.FunctionValue.pLocalFrame = *(float *)&prop.pNode + *(float *)&resultVal.T.Type;
      *(float *)&prop.pNode = r.y2 - r.y1;
      *(float *)&prop.pNode = 20.0 * *(float *)&prop.pNode;
      *((float *)&resultVal.NV + 3) = *(float *)&prop.pNode + *(float *)&resultVal.V.pStringNode;
      pDispObj->SetScale9Grid(pDispObj, (const Scaleform::Render::Rect<float> *)&resultVal);
    }
    else
    {
      v19 = this->pDispObj;
      v23[0] = 0.0;
      v23[1] = 0.0;
      v23[2] = 0.0;
      v23[3] = 0.0;
      v19->SetScale9Grid(v19, (const Scaleform::Render::Rect<float> *)v23);
    }
LABEL_26:
    if ( v21.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    return 1;
  }
  if ( v6 == M_hitTestDisable && this->GetASEnvironment(this)->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v12 = this->pDispObj;
    v13 = this->GetASEnvironment(this);
    if ( Scaleform::GFx::AS2::Value::ToBool(&v21, v13) )
      v12->Flags |= 0x800u;
    else
      v12->Flags &= ~0x800u;
    if ( v21.T.Type >= 5u )
    {
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
      return 1;
    }
    return 1;
  }
LABEL_29:
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  return 0;
}
