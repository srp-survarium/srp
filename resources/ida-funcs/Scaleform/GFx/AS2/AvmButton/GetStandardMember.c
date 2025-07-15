char __userpurge Scaleform::GFx::AS2::AvmButton::GetStandardMember@<al>(
        Scaleform::GFx::AS2::AvmButton *this@<ecx>,
        double a2@<st0>,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *pval,
        bool opcodeFlag)
{
  bool v6; // bl
  Scaleform::GFx::AS2::Environment *v8; // ebx
  Scaleform::GFx::AS2::RectangleObject *v9; // eax
  Scaleform::GFx::AS2::RectangleObject *v10; // eax
  Scaleform::GFx::AS2::RectangleObject *v11; // esi
  unsigned int RefCount; // eax
  float v13; // [esp+5Ch] [ebp-34h]
  float v14; // [esp+5Ch] [ebp-34h]
  float v15; // [esp+5Ch] [ebp-34h]
  float v16; // [esp+5Ch] [ebp-34h]
  Scaleform::Render::Rect<float> result; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+70h] [ebp-20h] BYREF

  if ( Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(this, a2, member, pval, opcodeFlag) )
    return 1;
  if ( member != M_scale9Grid )
  {
    if ( member == M_hitTestDisable && this->GetASEnvironment(this)->StringContext.pContext->GFxExtensions.Value == 1 )
    {
      v6 = (this->pDispObj->Flags & 0x800) != 0;
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = v6;
      return 1;
    }
    return 0;
  }
  if ( this->GetASEnvironment(this)->StringContext.SWFVersion >= 8u )
  {
    if ( Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this->pDispObj) )
    {
      v8 = (Scaleform::GFx::AS2::Environment *)this->GetASEnvironment(this);
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj, &result);
      v9 = (Scaleform::GFx::AS2::RectangleObject *)v8->StringContext.pContext->pHeap->Alloc(
                                                     v8->StringContext.pContext->pHeap,
                                                     52u,
                                                     0);
      if ( v9 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      v13 = result.x1 * 0.05000000074505806;
      r.x1 = v13;
      v14 = result.y1 * 0.05000000074505806;
      r.y1 = v14;
      v15 = result.x2 * 0.05000000074505806;
      r.x2 = v15;
      v16 = 0.05000000074505806 * result.y2;
      r.y2 = v16;
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v11, v8, &r);
      Scaleform::GFx::AS2::Value::SetAsObject(pval, v11);
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
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
