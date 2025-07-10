bool __thiscall Scaleform::GFx::AS2::Value::IsEqual(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  unsigned __int8 Type; // al
  char v5; // dl
  unsigned __int8 v6; // bl
  char v7; // cl
  bool v8; // bl
  bool result; // al
  bool v10; // bl
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::ASStringNode *v12; // esi
  unsigned int RefCount; // eax
  bool v14; // bl
  bool v16; // bl
  long double val; // st7
  bool IsEqual; // bl
  Scaleform::GFx::ASStringNode *v19; // eax
  const Scaleform::GFx::ASString *CharacterNamePath; // esi
  Scaleform::GFx::AS2::Value primVal; // [esp+48h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v22; // [esp+58h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v23; // [esp+68h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+78h] [ebp-10h] BYREF

  Type = this->T.Type;
  v5 = !this->T.Type || Type == 10 || Type == 1;
  v6 = v->T.Type;
  v7 = !v->T.Type || v6 == 10 || v6 == 1;
  if ( v5 || v7 )
    return v5 == v7;
  switch ( Type )
  {
    case 2u:
      v24.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
      v24.T.Type = 3;
      IsEqual = Scaleform::GFx::AS2::Value::IsEqual(&v24, penv, v);
      if ( v24.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v24);
      result = IsEqual;
      break;
    case 3u:
      if ( v6 != 2 && (Scaleform::GFx::AS2::Value::IsFunction(v) || v6 == 6) )
      {
        Scaleform::GFx::AS2::Value::ToPrimitive(v, &primVal, penv, NoHint);
        if ( !Scaleform::GFx::AS2::Value::IsPrimitive(&primVal) )
          goto LABEL_33;
        v16 = Scaleform::GFx::AS2::Value::IsEqual(this, penv, &primVal);
        if ( primVal.T.Type < 5u )
          goto LABEL_32;
        goto LABEL_72;
      }
      *(double *)&primVal.T.Type = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
      if ( Scaleform::GFx::NumberUtil::IsNaN(this->NV.NumberValue) )
      {
        if ( !Scaleform::GFx::NumberUtil::IsNaN(*(long double *)&primVal.T.Type) )
          goto LABEL_35;
        result = 1;
      }
      else
      {
        if ( Scaleform::GFx::NumberUtil::IsNaN(*(long double *)&primVal.T.Type) )
          goto LABEL_35;
        result = *(double *)&primVal.T.Type == this->NV.NumberValue;
      }
      break;
    case 4u:
      if ( v6 == 3 )
      {
        val = (double)this->NV.Int32Value;
        primVal.T.Type = 0;
        Scaleform::GFx::AS2::Value::SetNumber(&primVal, val);
        v16 = Scaleform::GFx::AS2::Value::IsEqual(&primVal, penv, v);
        if ( primVal.T.Type < 5u )
          goto LABEL_32;
        goto LABEL_72;
      }
      if ( v6 != 2 && (Scaleform::GFx::AS2::Value::IsFunction(v) || v6 == 6) )
      {
        Scaleform::GFx::AS2::Value::ToPrimitive(v, &primVal, penv, NoHint);
        if ( !Scaleform::GFx::AS2::Value::IsPrimitive(&primVal) )
          goto LABEL_33;
        v16 = Scaleform::GFx::AS2::Value::IsEqual(this, penv, &primVal);
        if ( primVal.T.Type < 5u )
          goto LABEL_32;
        goto LABEL_72;
      }
      result = this->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v, penv);
      break;
    case 5u:
      if ( Scaleform::GFx::AS2::Value::IsNumber(v) )
      {
        v22.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
        v22.T.Type = 3;
        v8 = Scaleform::GFx::AS2::Value::IsEqual(&v22, penv, v);
        if ( v22.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v22);
        result = v8;
      }
      else if ( v6 == 2 )
      {
        v23.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
        v23.T.Type = 3;
        v10 = Scaleform::GFx::AS2::Value::IsEqual(this, penv, &v23);
        if ( v23.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v23);
        result = v10;
      }
      else
      {
        if ( Scaleform::GFx::AS2::Value::IsFunction(v) || v6 == 6 )
        {
          Scaleform::GFx::AS2::Value::ToPrimitive(v, &primVal, penv, NoHint);
          if ( !Scaleform::GFx::AS2::Value::IsPrimitive(&primVal) )
            goto LABEL_33;
          v16 = Scaleform::GFx::AS2::Value::IsEqual(this, penv, &primVal);
          if ( primVal.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&primVal);
          goto LABEL_32;
        }
        Scaleform::GFx::AS2::Value::ToStringImpl(v, (Scaleform::GFx::ASString *)&primVal, penv, -1, 0);
        pStringNode = this->V.pStringNode;
        v12 = *(Scaleform::GFx::ASStringNode **)&primVal.T.Type;
        RefCount = pStringNode->RefCount;
        v14 = pStringNode == *(Scaleform::GFx::ASStringNode **)&primVal.T.Type;
        pStringNode->RefCount = RefCount;
        if ( !RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pStringNode);
        if ( v12->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        result = v14;
      }
      break;
    case 6u:
    case 8u:
      if ( Scaleform::GFx::AS2::Value::IsNumber(v) || v6 == 5 || v6 == 2 )
      {
        Scaleform::GFx::AS2::Value::ToPrimitive(this, &primVal, penv, NoHint);
        if ( !Scaleform::GFx::AS2::Value::IsPrimitive(&primVal) )
        {
LABEL_33:
          if ( primVal.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&primVal);
          goto LABEL_35;
        }
        v16 = Scaleform::GFx::AS2::Value::IsEqual(&primVal, penv, v);
        if ( primVal.T.Type < 5u )
        {
LABEL_32:
          result = v16;
        }
        else
        {
LABEL_72:
          Scaleform::GFx::AS2::Value::DropRefs(&primVal);
          result = v16;
        }
      }
      else if ( this->T.Type == 6 && v6 == 6 )
      {
        result = this->NV.Int32Value == v->NV.Int32Value;
      }
      else
      {
        if ( this->T.Type != 8 || v6 != 8 )
          goto LABEL_35;
        result = this->NV.Int32Value == v->NV.Int32Value;
      }
      break;
    case 7u:
      if ( v6 == 7 )
      {
        v19 = this->V.pStringNode;
        if ( v19 && v->NV.Int32Value )
        {
          CharacterNamePath = Scaleform::GFx::AS2::Value::GetCharacterNamePath(v, penv);
          result = Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, penv)->pNode == CharacterNamePath->pNode;
        }
        else
        {
          result = v19 == v->V.pStringNode;
        }
      }
      else
      {
LABEL_35:
        result = 0;
      }
      break;
    default:
      result = Type == v6;
      break;
  }
  return result;
}
