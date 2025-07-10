bool __thiscall Scaleform::GFx::AS2::AvmSprite::SetStandardMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        const Scaleform::GFx::AS2::Value *origVal,
        Scaleform::String opcodeFlag)
{
  Scaleform::GFx::AS2::Environment *v5; // eax
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v6; // ebx
  Scaleform::GFx::AS2::Environment *v7; // edi
  Scaleform::GFx::AS2::MovieClipObject *pObject; // eax
  char *pName; // edx
  Scaleform::GFx::ASStringManager *pMovieImpl; // ecx
  char v11; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v13; // cf
  bool result; // al
  Scaleform::GFx::Sprite *pDispObj; // edi
  const Scaleform::GFx::AS2::Environment *v16; // eax
  char v17; // al
  unsigned __int8 Type; // bl
  Scaleform::GFx::InteractiveObject *v19; // edi
  const Scaleform::GFx::AS2::Environment *v20; // eax
  unsigned __int8 v21; // bl
  const Scaleform::GFx::AS2::Environment *v22; // eax
  char v23; // al
  Scaleform::GFx::InteractiveObject *v24; // edi
  const Scaleform::GFx::AS2::Environment *v25; // eax
  char v26; // al
  const Scaleform::GFx::AS2::Environment *v27; // eax
  Scaleform::GFx::Sprite *v28; // eax
  Scaleform::GFx::AS2::Environment *v29; // ebx
  Scaleform::GFx::AS2::Object *v30; // eax
  Scaleform::GFx::AS2::RectangleObject *v31; // edi
  Scaleform::GFx::InteractiveObject *v32; // ecx
  Scaleform::GFx::InteractiveObject *v33; // esi
  Scaleform::GFx::AS2::Environment *v34; // ebx
  Scaleform::GFx::AS2::Object *v35; // eax
  Scaleform::GFx::AS2::RectangleObject *v36; // edi
  Scaleform::GFx::ASString prop; // [esp+19Ch] [ebp-64h] BYREF
  Scaleform::GFx::AS2::Value v38; // [esp+1A0h] [ebp-60h] BYREF
  Scaleform::Render::Rect<double> resultVal; // [esp+1B0h] [ebp-50h] BYREF
  float v40[4]; // [esp+1D0h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+1E0h] [ebp-20h] BYREF

  Scaleform::GFx::AS2::Value::Value(&v38, origVal);
  v5 = this->GetASEnvironment(this);
  v6 = member;
  v7 = v5;
  if ( member > M_ymouse )
  {
    if ( v5 )
    {
      pObject = this->ASMovieClipObj.pObject;
      if ( pObject )
      {
        if ( pObject->pWatchpoints )
        {
          pName = (char *)Scaleform::GFx::AS2::AvmCharacter::MemberTable[member].pName;
          pMovieImpl = (Scaleform::GFx::ASStringManager *)v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
          LOBYTE(resultVal.x1) = 0;
          *(float *)&prop.pNode = COERCE_FLOAT(
                                    Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                      pMovieImpl,
                                      pName,
                                      strlen(pName),
                                      0));
          ++prop.pNode->RefCount;
          v11 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(
                  this->ASMovieClipObj.pObject,
                  v7,
                  &prop,
                  &v38,
                  (Scaleform::GFx::AS2::Value *)&resultVal);
          pNode = prop.pNode;
          --prop.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( v11 )
            Scaleform::GFx::AS2::Value::operator=(&v38, (const Scaleform::GFx::AS2::Value *)&resultVal);
          if ( LOBYTE(resultVal.x1) >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&resultVal);
          v6 = member;
        }
      }
    }
  }
  if ( Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(this, v6, &v38, opcodeFlag) )
  {
$LN22_27:
    v13 = v38.T.Type < 5u;
LABEL_15:
    if ( !v13 )
      Scaleform::GFx::AS2::Value::DropRefs(&v38);
    return 1;
  }
  else
  {
    switch ( v6 )
    {
      case M_currentframe:
      case M_totalframes:
      case M_framesloaded:
        goto $LN22_27;
      case M_lockroot:
        pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
        v16 = this->GetASEnvironment(this);
        v17 = Scaleform::GFx::AS2::Value::ToBool(&v38, v16);
        Scaleform::GFx::Sprite::SetLockRoot(pDispObj, v17);
        if ( v38.T.Type < 5u )
          return 1;
        Scaleform::GFx::AS2::Value::DropRefs(&v38);
        return 1;
      case M_focusEnabled:
        Type = v38.T.Type;
        if ( !v38.T.Type || v38.T.Type == 10 )
        {
          BYTE1(this->pDispObj[1].pIndXFormData) = 0;
          v13 = Type < 5u;
        }
        else
        {
          v19 = this->pDispObj;
          v20 = this->GetASEnvironment(this);
          BYTE1(v19[1].pIndXFormData) = 2 - (Scaleform::GFx::AS2::Value::ToBool(&v38, v20) != 0);
          v13 = Type < 5u;
        }
        goto LABEL_15;
      case M_tabChildren:
        v21 = v38.T.Type;
        if ( !v38.T.Type || v38.T.Type == 10 )
        {
          this->TabChildren.Value = 0;
          v13 = v21 < 5u;
        }
        else
        {
          v22 = this->GetASEnvironment(this);
          v23 = Scaleform::GFx::AS2::Value::ToBool(&v38, v22);
          this->TabChildren.Value = (v23 == 0) + 1;
          Scaleform::GFx::InteractiveObject::SetTabChildrenDisabledFlag(this->pDispObj, v23 == 0);
          v13 = v21 < 5u;
        }
        goto LABEL_15;
      case M_scale9Grid:
        if ( this->GetASEnvironment(this)->StringContext.SWFVersion < 8u )
          goto LABEL_44;
        v29 = this->GetASEnvironment(this);
        v30 = Scaleform::GFx::AS2::Value::ToObject(&v38, v29);
        v31 = (Scaleform::GFx::AS2::RectangleObject *)v30;
        if ( v30 && v30->GetObjectType(&v30->Scaleform::GFx::AS2::ObjectInterface) == Object_Rectangle )
        {
          r.x1 = 0.0;
          r.y1 = 0.0;
          r.x2 = 0.0;
          r.y2 = 0.0;
          Scaleform::GFx::AS2::RectangleObject::GetProperties(v31, v29, &r);
          *(float *)&prop.pNode = r.x1;
          v32 = this->pDispObj;
          *(float *)&resultVal.x1 = *(float *)&prop.pNode * 20.0;
          *(float *)&prop.pNode = r.y1;
          *((float *)&resultVal.x1 + 1) = *(float *)&prop.pNode * 20.0;
          *(float *)&prop.pNode = r.x2 - r.x1;
          *(float *)&prop.pNode = *(float *)&prop.pNode * 20.0;
          *(float *)&resultVal.y1 = *(float *)&prop.pNode + *(float *)&resultVal.x1;
          *(float *)&prop.pNode = r.y2 - r.y1;
          *(float *)&prop.pNode = 20.0 * *(float *)&prop.pNode;
          *((float *)&resultVal.y1 + 1) = *(float *)&prop.pNode + *((float *)&resultVal.x1 + 1);
          v32->SetScale9Grid(v32, (const Scaleform::Render::Rect<float> *)&resultVal);
        }
        else
        {
          v33 = this->pDispObj;
          v40[0] = 0.0;
          v40[1] = 0.0;
          v40[2] = 0.0;
          v40[3] = 0.0;
          v33->SetScale9Grid(v33, (const Scaleform::Render::Rect<float> *)v40);
        }
        goto $LN22_27;
      case M_hitArea:
        v27 = this->GetASEnvironment(this);
        v28 = (Scaleform::GFx::Sprite *)Scaleform::GFx::AS2::Value::ToCharacter(&v38, v27);
        if ( v28
          && (v28->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
            & 0x400) != 0 )
        {
          Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)this->pDispObj, v28);
          goto $LN22_27;
        }
        Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)this->pDispObj, 0);
LABEL_44:
        if ( v38.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v38);
        result = 0;
        break;
      case M_scrollRect:
        if ( this->GetASEnvironment(this)->StringContext.SWFVersion >= 8u )
        {
          v34 = this->GetASEnvironment(this);
          v35 = Scaleform::GFx::AS2::Value::ToObject(&v38, v34);
          v36 = (Scaleform::GFx::AS2::RectangleObject *)v35;
          if ( v35 )
          {
            if ( v35->GetObjectType(&v35->Scaleform::GFx::AS2::ObjectInterface) == Object_Rectangle )
            {
              r.x1 = 0.0;
              r.y1 = 0.0;
              r.x2 = 0.0;
              r.y2 = 0.0;
              Scaleform::GFx::AS2::RectangleObject::GetProperties(v36, v34, &r);
              resultVal.x1 = r.x1 * 20.0;
              resultVal.y1 = r.y1 * 20.0;
              resultVal.x2 = resultVal.x1 + (r.x2 - r.x1) * 20.0;
              resultVal.y2 = resultVal.y1 + 20.0 * (r.y2 - r.y1);
              Scaleform::GFx::DisplayObject::SetScrollRect(this->pDispObj, &resultVal);
            }
          }
          else
          {
            Scaleform::GFx::DisplayObject::SetScrollRect(this->pDispObj, 0);
          }
        }
        goto LABEL_44;
      case M_hitTestDisable:
        if ( this->GetASEnvironment(this)->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_44;
        v24 = this->pDispObj;
        v25 = this->GetASEnvironment(this);
        v26 = Scaleform::GFx::AS2::Value::ToBool(&v38, v25);
        Scaleform::GFx::InteractiveObject::SetHitTestDisableFlag(v24, v26);
        goto $LN22_27;
      default:
        goto LABEL_44;
    }
  }
  return result;
}
