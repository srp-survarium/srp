char __thiscall Scaleform::GFx::AS2::ColorTransformObject::SetMember(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  unsigned int v7; // esi
  int v8; // edi
  int v9; // ebx
  long double v10; // st7
  __int64 v12; // [esp+1Ch] [ebp-8h]

  if ( !strcmp(name->pNode->pData, "redMultiplier") )
  {
    *(float *)&this->ArePropertiesSet = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "greenMultiplier") )
  {
    *((float *)&this->Scaleform::GFx::AS2::Object + 13) = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blueMultiplier") )
  {
    *((float *)&this->Scaleform::GFx::AS2::Object + 14) = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "alphaMultiplier") )
  {
    *((float *)&this->Scaleform::GFx::AS2::Object + 15) = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "redOffset") )
  {
    this->mColorTransform.M[0][0] = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "greenOffset") )
  {
    this->mColorTransform.M[0][1] = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "blueOffset") )
  {
    this->mColorTransform.M[0][2] = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "alphaOffset") )
  {
    this->mColorTransform.M[0][3] = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "rgb") )
  {
    *(float *)&this->ArePropertiesSet = 0.0;
    *((float *)&this->Scaleform::GFx::AS2::Object + 13) = 0.0;
    *((float *)&this->Scaleform::GFx::AS2::Object + 14) = 0.0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    if ( !Scaleform::GFx::NumberUtil::IsNaN(v10) )
    {
      v12 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(val, penv);
      v7 = BYTE2(v12);
      v8 = BYTE1(v12);
      v9 = (unsigned __int8)v12;
    }
    this->mColorTransform.M[0][0] = (float)v7;
    this->mColorTransform.M[0][1] = (float)v8;
    this->mColorTransform.M[0][2] = (float)v9;
    return 1;
  }
  else
  {
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
}
