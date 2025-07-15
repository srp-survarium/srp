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
  Scaleform::GFx::AS2::Value pv1; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value pv2; // [esp+28h] [ebp-10h] BYREF

  v3 = penv;
  pv1.T.Type = 0;
  pv2.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&pv1, v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  v6 = Scaleform::GFx::AS2::Value::ToPrimitive(v, &result, v3, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&pv2, v6);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  if ( pv1.T.Type == 5 || pv2.T.Type == 5 )
  {
    SWFVersion = v3->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&pv1, (Scaleform::GFx::ASString *)&penv, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::DropRefs(&pv1);
    v11 = (Scaleform::GFx::ASStringNode *)penv;
    ++penv->Stack.pPageEnd;
    v12 = v11->RefCount-- == 1;
    pv1.T.Type = 5;
    pv1.NV.Int32Value = (int)v11;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v13 = Scaleform::GFx::AS2::Value::ToStringVersioned(&pv2, (Scaleform::GFx::ASString *)&penv, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::StringConcat(&pv1, v3, v13);
    v14 = (Scaleform::GFx::ASStringNode *)penv;
    --penv->Stack.pPageEnd;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    Scaleform::GFx::AS2::Value::ToStringImpl(&pv1, (Scaleform::GFx::ASString *)&penv, v3, -1, 0);
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
    *(double *)&result.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&pv2, v3);
    v7 = Scaleform::GFx::AS2::Value::ToNumber(&pv1, v3);
    v8 = this->T.Type < 5u;
    *(double *)&result.T.Type = v7 + *(double *)&result.T.Type;
    if ( !v8 )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    v9 = *(double *)&result.T.Type;
    this->T.Type = 3;
    this->NV.NumberValue = v9;
  }
  if ( pv2.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pv2);
  if ( pv1.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pv1);
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
  Scaleform::GFx::AS2::Value pv1; // [esp+18h] [ebp-10h] BYREF

  v3 = penv;
  pv1.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&pv1, v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  if ( pv1.T.Type == 5 )
  {
    SWFVersion = v3->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&pv1, (Scaleform::GFx::ASString *)&penv, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::DropRefs(&pv1);
    v7 = (Scaleform::GFx::ASStringNode *)penv;
    ++penv->Stack.pPageEnd;
    v8 = v7->RefCount-- == 1;
    pv1.T.Type = 5;
    pv1.NV.Int32Value = (int)v7;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    result.T.Type = 4;
    result.NV.Int32Value = (int)v2;
    v9 = Scaleform::GFx::AS2::Value::ToStringVersioned(&result, (Scaleform::GFx::ASString *)&v2, v3, SWFVersion);
    Scaleform::GFx::AS2::Value::StringConcat(&pv1, v3, v9);
    v10 = v2;
    --v2->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    Scaleform::GFx::AS2::Value::ToStringImpl(&pv1, (Scaleform::GFx::ASString *)&v2, v3, -1, 0);
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
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&pv1, v3);
    v13 = this->T.Type < 5u;
    *(double *)&result.T.Type = v12 + (double)(int)v2;
    if ( !v13 )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    v14 = *(double *)&result.T.Type;
    this->T.Type = 3;
    this->NV.NumberValue = v14;
  }
  if ( pv1.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pv1);
}
