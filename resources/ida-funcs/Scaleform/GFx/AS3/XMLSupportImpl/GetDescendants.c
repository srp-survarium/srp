Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::GetDescendants(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Instances::fl::XMLList *v,
        const Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *v4; // esi
  unsigned int v5; // eax
  bool v7; // dl
  Scaleform::GFx::AS3::Value::V1U pNext; // ecx
  int v9; // ebp
  Scaleform::GFx::AS3::Object *v10; // edi
  Scaleform::GFx::AS3::Value::V1U v11; // eax
  int v12; // eax
  Scaleform::GFx::AS3::CheckResult *v13; // eax

  v4 = (Scaleform::GFx::AS3::Value *)v;
  v5 = (int)v->__vftable & 0x1F;
  v7 = 0;
  if ( v5 - 12 <= 3 )
  {
    pNext = (Scaleform::GFx::AS3::Value::V1U)v->pNext;
    if ( pNext.VInt )
    {
      v9 = *(_DWORD *)(pNext.VInt + 20);
      if ( *(_DWORD *)(v9 + 60) == 13 && (*(_DWORD *)(v9 + 56) & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::XMLSupportImpl::MakeXMLList(
          this,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v);
        v10 = v;
        (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Instances::fl::XMLList *, const Scaleform::GFx::AS3::Multiname *))(*(_DWORD *)v4->value.VS._1.VInt + 156))(
          v4->value.VS._1,
          v,
          mn);
LABEL_11:
        Scaleform::GFx::AS3::Value::Pick(v4, v10);
        v7 = 1;
        goto LABEL_12;
      }
    }
  }
  if ( v5 - 12 <= 3 )
  {
    v11 = (Scaleform::GFx::AS3::Value::V1U)v->pNext;
    if ( v11.VInt )
    {
      v12 = *(_DWORD *)(v11.VInt + 20);
      if ( *(_DWORD *)(v12 + 60) == 14 && (*(_DWORD *)(v12 + 56) & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::XMLSupportImpl::MakeXMLList(
          this,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v);
        v10 = v;
        Scaleform::GFx::AS3::Instances::fl::XMLList::GetDescendants(
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VInt,
          v,
          mn);
        goto LABEL_11;
      }
    }
  }
LABEL_12:
  v13 = result;
  result->Result = v7;
  return v13;
}
