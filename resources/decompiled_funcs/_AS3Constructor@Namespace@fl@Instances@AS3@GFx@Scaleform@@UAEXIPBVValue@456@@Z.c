void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  char v3; // bl
  Scaleform::GFx::AS3::VM *VMRef; // esi
  Scaleform::GFx::AS3::Value *v6; // ebp
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ecx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  const Scaleform::GFx::ASString *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *VStr; // ecx
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+Fh] [ebp-25h] BYREF
  Scaleform::GFx::ASString p; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::ASString v; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::ASString v22; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v23; // [esp+1Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+24h] [ebp-10h] BYREF

  v3 = 0;
  v22.pNode = 0;
  VMRef = this->VMRef;
  if ( argc )
  {
    v6 = argv;
    if ( argc != 1 )
    {
      StringManagerRef = VMRef->StringManagerRef;
      p.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
      ++p.pNode->RefCount;
      argv = (Scaleform::GFx::AS3::Value *)&StringManagerRef->pStringManager->EmptyStringNode;
      ++argv->value.VS._2.VObj;
      if ( Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&argc, &p)->Result
        && Scaleform::GFx::AS3::Value::Convert2String(v6 + 1, &result, (Scaleform::GFx::ASString *)&argv)->Result )
      {
        if ( !p.pNode->Size || argv[1].Bonus.pWeakProxy )
        {
          Scaleform::GFx::AS3::Value::Assign(&this->Prefix, v6);
          Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v6 + 1);
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v23, eXMLNamespaceWithPrefixAndNoURI, VMRef);
          Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v8);
          pNode = v23.Message.pNode;
          --v23.Message.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      v10 = (Scaleform::GFx::ASStringNode *)argv;
      --argv->value.VS._2.VObj;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v11 = p.pNode;
      --p.pNode->RefCount;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      return;
    }
    if ( (argv->Flags & 0x1F) == 0xB )
    {
      Scaleform::GFx::AS3::Instances::fl::Namespace::operator=(this, argv->value.VS._1.VNs);
      return;
    }
    if ( Scaleform::GFx::AS3::IsQNameObject(argv) )
    {
      v12 = *(const Scaleform::GFx::ASString **)(v6->value.VS._1.VInt + 36);
      if ( v12 )
      {
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v12 + 7);
      }
      else
      {
        v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                VMRef->StringManagerRef,
                &v22,
                "*");
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v13);
        v14 = v22.pNode;
        --v22.pNode->RefCount;
        if ( !v14->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      }
      return;
    }
    Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v6);
    if ( (v6->Flags & 0x1F) == 0xA )
    {
      VStr = v6->value.VS._1.VStr;
      v3 = 1;
      ++VStr->RefCount;
      if ( !VStr->Size )
      {
        LOBYTE(argv) = 1;
        goto LABEL_26;
      }
    }
    else
    {
      VStr = (Scaleform::GFx::ASStringNode *)argv;
    }
    LOBYTE(argv) = 0;
LABEL_26:
    if ( (v3 & 1) != 0 && VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    if ( (_BYTE)argv )
    {
      Scaleform::GFx::AS3::Value::Assign(&this->Prefix, v6);
    }
    else
    {
      Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
      Scaleform::GFx::AS3::Value::Assign(&this->Prefix, Undefined);
    }
    return;
  }
  v.pNode = &VMRef->StringManagerRef->pStringManager->EmptyStringNode;
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&other, &v);
  Scaleform::GFx::AS3::Value::Assign(&this->Prefix, &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
  }
  v18 = v.pNode;
  --v.pNode->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}
