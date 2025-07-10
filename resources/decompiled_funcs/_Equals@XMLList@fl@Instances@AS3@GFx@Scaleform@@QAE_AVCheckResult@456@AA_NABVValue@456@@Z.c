Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::Equals(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *resulta,
        const Scaleform::GFx::AS3::Value *v)
{
  const Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *VInt; // eax
  unsigned int Size; // ecx
  int v9; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v12; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v13; // edx
  Scaleform::GFx::AS3::Instances::fl::XMLList *other; // [esp+Ch] [ebp-28h]
  unsigned int v15; // [esp+10h] [ebp-24h]
  Scaleform::GFx::AS3::Value l; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+24h] [ebp-10h] BYREF
  bool resultb; // [esp+3Ch] [ebp+8h]

  v4 = v;
  if ( (v->Flags & 0x1F) == 0 && !this->List.Data.Size )
  {
    *resulta = 1;
    v6 = result;
    result->Result = 1;
    return v6;
  }
  if ( (v->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(v->value.VS._1.VObj) )
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VInt;
    Size = this->List.Data.Size;
    other = VInt;
    v15 = Size;
    if ( VInt->List.Data.Size == Size )
    {
      v9 = 0;
      if ( Size )
      {
        while ( 1 )
        {
          Data = VInt->List.Data.Data;
          r.Flags = 0;
          r.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Value::AssignUnsafe(&r, Data[v9].pObject);
          v12 = this->List.Data.Data;
          l.Flags = 0;
          l.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Value::AssignUnsafe(&l, v12[v9].pObject);
          resultb = !Scaleform::GFx::AS3::AbstractEqual((Scaleform::GFx::AS3::CheckResult *)&v, resulta, &l, &r)->Result;
          if ( (l.Flags & 0x1F) > 9 )
          {
            if ( (l.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&l);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&l);
          }
          if ( (r.Flags & 0x1F) > 9 )
          {
            if ( (r.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
          }
          if ( resultb )
            break;
          if ( !*resulta )
            goto LABEL_21;
          if ( ++v9 >= v15 )
            goto LABEL_21;
          VInt = other;
        }
        v6 = result;
        result->Result = 0;
      }
      else
      {
LABEL_21:
        v6 = result;
        result->Result = 1;
      }
      return v6;
    }
LABEL_29:
    v6 = result;
    *resulta = 0;
    result->Result = 1;
    return v6;
  }
  if ( this->List.Data.Size != 1 )
    goto LABEL_29;
  v13 = this->List.Data.Data;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::AssignUnsafe(&r, v13->pObject);
  Scaleform::GFx::AS3::AbstractEqual(result, resulta, &r, v4);
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      return result;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
  return result;
}
