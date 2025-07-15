// local variable allocation has failed, the output may be wrong!
Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::AbstractLessThan(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Boolean3 *resulta,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  Scaleform::GFx::AS3::CheckResult *v4; // esi
  int v5; // eax
  int v6; // ecx
  bool v7; // sf
  bool v8; // of
  Scaleform::GFx::AS3::Value::V1U v9; // eax
  Scaleform::GFx::ASStringNode *VInt; // ecx
  _DWORD *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *VStr; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  char v17; // bl
  char v18; // bl
  Scaleform::GFx::AS3::Boolean3 v19; // eax
  Scaleform::GFx::AS3::CheckResult v21; // [esp+17h] [ebp-2Dh] BYREF
  Scaleform::GFx::ASString str2; // [esp+18h] [ebp-2Ch] BYREF
  long double str1; // [esp+1Ch] [ebp-28h] OVERLAPPED BYREF
  Scaleform::GFx::AS3::Value _2; // [esp+24h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value _1; // [esp+34h] [ebp-10h] BYREF

  _1.Flags = 0;
  _1.Bonus.pWeakProxy = 0;
  _2.Flags = 0;
  _2.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(l, &v21, &_1, hintNumber)->Result
    || !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(r, &v21, &_2, hintNumber)->Result )
  {
    v4 = result;
    result->Result = 0;
    goto LABEL_41;
  }
  v5 = _1.Flags & 0x1F;
  v6 = _2.Flags & 0x1F;
  if ( v5 == 2 )
  {
    if ( v6 == 2 )
    {
      v4 = result;
      v8 = __OFSUB__(_1.value.VS._1.VInt, _2.value.VS._1.VInt);
      v7 = _1.value.VS._1.VInt - _2.value.VS._1.VInt < 0;
      result->Result = 1;
      *resulta = (v7 == v8) + 1;
      goto LABEL_41;
    }
    goto LABEL_23;
  }
  if ( v5 == 3 )
  {
    if ( v6 == 3 )
    {
      v4 = result;
      *resulta = 2 - (_1.value.VS._1.VInt < (unsigned int)_2.value.VS._1.VInt);
      result->Result = 1;
      goto LABEL_41;
    }
    goto LABEL_23;
  }
  if ( v5 != 10 || v6 != 10 || (v9 = _1.value.VS._1, !_1.value.VS._1.VInt) || !_2.value.VS._1.VInt )
  {
LABEL_23:
    v17 = 1;
    if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(&_1, &v21, &str1)->Result )
      Scaleform::GFx::AS3::Value::SetNumber(&_1, str1);
    else
      v17 = 0;
    if ( !v17 )
      goto LABEL_27;
    v18 = 1;
    if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(&_2, &v21, &str1)->Result )
      Scaleform::GFx::AS3::Value::SetNumber(&_2, str1);
    else
      v18 = 0;
    if ( v18 )
    {
      str1 = _1.value.VNumber;
      if ( (HIDWORD(str1) & 0x7FF00000) == 0x7FF00000 && HIDWORD(str1) & 0xFFFFF | LODWORD(str1)
        || (str1 = _2.value.VNumber, (HIDWORD(str1) & 0x7FF00000) == 0x7FF00000)
        && HIDWORD(str1) & 0xFFFFF | LODWORD(str1) )
      {
        *resulta = undefined3;
      }
      else
      {
        v19 = true3;
        if ( _2.value.VNumber <= _1.value.VNumber )
          v19 = false3;
        *resulta = v19;
      }
      v4 = result;
      result->Result = 1;
    }
    else
    {
LABEL_27:
      v4 = result;
      result->Result = 0;
    }
    goto LABEL_41;
  }
  ++*(_DWORD *)(_1.value.VS._1.VInt + 12);
  VInt = (Scaleform::GFx::ASStringNode *)v9.VInt;
  v11 = (_DWORD *)(v9.VInt + 12);
  LODWORD(str1) = VInt;
  v12 = ++*v11 == 1;
  --*v11;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(VInt);
  VStr = _2.value.VS._1.VStr;
  ++*(_DWORD *)(_2.value.VS._1.VInt + 12);
  v14 = VStr;
  VStr = (Scaleform::GFx::ASStringNode *)((char *)VStr + 12);
  str2.pNode = v14;
  v12 = ++VStr->pData == (const char *)1;
  --VStr->pData;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v4 = result;
  *resulta = 2 - Scaleform::GFx::ASString::operator<((Scaleform::GFx::ASString *)&str1, &str2);
  pNode = str2.pNode;
  --str2.pNode->RefCount;
  result->Result = 1;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v16 = (Scaleform::GFx::ASStringNode *)LODWORD(str1);
  --*(_DWORD *)(LODWORD(str1) + 12);
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
LABEL_41:
  Scaleform::GFx::AS3::Value::~Value(&_2);
  Scaleform::GFx::AS3::Value::~Value(&_1);
  return v4;
}
