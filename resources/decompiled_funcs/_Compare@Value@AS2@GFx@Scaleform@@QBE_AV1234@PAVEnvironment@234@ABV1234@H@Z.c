Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Value::Compare(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v,
        int action)
{
  bool IsEqual; // cl
  Scaleform::GFx::AS2::Value *v6; // eax
  unsigned __int8 Type; // al
  unsigned __int8 v8; // bl
  Scaleform::GFx::AS2::Value *v9; // esi
  Scaleform::GFx::ASStringNode *v10; // eax
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  bool v14; // cl
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // esi
  bool v17; // cf
  long double v18; // st7
  long double val1; // [esp+18h] [ebp-30h] BYREF
  long double val2; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value pv1; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value pv2; // [esp+38h] [ebp-10h] BYREF

  if ( !action )
  {
    IsEqual = Scaleform::GFx::AS2::Value::IsEqual(this, penv, v);
    v6 = result;
    result->T.Type = 2;
    result->V.BooleanValue = IsEqual;
    return v6;
  }
  Scaleform::GFx::AS2::Value::ToPrimitive(this, &pv1, penv, NoHint);
  Scaleform::GFx::AS2::Value::ToPrimitive(v, &pv2, penv, NoHint);
  Type = pv1.T.Type;
  v8 = pv2.T.Type;
  if ( pv1.T.Type == 5 && pv2.T.Type == 5 )
  {
    if ( action >= 0 )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(&pv2, (Scaleform::GFx::ASString *)&val2, penv, -1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(&pv1, (Scaleform::GFx::ASString *)&val1, penv, -1, 0);
      v13 = (Scaleform::GFx::ASStringNode *)LODWORD(val1);
      if ( LODWORD(val1) == LODWORD(val2) )
      {
        v14 = 0;
      }
      else
      {
        v11 = !Scaleform::GFx::ASString::operator<(
                 (Scaleform::GFx::ASString *)&val1,
                 (const Scaleform::GFx::ASString *)&val2);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(val1);
        v14 = v11;
      }
      v9 = result;
      --v13->RefCount;
      result->V.BooleanValue = v14;
      v11 = v13->RefCount == 0;
      result->T.Type = 2;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      v15 = (Scaleform::GFx::ASStringNode *)LODWORD(val2);
      --*(_DWORD *)(LODWORD(val2) + 12);
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(&pv2, (Scaleform::GFx::ASString *)&val1, penv, -1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(&pv1, (Scaleform::GFx::ASString *)&val2, penv, -1, 0);
      v9 = result;
      result->V.BooleanValue = Scaleform::GFx::ASString::operator<(
                                 (Scaleform::GFx::ASString *)&val2,
                                 (const Scaleform::GFx::ASString *)&val1);
      v10 = (Scaleform::GFx::ASStringNode *)LODWORD(val2);
      --*(_DWORD *)(LODWORD(val2) + 12);
      v11 = v10->RefCount == 0;
      result->T.Type = 2;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v12 = (Scaleform::GFx::ASStringNode *)LODWORD(val1);
      --*(_DWORD *)(LODWORD(val1) + 12);
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
    Scaleform::GFx::AS2::Value::DropRefs(&pv2);
    Scaleform::GFx::AS2::Value::DropRefs(&pv1);
    return v9;
  }
  if ( penv->StringContext.SWFVersion <= 6u || pv1.T.Type && pv1.T.Type != 10 && pv2.T.Type && pv2.T.Type != 10 )
  {
    v18 = Scaleform::GFx::AS2::Value::ToNumber(&pv1, penv);
    if ( action >= 0 )
    {
      val2 = v18;
      val1 = Scaleform::GFx::AS2::Value::ToNumber(&pv2, penv);
    }
    else
    {
      val1 = v18;
      val2 = Scaleform::GFx::AS2::Value::ToNumber(&pv2, penv);
    }
    if ( Scaleform::GFx::NumberUtil::IsNaN(val1) || Scaleform::GFx::NumberUtil::IsNaN(val2) )
    {
      v16 = result;
      result->T.Type = 0;
      goto LABEL_47;
    }
    if ( val1 != val2
      && (!Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(val1) || !Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(val2))
      && (!Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(val2) || !Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(val1))
      && !Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(val1) )
    {
      if ( Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(val2) )
      {
        v16 = result;
        result->T.Type = 2;
        result->V.BooleanValue = 1;
        goto LABEL_47;
      }
      if ( !Scaleform::GFx::NumberUtil::IsNEGATIVE_INFINITY(val2) )
      {
        if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_INFINITY(val1) )
        {
          v16 = result;
          result->T.Type = 2;
          result->V.BooleanValue = 1;
          goto LABEL_47;
        }
        if ( val2 > val1 )
        {
          v16 = result;
          result->T.Type = 2;
          result->V.BooleanValue = 1;
          goto LABEL_47;
        }
      }
    }
    v16 = result;
    result->T.Type = 2;
    result->V.BooleanValue = 0;
LABEL_47:
    if ( v8 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pv2);
    v17 = pv1.T.Type < 5u;
    goto LABEL_50;
  }
  v16 = result;
  result->T.Type = 0;
  if ( v8 >= 5u )
  {
    Scaleform::GFx::AS2::Value::DropRefs(&pv2);
    Type = pv1.T.Type;
  }
  v17 = Type < 5u;
LABEL_50:
  if ( !v17 )
    Scaleform::GFx::AS2::Value::DropRefs(&pv1);
  return v16;
}
