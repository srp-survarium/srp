int __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLElement *other)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v2; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // eax
  unsigned int Size; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *Data; // edx
  _DWORD *v11; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v12; // edi
  unsigned int v13; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v14; // edx
  int v15; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // eax
  int v17; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v18; // ecx
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-39h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v20; // [esp+14h] [ebp-38h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v21; // [esp+18h] [ebp-34h]
  unsigned int i; // [esp+1Ch] [ebp-30h]
  unsigned int v23; // [esp+20h] [ebp-2Ch]
  unsigned int v24; // [esp+24h] [ebp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v25; // [esp+28h] [ebp-24h]
  Scaleform::GFx::AS3::Value l; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v27; // [esp+3Ch] [ebp-10h] BYREF

  v2 = other;
  v3 = this;
  v21 = this;
  if ( this == other )
    return 1;
  v4 = other->GetKind(other);
  if ( v3->GetKind(v3) != v4 )
    return 2;
  if ( v3->Text.pNode != v2->Text.pNode )
    return 2;
  pObject = v3->Ns.pObject;
  v6 = v2->Ns.pObject;
  if ( pObject->Uri.pNode != v6->Uri.pNode )
    return 2;
  if ( ((*((_BYTE *)pObject + 20) ^ *((_BYTE *)v6 + 20)) & 0xF) != 0 )
    return 2;
  Size = v3->Attrs.Data.Size;
  v23 = Size;
  if ( Size != v2->Attrs.Data.Size )
    return 2;
  v9 = v3->Children.Data.Size;
  v24 = v9;
  if ( v9 != v2->Children.Data.Size )
    return 2;
  i = 0;
  if ( !Size )
    goto LABEL_23;
  Data = v3->Attrs.Data.Data;
  v25 = v2->Attrs.Data.Data;
  v20 = Data;
  while ( 2 )
  {
    v11 = &v20->pObject->__vftable;
    v12 = v25;
    v13 = 0;
    while ( 1 )
    {
      v14 = v12->pObject;
      if ( (Scaleform::GFx::ASStringNode *)v11[8] == v12->pObject->Text.pNode )
      {
        v15 = v11[10];
        if ( !v15 )
        {
          if ( v14->Ns.pObject )
            goto LABEL_28;
          goto LABEL_20;
        }
        v16 = v14->Ns.pObject;
        if ( v16 )
          break;
      }
LABEL_28:
      ++v13;
      ++v12;
      if ( v13 >= v23 )
        return 2;
    }
    if ( *(Scaleform::GFx::ASStringNode **)(v15 + 28) != v16->Uri.pNode
      || ((*((_BYTE *)v16 + 20) ^ *(_BYTE *)(v15 + 20)) & 0xF) != 0 )
    {
      v3 = v21;
      goto LABEL_28;
    }
    v3 = v21;
LABEL_20:
    if ( (Scaleform::GFx::ASStringNode *)v11[11] != v14->Data.pNode )
      goto LABEL_28;
    ++v20;
    if ( ++i < v23 )
      continue;
    break;
  }
  v9 = v24;
  v2 = other;
LABEL_23:
  v17 = 0;
  if ( !v9 )
    return 1;
  while ( 1 )
  {
    v18 = v2->Children.Data.Data;
    v27.Flags = 0;
    v27.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v27, v18[v17].pObject);
    l.Flags = 0;
    l.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&l, v3->Children.Data.Data[v17].pObject);
    Scaleform::GFx::AS3::AbstractEqual(&result, (bool *)&other, &l, &v27);
    if ( (l.Flags & 0x1F) > 9 )
    {
      if ( (l.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&l);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&l);
    }
    if ( (v27.Flags & 0x1F) > 9 )
    {
      if ( (v27.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v27);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
    if ( !(_BYTE)other )
      break;
    if ( ++v17 >= v24 )
      return 1;
  }
  return 2;
}
