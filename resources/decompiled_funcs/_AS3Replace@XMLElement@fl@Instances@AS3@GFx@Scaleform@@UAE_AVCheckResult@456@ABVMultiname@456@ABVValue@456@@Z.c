Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::AS3Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SoundObject *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v8; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::CheckResult *v10; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  unsigned int Size; // esi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::V2U v16; // ebx
  int v17; // edi
  bool v18; // zf
  bool v19; // cl
  Scaleform::GFx::AS3::Object *pV; // [esp-4h] [ebp-50h]
  Scaleform::GFx::ASString s; // [esp+10h] [ebp-3Ch] BYREF
  unsigned int ind[2]; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value i; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value c; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+3Ch] [ebp-10h] BYREF

  v4 = value;
  pVM = this->pTraits.pObject->pVM;
  v7 = (value->Flags & 0x1F) - 12;
  c.Flags = 0;
  c.Bonus.pWeakProxy = 0;
  if ( v7 <= 3 && Scaleform::GFx::AS3::IsXMLObject(value->value.VS._1.VObj) )
  {
    v8 = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value **, _DWORD))(*(_DWORD *)v4->value.VS._1.VInt + 128))(
                                                                               v4->value.VS._1,
                                                                               &value,
                                                                               0);
    goto LABEL_4;
  }
  if ( (v4->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(v4->value.VS._1.VObj) )
  {
    v8 = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(
           (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VInt,
           (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&value,
           0);
LABEL_4:
    pV = v8->pV;
    other.Flags = 0;
    other.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::PickUnsafe(&other, pV);
    Scaleform::GFx::AS3::Value::Assign(&c, &other);
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
    goto LABEL_19;
  }
  pStringManager = pVM->StringManagerRef->pStringManager;
  s.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&value, &s)->Result )
  {
    v10 = result;
    pNode = s.pNode;
    p_RefCount = &s.pNode->RefCount;
    result->Result = 0;
    if ( !--*p_RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (c.Flags & 0x1F) <= 9 )
      return v10;
    if ( (c.Flags & 0x200) == 0 )
      goto LABEL_44;
LABEL_43:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&c);
    return v10;
  }
  Scaleform::GFx::AS3::Value::Assign(&c, &s);
  v13 = s.pNode;
  --s.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
LABEL_19:
  if ( !Scaleform::GFx::AS3::GetVectorInd(
          (Scaleform::GFx::AS3::CheckResult *)&value,
          (const Scaleform::GFx::AS3::Multiname *)prop_name,
          ind)->Result )
  {
    Size = this->Children.Data.Size;
    LOWORD(Flags) = 0;
    i.Bonus.pWeakProxy = 0;
    i.Flags = 0;
    if ( Size )
    {
      v16.VObj = (Scaleform::GFx::AS3::Object *)ind[1];
      v17 = 4 * Size - 4;
      do
      {
        v18 = !Scaleform::GFx::AS3::Instances::fl::XML::Matches(
                 *(Scaleform::GFx::AS3::Instances::fl::XML **)((char *)&this->Children.Data.Data->pObject + v17),
                 prop_name);
        Flags = i.Flags;
        if ( !v18 )
        {
          if ( (i.Flags & 0x1F) != 0 )
          {
            this->DeleteByIndex(this, i.value.VS._1.VInt);
            Flags = i.Flags;
          }
          if ( (Flags & 0x1F) > 9 )
          {
            if ( (Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&i);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&i);
            Flags = i.Flags;
          }
          Flags = Flags & 0xFFFFFFE0 | 2;
          i.Flags = Flags;
          i.value.VS._1.VInt = Size - 1;
          i.value.VS._2 = v16;
        }
        --Size;
        v17 -= 4;
      }
      while ( Size );
    }
    v19 = 1;
    if ( (Flags & 0x1F) != 0 )
    {
      v19 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
              this,
              (Scaleform::GFx::AS3::CheckResult *)&prop_name,
              i.value.VS._1.VStr,
              &c)->Result;
      LOWORD(Flags) = i.Flags;
    }
    v10 = result;
    result->Result = v19;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&i);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&i);
    }
    if ( (c.Flags & 0x1F) <= 9 )
      return v10;
    if ( (c.Flags & 0x200) == 0 )
      goto LABEL_44;
    goto LABEL_43;
  }
  v10 = result;
  Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(this, result, (Scaleform::GFx::ASStringNode *)ind[0], &c);
  if ( (c.Flags & 0x1F) > 9 )
  {
    if ( (c.Flags & 0x200) != 0 )
      goto LABEL_43;
LABEL_44:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&c);
  }
  return v10;
}
