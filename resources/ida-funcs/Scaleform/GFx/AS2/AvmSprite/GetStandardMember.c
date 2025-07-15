char __userpurge Scaleform::GFx::AS2::AvmSprite::GetStandardMember@<al>(
        Scaleform::GFx::AS2::AvmSprite *this@<ecx>,
        double a2@<st0>,
        double a3@<st1>,
        int member,
        Scaleform::GFx::AS2::Value *pval,
        bool opcodeFlag)
{
  char v7; // al
  unsigned int v8; // eax
  int v10; // eax
  int v11; // eax
  unsigned __int8 Value; // al
  Scaleform::GFx::AS2::Value *v13; // ecx
  Scaleform::GFx::AS2::Environment *v14; // ebx
  Scaleform::GFx::AS2::RectangleObject *v15; // eax
  Scaleform::GFx::AS2::RectangleObject *v16; // eax
  Scaleform::GFx::AS2::RectangleObject *v17; // esi
  const Scaleform::Render::Rect<double> *p_r; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::AS2::RectangleObject *v21; // eax
  Scaleform::GFx::AS2::RectangleObject *v22; // eax
  float v23; // [esp+Ch] [ebp-44h]
  float v24; // [esp+Ch] [ebp-44h]
  float v25; // [esp+Ch] [ebp-44h]
  float v26; // [esp+Ch] [ebp-44h]
  Scaleform::Render::Rect<float> result; // [esp+10h] [ebp-40h] BYREF
  long double v28; // [esp+20h] [ebp-30h]
  long double v29; // [esp+28h] [ebp-28h]
  Scaleform::Render::Rect<double> r; // [esp+30h] [ebp-20h] BYREF

  Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(this, a2, a3, member, pval, opcodeFlag);
  if ( v7 )
    return 1;
  switch ( member )
  {
    case 4:
      v8 = this->pDispObj->GetCurrentFrame(this->pDispObj);
      Scaleform::GFx::AS2::Value::SetInt(pval, v8 + 1);
      return 1;
    case 5:
      v10 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->pDispObj[1].CreateFrame + 40))(this->pDispObj[1].CreateFrame);
      Scaleform::GFx::AS2::Value::SetInt(pval, v10);
      return 1;
    case 12:
      v11 = this->pDispObj->GetLoadingFrame(this->pDispObj);
      Scaleform::GFx::AS2::Value::SetInt(pval, v11);
      return 1;
    case 28:
      Scaleform::GFx::AS2::Value::SetBool(pval, ((int)this->pDispObj[1].pIndXFormData & 0x20) != 0);
      return 1;
    case 34:
      Value = BYTE1(this->pDispObj[1].pIndXFormData);
      v13 = pval;
      if ( Value )
        goto LABEL_9;
      goto LABEL_12;
    case 35:
      Value = this->TabChildren.Value;
      if ( !Value )
        goto LABEL_11;
LABEL_9:
      Scaleform::GFx::AS2::Value::SetBool(pval, Value == 1);
      return 1;
    case 37:
      if ( this->GetASEnvironment(this)->StringContext.SWFVersion < 8u )
        return 0;
      if ( !Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this->pDispObj) )
        goto LABEL_11;
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj, &result);
      v14 = (Scaleform::GFx::AS2::Environment *)this->GetASEnvironment(this);
      v15 = (Scaleform::GFx::AS2::RectangleObject *)v14->StringContext.pContext->pHeap->Alloc(
                                                      v14->StringContext.pContext->pHeap,
                                                      52u,
                                                      0);
      if ( v15 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v15, v14);
        v17 = v16;
      }
      else
      {
        v17 = 0;
      }
      p_r = &r;
      v23 = result.x1 * 0.05000000074505806;
      r.x1 = v23;
      v24 = result.y1 * 0.05000000074505806;
      r.y1 = v24;
      v25 = result.x2 * 0.05000000074505806;
      r.x2 = v25;
      v26 = 0.05000000074505806 * result.y2;
      r.y2 = v26;
      goto LABEL_24;
    case 38:
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
    case 39:
      if ( this->GetASEnvironment(this)->StringContext.SWFVersion < 8u )
        return 0;
      pDispObj = this->pDispObj;
      if ( !pDispObj->pScrollRect )
      {
LABEL_11:
        v13 = pval;
LABEL_12:
        Scaleform::GFx::AS2::Value::DropRefs(v13);
        pval->T.Type = 0;
        return 1;
      }
      Scaleform::Render::Rect<double>::Rect<double>(&r, &pDispObj->pScrollRect->Rectangle);
      v14 = (Scaleform::GFx::AS2::Environment *)this->GetASEnvironment(this);
      v21 = (Scaleform::GFx::AS2::RectangleObject *)v14->StringContext.pContext->pHeap->Alloc(
                                                      v14->StringContext.pContext->pHeap,
                                                      52u,
                                                      0);
      if ( v21 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v21, v14);
        v17 = v22;
      }
      else
      {
        v17 = 0;
      }
      p_r = (const Scaleform::Render::Rect<double> *)&result;
      *(double *)&result.x1 = r.x1 * 0.05;
      *(double *)&result.x2 = r.y1 * 0.05;
      v28 = r.x2 * 0.05;
      v29 = 0.05 * r.y2;
LABEL_24:
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v17, v14, p_r);
      Scaleform::GFx::AS2::Value::SetAsObject(pval, v17);
      if ( !v17 )
        return 1;
      RefCount = v17->RefCount;
      if ( (RefCount & 0x3FFFFFF) == 0 )
        return 1;
      v17->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
      return 1;
    case 71:
      if ( this->GetASEnvironment(this)->StringContext.pContext->GFxExtensions.Value != 1 )
        return 0;
      Scaleform::GFx::AS2::Value::SetBool(pval, (this->pDispObj->Flags & 0x800) != 0);
      return 1;
    default:
      return 0;
  }
}
