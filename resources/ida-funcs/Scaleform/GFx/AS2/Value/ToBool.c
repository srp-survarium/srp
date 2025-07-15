bool __userpurge Scaleform::GFx::AS2::Value::ToBool@<al>(
        Scaleform::GFx::AS2::Value *this@<ecx>,
        int a2@<edi>,
        const Scaleform::GFx::AS2::Environment *penv)
{
  unsigned __int8 Type; // al
  Scaleform::GFx::ASStringNode *pStringNode; // esi
  bool v7; // c3
  long double v8; // [esp+Ch] [ebp-8h] BYREF

  Type = this->T.Type;
  if ( this->T.Type == 5 )
  {
    pStringNode = this->V.pStringNode;
    if ( !pStringNode->Size )
      return 0;
    if ( penv->StringContext.SWFVersion <= 6u )
    {
      if ( !Scaleform::GFx::AS2::StringToNumber((char *)pStringNode->pData, a2, &v8)
        || Scaleform::GFx::NumberUtil::IsNaN(v8) )
      {
        return 0;
      }
      v7 = 0.0 == v8;
      return !v7;
    }
    return 1;
  }
  else
  {
    switch ( Type )
    {
      case 3u:
        if ( Scaleform::GFx::NumberUtil::IsNaN(this->NV.NumberValue) )
          return 0;
        v7 = 0.0 == this->NV.NumberValue;
        return !v7;
      case 4u:
        return this->NV.Int32Value != 0;
      case 2u:
        return this->V.BooleanValue;
      case 6u:
        return this->NV.Int32Value != 0;
      case 7u:
        return Scaleform::GFx::AS2::Value::ToCharacter(this, penv) != 0;
      case 8u:
        return this->NV.Int32Value != 0;
    }
    return Type == 11;
  }
}
