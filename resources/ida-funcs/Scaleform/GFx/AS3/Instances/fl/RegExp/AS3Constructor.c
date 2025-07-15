void __thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebp
  Scaleform::GFx::AS3::Value *v5; // edi
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ecx
  Scaleform::GFx::AS3::Instances::fl::RegExp *VInt; // ebp
  const Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASStringNode *ID; // eax
  const Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v15; // edi
  const char *Flags; // esi
  const char *pData; // edi
  char v18; // al
  int v19; // ecx
  const Scaleform::GFx::AS3::Value *v20; // edx
  int v21; // eax
  char i; // al
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASString opt; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::VM::Error result; // [esp+Ch] [ebp-10h] BYREF
  int errorOffset; // [esp+14h] [ebp-8h] BYREF
  const char *error; // [esp+18h] [ebp-4h] BYREF

  v3 = argc;
  if ( !argc )
    return;
  v5 = argv;
  if ( (argv->Flags & 0x1F) == 0 || (argv->Flags & 0x1F) - 12 <= 3 && !argv->value.VS._1.VInt )
    return;
  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  argv = (Scaleform::GFx::AS3::Value *)&StringManagerRef->pStringManager->EmptyStringNode;
  ++argv->value.VS._2.VObj;
  opt.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++opt.pNode->RefCount;
  if ( (v5->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(pVM, v5, "RegExp", pVM->CurrentDomain) )
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v5->value.VS._1.VInt;
    v9 = Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(VInt, (Scaleform::GFx::ASString *)&result);
    Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&argv, v9);
    ID = (Scaleform::GFx::ASStringNode *)result.ID;
    --*(_DWORD *)(result.ID + 12);
    if ( !ID->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(ID);
    v11 = Scaleform::GFx::AS3::Instances::fl::RegExp::optionFlagsGet(VInt, (Scaleform::GFx::ASString *)&result);
    Scaleform::GFx::ASString::operator=(&opt, v11);
    v12 = (Scaleform::GFx::ASStringNode *)result.ID;
    --*(_DWORD *)(result.ID + 12);
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( argc >= 2 && !Scaleform::GFx::AS3::Value::IsNullOrUndefined(v5 + 1) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&result, eRegExpFlagsArgumentError, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v13);
      pNode = result.Message.pNode;
      --result.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_43;
    }
LABEL_19:
    Flags = (const char *)argv->Flags;
    pData = opt.pNode->pData;
    Scaleform::String::operator=(&this->Pattern, (char *)argv->Flags);
    v18 = *Flags;
    v19 = 0;
    if ( *Flags )
    {
      v20 = argv;
      do
      {
        if ( v18 == 40 && Flags[1] == 63 && Flags[2] == 80 && Flags[3] == 60 )
        {
          this->HasNamedGroups = 1;
        }
        else if ( !pData && v18 == 47 && (Flags == (const char *)v20->Flags || *(Flags - 1) != 92) )
        {
          v21 = v19++;
          if ( v21 > 0 )
            pData = Flags;
        }
        v18 = *++Flags;
      }
      while ( v18 );
    }
    if ( pData )
    {
      for ( i = *pData; i; ++pData )
      {
        switch ( i )
        {
          case 'g':
            this->IsGlobal = 1;
            break;
          case 'i':
            this->OptionFlags |= 1u;
            break;
          case 'm':
            this->OptionFlags |= 2u;
            break;
          case 's':
            this->OptionFlags |= 4u;
            break;
          case 'x':
            this->OptionFlags |= 8u;
            break;
          default:
            break;
        }
        i = pData[1];
      }
    }
    this->CompRegExp = (struct real_pcre *)pcre_compile(
                                             (unsigned __int8 *)((this->Pattern.HeapTypeBits & 0xFFFFFFFC) + 8),
                                             this->OptionFlags,
                                             &error,
                                             &errorOffset,
                                             0);
    goto LABEL_43;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2String(
         v5,
         (Scaleform::GFx::AS3::CheckResult *)&argc,
         (Scaleform::GFx::ASString *)&argv)->Result )
  {
    if ( v3 < 2 )
      goto LABEL_19;
    v15 = v5 + 1;
    if ( Scaleform::GFx::AS3::Value::IsNullOrUndefined(v15)
      || Scaleform::GFx::AS3::Value::Convert2String(v15, (Scaleform::GFx::AS3::CheckResult *)&argc, &opt)->Result )
    {
      goto LABEL_19;
    }
  }
LABEL_43:
  v23 = opt.pNode;
  --opt.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  v24 = (Scaleform::GFx::ASStringNode *)argv;
  --argv->value.VS._2.VObj;
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
}
