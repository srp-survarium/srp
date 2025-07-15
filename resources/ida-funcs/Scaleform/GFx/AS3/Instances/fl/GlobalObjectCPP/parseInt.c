void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::parseInt(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  unsigned int Size; // esi
  double v9; // st7
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString str; // [esp+Ch] [ebp-1Ch] BYREF
  int radix; // [esp+10h] [ebp-18h] BYREF
  unsigned int offset; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+18h] [ebp-10h] BYREF

  v4 = argv;
  v5 = argc;
  str.pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[16].pNode;
  ++str.pNode->RefCount;
  if ( !v5 || Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&argc, &str)->Result )
  {
    radix = 0;
    Size = str.pNode->Size;
    offset = 0;
    if ( Size )
    {
      if ( v5 >= 2
        && !Scaleform::GFx::AS3::Value::Convert2Int32(v4 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &radix)->Result )
      {
        goto LABEL_14;
      }
      v9 = Scaleform::GFx::NumberUtil::StringToInt((char *)str.pNode->pData, Size, radix, &offset);
    }
    else
    {
      v9 = Scaleform::GFx::NumberUtil::NaN();
    }
    other.value.VNumber = v9;
    other.Bonus.pWeakProxy = 0;
    other.Flags = 4;
    Scaleform::GFx::AS3::Value::Assign(result, &other);
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
LABEL_14:
    pNode = str.pNode;
    --str.pNode->RefCount;
    v7 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_15;
  }
  v6 = str.pNode;
  --str.pNode->RefCount;
  v7 = v6;
  if ( v6->RefCount )
    return;
LABEL_15:
  Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
