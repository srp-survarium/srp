Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::ArrayBase::ToString(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *sep)
{
  unsigned int v4; // ebp
  char *v5; // edi
  void (__thiscall *GetValueUnsafe)(Scaleform::GFx::AS3::ArrayBase *, unsigned int, Scaleform::GFx::AS3::Value *); // edx
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS3::CheckResult v10; // [esp+13h] [ebp-29h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+14h] [ebp-28h] BYREF
  Scaleform::StringBuffer buff; // [esp+24h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&buff, this->VMRef->MHeap);
  v4 = this->GetArraySize(this);
  v5 = 0;
  if ( !v4 )
    goto LABEL_20;
  while ( 1 )
  {
    if ( v5 )
      Scaleform::StringBuffer::AppendString(&buff, (char *)sep->pNode->pData, 0xFFFFFFFF);
    GetValueUnsafe = this->GetValueUnsafe;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    GetValueUnsafe(this, (unsigned int)v5, &v);
    if ( (v.Flags & 0x1F) != 0 && ((v.Flags & 0x1F) - 12 > 3 || v.value.VS._1.VInt) )
      break;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) == 0 )
        goto LABEL_13;
LABEL_9:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    }
LABEL_14:
    if ( (unsigned int)++v5 >= v4 )
      goto LABEL_20;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2String(&v, v5, &v10, &buff)->Result )
  {
    if ( (v.Flags & 0x1F) <= 9 )
      goto LABEL_14;
    if ( (v.Flags & 0x200) == 0 )
    {
LABEL_13:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      goto LABEL_14;
    }
    goto LABEL_9;
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
LABEL_20:
  pData = buff.pData;
  if ( !buff.pData )
    pData = (char *)&buf;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->VMRef->StringManagerRef->pStringManager,
                 pData,
                 buff.Size);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
  return result;
}
