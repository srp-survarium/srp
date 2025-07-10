void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3lastIndexOf(
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
  Scaleform::GFx::AS3::Value *v11; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  int v15; // ebx
  unsigned int v16; // esi
  int v17; // ebp
  int i; // edi
  unsigned int v19; // eax
  unsigned int v20; // esi
  unsigned int Char_Advance0; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::ASString thisStr; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::ASString searchAddRef; // [esp+10h] [ebp-2Ch] BYREF
  const char *search; // [esp+14h] [ebp-28h] BYREF
  const char *str; // [esp+18h] [ebp-24h] BYREF
  long double s2; // [esp+1Ch] [ebp-20h] BYREF
  long double start_num; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value start_value; // [esp+2Ch] [ebp-10h] BYREF

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
    v8.VObj = *(Scaleform::GFx::AS3::Object **)((char *)&start_num + 4);
    result->Flags = v7;
    result->value.VS._2 = v8;
    return;
  }
  StringManagerRef = vm->StringManagerRef;
  thisStr.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++thisStr.pNode->RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&argc, &thisStr)->Result )
    goto LABEL_11;
  pStringManager = StringManagerRef->pStringManager;
  v11 = argv;
  searchAddRef.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v11, (Scaleform::GFx::AS3::CheckResult *)&argc, &searchAddRef)->Result )
  {
    pNode = searchAddRef.pNode;
    --searchAddRef.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_11:
    v13 = thisStr.pNode;
    --thisStr.pNode->RefCount;
    v14 = v13;
    if ( v13->RefCount )
      return;
    goto LABEL_50;
  }
  str = thisStr.pNode->pData;
  search = searchAddRef.pNode->pData;
  v15 = 0x7FFFFFF;
  if ( v6 > 1 )
  {
    start_num = 134217727.0;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(v11 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &start_num)->Result )
      goto LABEL_47;
    v15 = 0;
    start_value.value.VNumber = start_num;
    s2 = start_num;
    start_value.Flags = 4;
    start_value.Bonus.pWeakProxy = 0;
    if ( (HIDWORD(s2) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(s2) | LODWORD(s2)
      || (s2 = start_num, start_num == INFINITY) )
    {
      v15 = 0x7FFFFFF;
    }
    else
    {
      s2 = start_num;
      if ( start_num != -INFINITY )
        v15 = (int)start_num;
    }
    Scaleform::GFx::AS3::Value::~Value(&start_value);
  }
  if ( Scaleform::GFx::ASConstString::GetLength(&searchAddRef) )
  {
    v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&search);
    LODWORD(start_num) = v16;
    if ( !v16 )
      --search;
    v17 = -1;
    for ( i = 0; ; ++i )
    {
      v19 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&str);
      if ( !v19 )
        break;
      if ( i <= v15 && v19 == v16 )
      {
        argc = str;
        LODWORD(s2) = search;
        do
        {
          v20 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&argc);
          if ( !v20 )
            --argc;
          Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&s2);
          if ( !Char_Advance0 )
            --LODWORD(s2);
          if ( !v20 )
            break;
          if ( !Char_Advance0 )
            goto LABEL_41;
        }
        while ( v20 == Char_Advance0 );
        if ( Char_Advance0 )
          goto LABEL_42;
LABEL_41:
        v17 = i;
LABEL_42:
        if ( !v20 )
          goto LABEL_46;
        v16 = LODWORD(start_num);
      }
    }
    --str;
LABEL_46:
    Scaleform::GFx::AS3::Value::SetSInt32(result, v17);
  }
  else if ( v6 <= 1 )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, thisStr.pNode->Size);
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, v15);
  }
LABEL_47:
  v22 = searchAddRef.pNode;
  --searchAddRef.pNode->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v23 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  v14 = v23;
  if ( !v23->RefCount )
LABEL_50:
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}
