char __userpurge Scaleform::GFx::AS2::AvmButton::GetStandardMember@<al>(
        Scaleform::GFx::AS2::AvmButton *this@<ecx>,
        double a2@<st0>,
        double a3@<st1>,
        int member,
        Scaleform::GFx::AS2::Value *pval,
        bool opcodeFlag)
{
  char v7; // al
  bool v8; // bl
  Scaleform::GFx::AS2::Environment *v10; // ebx
  Scaleform::GFx::AS2::RectangleObject *v11; // eax
  Scaleform::GFx::AS2::RectangleObject *v12; // eax
  Scaleform::GFx::AS2::RectangleObject *v13; // esi
  unsigned int RefCount; // eax
  float v15; // [esp+Ch] [ebp-34h]
  float v16; // [esp+Ch] [ebp-34h]
  float v17; // [esp+Ch] [ebp-34h]
  float v18; // [esp+Ch] [ebp-34h]
  Scaleform::Render::Rect<float> result; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+20h] [ebp-20h] BYREF

  Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(this, a2, a3, member, pval, opcodeFlag);
  if ( v7 )
    return 1;
  if ( member != 37 )
  {
    if ( member == 71 && this->GetASEnvironment(this)->StringContext.pContext->GFxExtensions.Value == 1 )
    {
      v8 = (this->pDispObj->Flags & 0x800) != 0;
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = v8;
      return 1;
    }
    return 0;
  }
  if ( this->GetASEnvironment(this)->StringContext.SWFVersion >= 8u )
  {
    if ( Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this->pDispObj) )
    {
      v10 = (Scaleform::GFx::AS2::Environment *)this->GetASEnvironment(this);
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj, &result);
      v11 = (Scaleform::GFx::AS2::RectangleObject *)v10->StringContext.pContext->pHeap->Alloc(
                                                      v10->StringContext.pContext->pHeap,
                                                      52u,
                                                      0);
      if ( v11 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v11, v10);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      v15 = result.x1 * 0.05000000074505806;
      r.x1 = v15;
      v16 = result.y1 * 0.05000000074505806;
      r.y1 = v16;
      v17 = result.x2 * 0.05000000074505806;
      r.x2 = v17;
      v18 = 0.05000000074505806 * result.y2;
      r.y2 = v18;
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v13, v10, &r);
      Scaleform::GFx::AS2::Value::SetAsObject(pval, v13);
      if ( v13 )
      {
        RefCount = v13->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v13->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
          return 1;
        }
      }
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 0;
    }
    return 1;
  }
  return 0;
}
