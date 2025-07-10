char __userpurge Scaleform::GFx::AS2::AvmSprite::GetStandardMember@<al>(
        Scaleform::GFx::AS2::AvmSprite *this@<ecx>,
        double a2@<st0>,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *pval,
        bool opcodeFlag)
{
  unsigned int v6; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned __int8 Value; // al
  Scaleform::GFx::AS2::Value *v11; // ecx
  Scaleform::GFx::AS2::Environment *v12; // ebx
  Scaleform::GFx::AS2::RectangleObject *v13; // eax
  Scaleform::GFx::AS2::RectangleObject *v14; // eax
  Scaleform::GFx::AS2::RectangleObject *v15; // esi
  const Scaleform::Render::Rect<double> *p_r; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::AS2::RectangleObject *v19; // eax
  Scaleform::GFx::AS2::RectangleObject *v20; // eax
  float v21; // [esp+CCh] [ebp-44h]
  float v22; // [esp+CCh] [ebp-44h]
  float v23; // [esp+CCh] [ebp-44h]
  float v24; // [esp+CCh] [ebp-44h]
  Scaleform::Render::Rect<float> result; // [esp+D0h] [ebp-40h] BYREF
  long double v26; // [esp+E0h] [ebp-30h]
  long double v27; // [esp+E8h] [ebp-28h]
  Scaleform::Render::Rect<double> r; // [esp+F0h] [ebp-20h] BYREF

  if ( Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(this, a2, member, pval, opcodeFlag) )
    return 1;
  switch ( member )
  {
    case M_currentframe:
      v6 = this->pDispObj->GetCurrentFrame(this->pDispObj);
      Scaleform::GFx::AS2::Value::SetInt(pval, v6 + 1);
      return 1;
    case M_totalframes:
      v8 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->pDispObj[1].CreateFrame + 40))(this->pDispObj[1].CreateFrame);
      Scaleform::GFx::AS2::Value::SetInt(pval, v8);
      return 1;
    case M_framesloaded:
      v9 = this->pDispObj->GetLoadingFrame(this->pDispObj);
      Scaleform::GFx::AS2::Value::SetInt(pval, v9);
      return 1;
    case M_lockroot:
      Scaleform::GFx::AS2::Value::SetBool(pval, ((int)this->pDispObj[1].pIndXFormData & 0x20) != 0);
      return 1;
    case M_focusEnabled:
      Value = BYTE1(this->pDispObj[1].pIndXFormData);
      v11 = pval;
      if ( Value )
        goto LABEL_9;
      goto LABEL_12;
    case M_tabChildren:
      Value = this->TabChildren.Value;
      if ( !Value )
        goto LABEL_11;
LABEL_9:
      Scaleform::GFx::AS2::Value::SetBool(pval, Value == 1);
      return 1;
    case M_scale9Grid:
      if ( this->GetASEnvironment(this)->StringContext.SWFVersion < 8u )
        return 0;
      if ( !Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this->pDispObj) )
        goto LABEL_11;
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj, &result);
      v12 = (Scaleform::GFx::AS2::Environment *)this->GetASEnvironment(this);
      v13 = (Scaleform::GFx::AS2::RectangleObject *)v12->StringContext.pContext->pHeap->Alloc(
                                                      v12->StringContext.pContext->pHeap,
                                                      52u,
                                                      0);
      if ( v13 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v13, v12);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      p_r = &r;
      v21 = result.x1 * 0.05000000074505806;
      r.x1 = v21;
      v22 = result.y1 * 0.05000000074505806;
      r.y1 = v22;
      v23 = result.x2 * 0.05000000074505806;
      r.x2 = v23;
      v24 = 0.05000000074505806 * result.y2;
      r.y2 = v24;
      goto LABEL_24;
    case M_hitArea:
      if ( this->pDispObj[1].pGeomData )
      {
        Scaleform::GFx::AS2::Value::SetAsCharacterHandle(
          pval,
          (Scaleform::GFx::CharacterHandle *)this->pDispObj[1].pGeomData);
        return 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::DropRefs(pval);
        pval->T.Type = 0;
        return 0;
      }
    case M_scrollRect:
      if ( this->GetASEnvironment(this)->StringContext.SWFVersion < 8u )
        return 0;
      pDispObj = this->pDispObj;
      if ( !pDispObj->pScrollRect )
      {
LABEL_11:
        v11 = pval;
LABEL_12:
        Scaleform::GFx::AS2::Value::DropRefs(v11);
        pval->T.Type = 0;
        return 1;
      }
      Scaleform::Render::Rect<double>::Rect<double>(&r, &pDispObj->pScrollRect->Rectangle);
      v12 = (Scaleform::GFx::AS2::Environment *)this->GetASEnvironment(this);
      v19 = (Scaleform::GFx::AS2::RectangleObject *)v12->StringContext.pContext->pHeap->Alloc(
                                                      v12->StringContext.pContext->pHeap,
                                                      52u,
                                                      0);
      if ( v19 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v19, v12);
        v15 = v20;
      }
      else
      {
        v15 = 0;
      }
      p_r = (const Scaleform::Render::Rect<double> *)&result;
      *(double *)&result.x1 = r.x1 * 0.05;
      *(double *)&result.x2 = r.y1 * 0.05;
      v26 = r.x2 * 0.05;
      v27 = 0.05 * r.y2;
LABEL_24:
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v15, v12, p_r);
      Scaleform::GFx::AS2::Value::SetAsObject(pval, v15);
      if ( !v15 )
        return 1;
      RefCount = v15->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) == 0 )
        return 1;
      v15->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
      return 1;
    case M_hitTestDisable:
      if ( this->GetASEnvironment(this)->StringContext.pContext->GFxExtensions.Value != 1 )
        return 0;
      Scaleform::GFx::AS2::Value::SetBool(pval, (this->pDispObj->Flags & 0x800) != 0);
      return 1;
    default:
      return 0;
  }
}
