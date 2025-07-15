void __thiscall Scaleform::GFx::AS2::Value::Add(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Environment *v3; // esi
  const Scaleform::GFx::AS2::Value *v5; // eax
  const Scaleform::GFx::AS2::Value *v6; // eax
  long double v7; // st7
  bool v8; // cf
  long double v9; // st7
  unsigned int SWFVersion; // edi
  Scaleform::GFx::ASStringNode *v11; // ecx
  bool v12; // zf
  const Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // ecx
  Scaleform::GFx::AS2::Value result; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v17; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+28h] [ebp-10h] BYREF

  v3 = penv;
  v17.T.Type = 0;
  v18.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&v17, v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  v6 = Scaleform::GFx::AS2::Value::ToPrimitive(v, &result, v3, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&v18, v6);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  if ( v17.T.Type == 5 || v18.T.Type == 5 )
  {
    SWFVersion = v3->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&v17, (Scaleform::GFx::ASString *)&penv, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
    v11 = (Scaleform::GFx::ASStringNode *)penv;
    ++penv->Stack.pPageEnd;
    v12 = v11->RefCount-- == 1;
    v17.T.Type = 5;
    v17.NV.Int32Value = (int)v11;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v13 = Scaleform::GFx::AS2::Value::ToStringVersioned(&v18, (Scaleform::GFx::ASString *)&penv, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::StringConcat(&v17, v3, v13);
    v14 = (Scaleform::GFx::ASStringNode *)penv;
    --penv->Stack.pPageEnd;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, (Scaleform::GFx::ASString *)&penv, v3, -1, 0);
    if ( this->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    v15 = (Scaleform::GFx::ASStringNode *)penv;
    this->T.Type = 5;
    this->NV.Int32Value = (int)v15;
    v12 = ++v15->RefCount == 1;
    --v15->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
  else
  {
    *(double *)&result.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&v18, v3);
    v7 = Scaleform::GFx::AS2::Value::ToNumber(&v17, v3);
    v8 = this->T.Type < 5u;
    *(double *)&result.T.Type = v7 + *(double *)&result.T.Type;
    if ( !v8 )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    v9 = *(double *)&result.T.Type;
    this->T.Type = 3;
    this->NV.NumberValue = v9;
  }
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
}


void __thiscall Scaleform::GFx::AS2::Value::Add(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASStringNode *v2)
{
  Scaleform::GFx::AS2::Environment *v3; // esi
  const Scaleform::GFx::AS2::Value *v5; // eax
  unsigned int SWFVersion; // ebp
  Scaleform::GFx::ASStringNode *v7; // ecx
  bool v8; // zf
  const Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // ecx
  long double v12; // st7
  bool v13; // cf
  long double v14; // st7
  Scaleform::GFx::AS2::Value result; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v16; // [esp+18h] [ebp-10h] BYREF

  v3 = penv;
  v16.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&v16, v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  if ( v16.T.Type == 5 )
  {
    SWFVersion = v3->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&v16, (Scaleform::GFx::ASString *)&penv, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
    v7 = (Scaleform::GFx::ASStringNode *)penv;
    ++penv->Stack.pPageEnd;
    v8 = v7->RefCount-- == 1;
    v16.T.Type = 5;
    v16.NV.Int32Value = (int)v7;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    result.T.Type = 4;
    result.NV.Int32Value = (int)v2;
    v9 = Scaleform::GFx::AS2::Value::ToStringVersioned(&result, (Scaleform::GFx::ASString *)&v2, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::StringConcat(&v16, v3, v9);
    v10 = v2;
    --v2->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    Scaleform::GFx::AS2::Value::ToStringImpl(&v16, (Scaleform::GFx::ASString *)&v2, v3, -1, 0);
    if ( this->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    v11 = v2;
    this->T.Type = 5;
    this->NV.Int32Value = (int)v11;
    v8 = ++v11->RefCount == 1;
    --v11->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&v16, v3);
    v13 = this->T.Type < 5u;
    *(double *)&result.T.Type = v12 + (double)(int)v2;
    if ( !v13 )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    v14 = *(double *)&result.T.Type;
    this->T.Type = 3;
    this->NV.NumberValue = v14;
  }
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
}
