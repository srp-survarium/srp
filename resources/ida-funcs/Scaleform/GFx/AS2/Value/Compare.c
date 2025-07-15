Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Value::Compare(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *result,
        __int64 penv,
        int action)
{
  bool IsEqual; // cl
  Scaleform::GFx::AS2::Value *v5; // eax
  unsigned __int8 Type; // al
  unsigned __int8 v7; // bl
  Scaleform::GFx::AS2::Value *v8; // esi
  Scaleform::GFx::ASStringNode *v9; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v13; // cl
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // esi
  bool v16; // cf
  double v17; // st7
  Scaleform::GFx::ASString str[2]; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::ASString v19[2]; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value resulta; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+38h] [ebp-10h] BYREF

  if ( !action )
  {
    IsEqual = Scaleform::GFx::AS2::Value::IsEqual(
                this,
                (Scaleform::GFx::AS2::Environment *)penv,
                (Scaleform::GFx::AS2::Value *)HIDWORD(penv));
    v5 = result;
    result->T.Type = 2;
    result->V.BooleanValue = IsEqual;
    return v5;
  }
  Scaleform::GFx::AS2::Value::ToPrimitive(this, &resulta, (Scaleform::GFx::AS2::Environment *)penv, NoHint);
  Scaleform::GFx::AS2::Value::ToPrimitive(
    (Scaleform::GFx::AS2::Value *)HIDWORD(penv),
    &v21,
    (Scaleform::GFx::AS2::Environment *)penv,
    NoHint);
  Type = resulta.T.Type;
  v7 = v21.T.Type;
  if ( resulta.T.Type == 5 && v21.T.Type == 5 )
  {
    if ( action >= 0 )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(&v21, v19, (Scaleform::GFx::AS2::Environment *)penv, -1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(&resulta, str, (Scaleform::GFx::AS2::Environment *)penv, -1, 0);
      pNode = str[0].pNode;
      if ( str[0].pNode == v19[0].pNode )
      {
        v13 = 0;
      }
      else
      {
        v10 = !Scaleform::GFx::ASString::operator<(str, v19);
        pNode = str[0].pNode;
        v13 = v10;
      }
      v8 = result;
      --pNode->RefCount;
      result->V.BooleanValue = v13;
      v10 = pNode->RefCount == 0;
      result->T.Type = 2;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v14 = v19[0].pNode;
      --v19[0].pNode->RefCount;
      if ( !v14->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    else
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(&v21, str, (Scaleform::GFx::AS2::Environment *)penv, -1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(&resulta, v19, (Scaleform::GFx::AS2::Environment *)penv, -1, 0);
      v8 = result;
      result->V.BooleanValue = Scaleform::GFx::ASString::operator<(v19, str);
      v9 = v19[0].pNode;
      --v19[0].pNode->RefCount;
      v10 = v9->RefCount == 0;
      result->T.Type = 2;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      v11 = str[0].pNode;
      --str[0].pNode->RefCount;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
    Scaleform::GFx::AS2::Value::DropRefs(&resulta);
    return v8;
  }
  if ( *(_BYTE *)(penv + 120) <= 6u || resulta.T.Type && resulta.T.Type != 10 && v21.T.Type && v21.T.Type != 10 )
  {
    v17 = Scaleform::GFx::AS2::Value::ToNumber(&resulta, (Scaleform::GFx::AS2::Environment *)penv);
    if ( action >= 0 )
    {
      *(double *)&v19[0].pNode = v17;
      *(double *)&str[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v21, (Scaleform::GFx::AS2::Environment *)penv);
    }
    else
    {
      *(double *)&str[0].pNode = v17;
      *(double *)&v19[0].pNode = Scaleform::GFx::AS2::Value::ToNumber(&v21, (Scaleform::GFx::AS2::Environment *)penv);
    }
    if ( Scaleform::GFx::NumberUtil::IsNaN(*(long double *)&str[0].pNode)
      || Scaleform::GFx::NumberUtil::IsNaN(*(long double *)&v19[0].pNode) )
    {
      v15 = result;
      result->T.Type = 0;
      goto LABEL_47;
    }
    if ( *(double *)&str[0].pNode != *(double *)&v19[0].pNode
      && (!Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(*(long double *)&str[0].pNode)
       || !Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(*(long double *)&v19[0].pNode))
      && (!Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(*(long double *)&v19[0].pNode)
       || !Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(*(long double *)&str[0].pNode))
      && !Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(*(long double *)&str[0].pNode) )
    {
      if ( Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(*(long double *)&v19[0].pNode) )
      {
        v15 = result;
        result->T.Type = 2;
        result->V.BooleanValue = 1;
        goto LABEL_47;
      }
      if ( !Scaleform::GFx::NumberUtil::IsNEGATIVE_INFINITY(*(long double *)&v19[0].pNode) )
      {
        if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_INFINITY(*(long double *)&str[0].pNode) )
        {
          v15 = result;
          result->T.Type = 2;
          result->V.BooleanValue = 1;
          goto LABEL_47;
        }
        if ( *(double *)&v19[0].pNode > *(double *)&str[0].pNode )
        {
          v15 = result;
          result->T.Type = 2;
          result->V.BooleanValue = 1;
          goto LABEL_47;
        }
      }
    }
    v15 = result;
    result->T.Type = 2;
    result->V.BooleanValue = 0;
LABEL_47:
    if ( v7 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    v16 = resulta.T.Type < 5u;
    goto LABEL_50;
  }
  v15 = result;
  result->T.Type = 0;
  if ( v7 >= 5u )
  {
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
    Type = resulta.T.Type;
  }
  v16 = Type < 5u;
LABEL_50:
  if ( !v16 )
    Scaleform::GFx::AS2::Value::DropRefs(&resulta);
  return v15;
}
