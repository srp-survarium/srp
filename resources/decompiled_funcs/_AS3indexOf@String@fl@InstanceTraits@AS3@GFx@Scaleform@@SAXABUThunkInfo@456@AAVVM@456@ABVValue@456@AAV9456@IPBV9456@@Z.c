void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3indexOf(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        const char *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v6; // edi
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Value::V2U v8; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringManager *v11; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  unsigned int v15; // ebp
  int i; // edi
  unsigned int v17; // eax
  unsigned int v18; // esi
  unsigned int v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASString searchAddRef; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString thisStr; // [esp+Ch] [ebp-18h] BYREF
  const char *search; // [esp+10h] [ebp-14h] BYREF
  const char *str; // [esp+14h] [ebp-10h] BYREF
  const char *s2; // [esp+18h] [ebp-Ch] BYREF
  int start[2]; // [esp+1Ch] [ebp-8h] BYREF

  v6 = (unsigned int)argc;
  if ( !argc )
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    v7 = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = -1;
    v8.VObj = (Scaleform::GFx::AS3::Object *)start[1];
    result->Flags = v7;
    result->value.VS._2 = v8;
    return;
  }
  StringManagerRef = vm->StringManagerRef;
  pStringManager = StringManagerRef->pStringManager;
  thisStr.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&argc, &thisStr)->Result )
    goto LABEL_15;
  v11 = StringManagerRef->pStringManager;
  v12 = argv;
  searchAddRef.pNode = &v11->EmptyStringNode;
  ++v11->EmptyStringNode.RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v12, (Scaleform::GFx::AS3::CheckResult *)&argc, &searchAddRef)->Result )
    goto LABEL_13;
  if ( !Scaleform::GFx::ASConstString::GetLength(&searchAddRef) )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, 0);
    goto LABEL_13;
  }
  search = searchAddRef.pNode->pData;
  str = thisStr.pNode->pData;
  start[0] = 0;
  if ( v6 > 1
    && !Scaleform::GFx::AS3::Value::Convert2Int32(v12 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, start)->Result )
  {
LABEL_13:
    pNode = searchAddRef.pNode;
    --searchAddRef.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_15:
    v14 = thisStr.pNode;
    --thisStr.pNode->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return;
  }
  v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&search);
  if ( !v15 )
    --search;
  for ( i = 0; ; ++i )
  {
    v17 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&str);
    if ( !v17 )
      break;
    if ( i >= start[0] && v17 == v15 )
    {
      argc = str;
      s2 = search;
      do
      {
        v18 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&argc);
        if ( !v18 )
          --argc;
        v19 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&s2);
        if ( !v19 )
          --s2;
        if ( !v18 )
          break;
        if ( !v19 )
          goto LABEL_41;
      }
      while ( v18 == v19 );
      if ( !v19 )
      {
LABEL_41:
        Scaleform::GFx::AS3::Value::SetSInt32(result, i);
        goto LABEL_36;
      }
      if ( !v18 )
        goto LABEL_35;
    }
  }
  --str;
LABEL_35:
  Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
LABEL_36:
  v20 = searchAddRef.pNode;
  --searchAddRef.pNode->RefCount;
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}
