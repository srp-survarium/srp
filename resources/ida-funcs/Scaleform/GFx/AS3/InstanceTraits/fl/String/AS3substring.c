void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3substring(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  unsigned int Length; // eax
  double v8; // st7
  double v9; // st6
  long double v10; // rt0
  long double v11; // st6
  long double v12; // st7
  long double v13; // rt2
  long double v14; // st6
  double v15; // st7
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // ecx
  bool v19; // zf
  long double v20; // st5
  long double v21; // st7
  char *v22; // esi
  long double v23; // rt0
  double v24; // st5
  signed int v25; // eax
  char *v26; // ecx
  Scaleform::GFx::ASString *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult v30; // [esp+Fh] [ebp-41h] BYREF
  Scaleform::GFx::ASString thisStr; // [esp+10h] [ebp-40h] BYREF
  unsigned int utf8Len; // [esp+14h] [ebp-3Ch] BYREF
  double endNumber; // [esp+18h] [ebp-38h] BYREF
  double startNumber; // [esp+20h] [ebp-30h] BYREF
  long double v35; // [esp+28h] [ebp-28h]
  Scaleform::GFx::AS3::Value ve; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value vb; // [esp+40h] [ebp-10h] BYREF

  utf8Len = 0;
  StringManagerRef = vm->StringManagerRef;
  thisStr.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++thisStr.pNode->RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, &v30, &thisStr)->Result )
    goto LABEL_31;
  Length = Scaleform::GFx::ASConstString::GetLength(&thisStr);
  v8 = 0.0;
  startNumber = 0.0;
  v9 = 2147483647.0;
  endNumber = 2147483647.0;
  utf8Len = Length;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &v30, &startNumber)->Result )
      goto LABEL_31;
    v8 = startNumber;
    v9 = endNumber;
  }
  if ( argc >= 2 )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v30, &endNumber)->Result )
    {
      v8 = startNumber;
      v9 = endNumber;
      goto LABEL_8;
    }
LABEL_31:
    pNode = thisStr.pNode;
    --thisStr.pNode->RefCount;
    v18 = pNode;
    v19 = pNode->RefCount == 0;
    goto LABEL_32;
  }
LABEL_8:
  v10 = v9;
  v11 = v8;
  v12 = v10;
  vb.value.VNumber = v11;
  v35 = v11;
  vb.Flags = 4;
  vb.Bonus.pWeakProxy = 0;
  if ( (HIDWORD(v35) & 0x7FF00000) == 0x7FF00000 && HIDWORD(v35) & 0xFFFFF | LODWORD(v35) )
  {
    startNumber = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
    v11 = startNumber;
    v12 = endNumber;
  }
  v13 = v11;
  v14 = v12;
  v15 = v13;
  ve.value.VNumber = v14;
  ve.Flags = 4;
  v35 = v14;
  ve.Bonus.pWeakProxy = 0;
  if ( (HIDWORD(v35) & 0x7FF00000) == 0x7FF00000 && HIDWORD(v35) & 0xFFFFF | LODWORD(v35) )
  {
    endNumber = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
    v14 = endNumber;
    v15 = startNumber;
  }
  if ( v15 != v14 )
  {
    v20 = (double)utf8Len;
    if ( v20 >= v15 )
    {
      v23 = v20;
      v24 = v15;
      v21 = v23;
      v22 = (char *)(int)v24;
    }
    else
    {
      v21 = v20;
      v22 = (char *)utf8Len;
    }
    if ( v14 <= v21 )
      v25 = (int)v14;
    else
      v25 = utf8Len;
    if ( v25 < (int)v22 )
    {
      v26 = v22;
      v22 = (char *)v25;
      v25 = (signed int)v26;
    }
    if ( (int)v22 < 0 )
      v22 = 0;
    v27 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(
            (Scaleform::GFx::ASString *)&utf8Len,
            StringManagerRef,
            &thisStr,
            v22,
            v25 - (_DWORD)v22);
    Scaleform::GFx::AS3::Value::Assign(result, v27);
    v28 = (Scaleform::GFx::ASStringNode *)utf8Len;
    --*(_DWORD *)(utf8Len + 12);
    if ( !v28->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    Scaleform::GFx::AS3::Value::~Value(&ve);
    Scaleform::GFx::AS3::Value::~Value(&vb);
    goto LABEL_31;
  }
  utf8Len = (unsigned int)&StringManagerRef->pStringManager->EmptyStringNode;
  ++*(_DWORD *)(utf8Len + 12);
  Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&utf8Len);
  v16 = (Scaleform::GFx::ASStringNode *)utf8Len;
  --*(_DWORD *)(utf8Len + 12);
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  Scaleform::GFx::AS3::Value::~Value(&ve);
  Scaleform::GFx::AS3::Value::~Value(&vb);
  v17 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  v18 = v17;
  v19 = v17->RefCount == 0;
LABEL_32:
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}
