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
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::InteractiveObject *v12; // edi
  const Scaleform::GFx::AS2::Environment *v13; // eax
  Scaleform::GFx::AS2::Environment *v15; // ebx
  Scaleform::GFx::AS2::Object *v16; // eax
  Scaleform::GFx::AS2::RectangleObject *v17; // edi
  Scaleform::GFx::InteractiveObject *pDispObj; // esi
  Scaleform::GFx::InteractiveObject *v19; // esi
  Scaleform::GFx::ASStringNode *v20; // [esp+Ch] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v22; // [esp+20h] [ebp-40h] BYREF
  float v23[4]; // [esp+30h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+40h] [ebp-20h] BYREF

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
    v22.T.Type = 0;
    *(float *)&v20 = COERCE_FLOAT(Scaleform::GFx::ASStringManager::CreateConstStringNode(pMovieImpl, pName, strlen(pName), 0));
    ++v20->RefCount;
    v10 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(
            this->ASButtonObj.pObject,
            v7,
            (const Scaleform::GFx::ASString *)&v20,
            &v21,
            &v22);
    v11 = v20;
    --v20->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( v10 )
      Scaleform::GFx::AS2::Value::operator=(&v21, &v22);
    if ( v22.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v22);
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
      *(float *)&v20 = r.x1;
      pDispObj = this->pDispObj;
      *(float *)&v22.T.Type = *(float *)&v20 * 20.0;
      *(float *)&v20 = r.y1;
      *(float *)&v22.V.pStringNode = *(float *)&v20 * 20.0;
      *(float *)&v20 = r.x2 - r.x1;
      *(float *)&v20 = *(float *)&v20 * 20.0;
      *(float *)&v22.V.FunctionValue.pLocalFrame = *(float *)&v20 + *(float *)&v22.T.Type;
      *(float *)&v20 = r.y2 - r.y1;
      *(float *)&v20 = 20.0 * *(float *)&v20;
      *((float *)&v22.NV + 3) = *(float *)&v20 + *(float *)&v22.V.pStringNode;
      pDispObj->SetScale9Grid(pDispObj, (const Scaleform::Render::Rect<float> *)&v22);
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
    if ( Scaleform::GFx::AS2::Value::ToBool(&v21, (int)v12, v13) )
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
